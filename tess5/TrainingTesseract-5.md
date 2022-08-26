# How to train LSTM/neural net Tesseract

**Have questions about the training process?** If you had some problems during
the training process and you need help, use
[tesseract-ocr](https://groups.google.com/forum/#!forum/tesseract-ocr)
mailing-list to ask your question(s). **PLEASE DO NOT** report your problems and
ask questions about training as
[issues](https://github.com/tesseract-ocr/tesseract/issues)!

**Training with `tesstrain.sh` bash scripts is unsupported/abandoned for Tesseract 5.
Please use python scripts from [tesstrain repo](https://github.com/tesseract-ocr/tesstrain) for training.**

# Contents

   * [Introduction](#introduction)
   * [Before You Start](#before-you-start)
   * [Hardware-Software Requirements](#hardware-software-requirements)
   * [Additional Libraries Required](#additional-libraries-required)
   * [Building the Training Tools](#building-the-training-tools)
   * [Training Text Requirements](#training-text-requirements)
   * [Overview of Training Process](#overview-of-training-process)
   * [Understanding the Various Files Used During Training](#understanding-the-various-files-used-during-training)
   * [LSTMTraining Command Line](#lstmtraining-command-line)
      * [Unicharset Compression-recoding](#unicharset-compression-recoding)
      * [Randomized Training Data and sequential_training](#randomized-training-data-and-sequential_training)
      * [Model output](#model-output)
      * [Net Mode and Optimization](#net-mode-and-optimization)
      * [Perfect Sample Delay](#perfect-sample-delay)
      * [Debug Interval and Visual Debugging](#debug-interval-and-visual-debugging)
      * [Iterations and Checkpoints](#iterations-and-checkpoints)
      * [Error Messages From Training](#error-messages-from-training)
   * [Combining the Output Files](#combining-the-output-files)
   * [The Hallucination Effect](#the-hallucination-effect)

## Introduction

Tesseract 4.00 introduced a new neural network-based recognition engine that
delivers significantly higher accuracy (on document images) than the previous
versions, in return for a significant increase in required compute power. On
complex languages however, it may actually be *faster* than base Tesseract.

Neural networks require significantly more training data and train *a lot*
slower than base Tesseract. For Latin-based languages, the existing model data
provided has been trained on about [400000 textlines spanning about 4500
fonts](https://github.com/tesseract-ocr/tesseract/issues/654#issuecomment-274574951).
For other scripts, not so many fonts are available, but they have still been
trained on a similar number of textlines. Instead of taking a few minutes to a
couple of hours to train, Tesseract 4.00 takes a few *days* to a couple of
*weeks.* Even with all this new training data, you might find it inadequate for
your particular problem, and therefore you are here wanting to retrain it.

There are multiple options for training:

*   Fine tune. Starting with an existing trained language, train on your
    specific additional data. This may work for problems that are close to the
    existing training data, but different in some subtle way, like a
    particularly unusual font. May work with even a small amount of training
    data.
*   Cut off the top layer (or some arbitrary number of layers) from the network
    and retrain a new top layer using the new data. If fine tuning doesn't work,
    this is most likely the next best option. Cutting off the top layer could
    still work for training a completely new language or script, if you start
    with the most similar looking script.
*   Retrain from scratch. This is a daunting task, unless you have a very
    representative and sufficiently large training set for your problem. If not,
    you are likely to end up with an over-fitted network that does really well
    on the training data, but not on the actual data.

While the above options may sound different, the training steps are actually
almost identical, apart from the command line, so it is relatively easy to try
it all ways, given the time or hardware to run them in parallel.

The old recognition engine is still present, and can also be trained, but is
deprecated, and, unless good reasons materialize to keep it, may be deleted
in a future release.

## Before You Start

You don't need any background in neural networks to train Tesseract, but it
may help in understanding the difference between the training options. Please
read the [Implementation introduction](../tess4/NeuralNetsInTesseract4.00.md) before delving
too deeply into the training process.

**Important note**: 
It's important to note that, unless you're using a very unusual font or
a new language, retraining Tesseract is unlikely to help.
Before you invest time and effort on training Tesseract, it
is highly recommended to read the [ImproveQuality](../ImproveQuality.md) page.
Many times recognition can be improved just by preprocessing the input image.

## Hardware-Software Requirements

At time of writing, training only works on Linux. (macOS almost works; it requires
minor hacks to the shell scripts to account for the older version of `bash` it
provides and differences in `mktemp`.) Windows is unknown, but would need msys or Cygwin.

As for running Tesseract, it is useful, but not essential to have a multi-core (4 is good)
machine, with OpenMP and Intel Intrinsics support for SSE/AVX extensions.
Basically it will still run on anything with enough memory, but the higher-end
your processor is, the faster it will go. No GPU is needed. (No support.) Memory
use can be controlled via the --max_image_MB command-line option, but you are
likely to need at least 1GB of memory over and above what is taken by your OS.

## Additional Libraries Required

Beginning with 3.03, additional libraries are required to build the training
tools.

```bash
sudo apt-get install libicu-dev libpango1.0-dev libcairo2-dev
```

## Building the Training Tools

Beginning with 3.03, if you're compiling Tesseract from source you need to make
and install the training tools with separate make commands.

For training, you will have to ensure all those optional dependencies are installed
and that Tesseract's build environment can locate them.
Look for these lines in the output of `./configure`:

```
checking for pkg-config... [some valid path]
checking for lept >= 1.74... yes
checking for libarchive... yes
checking for icu-uc >= 52.1... yes
checking for icu-i18n >= 52.1... yes
checking for pango >= 1.22.0... yes
checking for cairo... yes
[...]
Training tools can be built and installed with:
```

(The version numbers may change over time, of course. What we are looking for is
"yes", all of the optional dependencies are available.)

After configuring, you can attempt to build the training tools:

```bash
make
make training
sudo make training-install
```

It is also useful, but not required, to build [ScrollView.jar](https://github.com/tesseract-ocr/tessdoc/blob/main/ViewerDebugging.md):

```bash
make ScrollView.jar
export SCROLLVIEW_PATH=$PWD/java
```

## Training Text Requirements

For Latin-based languages, the existing model data provided has been trained on
about [400000 textlines spanning about 4500
fonts](https://github.com/tesseract-ocr/tesseract/issues/654#issuecomment-274574951).
For other scripts, not so many fonts are available, but they have still been
trained on a similar number of textlines.

Note that it is beneficial to have more training text and make more pages
though, as neural nets don't generalize as well and need to train on something
similar to what they will be running on. If the target domain is severely
limited, then all the dire warnings about needing a lot of training data may not
apply, but the network specification may need to be changed.

## Overview of Training Process

The main steps in training are:

1.  [Prepare training
    text.](https://github.com/tesseract-ocr/tesseract/issues/654#issuecomment-274574951)
1.  Render text to image + box file. (Or create hand-made box files for existing
    image data.)
1.  Make unicharset file. (Can be partially specified, i.e. created manually).
1.  [Make a starter/proto traineddata from the unicharset and optional dictionary
     data.](#creating-starter-traineddata)
1.  Run tesseract to process image + box file to make training data set (lstmf files).
1.  Run training on training data set.
1.  Combine data files.

The key differences from training base Tesseract (Legacy Tesseract 3.04) are:

*   The boxes only need to be at the *textline level.* It is thus *far easier*
    to make training data from existing image data.
*   The .tr files are replaced by .lstmf data files.
*   Fonts *can and should be mixed freely* instead of being separate.
*   The clustering steps (mftraining, cntraining, shapeclustering) are replaced
    with a single slow `lstmtraining` step.

The training cannot be quite as automated as the training for 3.04 for several
reasons:

*   The slow training step isn't good to run from the middle of a script as it
    can be restarted if stopped, and it is hard to tell automatically when it is
    finished.
*   There are multiple options for how to train the network (see above).
*   The language models and unicharset are allowed to be different from those
    used by base/legacy Tesseract, but don't have to be.
*   It isn't necessary to have a base/legacy Tesseract of the same language as the
    neural net Tesseract.

## Understanding the Various Files Used During Training

As with base/legacy Tesseract, the completed LSTM model and everything else it needs is
collected in the `traineddata` file. Unlike base/legacy Tesseract, a `starter/proto traineddata`
file is given during training, and has to be setup in advance. It can contain:

*   Config file providing control parameters.
*   **Unicharset** defining the character set.
*   **Unicharcompress,** aka the recoder, which maps the unicharset further to
    the codes actually used by the neural network recognizer.
*   Punctuation pattern dawg, with patterns of punctuation allowed around words.
*   Word dawg. The system word-list language model.
*   Number dawg, with patterns of numbers that are allowed.

Bold elements **must** be provided. Others are optional, but if any of the dawgs
are provided, the **punctuation dawg** must also be provided. 

A new tool `combine_lang_model` is provided to make a `starter traineddata` from a
`unicharset` and optional wordlists and is required for training.

During training, the trainer writes checkpoint files, which is a standard
behavior for neural network trainers. This allows training to be stopped and
continued again later if desired. Any checkpoint can be converted to a full
`traineddata` for recognition by using the `--stop_training` command-line flag.

The trainer also periodically writes checkpoint files at new bests achieved
during training.

It is possible to modify the network and retrain just part of it, or fine tune
for specific training data (even with a modified unicharset!) by telling the
trainer to `--continue_from` either an existing checkpoint file, or from a naked
LSTM model file that has been extracted from an existing `traineddata` file
using `combine_tessdata` _provided it has not been converted to integer._

If the unicharset is changed in the `--traineddata` flag, compared to the one
that was used in the model provided via `--continue_from`, then the
`--old_traineddata` flag must be provided with the corresponding `traineddata`
file that holds the `unicharset` and `recoder.` This enables the trainer to
compute the mapping between the character sets.

The training data is provided via `.lstmf` files, which are serialized
`DocumentData` They contain an image and the corresponding UTF8 text
transcription, and can be generated from tif/box file pairs using Tesseract in a
similar manner to the way `.tr` files were created for the old engine.

## LSTMTraining Command Line

The lstmtraining program is a multi-purpose tool for training neural networks.
The following table describes its command-line options:

| **Flag**               | **Type** | **Default** | **Explanation**    |
| :--------------------- | :------: | :---------: | :----------------- |
| `traineddata`          | `string` | none        | Path to the starter traineddata file that contains the unicharset, recoder and optional language model. |
| `net_spec`             | `string` | none        | Specifies the topology of the network. |
| `model_output`         | `string` | none        | Base path of output model files/checkpoints. |
| `max_image_MB`         | `int`    | `6000`      | Maximum amount of memory to use for caching images. |
| `learning_rate`        | `double` | `10e-4`     | Initial learning rate for SGD algorithm. |
| `sequential_training`  | `bool`   | `false`     | Set to true for sequential training. Default is to process all training data in round-robin fashion. |
| `net_mode`             | `int`    | `192`       | Flags from `NetworkFlags`in `network.h`. Possible values: `128` for Adam optimization instead of momentum; `64` to allow different layers to have their own learning  rates, discovered automatically. |
| `perfect_sample_delay` | `int`    | `0`         | When the network gets good, only backprop a perfect sample after this many imperfect samples have been seen since the last perfect sample was allowed through. |
| `debug_interval`       | `int`    | `0`         | If non-zero, show visual debugging every this many iterations. |
| `weight_range`         | `double` | `0.1`       | Range of random values to initialize weights. |
| `momentum`             | `double` | `0.5`       | Momentum for alpha smoothing gradients. |
| `adam_beta`            | `double` | `0.999`     | Smoothing factor squared gradients in ADAM algorithm. |
| `max_iterations`       | `int`    | `0`         | Stop training after this many iterations. |
| `target_error_rate`    | `double` | `0.01`      | Stop training if the mean percent error rate gets below this value. |
| `continue_from`        | `string` | none        | Path to previous checkpoint from which to continue training or fine tune. |
| `stop_training`        | `bool`   | `false`     | Convert the training checkpoint in `--continue_from` to a recognition model. |
| `convert_to_int`       | `bool`   | `false`     | With `stop_training`, convert to 8-bit integer for greater speed, with slightly less accuracy. |
| `append_index`         | `int`    | `-1`        | Cut the head off the network at the given index and append `--net_spec` network in place of the cut off part. |
| `train_listfile`       | `string` | none        | Filename of a file listing training data files. |
| `eval_listfile`        | `string` | none        | Filename of a file listing evaluation data files to be used in evaluating the model independently of the training data. |

Most of the flags work with defaults, and several are only required for
particular operations listed below, but first some detailed comments on the more
complex flags:

### Unicharset Compression-recoding

LSTMs are great at learning sequences, but slow down *a lot* when the number of
states is too large. There are empirical results that suggest it is better to
ask an LSTM to learn a long sequence than a short sequence of many classes, so
for the complex scripts, (Han, Hangul, and the Indic scripts) it is better to
recode each symbol as a short sequence of codes from a small number of classes
than have a large set of classes. 

The `combine_lang_model` command has this
feature on by default. It encodes each Han character as a variable-length
sequence of 1-5 codes, Hangul using the Jamo encoding as a sequence of 3 codes,
and other scripts as a sequence of their unicode components. For the scripts
that use a _virama_ character to generate conjunct consonants, (All the Indic
scripts plus Myanmar and Khmer) the function `NormalizeCleanAndSegmentUTF8`
pairs the virama with an appropriate neighbor to generate a more glyph-oriented
encoding in the unicharset. To make full use of this improvement, the
`--pass_through_recoder` flag should be set for `combine_lang_model` for these
scripts.

### Randomized Training Data and sequential_training

For Stochastic Gradient Descent to work properly, the training data is supposed
to be randomly shuffled across all the sample files, so the trainer can read its
way through each file in turn and go back to the first one when it reaches the
end.

If using the rendering code, (via `tesstrain.py`) then it will shuffle the
sample text lines within each file, but you will get a set of files, each
containing training samples from a single font. To add a more even mix, the
default is to process one sample from each file in turn aka 'round robin' style.
If you have generated training data some other way, or it is all from the same
style (a handwritten manuscript book for instance) then you can use the
`--sequential_training` flag for `lstmtraining.` This is more memory efficient
since it will load data from only two files at a time, and process them in
sequence. (The second file is read-ahead so it is ready when needed.)

### Model output

The trainer saves checkpoints periodically using `--model_output` as a basename.
It is therefore possible to stop training at any point, and restart it, using
the same command line, and it will continue. To force a restart, use a different
`--model_output` or delete all the files.

### Net Mode and Optimization

The `128` flag turns on Adam optimization, which seems to work a lot better than
plain momentum.

The `64` flag enables automatic layer-specific learning rate. When progress
stalls, the trainer investigates which layer(s) should have their learning rate
reduced independently, and may lower one or more learning rates to continue
learning.

The default value of `net_mode` of `192` enables both Adam and layer-specific
learning rates.

### Perfect Sample Delay

Training on "easy" samples isn't necessarily a good idea, as it is a waste of
time, but the network shouldn't be allowed to forget how to handle them, so it
is possible to discard some easy samples if they are coming up too often. The
`--perfect_sample_delay` argument discards perfect samples if there haven't been
that many imperfect ones seen since the last perfect sample. 

The current default
value of zero uses all samples. In practice the value doesn't seem to have a
huge effect, and if training is allowed to run long enough, zero produces the
best results.

### Debug Interval and Visual Debugging

With zero (default) `--debug_interval`, the trainer outputs a progress report
every 100 iterations, similar to the following example.

```
At iteration 717/10500/10500, Mean rms=0.113000%, delta=0.009000%, BCER train=0.029000%, BWER train=0.083000%, skip ratio=0.000000%,  New worst BCER = 0.029000 wrote checkpoint.

At iteration 718/10600/10600, Mean rms=0.112000%, delta=0.007000%, BCER train=0.023000%, BWER train=0.085000%, skip ratio=0.000000%,  New worst BCER = 0.023000 wrote checkpoint.

2 Percent improvement time=509, best error was 2.033 @ 209
At iteration 718/10700/10700, Mean rms=0.111000%, delta=0.006000%, BCER train=0.019000%, BWER train=0.069000%, skip ratio=0.000000%,  New best BCER = 0.019000 wrote best model:data/engRupee/checkpoints/engRupee_0.019000_718_10700.checkpoint wrote checkpoint.

2 Percent improvement time=509, best error was 2.033 @ 209
At iteration 718/10800/10800, Mean rms=0.108000%, delta=0.002000%, BCER train=0.007000%, BWER train=0.052000%, skip ratio=0.000000%,  New best BCER = 0.007000 wrote best model:data/engRupee/checkpoints/engRupee_0.007000_718_10800.checkpoint wrote checkpoint.

Finished! Selected model with minimal training error rate (BCER) = 0.007

```

With `--debug_interval -1`, the trainer outputs verbose debug text for every
training iteration. The text debug information includes the truth text, the recognized text, the
iteration number, the training sample id (lstmf file and line) and the mean value of
several error metrics. `GROUND TRUTH` for the line is displayed in all cases.
`ALIGNED TRUTH` and `BEST OCR TEXT` are displayed only when different from
the `GROUND TRUTH`.

```
Iteration 455038: GROUND  TRUTH : उप॑ त्वाग्ने दि॒वेदि॑वे॒ दोषा॑वस्तर्धि॒या व॒यम् ।
File /tmp/san-2019-03-28.jsY/san.Mangal.exp0.lstmf line 451 (Perfect):
Mean rms=1.267%, delta=4.155%, train=11.308%(32.421%), skip ratio=0%
Iteration 455039: GROUND  TRUTH : मे अपराध और बैठे दुकानों नाम सकते अधिवक्ता, दोबारा साधन विषैले लगाने पर प्रयोगकर्ताओं भागे
File /tmp/san-2019-04-04.H4m/san.FreeSerif.exp0.lstmf line 28 (Perfect):
Mean rms=1.267%, delta=4.153%, train=11.3%(32.396%), skip ratio=0%
```

```
Iteration 1526: GROUND  TRUTH : 𒃻 𒀸 𒆳𒆳 𒅘𒊏𒀀𒋾
Iteration 1526: ALIGNED TRUTH : 𒃻 𒀸 𒆳𒆳 𒅘𒊏𒊏𒀀𒋾
Iteration 1526: BEST OCR TEXT :    𒀀𒋾
File /tmp/eng-2019-04-06.Ieb/eng.CuneiformComposite.exp0.lstmf line 19587 :
Mean rms=0.941%, delta=12.319%, train=56.134%(99.965%), skip ratio=0.6%
Iteration 1527: GROUND  TRUTH : 𒀭𒌋𒐊
Iteration 1527: BEST OCR TEXT : 𒀭𒌋
File /tmp/eng-2019-04-06.Ieb/eng.CuneiformOB.exp0.lstmf line 7771 :
Mean rms=0.941%, delta=12.329%, train=56.116%(99.965%), skip ratio=0.6%
```

With `--debug_interval > 0`, the trainer displays several windows of debug
information on the layers of the network. 

In the special case of
`--debug_interval 1` it waits for a click in the `LSTMForward` window before
continuing to the next iteration, but for all others it just continues and draws
information at the frequency requested.

**NOTE that to use --debug_interval > 0 you must build
[ScrollView.jar](https://github.com/tesseract-ocr/tessdoc/blob/main/ViewerDebugging) as well as the other training tools.** See
[Building the Training Tools](#building-the-training-tools)

The visual debug information includes:

A forward and backward window for each network layer. Most are just random
noise, but the `Output/Output-back` and `ConvNL` windows are worth viewing.
`Output` shows the output of the final Softmax, which starts out as a yellow
line for the null character, and gradually develops yellow marks at each point
where it thinks there is a character. (The x-axis is the image x-coordinate, and
the y-axis is character class.) The `Output-back` window shows the difference
between the actual output and the target using the same layout, but with yellow
for "give me more of this" and blue for "give me less of this". As the network
learns, the `ConvNL` window develops the typical edge detector results that you
expect from the bottom layer.

`LSTMForward` shows the output of the whole network on the training image.
`LSTMTraining` shows the training target on the training image. In both, green
lines are drawn to show the peak output for each character, and the character
itself is drawn to the right of the line.

The other two windows worth looking at are `CTC Outputs` and `CTC Targets`.
These show the current output of the network and the targets as a line graph of
strength of output against image x-coordinate. Instead of a heatmap, like the
`Output` window, a different colored line is drawn for each character class and
the y-axis is strength of output.

### Iterations and Checkpoints

During the training we see this kind of information :

```
2 Percent improvement time=100, best error was 100 @ 0
At iteration 100/100/100, Mean rms=6.042000%, delta=63.801000%, BCER train=98.577000%, BWER train=100.000000%, skip ratio=0.000000%,  New best BCER = 98.577000 wrote checkpoint.

2 Percent improvement time=200, best error was 100 @ 0
At iteration 200/200/200, Mean rms=5.709000%, delta=58.372000%, BCER train=98.399000%, BWER train=99.986000%, skip ratio=0.000000%,  New best BCER = 98.399000 wrote checkpoint.
...
At iteration 14615/695400/698614, Mean rms=0.131000%, delta=0.038000%, BCER train=0.207000%, BWER train=0.579000%, skip ratio=0.4%,  wrote checkpoint.
```

In the above example,
```
14615 : learning_iteration
695400 : training_iteration
698614 : sample_iteration
```

**sample_iteration :** "Index into training sample set. (sample_iteration >= training_iteration)." It is how many times a training file has been passed into the learning process.

**training_iteration :** "Number of actual backward training steps used." It is how many times a training file has been SUCCESSFULLY passed into the learning process. So every time you get an error : "Image too large to learn!!" - "Encoding of string failed!" - "Deserialize header failed", the sample_iteration increments but not the training_iteration. Actually you have 1 - (695400 / 698614) = 0.4% which is the **skip ratio :** proportion of files that have been skipped because of an error

**learning_iteration :** "Number of iterations that yielded a non-zero delta error and thus provided significant learning. (learning_iteration <= training_iteration). learning_iteration_ is used to measure rate of learning progress."
So it uses the delta value to assess it the iteration has been useful.

What is good to know is that when you specify a maximum number of iterations to the training process it uses the middle iteration number **(training_iteration)** to know when to stop. But when it writes a checkpoint, the checkpoint name also uses the best iteration number **(learning_iteration)**, along with the char train rate. So a checkpoint name is the concatenation of **model_name & char_train & learning_iteration  & training_iteration** eg. sanLayer_1.754_347705_659600.checkpoint.

The lstmtraining program outputs two kinds of checkpoint files:

*   `<model_base>_checkpoint` is the latest model file along with backup models to be used
    if the training runs into divergence.
*   `<model_base>_<char_error>_<learning_iteration>_<training_iteration>.checkpoint` is periodically written as
    the model with the best training error at that point in training. It is a training dump just like the
    `<model_base>_checkpoint`, but is smaller because it doesn't have a backup model to be used
    if the training runs into divergence.

Either kind of these checkpoint files can be converted to a standard (best/float) traineddata file or
slightly less accurate (fast/integer) traineddata file by using the `stop_training` and `convert_to_int`
flags with lstmtraining.

### Error Messages From Training

There are various error messages that can occur when running the training, some
of which can be important, and others not so much:

`Encoding of string failed!` results when the text string for a training image
cannot be encoded using the given unicharset. Possible causes are:

1.  There is an un-represented character in the text, say a British Pound sign
    that is not in your unicharset.
1.  A stray unprintable character (like tab or a control character) in the text.
1.  There is an un-represented Indic grapheme/aksara in the text.

In any case it will result in that training image being ignored by the trainer.
If the error is infrequent, it is harmless, but it may indicate that your
unicharset is inadequate for representing the language that you are training.

`Unichar xxx is too long to encode!!` (Most likely Indic only). There is an
upper limit to the length of unicode characters that can be used in the recoder,
which simplifies the unicharset for the LSTM engine. It will just continue and
leave that Aksara out of the recognizable set, but if there are a lot, then you
are in trouble.

`Bad box coordinates in boxfile string!` The LSTM trainer only needs bounding
box information for a complete textline, instead of at a character level, but if
you put spaces in the box string, like this:

```
<text for line including spaces> <left> <bottom> <right> <top> <page>
```

the parser will be confused and give you the error message.

`Deserialize header failed` occurs when a training input is not in LSTM format
or the file is not readable. Check your filelist file to see if it contains
valid filenames.

`No block overlapping textline:` occurs when layout analysis fails to correctly
segment the image that was given as training data. The textline is dropped. Not
much problem if there aren't many, but if there are a lot, there is probably
something wrong with the training text or rendering process.

`<Undecodable>` can occur in either the ALIGNED_TRUTH or OCR TEXT output early
in training. It is a consequence of unicharset compression and CTC training.
(See Unicharset Compression and train_mode above). This should be harmless and
can be safely ignored. Its frequency should fall as training progresses.

## Combining the Output Files

The lstmtraining program outputs two kinds of checkpoint files:

*   `<model_base>_checkpoint` is the latest model file.
*   `<model_base><char_error>_<iteration>.checkpoint` is periodically written as
    the model with the best training error. It is a training dump just like the
    checkpoint, but is smaller because it doesn't have a backup model to be used
    if the training runs into divergence.

Either of these files can be converted to a standard traineddata file.
This will extract the recognition model from the training dump, and insert it
into the --traineddata argument, along with the unicharset, recoder, and any
dawgs that were provided during training.

**NOTE** Tesseract will now run happily with a traineddata file that
contains *just* `lang.lstm`, `lang.lstm-unicharset` and `lang.lstm-recoder`. The
`lstm-*-dawgs` are optional, and *none of the other components are required or
used with OEM_LSTM_ONLY as the OCR engine mode.* No bigrams, unichar ambigs or
any of the other components are needed or even have any effect if present. The
only other component that does anything is the `lang.config`, which can affect
layout analysis, and sub-languages.

If added to an existing Tesseract traineddata file, the `lstm-unicharset`
doesn't have to match the Tesseract `unicharset`, but the same unicharset must
be used to train the LSTM and build the `lstm-*-dawgs` files.

## The Hallucination Effect

If you notice that your model is misbehaving, for example by:
* Adding a `Capital` letter instead of a `Small` letter at the beginning of certain words.
* Adding `Space` where it should not do that.
* etc...

[Then read the hallucination topic.](https://github.com/tesseract-ocr/tessdoc/blob/bc73ab3c1ed7846a48ef2630a053017de3ec07c3/tess4/The-Hallucination-Effect.md)
