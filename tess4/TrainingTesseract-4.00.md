# How to train Tesseract 4.00

**Training with `tesstrain.sh` is now unsupported/abandoned. 
Please use python scripts from https://github.com/tesseract-ocr/tesstrain for training. **

**Have questions about the training process?** If you had some problems during
the training process and you need help, use
[tesseract-ocr](https://groups.google.com/forum/#!forum/tesseract-ocr)
mailing-list to ask your question(s). **PLEASE DO NOT** report your problems and
ask questions about training as
[issues](https://github.com/tesseract-ocr/tesseract/issues)!

# Contents of guide and tutorial by Ray Smith

   * [Introduction](#introduction)
   * [Before You Start](#before-you-start)
   * [Additional Libraries Required](#additional-libraries-required)
   * [Building the Training Tools](#building-the-training-tools)
   * [Hardware-Software Requirements](#hardware-software-requirements)
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
   * [TessTutorial](#tesstutorial)
      * [One-time Setup for TessTutorial](#one-time-setup-for-tesstutorial)
      * [Creating Training Data](#creating-training-data)
         * [Making Box Files](#making-box-files)
         * [Using tesstrain.sh](#using-tesstrainsh)
      * [Tutorial guide to lstmtraining](#tutorial-guide-to-lstmtraining)
         * [Creating Starter Traineddata](#creating-starter-traineddata)
         * [Training From Scratch](#training-from-scratch)
         * [Fine Tuning for Impact](#fine-tuning-for-impact)
         * [Fine Tuning for ± a few characters](#fine-tuning-for--a-few-characters)
         * [Training Just a Few Layers](#training-just-a-few-layers)
      * [Error Messages From Training](#error-messages-from-training)
   * [Combining the Output Files](#combining-the-output-files)
   * [The Hallucination Effect](#the-hallucination-effect)

# Initial Remark

The following guide and tutorials is deprecated for Tesseract 5.
Training with `tesstrain.sh` is unsupported/abandoned.
Please use scripts from https://github.com/tesseract-ocr/tesstrain for training.

# Introduction

Tesseract 4.00 includes a new neural network-based recognition engine that
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

For 4.00 at least, the old recognition engine is still present, and can also be
trained, but is deprecated, and, unless good reasons materialize to keep it, may
be deleted in a future release.

# Before You Start

You don't need any background in neural networks to train Tesseract 4.00, but it
may help in understanding the difference between the training options. Please
read the [Implementation introduction](NeuralNetsInTesseract4.00.md) before delving
too deeply into the training process, and the same note as for training
Tesseract 3.04 applies:

**Important note**: Before you invest time and effort on training Tesseract, it
is highly recommended to read the [ImproveQuality](https://github.com/tesseract-ocr/tessdoc/blob/main/ImproveQuality.md) page.

# Additional Libraries Required

Beginning with 3.03, additional libraries are required to build the training
tools.

```bash
sudo apt-get install libicu-dev libpango1.0-dev libcairo2-dev
```

# Building the Training Tools

Beginning with 3.03, if you're compiling Tesseract from source you need to make
and install the training tools with separate make commands. Once the above
additional libraries have been installed, run the following from the Tesseract
source directory:

```bash
./configure
```
or if you plan to run in docker (or do not require graphics):
```bash
./configure --disable-graphics
```

By default Tesseract configuration will proceed if dependencies required only
for training are missing, but for training, you will have to ensure all those
optional dependencies are installed and that Tesseract's build environment
can locate them. Look for these lines in the output of `./configure`:

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

If configure does not say the training tools can be built, you still need to add
libraries or ensure that `pkg-config` can find them.

After configuring, you can attempt to build the training tools:

```bash
make
make training
sudo make training-install
```

It is also useful, but not required, to build [ScrollView.jar](ViewerDebugging):

```bash
make ScrollView.jar
export SCROLLVIEW_PATH=$PWD/java
```

## On macOS Mojave with Homebrew

Homebrew has an unusual way of setting up `pkgconfig` so you must opt-in to certain files.
In general run `brew info package` and ensure that you append the mentioned PKG_CONFIG_PATH
to this environment variable.

```bash
brew install cairo pango icu4c autoconf libffi libarchive
export PKG_CONFIG_PATH=\
$(brew --prefix)/lib/pkgconfig:\
$(brew --prefix)/opt/libarchive/lib/pkgconfig:\
$(brew --prefix)/opt/icu4c/lib/pkgconfig:\
$(brew --prefix)/opt/libffi/lib/pkgconfig
./configure
```


# Hardware-Software Requirements

At time of writing, training only works on Linux. (macOS almost works; it requires
minor hacks to the shell scripts to account for the older version of `bash` it
provides and differences in `mktemp`.) Windows is unknown, but would need msys or Cygwin.

As for running Tesseract 4.0.0, it is useful, but not essential to have a multi-core (4 is good)
machine, with OpenMP and Intel Intrinsics support for SSE/AVX extensions.
Basically it will still run on anything with enough memory, but the higher-end
your processor is, the faster it will go. No GPU is needed. (No support.) Memory
use can be controlled via the --max_image_MB command-line option, but you are
likely to need at least 1GB of memory over and above what is taken by your OS.

# Training Text Requirements

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

# Overview of Training Process

The overall training process is similar to [training 3.04](TrainingTesseract).

Conceptually the same:

1.  [Prepare training
    text.](https://github.com/tesseract-ocr/tesseract/issues/654#issuecomment-274574951)
1.  Render text to image + box file. (Or create hand-made box files for existing
    image data.)
1.  Make unicharset file. (Can be partially specified, ie created manually).
1.  [Make a starter traineddata from the unicharset and optional dictionary
     data.](#creating-starter-traineddata)
1.  Run tesseract to process image + box file to make training data set.
1.  Run training on training data set.
1.  Combine data files.

The key differences are:

*   The boxes only need to be at the *textline level.* It is thus *far easier*
    to make training data from existing image data.
*   The .tr files are replaced by .lstmf data files.
*   Fonts *can and should be mixed freely* instead of being separate.
*   The clustering steps (mftraining, cntraining, shapeclustering) are replaced
    with a single slow lstmtraining step.

The training cannot be quite as automated as the training for 3.04 for several
reasons:

*   The slow training step isn't good to run from the middle of a script as it
    can be restarted if stopped, and it is hard to tell automatically when it is
    finished.
*   There are multiple options for how to train the network (see above).
*   The language models and unicharset are allowed to be different from those
    used by base Tesseract, but don't have to be.
*   It isn't necessary to have a base Tesseract of the same language as the
    neural net Tesseract.

# Understanding the Various Files Used During Training

As with base Tesseract, the completed LSTM model and everything else it needs is
collected in the `traineddata` file. Unlike base Tesseract, a `starter
traineddata` file is given during training, and has to be setup in advance. It
can contain:

*   Config file providing control parameters.
*   **Unicharset** defining the character set.
*   **Unicharcompress,** aka the recoder, which maps the unicharset further to
    the codes actually used by the neural network recognizer.
*   Punctuation pattern dawg, with patterns of punctuation allowed around words.
*   Word dawg. The system word-list language model.
*   Number dawg, with patterns of numbers that are allowed.

Bold elements **must** be provided. Others are optional, but if any of the dawgs
are provided, the punctuation dawg must also be provided. A new tool:
`combine_lang_model` is provided to make a `starter traineddata` from a
`unicharset` and optional wordlists.

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

# LSTMTraining Command Line

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

## Unicharset Compression-recoding

LSTMs are great at learning sequences, but slow down *a lot* when the number of
states is too large. There are empirical results that suggest it is better to
ask an LSTM to learn a long sequence than a short sequence of many classes, so
for the complex scripts, (Han, Hangul, and the Indic scripts) it is better to
recode each symbol as a short sequence of codes from a small number of classes
than have a large set of classes. The `combine_lang_model` command has this
feature on by default. It encodes each Han character as a variable-length
sequence of 1-5 codes, Hangul using the Jamo encoding as a sequence of 3 codes,
and other scripts as a sequence of their unicode components. For the scripts
that use a _virama_ character to generate conjunct consonants, (All the Indic
scripts plus Myanmar and Khmer) the function `NormalizeCleanAndSegmentUTF8`
pairs the virama with an appropriate neighbor to generate a more glyph-oriented
encoding in the unicharset. To make full use of this improvement, the
`--pass_through_recoder` flag should be set for `combine_lang_model` for these
scripts.

## Randomized Training Data and sequential_training

For Stochastic Gradient Descent to work properly, the training data is supposed
to be randomly shuffled across all the sample files, so the trainer can read its
way through each file in turn and go back to the first one when it reaches the
end.

If using the rendering code, (via `tesstrain.sh`) then it will shuffle the
sample text lines within each file, but you will get a set of files, each
containing training samples from a single font. To add a more even mix, the
default is to process one sample from each file in turn aka 'round robin' style.
If you have generated training data some other way, or it is all from the same
style (a handwritten manuscript book for instance) then you can use the
`--sequential_training` flag for `lstmtraining.` This is more memory efficient
since it will load data from only two files at a time, and process them in
sequence. (The second file is read-ahead so it is ready when needed.)

## Model output

The trainer saves checkpoints periodically using `--model_output` as a basename.
It is therefore possible to stop training at any point, and restart it, using
the same command line, and it will continue. To force a restart, use a different
`--model_output` or delete all the files.

## Net Mode and Optimization

The `128` flag turns on Adam optimization, which seems to work a lot better than
plain momentum.

The `64` flag enables automatic layer-specific learning rate. When progress
stalls, the trainer investigates which layer(s) should have their learning rate
reduced independently, and may lower one or more learning rates to continue
learning.

The default value of `net_mode` of `192` enables both Adam and layer-specific
learning rates.

Here is a sample of messages seen in case of divergence, when learning rate is being reduced.

```

Iteration 8999: GROUND  TRUTH : . هريغ )9(فرعي ال ؛ ميملا رسكب » رخنم « و » رخنم « اولاق
Iteration 8999: BEST OCR TEXT : . هريغ )6(فرعي ال ؛ ميملا رسكب » رخنم « و » رخنم « اولاق
File /home/ubuntu/OCR_GS_Data/ara/AWN/book_IbnQutayba.Adab_7_final_200_000742.lstmf line 0 :
Mean rms=1.696%, delta=3.16%, train=113.332%(18.851%), skip ratio=0.1%
Warning: LSTMTrainer deserialized an LSTMRecognizer!
At iteration 7794/9000/9011, Mean rms=1.696%, delta=3.16%, char train=113.332%, word train=18.851%, skip ratio=0.1%,  New worst char error = 113.332At iteration 7507, stage 0, Eval Char error rate=5.4443537, Word error rate=16.233627
Divergence! Reverted to iteration 5870/6400/6408
Reduced learning rate to :0.00025000001
 wrote checkpoint.

Iteration 6400: GROUND  TRUTH : بيرق ناك اذإ »)1(ددعقو ددعق لجر « و ، هتصاخ : يأ » هللخدو نالف للخد«
File /home/ubuntu/OCR_GS_Data/ara/AWN/book_IbnQutayba.Adab_7_final_b_200_000438.lstmf line 0 (Perfect):
Mean rms=1.759%, delta=2.898%, train=62.442%(21.232%), skip ratio=0.2%
Iteration 6401: GROUND  TRUTH : . )1(هجيه ام ردق ىلع
Iteration 6401: ALIGNED TRUTH : . )1(هجيه ام ردق ىىلع
Iteration 6401: BEST OCR TEXT : . )1(هجيمه ام ردق مع

```

## Perfect Sample Delay

Training on "easy" samples isn't necessarily a good idea, as it is a waste of
time, but the network shouldn't be allowed to forget how to handle them, so it
is possible to discard some easy samples if they are coming up too often. The
`--perfect_sample_delay` argument discards perfect samples if there haven't been
that many imperfect ones seen since the last perfect sample. The current default
value of zero uses all samples. In practice the value doesn't seem to have a
huge effect, and if training is allowed to run long enough, zero produces the
best results.

## Debug Interval and Visual Debugging

With zero (default) `--debug_interval`, the trainer outputs a progress report
every 100 iterations, similar to the following example.

```
At iteration 61239/65000/65015, Mean rms=1.62%, delta=8.587%, char train=16.786%, word train=36.633%, skip ratio=0.1%,  wrote checkpoint.

At iteration 61332/65100/65115, Mean rms=1.601%, delta=8.347%, char train=16.497%, word train=36.24%, skip ratio=0.1%,  wrote checkpoint.

2 Percent improvement time=44606, best error was 17.77 @ 16817
Warning: LSTMTrainer deserialized an LSTMRecognizer!
At iteration 61423/65200/65215, Mean rms=1.559%, delta=7.841%, char train=15.7%, word train=35.68%, skip ratio=0.1%,  New best char error = 15.7At iteration 45481, stage 0, Eval Char error rate=6.9447893, Word error rate=27.039255 wrote best model:./SANLAYER/LAYER15.7_61423.checkpoint wrote checkpoint.

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
information on the layers of the network. In the special case of
`--debug_interval 1` it waits for a click in the `LSTMForward` window before
continuing to the next iteration, but for all others it just continues and draws
information at the frequency requested.

**NOTE that to use --debug_interval > 0 you must build
[ScrollView.jar](ViewerDebugging) as well as the other training tools.** See
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

## Iterations and Checkpoints

During the training we see this kind of information :

```
At iteration 100/100/100, Mean rms=4.514%, delta=19.089%, char train=96.314%, word train=100%, skip ratio=0%,  New best char error = 96.314 wrote checkpoint.
...
At iteration 14615/695400/698614, Mean rms=0.158%, delta=0.295%, char train=1.882%, word train=2.285%, skip ratio=0.4%,  wrote checkpoint.
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


# TessTutorial

The process of [Creating the training data](#creating-training-data) is
documented below, followed by a [Tutorial guide to
lstmtraining](#tutorial-guide-to-lstmtraining) which gives an introduction to
the main training process, with command-lines that have been tested for real. On
Linux at least, you should be able to just copy-paste the command lines into
your terminal.

To make the `tesstrain.sh` script work, it will be necessary to
either set `PATH` to include your local `training` and `api` directories, or use
`make install`.

## One-time Setup for TessTutorial

In order to successfully run the TessTutorial, you need to have a working
installation of tesseract and training tools and have the training scripts and
required traineddata files in certain directories.
These instructions only cover the case of rendering from fonts,
so the [needed fonts](Fonts) must be installed first.
Note that your fonts location may vary.

```
sudo apt update
sudo apt install ttf-mscorefonts-installer
sudo apt install fonts-dejavu
fc-cache -vf
```

Follow the instructions below
to do the first time setup for TessTutorial.

```
mkdir ~/tesstutorial
cd ~/tesstutorial

mkdir langdata
cd langdata
wget https://raw.githubusercontent.com/tesseract-ocr/langdata_lstm/main/radical-stroke.txt
wget https://raw.githubusercontent.com/tesseract-ocr/langdata_lstm/main/common.punc
wget https://raw.githubusercontent.com/tesseract-ocr/langdata_lstm/main/font_properties
wget https://raw.githubusercontent.com/tesseract-ocr/langdata_lstm/main/Latin.unicharset
wget https://raw.githubusercontent.com/tesseract-ocr/langdata_lstm/main/Latin.xheights
mkdir eng
cd eng
wget https://raw.githubusercontent.com/tesseract-ocr/langdata/main/eng/eng.training_text
wget https://raw.githubusercontent.com/tesseract-ocr/langdata/main/eng/eng.punc
wget https://raw.githubusercontent.com/tesseract-ocr/langdata/main/eng/eng.numbers
wget https://raw.githubusercontent.com/tesseract-ocr/langdata/main/eng/eng.wordlist

cd ~/tesstutorial
git clone --depth 1 https://github.com/tesseract-ocr/tesseract.git
cd tesseract/tessdata
wget https://github.com/tesseract-ocr/tessdata/raw/main/eng.traineddata
wget https://github.com/tesseract-ocr/tessdata/raw/main/osd.traineddata
mkdir best
cd best
wget https://github.com/tesseract-ocr/tessdata_best/raw/main/eng.traineddata
wget https://github.com/tesseract-ocr/tessdata_best/raw/main/heb.traineddata
wget https://github.com/tesseract-ocr/tessdata_best/raw/main/chi_sim.traineddata

```

## Creating Training Data

As with base Tesseract, there is a choice between rendering synthetic training
data from fonts, or labeling some pre-existing images (like ancient manuscripts
for example).

In either case, the required format is still the tiff/box file
pair, except that the boxes only need to cover a textline instead of individual
characters.

If you use tesstrain.sh then required `synthetic` training data (box/tiff pairs and
lstmf files) is created from the training text and given list of fonts.

### Making Box Files

Multiple formats of box files are accepted by Tesseract 4 for LSTM training,
though they are different from the one used by Tesseract 3
([details](https://github.com/tesseract-ocr/tesseract/issues/2357)).

Each line in the box file matches a 'character' (glyph) in the tiff image.

`<symbol> <left> <bottom> <right> <top> <page>`
Where `<left> <bottom> <right> <top> <page>` could be bounding-box coordinates
of a single glyph or of a whole textline ([see examples](https://github.com/tesseract-ocr/tesseract/issues/2357#issuecomment-477239316)).

To mark an end-of-textline, a special line must be inserted after a series of lines.

`<tab> <left> <bottom> <right> <top> <page>`

Box files can be generated using Tesseract 4.0 using the `lstmbox` config from image data using `tesseract <image name including extension> <box file name> lstmbox`. For example, `tesseract image.png image lstmbox` will generate a box file with name `image.box` for the image in the current directory.

Note that in all cases, even for right-to-left languages, such as Arabic, the
text transcription for the line, *should be ordered left-to-right.* In other words, the network
is going to learn from left-to-right regardless of the language, and the
right-to-left/bidi handling happens at a higher level inside Tesseract.



### Using tesstrain.sh

The setup for running tesstrain.sh is the
same as for base Tesseract. Use `--linedata_only` option for LSTM training.
Note that it is beneficial to have more training
text and make more pages though, as neural nets don't generalize as well and
need to train on something similar to what they will be running on. If the
target domain is severely limited, then all the dire warnings about needing a
lot of training data may not apply, but the network specification may need to be
changed.

Training data is created using [tesstrain.sh](https://github.com/tesseract-ocr/tesseract/blob/main/src/training/tesstrain.sh)
as follows:

```
src/training/tesstrain.sh --fonts_dir /usr/share/fonts --lang eng --linedata_only \
  --noextract_font_properties --langdata_dir ../langdata \
  --tessdata_dir ./tessdata --output_dir ~/tesstutorial/engtrain
```
And the following is printed out after a successful run:
```
Created starter traineddata for LSTM training of language 'eng'
Run 'lstmtraining' command to continue LSTM training for language 'eng'
```

The above command makes LSTM training data equivalent to the data used to train
base Tesseract for English. For making a general-purpose LSTM-based OCR engine,
it is woefully inadequate, but makes a good tutorial demo.

Now try this to make eval data for the 'Impact' font:

```
src/training/tesstrain.sh --fonts_dir /usr/share/fonts --lang eng --linedata_only \
  --noextract_font_properties --langdata_dir ../langdata \
  --tessdata_dir ./tessdata \
  --fontlist "Impact Condensed" --output_dir ~/tesstutorial/engeval
```
We will use that data later to demonstrate tuning.

## Tutorial guide to lstmtraining

### Creating Starter Traineddata

`lstmtraining` takes a
`traineddata` file on its command-line, to obtain all the information it needs
on the language to be learned. The `traineddata` *must* contain at least an
`lstm-unicharset` and `lstm-recoder` component, and may also contain the three
dawg files: `lstm-punc-dawg lstm-word-dawg lstm-number-dawg` A `config` file is
also optional. The other components, if present, will be ignored and unused.

There is no tool to create the `lstm-recoder` directly. Instead there is a
tool, `combine_lang_model`, which takes as input an `input_unicharset` and
`script_dir` (`script_dir` points to the `langdata` directory) and `lang` (`lang` is the
language being used) and optional word list files. It creates the `lstm-recoder`
from the `input_unicharset` and creates all the dawgs, if wordlists are provided,
putting everything together into a `traineddata` file.

If you use tesstrain.sh then the starter traineddata is also created along with
`synthetic` training data (box/tiff pairs and lstmf files)
from the training text and given list of fonts.


### Training From Scratch

The following example shows the command line for training from scratch. Try it
with the default training data created with the command-lines above.

```
mkdir -p ~/tesstutorial/engoutput
training/lstmtraining --debug_interval 100 \
  --traineddata ~/tesstutorial/engtrain/eng/eng.traineddata \
  --net_spec '[1,36,0,1 Ct3,3,16 Mp3,3 Lfys48 Lfx96 Lrx96 Lfx256 O1c111]' \
  --model_output ~/tesstutorial/engoutput/base --learning_rate 20e-4 \
  --train_listfile ~/tesstutorial/engtrain/eng.training_files.txt \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt \
  --max_iterations 5000 &>~/tesstutorial/engoutput/basetrain.log
```
(Note that "O1c111" in the net spec means 111 output classes; this should match the number of entries in the unicharset file.)

In a separate window monitor the log file:

```
tail -f ~/tesstutorial/engoutput/basetrain.log
```

You should observe that by 600 iterations, the spaces (white) are starting to
show on the `CTC Outputs` window and by 1300 iterations green lines appear on
the `LSTMForward` window where there are spaces in the image.

By 1300 iterations, there are noticeable non-space bumps in the `CTC Outputs.`
Note that the `CTC Targets,` which started at all the same height are now varied
in height because of the definite output for spaces and some and the tentative
outputs for other characters. At the same time, the characters and positioning
of the green lines in the `LSTMTraining` window are not as accurate as they were
initially, because the partial output from the network confuses the CTC
algorithm. (CTC assumes statistical independence between the different
x-coordinates, but they are clearly not independent.)

By 2000 iterations, it should be clear on the `Output` window that some faint
yellow marks are appearing to indicate that there is some growing output for
non-null and non-space, and characters are starting to appear in the
`LSTMForward` window.

The character error rate falls below 50% just after 3700 iterations, and by 5000
to about 13%, where it will terminate. (In about 20 minutes on a current
high-end machine with AVX.)

Note that this engine is trained on the same amount of training data as used by
the legacy Tesseract engine, but its accuracy on other fonts is probably very
poor. Run an independent test on the 'Impact' font:

```
training/lstmeval --model ~/tesstutorial/engoutput/base_checkpoint \
  --traineddata ~/tesstutorial/engtrain/eng/eng.traineddata \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt
```

85% character error rate? Not so good!

Now base Tesseract doesn't do very well on 'Impact', but it is included in the
4500 or so fonts used to train the new LSTM version, so if you can run on that
for a comparison:

```
training/lstmeval --model tessdata/best/eng.traineddata \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt
```

2.45% character error rate? Much better!

For reference in the next section, also run a test of the full model on the
training set that we have been using:

```
training/lstmeval --model tessdata/best/eng.traineddata \
  --eval_listfile ~/tesstutorial/engtrain/eng.training_files.txt
```

Char error rate=0.25047642, Word error rate=0.63389585

You can train for another 5000 iterations, and get the error rate on the
training set a lot lower, but it doesn't help the `Impact` font much:

```
mkdir -p ~/tesstutorial/engoutput
training/lstmtraining \
  --traineddata ~/tesstutorial/engtrain/eng/eng.traineddata \
  --net_spec '[1,36,0,1 Ct3,3,16 Mp3,3 Lfys48 Lfx96 Lrx96 Lfx256 O1c111]' \
  --model_output ~/tesstutorial/engoutput/base --learning_rate 20e-4 \
  --train_listfile ~/tesstutorial/engtrain/eng.training_files.txt \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt \
  --max_iterations 10000 &>>~/tesstutorial/engoutput/basetrain.log
```

Character error rate on `Impact` now >100%, even as the error rate on the
training set has fallen to 2.68% character / 10.01% word:

```
training/lstmeval --model ~/tesstutorial/engoutput/base_checkpoint \
  --traineddata ~/tesstutorial/engtrain/eng/eng.traineddata \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt
```

This shows that the model has completely over-fitted to the supplied training
set! It is an excellent illustration of what happens when the training set
doesn't cover the desired variation in the target data.

In summary, training from scratch needs either a very constrained problem, a lot
of training data, or you need to shrink the network by reducing some of the
sizes of the layers in the `--net_spec` above. Alternatively, you could try fine
tuning...

### Fine Tuning for Impact

Please note that Fine Tuning for Impact can be done ONLY by using `float` models as the base to
continue from i.e. use the traineddata files from [tessdata_best](https://github.com/tesseract-ocr/tessdata_best) repo
not from [tessdata](https://github.com/tesseract-ocr/tessdata) or [tessdata_fast](https://github.com/tesseract-ocr/tessdata_fast).

Fine tuning is the process of training an existing model on new data without
changing any part of the network, although you **can** now add
characters to the character set. (See [Fine Tuning for ± a few
        characters](#fine-tuning-for--a-few-characters)).

```
training/lstmtraining --model_output /path/to/output [--max_image_MB 6000] \
  --continue_from /path/to/existing/model \
  --traineddata /path/to/original/traineddata \
  [--perfect_sample_delay 0] [--debug_interval 0] \
  [--max_iterations 0] [--target_error_rate 0.01] \
  --train_listfile /path/to/list/of/filenames.txt
```

**Note** that the `--continue_from` arg can point to a training checkpoint
**or** a recognition model, *even though the file formats are different.*
Training checkpoints are the files that begin with `--model_output` and end
in `checkpoint`. A recognition model can be extracted from an existing
traineddata file, using `combine_tessdata.` Note that it is also necessary to
supply the original traineddata file as well, as that contains the unicharset
and recoder. Let's start by fine tuning the model we built earlier, and see if
we can make it work for 'Impact':

```
mkdir -p ~/tesstutorial/impact_from_small
training/lstmtraining --model_output ~/tesstutorial/impact_from_small/impact \
  --continue_from ~/tesstutorial/engoutput/base_checkpoint \
  --traineddata ~/tesstutorial/engtrain/eng/eng.traineddata \
  --train_listfile ~/tesstutorial/engeval/eng.training_files.txt \
  --max_iterations 1200
```

This has character/word error at 22.36%/50.0% after 100 iterations and gets down
to 0.3%/1.2% at 1200. Now a stand-alone test:

```
training/lstmeval --model ~/tesstutorial/impact_from_small/impact_checkpoint \
  --traineddata ~/tesstutorial/engtrain/eng/eng.traineddata \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt
```

That shows a better result of 0.0086%/0.057% because the trainer is averaging
over 1000 iterations, and it has been improving. This isn't a representative
result for the `Impact` font though, as we are testing on the training data!

That was a bit of a toy example. The idea of fine tuning is really to apply it
to one of the fully-trained existing models:

```
mkdir -p ~/tesstutorial/impact_from_full
training/combine_tessdata -e tessdata/best/eng.traineddata \
  ~/tesstutorial/impact_from_full/eng.lstm
training/lstmtraining --model_output ~/tesstutorial/impact_from_full/impact \
  --continue_from ~/tesstutorial/impact_from_full/eng.lstm \
  --traineddata tessdata/best/eng.traineddata \
  --train_listfile ~/tesstutorial/engeval/eng.training_files.txt \
  --max_iterations 400
```

After 100 iterations, it has 1.35%/4.56% char/word error and gets down to
0.533%/1.633% at 400. Again, the stand-alone test gives a better result:

```
training/lstmeval --model ~/tesstutorial/impact_from_full/impact_checkpoint \
  --traineddata tessdata/best/eng.traineddata \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt
```

Char error 0.017%, word 0.120% What is more interesting though, is the effect on
the other fonts, so run a test on the base training set that we have been using:

```
training/lstmeval --model ~/tesstutorial/impact_from_full/impact_checkpoint \
  --traineddata tessdata/best/eng.traineddata \
  --eval_listfile ~/tesstutorial/engtrain/eng.training_files.txt
```

Char error rate=0.25548592, Word error rate=0.82523491

It is only slightly worse, despite having reached close to zero error on the
training set, and achieved it in only 400 iterations. **Note that further
training beyond 400 iterations makes the error on the base set higher.**

In summary, the pre-trained model can be fine-tuned or adapted to a small data
set, **without doing a lot of harm to its general accuracy.** It is still very
important however, to avoid over-fitting.

### Fine Tuning for ± a few characters

Please note that Fine Tuning for ± a few characters can be done ONLY by using `float` models as the base to
continue from i.e. use the traineddata files from [tessdata_best](https://github.com/tesseract-ocr/tessdata_best) repo
not from [tessdata](https://github.com/tesseract-ocr/tessdata) or [tessdata_fast](https://github.com/tesseract-ocr/tessdata_fast).

**New feature** It is possible to add a few new characters to the character set
and train for them by fine tuning, without a large amount of training data.

The training requires a new unicharset/recoder, optional language models, and
the old traineddata file containing the old unicharset/recoder.

```
training/lstmtraining --model_output /path/to/output [--max_image_MB 6000] \
  --continue_from /path/to/existing/model \
  --traineddata /path/to/traineddata/with/new/unicharset \
  --old_traineddata /path/to/existing/traineddata \
  [--perfect_sample_delay 0] [--debug_interval 0] \
  [--max_iterations 0] [--target_error_rate 0.01] \
  --train_listfile /path/to/list/of/filenames.txt
```

Let's try adding the plus-minus sign (±) to the existing English model. Modify
`langdata/eng/eng.training_text` to include some samples of ±. I inserted 14 of
them, as shown below:

```
grep ± ../langdata/eng/eng.training_text
alkoxy of LEAVES ±1.84% by Buying curved RESISTANCE MARKED Your (Vol. SPANIEL
TRAVELED ±85¢ , reliable Events THOUSANDS TRADITIONS. ANTI-US Bedroom Leadership
Inc. with DESIGNS self; ball changed. MANHATTAN Harvey's ±1.31 POPSET Os—C(11)
VOLVO abdomen, ±65°C, AEROMEXICO SUMMONER = (1961) About WASHING Missouri
PATENTSCOPE® # © HOME SECOND HAI Business most COLETTI, ±14¢ Flujo Gilbert
Dresdner Yesterday's Dilated SYSTEMS Your FOUR ±90° Gogol PARTIALLY BOARDS ﬁrm
Email ACTUAL QUEENSLAND Carl's Unruly ±8.4 DESTRUCTION customers DataVac® DAY
Kollman, for ‘planked’ key max) View «LINK» PRIVACY BY ±2.96% Ask! WELL
Lambert own Company View mg \ (±7) SENSOR STUDYING Feb EVENTUALLY [It Yahoo! Tv
United by #DEFINE Rebel PERFORMED ±500Gb Oliver Forums Many | ©2003-2008 Used OF
Avoidance Moosejaw pm* ±18 note: PROBE Jailbroken RAISE Fountains Write Goods (±6)
Oberﬂachen source.” CULTURED CUTTING Home 06-13-2008, § ±44.01189673355 €
netting Bookmark of WE MORE) STRENGTH IDENTICAL ±2? activity PROPERTY MAINTAINED
```

Now generate new training and eval data:

```
src/training/tesstrain.sh --fonts_dir /usr/share/fonts --lang eng --linedata_only \
  --noextract_font_properties --langdata_dir ../langdata \
  --tessdata_dir ./tessdata --output_dir ~/tesstutorial/trainplusminus
src/training/tesstrain.sh --fonts_dir /usr/share/fonts --lang eng --linedata_only \
  --noextract_font_properties --langdata_dir ../langdata \
  --tessdata_dir ./tessdata \
  --fontlist "Impact Condensed" --output_dir ~/tesstutorial/evalplusminus
```

Run fine tuning on the new training data. This requires more iterations, as it
only has a few samples of the new target character to go on:

```
training/combine_tessdata -e tessdata/best/eng.traineddata \
  ~/tesstutorial/trainplusminus/eng.lstm
training/lstmtraining --model_output ~/tesstutorial/trainplusminus/plusminus \
  --continue_from ~/tesstutorial/trainplusminus/eng.lstm \
  --traineddata ~/tesstutorial/trainplusminus/eng/eng.traineddata \
  --old_traineddata tessdata/best/eng.traineddata \
  --train_listfile ~/tesstutorial/trainplusminus/eng.training_files.txt \
  --max_iterations 3600
```

After 100 iterations, it has 1.26%/3.98% char/word error and gets down to
0.041%/0.185% at 3600. Again, the stand-alone test gives a better result:

```
training/lstmeval --model ~/tesstutorial/trainplusminus/plusminus_checkpoint \
  --traineddata ~/tesstutorial/trainplusminus/eng/eng.traineddata \
  --eval_listfile ~/tesstutorial/trainplusminus/eng.training_files.txt
```

Char error 0.0326%, word 0.128%. What is more interesting though, is whether the
new character can be recognized in the 'Impact' font, so run a test on the
impact eval set:

```
training/lstmeval --model ~/tesstutorial/trainplusminus/plusminus_checkpoint \
  --traineddata ~/tesstutorial/trainplusminus/eng/eng.traineddata \
  --eval_listfile ~/tesstutorial/evalplusminus/eng.training_files.txt
```

Char error rate=2.3767074, Word error rate=8.3829474

This compares very well against the original test of the original model on the
impact data set. Furthermore, if you check the errors:

```
training/lstmeval --model ~/tesstutorial/trainplusminus/plusminus_checkpoint \
  --traineddata ~/tesstutorial/trainplusminus/eng/eng.traineddata \
  --eval_listfile ~/tesstutorial/evalplusminus/eng.training_files.txt 2>&1 |
  grep ±
```

...you should see that it gets all the ± signs correct! (Every truth line that
contains a ± also contains a ± on the corresponding OCR line, and there are no
truth lines that don't have a matching OCR line in the grep output.)

This is excellent news! It means that one or more new characters can be added
without impacting existing accuracy, **and** the ability to recognize the new
character will, to some extent at least, generalize to other fonts!

NOTE: When fine tuning, it is important to experiment with the number of
iterations, since excessive training on a small data set will cause
over-fitting. ADAM, is great for finding the feature combinations necessary to
get that rare class correct, but it does seem to overfit more than simpler
optimizers.

### Training Just a Few Layers

Please note that Training Just a Few Layers can be done ONLY by using `float` models as the base to
continue from i.e. use the traineddata files from [tessdata_best](https://github.com/tesseract-ocr/tessdata_best) repo
not from [tessdata](https://github.com/tesseract-ocr/tessdata) or [tessdata_fast](https://github.com/tesseract-ocr/tessdata_fast).

Fine tuning is OK if you only want to add a new font style or need a couple of
new characters, but what if you want to train for Klingon? You are unlikely to
have much training data and it is unlike anything else, so what do you do? You
can try removing some of the top layers of an existing network model, replace
some of them with new randomized layers, and train with your data. The
command-line is mostly the same as [Training from
scratch](#training-from-scratch), but in addition you have to provide a model to
`--continue_from` and `--append_index`.

The `--append_index` argument tells it to remove all layers **above** the layer
with the given index, (starting from zero, in the outermost series) and then
append the given `--net_spec` argument to what remains. Although this indexing
system isn't a perfect way of referring to network layers, it is a consequence
of the greatly simplified network specification language. The builder will
output a string corresponding to the network it has generated, making it
reasonably easy to check that the index referred to the intended layer.

A new feature of 4.00 alpha is that combine_tessdata can list the content of a
traineddata file and its version string. In most cases, the version string
includes the net_spec that was used to train:

```
training/combine_tessdata -d tessdata/best/heb.traineddata
Version string:4.00.00alpha:heb:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1]
17:lstm:size=3022651, offset=192
18:lstm-punc-dawg:size=3022651, offset=3022843
19:lstm-word-dawg:size=673826, offset=3024221
20:lstm-number-dawg:size=625, offset=3698047
21:lstm-unicharset:size=1673826, offset=3703368
22:lstm-recoder:size=4023, offset=3703368
23:version:size=80, offset=3703993
```

and for chi_sim:

```
training/combine_tessdata -d tessdata/best/chi_sim.traineddata
Version string:4.00.00alpha:chi_sim:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
0:config:size=1966, offset=192
17:lstm:size=12152851, offset=2158
18:lstm-punc-dawg:size=282, offset=12155009
19:lstm-word-dawg:size=590634, offset=12155291
20:lstm-number-dawg:size=82, offset=12745925
21:lstm-unicharset:size=258834, offset=12746007
22:lstm-recoder:size=72494, offset=13004841
23:version:size=84, offset=13077335
```

Note that the number of layers is the same, but only the sizes differ. Therefore
in these models, the following values of `--append_index` will keep the
associated last layer, and append above:

**Index** | **Layer**
:-------: | :-----------
`0`       | Input
`1`       | `Ct3,3,16`
`2`       | `Mp3,3`
`3`       | `Lfys48/64`
`4`       | `Lfx96`
`5`       | `Lrx96`
`6`       | `Lfx192/512`

The weights in the remaining part of the existing model are unchanged initially,
but allowed to be modified by the new training data.

As an example, let's try converting the existing chi_sim model to eng. We will
cut off the last LSTM layer (which was bigger for chi_sim than the one used to
train the eng model) and the softmax, replacing with a smaller LSTM layer and a
new softmax:

```
mkdir -p ~/tesstutorial/eng_from_chi
training/combine_tessdata -e tessdata/best/chi_sim.traineddata \
  ~/tesstutorial/eng_from_chi/eng.lstm
training/lstmtraining --debug_interval 100 \
  --continue_from ~/tesstutorial/eng_from_chi/eng.lstm \
  --traineddata ~/tesstutorial/engtrain/eng/eng.traineddata \
  --append_index 5 --net_spec '[Lfx256 O1c111]' \
  --model_output ~/tesstutorial/eng_from_chi/base \
  --train_listfile ~/tesstutorial/engtrain/eng.training_files.txt \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt \
  --max_iterations 3000 &>~/tesstutorial/eng_from_chi/basetrain.log
```

Since the lower layers are already trained, this learns somewhat faster than
training from scratch. At 600 iterations, it suddenly starts producing output
and by 800, it is already getting most characters correct. By the time it stops
at 3000 iterations, it should be at 6.00% character/22.42% word.

Try the usual tests on the full training set:

```
training/lstmeval --model ~/tesstutorial/eng_from_chi/base_checkpoint \
  --traineddata ~/tesstutorial/engtrain/eng/eng.traineddata \
  --eval_listfile ~/tesstutorial/engtrain/eng.training_files.txt
```

and independent test on the `Impact` font:

```
training/lstmeval --model ~/tesstutorial/eng_from_chi/base_checkpoint \
  --traineddata ~/tesstutorial/engtrain/eng/eng.traineddata \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt
```

On the full training set, we get 5.557%/20.43% and on `Impact` 36.67%/83.23%,
which is much better than the from-scratch training, but is still badly
over-fitted.

In summary, it is possible to cut off the top layers of an existing network and
train, as if from scratch, but a fairly large amount of training data is still
required to avoid over-fitting.

## Error Messages From Training

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

# Combining the Output Files

The lstmtraining program outputs two kinds of checkpoint files:

*   `<model_base>_checkpoint` is the latest model file.
*   `<model_base><char_error>_<iteration>.checkpoint` is periodically written as
    the model with the best training error. It is a training dump just like the
    checkpoint, but is smaller because it doesn't have a backup model to be used
    if the training runs into divergence.

Either of these files can be converted to a standard traineddata file as
follows:

```
training/lstmtraining --stop_training \
  --continue_from ~/tesstutorial/eng_from_chi/base_checkpoint \
  --traineddata /path/to/traineddata/used/in/lstmtraining/eng.traineddata \
  --model_output ~/tesstutorial/eng_from_chi/eng.traineddata
```

This will extract the recognition model from the training dump, and insert it
into the --traineddata argument, along with the unicharset, recoder, and any
dawgs that were provided during training.

**NOTE** Tesseract 4.00 will now run happily with a traineddata file that
contains *just* `lang.lstm`, `lang.lstm-unicharset` and `lang.lstm-recoder`. The
`lstm-*-dawgs` are optional, and *none of the other components are required or
used with OEM_LSTM_ONLY as the OCR engine mode.* No bigrams, unichar ambigs or
any of the other components are needed or even have any effect if present. The
only other component that does anything is the `lang.config`, which can affect
layout analysis, and sub-languages.

If added to an existing Tesseract traineddata file, the `lstm-unicharset`
doesn't have to match the Tesseract `unicharset`, but the same unicharset must
be used to train the LSTM and build the `lstm-*-dawgs` files.

# The Hallucination Effect

If you notice that your model is misbehaving, for example by:
* Adding a `Capital` letter instead of a `Small` letter at the beginning of certain words.
* Adding `Space` where it should not do that.
* etc...

[Then read the hallucination topic.](The-Hallucination-Effect.md)
