# How to use the tools provided to train Tesseract 4.00

*   [Introduction](#introduction)
*   [Before You Start](#before-you-start)
*   [Additional Libraries Required](#additional-libraries-required)
*   [Building the Training Tools](#building-the-training-tools)
*   [Hardware/Software Requirements](#hardwaresoftware-requirements)
*   [Overview of Training Process](#overview-of-training-process)
*   [Creating the Training Data](#creating-training-data)
*   [Tutorial Guide to lstmtraining](#tutorial-guide-to-lstmtraining)
    *   [LSTMTraining Command Line](#lstmtraining-command-line)
        *   [Unicharset Compression](#unicharset-compression-and-train_mode)
        *   [Randomized Training Data](#randomized-training-data-and-train_mode)
        *   [Model Output](#model-output)
        *   [Net Mode and Optimization](#net-mode-and-optimization)
        *   [Perfect Sample Delay](#perfect-sample-delay)
        *   [Debug Interval](#debug-interval-and-visual-debugging)
    *   [Training From Scratch](#training-from-scratch)
    *   [Fine Tuning for Impact](#fine-tuning-for-impact)
    *   [Training Just a Few Layers](#training-just-a-few-layers)
    *   [Error Messages From Training](#error-messages-from-training)
*   [Combining the Output Files](#combining-the-output-files)

# Introduction

Tesseract 4.00 includes a new neural network-based recognition engine that
delivers significantly higher accuracy (on document images) than the previous
versions, in return for a significant increase in required compute power. On
complex languages however, it may actually be *faster* than base Tesseract.

Neural networks require significantly more training data and train *a lot*
slower than base Tesseract. For Latin-based languages, the existing model data
provided has been trained on about 400000 textlines spanning about 4500 fonts.
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
read the [Implementation introduction](NeuralNetsInTesseract4.00) before delving
too deeply into the training process, and the same note as for training
Tesseract 3.04 applies:

**Important note**: Before you invest time and effort on training Tesseract, it
is highly recommended to read the [ImproveQuality](ImproveQuality) page.

# Additional Libraries Required

Beginning with 3.03, additional libraries are required to build the training
tools.

```
sudo apt-get install libicu-dev
sudo apt-get install libpango1.0-dev
sudo apt-get install libcairo2-dev
```

# Building the Training Tools

Beginning with 3.03, if you're compiling Tesseract from source you need to make
and install the training tools with separate make commands. Once the above
additional libraries have been installed, run the following from the Tesseract
source directory:

```
make
make training
sudo make training-install
```

It is also useful, but not required, to build scrollview:

```
make ScrollView.jar
export SCROLLVIEW_PATH=$PWD/java
```

# Hardware/Software Requirements

At time of writing, training only works on Linux, and a little-endian machine
(eg Intel) is required to do any kind of incremental training. As for running
Tesseract 4.00, it is useful, but not essential to have a multi-core (4 is good)
machine, with OpenMP and Intel Intrinsics support for SSE/AVX extensions.
Basically it will still run on anything with enough memory, but the higher-end
your processor is, the faster it will go. No GPU is needed. (No support.)
Memory use can be controlled via the --max_image_MB command-line option, but
you are likely to need at least 1GB of memory over and above what is taken by
your OS.

# Overview of Training Process

The overall training process is similar to [training 3.04](TrainingTesseract)
Conceptually the same:

1.  Prepare training text.
1.  Render text to image + box file. (Or create hand-made box files for existing
    image data.)
1.  Make unicharset file.
1.  Optionally make dictionary data.
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
*   In theory it isn't necessary to have a base Tesseract of the same language
    as the neural net Tesseract, but currently it won't load without something
    there.

The process of [Creating the training data](#creating-training-data) is
documented below, followed by a [Tutorial guide to
lstmtraining](#tutorial-guide-to-lstmtraining) which gives an introduction to
the main training process, with command-lines that have been tested for real. On
Linux at least, you should be able to just copy-paste the command lines into
your terminal. To make the `tesstrain.sh` script work, it will be necessary to
either set `PATH` to include your local `training` and `api` directories, or use
`make install.`

# Creating Training Data

As with base Tesseract, there is a choice between rendering synthetic training data from fonts, or labelling some pre-existing images (like ancient manuscripts for example). In either case, the training process still require the tiff/box file pair. 

There are two possible ways to format a box file.

### Box File Format - First Option

In this format, each line in the box file matches a 'character' (glyph) in the tiff image.

<symbol> <left> <bottom> <right> <top> <page>

In this box file format, a special line must be inserted after a series of lines to indicate an end-of-line.

### Box File Format - Second Option

In this format the boxes only need to cover a textline instead of individual characters.

`WordStr <left> <bottom> <right> <top> <page> #<text for line including spaces>`

`'WordStr'` is a literal string that directs the box file parser to take the actual text
string from the end of the line after the `'#'` character.

Note that in all cases, even for right-to-left languages, such as Arabic, the
text transcription for the line, whether expressed as a sequences of boxes or
as a WordStr string, *should be ordered left-to-right.* In other words the
network is going to learn from left-to-right regardless of the language, and
the right-to-left/bidi handling happens at a higher level inside Tesseract.

These instructions only cover the case of rendering from fonts.

The setup for running [tesstrain.sh](Training-Tesseract-–-tesstrain.sh) is the
same as for base Tesseract. Note that it is beneficial to have more training text
and make more pages though, as neural nets don't generalize as well and need to
train on something similar to what they will be running on. If the target domain
is severely limited, then all the dire warnings about needing a lot of training
data may not apply, but the network specification may need to be changed.

Training data is created using [tesstrain.sh](Training-Tesseract-–-tesstrain.sh)
as follows: Note that your fonts location may vary.

```
training/tesstrain.sh --fonts_dir /usr/share/fonts --lang eng --linedata_only \
  --noextract_font_properties --langdata_dir ../langdata \
  --tessdata_dir ./tessdata --output_dir ~/tesstutorial/engtrain
```

The above command makes LSTM training data equivalent to the data used to train
base Tesseract for English. For making a general-purpose LSTM-based OCR engine,
it is woefully inadequate, but makes a good tutorial demo.

Now try this to make eval data for the 'Impact' font:

```
training/tesstrain.sh --fonts_dir /usr/share/fonts --lang eng --linedata_only \
  --noextract_font_properties --langdata_dir ../langdata \
  --tessdata_dir ./tessdata \
  --fontlist "Impact Condensed" --output_dir ~/tesstutorial/engeval
```

We will use that data later to demonstrate tuning.

# Tutorial Guide to lstmtraining

## LSTMTraining Command Line

The lstmtraining program is a multi-purpose tool for training neural networks.
The following table describes its command-line options:

| **Flag** | **Type** | **Default** | **Explanation** |
| :-------------------- | :------: | :---------: | :----------------- |
| `U` | `string` | none | Path to the unicharset for the character set. |
| `script_dir` | `string` | none | Path to the langdata directory used to get script unicharsets and the radical-stroke table. |
| `net_spec` | `string` | none | Specifies the topology of the network. |
| `model_output` | `string` | none | Base path of output model files/checkpoints. |
| `max_image_MB` | `int` | `6000` | Maximum amount of memory to use for caching images. |
| `learning_rate` | `double` | `1e-4` | Initial learning rate for SGD algorithm. |
| `train_mode` | `int` | `80` | Flags from `TrainingFlags` in `lstmrecognizer.h` Possible values= `64` for Compress unicharset, `16` for round-robin training. |
| `net_mode` | `int` | `192` | Flags from `NetworkFlags` in `network.h` Possible values= `128` for Adam optimization instead of momentum `64` to allow different layers to have their own learning rates, discovered automatically. |
| `perfect_sample_delay` | `int` | `4` | When the network gets good, only backprop a perfect sample after this many imperfect samples have been seen since the last perfect sample was allowed through.|
| `debug_interval` | `int` | `0` | If non-zero show visual debugging every this many iterations. |
| `weight_range` | `double` | `0.1` | Range of random values to initialize weights. |
| `momentum` | `double` | `0.9` | Momentum for alpha smoothing gradients. |
| `max_iterations` | `int` | `0` | Stop training after this many iterations. |
| `target_error_rate` | `double` | `0.01` | Stop training if the mean percent error rate gets below this value. |
| `continue_from` | `string` | none | Path to previous checkpoint from which to continue training or fine tune. |
| `stop_training` | `bool` | `false` | Convert the training checkpoint in `--continue_from` to a recognition model. |
| `append_index` | `int` | `-1` | Cut the head off the network at the given index and append `--net_spec` network in place of the cut off part. |
| `train_listfile` | `string` | none | Filename of a file listing training data files. |
| `eval_listfile` | `string` | none | Filename of a file listing evaluation data files to be used in evaluating the model independently of the training data. |

Most of the flags work with defaults, and several are only required for
particular operations listed below, but first some detailed comments on the more
complex flags:

### Unicharset Compression and train_mode

LSTMs are great at learning sequences, but slow down *a lot* when the number of
states is too large. There are empirical results that suggest it is better to
ask an LSTM to learn a long sequence than a short sequence of many classes, so
for the complex scripts, (Han, Hangul, and the Indic scripts) it is better to
recode each symbol as a short sequence of codes from a small number of classes
than have a large set of classes. The 64 flag for `--train_mode` turns this
feature on, and is included in the default. It encodes each Han character as a
sequence of 3 codes, Hangul using the Jamo encoding, and Indic script syllables
(Aksaras) as their unicode sequence. For the smaller, alphabetic scripts, like
Latin, all this does is fold the different shapes of single quotes to one class
and double quotes to one different class.

### Randomized Training Data and train_mode

For Stochastic Gradient Descent to work properly, the training data is supposed
to be randomly shuffled across all the sample files, so the trainer can read its
way through each file in turn and go back to the first one when it reaches the
end. This is entirely contrary to the way base Tesseract is trained!

If using the rendering code, (via `tesstrain.sh`) then it will shuffle the
sample text lines within each file, but you will get a set of files, each
containing training samples from a single font. To add a more even mix at least,
you should use the `16` flag value for `train_mode,` *even if you don't want the
unicharset compressed.*

### Model output

The trainer saves checkpoints periodically using `--model_output` as a basename.
It is therefore possible to stop training at any point, and restart it, using
the same command line, and it will continue. To force a restart, use a different
`--model_output` or delete all the files.

### Net Mode and Optimization

The `128` flag turns on Adam optimization, which seems to work a lot better than
plain momentum. The code calls it Adagrad, but it isn't, as momentum is still on
and Adagrad doesn't use momentum. Plain Adagrad without momentum doesn't work
very well at all.

The `64` flag enables automatic layer-specific learning rate. When progress
stalls, the trainer investigates which layer(s) should have their learning rate
reduced independently, and may lower one or more learning rates to continue
learning.

### Perfect Sample Delay

Training on "easy" samples isn't necessarily a good idea, as it is a waste of
time, but the network shouldn't be allowed to forget how to handle them, so it
is possible to discard some easy samples if they are coming up too often. The
`--perfect_sample_delay` argument discards perfect samples if there haven't been
that many imperfect ones seen since the last perfect sample.

### Debug Interval and Visual Debugging

With zero (default) `--debug_interval,` the trainer outputs a progress report
every 100 iterations.

With `--debug_interval -1,` the trainer outputs verbose text debug for every
training iteration.

With `--debug_interval > 0,` the trainer displays several windows of debug
information on the layers of the network. In the special case of
`--debug_interval 1` it waits for a click in the `LSTMForward` window before
continuing to the next iteration, but for all others it just continues and draws
information at the frequency requested.

**NOTE that to use --debug_interval > 0 you must build scrollview as well as
the other training tools.** See
[Building the Training Tools](#building-the-training-tools)

The text debug information includes the truth text, the recognized text, the
iteration number, the training sample id (file and page) and the mean value of
several error metrics.

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

The other two windows worth looking at are `CTC Outputs` and `CTC Targets.`
These show the current output of the network and the targets as a line graph of
strength of output against image x-coordinate. Instead of a heatmap, like the
`Output` window, a different colored line is drawn for each character class and
the y-axis is strength of output.

## Training From Scratch

The following example shows the command line for training from scratch. Try it
with the default training data created with the command-lines above.

```
mkdir -p ~/tesstutorial/engoutput
training/lstmtraining -U ~/tesstutorial/engtrain/eng.unicharset \
  --script_dir ../langdata --debug_interval 100 \
  --net_spec '[1,36,0,1 Ct5,5,16 Mp3,3 Lfys64 Lfx128 Lrx128 Lfx256 O1c105]' \
  --model_output ~/tesstutorial/engoutput/base \
  --train_listfile ~/tesstutorial/engtrain/eng.training_files.txt \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt \
  --max_iterations 5000 &>~/tesstutorial/engoutput/basetrain.log
```

In a separate window monitor the log file:

```
tail -f ~/tesstutorial/engoutput/basetrain.log
```

You should observe that by 500 iterations, the spaces (white) are starting to
show on the `CTC Outputs` window and by 800 iterations green lines appear on
the `LSTMForward` window where there are spaces in the image.

By 600 iterations, there are noticeable non-space bumps in the `CTC Outputs.`
Note that the `CTC Targets,` which started at all the same height are now varied
in height because of the definite output for spaces. At the same time, the
characters and positioning of the green lines in the `LSTMTraining` window are
not as accurate as they once were, because the partial output from the network
confuses the CTC algorithm. (CTC assumes statistical independence between the
different x-coordinates, but they are clearly not independent.)

By 2000 iterations, it should be clear on the `Output` window that some faint
yellow marks are appearing to indicate that there is some growing output for
non-null and non-space, and characters are starting to appear in the
`LSTMForward` window.

The character error rate falls below 50% at about 3200 iterations, and by 5000
to about 18%.

Note that this engine is trained on the same training data as used by base
Tesseract, but its accuracy on other fonts is probably very poor. It will stop
at 5000 iterations, (in about half an hour on a current high-end machine) by
which time its character error rate should be about 25%. Run an independent
test on the 'Impact' font:

```
training/lstmeval --model ~/tesstutorial/engoutput/base_checkpoint \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt
```

76% character error rate? Not so good!

Now base Tesseract doesn't do very well on 'Impact', but it is included in the
4500 or so fonts used to train the LSTM version, so if you extract out the
eng.lstm file from eng.traineddata, you can run on that for a comparison:

```
mkdir -p ~/tesstutorial/impact_from_full
training/combine_tessdata -e tessdata/eng.traineddata \
  ~/tesstutorial/impact_from_full/eng.lstm
training/lstmeval --model ~/tesstutorial/impact_from_full/eng.lstm \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt
```

1.7% character error rate? Much better!

For reference in the next section, also run a test of the full model on the
training set that we have been using:

```
training/lstmeval --model ~/tesstutorial/impact_from_full/eng.lstm \
  --eval_listfile ~/tesstutorial/engtrain/eng.training_files.txt
```

Char error rate=0.047221785, Word error rate=0.24679659.

You can train for another 5000 iterations, and get the error rate on the
training set a lot lower, but it doesn't help the `Impact` font much:

```
mkdir -p ~/tesstutorial/engoutput
training/lstmtraining -U ~/tesstutorial/engtrain/eng.unicharset \
  --script_dir ../langdata \
  --net_spec '[1,36,0,1 Ct5,5,16 Mp3,3 Lfys64 Lfx128 Lrx128 Lfx256 O1c105]' \
  --model_output ~/tesstutorial/engoutput/base \
  --train_listfile ~/tesstutorial/engtrain/eng.training_files.txt \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt \
  --max_iterations 10000 &>>~/tesstutorial/engoutput/basetrain.log
```

Character error rate on `Impact` still 75%, even as the error rate on the
training set has fallen to 0.86% character / 3.1% word:

```
training/lstmeval --model ~/tesstutorial/engoutput/base_checkpoint \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt
training/lstmeval --model ~/tesstutorial/engoutput/base_checkpoint \
  --eval_listfile ~/tesstutorial/engtrain/eng.training_files.txt
```

In summary, training from scratch needs either a very constrained problem, a lot
of training data, or you need to shrink the network by reducing some of the
sizes of the layers in the `--net_spec` above. Alternatively, you could try fine
tuning...

## Fine Tuning for Impact

Fine tuning is the process of training an existing model on new data without
changing anything else like the unicharset or any part of the network.
Doesn't need a unicharset, script_dir, or net_spec, as they all come from the
existing model.

```
training/lstmtraining --model_output /path/to/output [--max_image_MB 6000] \
  --continue_from /path/to/existing/model \
  [--perfect_sample_delay 4] [--debug_interval 0] \
  [--max_iterations 0] [--target_error_rate 0.01] \
  --train_listfile /path/to/list/of/filenames.txt
```

**Note** that the `--continue_from` arg can point to a training checkpoint
**or** a recognition model, *even though the file formats are different.*
Training checkpoints are the files that begin with `--model_output` and may end
in checkpoint or lstm. A recognition model can be extracted from an existing
traineddata file, as we did above. Let's start by fine tuning the model we built
earlier, and see if we can make it work for 'Impact':

```
mkdir -p ~/tesstutorial/impact_from_small
training/lstmtraining --model_output ~/tesstutorial/impact_from_small/impact \
  --continue_from ~/tesstutorial/engoutput/base_checkpoint \
  --train_listfile ~/tesstutorial/engeval/eng.training_files.txt \
  --max_iterations 1200
```

This has character/word error at 27.9%/56.2% after 100 iterations and gets down
to 1.4%/4.8% at 1200. Now a stand-alone test:

```
training/lstmeval --model ~/tesstutorial/impact_from_small/impact_checkpoint \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt
```

That shows a better result of 0.18%/0.92% because the trainer is averaging over
1000 iterations, and it has been improving. This isn't a representative result
for the `Impact` font though, as we are testing on the training data!

That was a bit of a toy example. The idea of fine tuning is really to apply it
to one of the fully-trained existing models:

```
mkdir -p ~/tesstutorial/impact_from_full
training/lstmtraining --model_output ~/tesstutorial/impact_from_full/impact \
  --continue_from ~/tesstutorial/impact_from_full/eng.lstm \
  --train_listfile ~/tesstutorial/engeval/eng.training_files.txt \
  --max_iterations 1200
```

After 100 iterations, it has 1.26%/3.98% char/word error and gets down to
0.31%/1.18% at 1200. Again, the stand-alone test gives a better result:

```
training/lstmeval --model ~/tesstutorial/impact_from_full/impact_checkpoint \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt
```

Char error 0.20%, word 0.70%. What is more interesting though, is the effect on
the other fonts, so run a test on the base training set that we have been using:

```
training/lstmeval --model ~/tesstutorial/impact_from_full/impact_checkpoint \
  --eval_listfile ~/tesstutorial/engtrain/eng.training_files.txt
```

Char error rate=0.04552459, Word error rate=0.22928254

It seems to have got better at that data set! This is probably because the
original model was trained on artificially degraded images to make it learn how
to deal with degraded text.

In summary, the pre-trained model can be fine-tuned or adapted to a small data
set, without doing a lot of harm to its general accuracy.

## Training Just a Few Layers

Fine tuning is OK if you don't want to change the unicharset, but what if you
want add a new character to a language, or you want to train for Klingon?
You are unlikely to have much training data and it is
unlike anything else, so what do you do? You can try removing some of the top
layers of an existing network model, replace some of them with new randomized
layers, and train with your data. The command-line is mostly the same as
[Training from scratch](#training-from-scratch), as you have to supply a
unicharset and net_spec, and you also have to provide a model to
`--continue_from` and `--append_index.`

The `--append_index` argument tells it to remove all layers **above** the layer
with the given index, (starting from zero, in the outermost series) and then
append the given `--net_spec` argument to what remains. Although this indexing
system isn't a perfect way of referring to network layers, it is a consequence
of the greatly simplified network specification language. The builder will
output a string corresponding to the network it has generated, making it
reasonably easy to check that the index referred to the intended layer.

For reference, as of 4.00 alpha, chi_sim, chi_tra, guj, hin, jpn, mal, mar, pan,
tel, tha were trained with this:

```
--learning_rate 10e-5
--net_spec '[1,0,0,1 Ct5,5,16 Mp3,3 Lfys64 Lfx128 Lrx128 Lfx384 O1c1]'
--net_mode 192
--perfect_sample_delay 19
```

and the rest were trained with this:

```
--learning_rate 10e-5
--net_spec '[1,0,0,1 Ct5,5,16 Mp3,3 Lfys64 Lfx128 Lrx128 Lfx256 O1c1]'
--net_mode 192
--perfect_sample_delay 19
```

The only difference between them is the size of the last LSTM layer. Therefore
in these models, the following values of `--append_index` will keep the
associated last layer, and append above:

**Index** | **Layer**
:-------: | :-----------
`0`       | Input
`1`       | `Ct5,5,16`
`2`       | `Mp3,3`
`3`       | `Lfys64`
`4`       | `Lfx128`
`5`       | `Lrx128`
`6`       | `Lfx256/384`

The weights in the remaining part of the existing model are unchanged initially,
but allowed to be modified by the new training data.

As an example, let's try converting the existing chi_sim model to eng. We will
cut off the last LSTM layer (which was bigger for chi_sim than the one used to
train the eng model) and the softmax, replacing with a smaller LSTM layer and a
new softmax:

```
mkdir -p ~/tesstutorial/eng_from_chi
training/combine_tessdata -e tessdata/chi_sim.traineddata \
  ~/tesstutorial/eng_from_chi/eng.lstm
training/lstmtraining -U ~/tesstutorial/engtrain/eng.unicharset \
  --script_dir ../langdata --debug_interval 100 \
  --continue_from ~/tesstutorial/eng_from_chi/eng.lstm \
  --append_index 5 --net_spec '[Lfx256 O1c105]' \
  --model_output ~/tesstutorial/eng_from_chi/base \
  --train_listfile ~/tesstutorial/engtrain/eng.training_files.txt \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt \
  --max_iterations 5000 &>~/tesstutorial/eng_from_chi/basetrain.log
```

Since the lower layers are already trained, this learns somewhat faster than
training from scratch. By 400 iterations, there are already some spaces being
output, by 500, some correct characters are being output, and by 1000 iterations,
it is already getting most characters correct. By the time it finishes, it
should be at 2.6% character/8.6% word.

Try the usual tests on the full training set and independent test on the
'Impact' font:

```
training/lstmeval --model ~/tesstutorial/eng_from_chi/base_checkpoint \
  --eval_listfile ~/tesstutorial/engtrain/eng.training_files.txt
training/lstmeval --model ~/tesstutorial/eng_from_chi/base_checkpoint \
  --eval_listfile ~/tesstutorial/engeval/eng.training_files.txt
```

On the full training set, we get 2.24%/7.36% and on `Impact` 23.9%/59.3%, which
is much better than the from-scratch training, but is still badly over-fitted.

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
box information for a complete textline, instead of at a character level, but
if you put spaces in the box string, like this:

```
<text for line including spaces> <left> <bottom> <right> <top> <page>
```

the parser will be confused and give you the error message. There
is a different format required for such boxfile strings:

```
WordStr <left> <bottom> <right> <top> <page> #<text for line including spaces>
```

`Deserialize header failed` occurs when a training input is not in LSTM format
or the file is not readable. Check your filelist file to see if it contains
valid filenames.

`No block overlapping textline:` occurs when layout analysis fails to correctly
segment the image that was given as training data. The textline is dropped.
Not much problem if there aren't many, but if there are a lot, there is
probably something wrong with the training text or rendering process.

`<Undecodable>` can occur in either the ALIGNED_TRUTH or OCR TEXT output early
in training. It is a consequence of unicharset compression and CTC training.
(See Unicharset Compression and train_mode above). This should be harmless and
can be safely ignored. Its frequency should fall as training progresses.

# Combining the Output Files

The lstmtraining program outputs two kinds of checkpoint files:

*   `<model_base>_checkpoint` is the latest model file.
*   `<model_base><char_error>_<iteration>.lstm` is periodically written as the
    model with the best training error. The lstm extension is misleading as this
    file is **not** in the same format as the recognition model file with the
    same extension name! It is a training dump just like the checkpoint, but is
    smaller because it doesn't have a backup model to be used if the training
    runs into divergence.

Either of these files can be converted to a recognition model as follows:

```
training/lstmtraining --model_output ~/tesstutorial/eng_from_chi/eng.lstm \
  --continue_from ~/tesstutorial/eng_from_chi/base_checkpoint \
  --stop_training
```

Finally, combine your new model with the language model files into a traineddata
file:

```
training/combine_tessdata -o tessdata/eng.traineddata \
  ~/tesstutorial/eng_from_chi/eng.lstm \
  ~/tesstutorial/engtrain/eng.lstm-number-dawg \
  ~/tesstutorial/engtrain/eng.lstm-punc-dawg \
  ~/tesstutorial/engtrain/eng.lstm-word-dawg
```

The dawg files are optional. It will work without them, but they do usually
provide some small improvement in accuracy.

**NOTE** Tesseract 4.00 will now run happily with a traineddata file that
contains *just* `lang.lstm.` The `lstm-*-dawgs` are optional, and *none of the
other files are required or used with OEM_LSTM_ONLY as the OCR engine mode.*
No bigrams, unichar ambigs or any of the other files are needed or even have
any effect if present.

If added to an existing Tesseract traineddata file, the LSTM unicharset doesn't
have to match the Tesseract unicharset, but the same unicharset must be
used to train the LSTM and build the `lstm-*-dawgs` files.
