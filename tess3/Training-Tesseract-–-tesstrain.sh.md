[tesstrain.sh](https://github.com/tesseract-ocr/tesseract/blob/3.05/training/tesstrain.sh) is a script that automatically calls the appropriate programs to create a new training for a language. It uses various programs for training, so you need to build them with 'make training' before using it.

This page details the version used for training of 3.0x branch. Not all files are required for LSTM training.

For 4.0 LSTM training usage, please see [TrainingTesseract-4.00](../TrainingTesseract-4.00.md).


# Example usage

```
$ ./tesstrain.sh --lang kan --langdata_dir /path/to/mylangdata --tessdata_dir /path/to/mytessdata
```

This is the most common usage of `tesstrain.sh`. See the comments at the top of `tesstrain.sh` for a description of all of the arguments it accepts.

The copy of tesstrain.sh that ships with Ubuntu is slightly modified to have a few of the default parameters automatically
filled out, because many of the directory locations are standardized. The documentation is in the standard location.

```
/usr/share/doc/tesseract/README.debian
```

The modification saves some typing.  This is an example of training for Japanese.

```
git clone https://github.com/tesseract-ocr/langdata.git
apt-get install fonts-noto-cjk fonts-japanese-mincho.ttf fonts-takao-gothic fonts-vlgothic
tesstrain.sh --lang jpn --langdata_dir langdata
```

# Langdata

tesstrain.sh needs certain files to use in the training process. These are normally stored in a 'langdata' directory. The langdata for the languages that are officially supported by Tesseract are all stored in the [langdata](https://github.com/tesseract-ocr/langdata) repository, but you can of course store langdata wherever you want.

## Required files

At a minimum the following files need to be provided in your langdata directory (note that [lang] is the language code, e.g. 'kan' or 'eng'):

 * [lang]/[lang].training_text (alternatively this can be specified on the command line with `--training_text /path/to/textfile`)

## Optional files

These files can optionally be in your langdata directory and will be used by tesstrain.sh to improve the quality of the training:

 * [lang]/[lang].wordlist (alternatively this can be specified on the command line with `--wordlist /path/to/wordlist`)
 * [lang]/[lang].word.bigrams
 * [lang]/[lang].numbers
 * [lang]/[lang].punc
 * [lang]/[lang].config
 * [lang]/[lang].unicharambigs
 * [lang]/[lang].training_text.bigram_freqs
 * [lang]/[lang].training_text.unigram_freqs

## General files

These are general files that can affect multiple languages, but may be edited if needed (note that [Script] is the script name, e.g. 'Greek' or 'Hebrew' or 'Devanagari'. One script can be used for multiple languages, eg. Devanagari script for Hindi, Sanskrit, Marathi, Nepali etc.):

 * [Script].xheights
 * [Script].unicharset
 * font_properties

Nick White's xheight tool can be used to find xheight of different fonts.To clone it and build the xheights tool, do the following:

```
$ git clone http://ancientgreekocr.org/grctraining.git
$ cd grctraining
$ make tools/xheight
```

To see how it's used for the Greek training, do:

```
$ make langdata/Greek.xheights
```


# Langdata files

## training_text

The training text is a text file that will used to train Tesseract for the language. It should contain several samples of each character, and be as close to a realistic sample of text as possible.

## wordlist

The wordlist is a text file with a list of words, one per line, ordered by decreasing frequency (so the most common word first).

## training_text.bigram_freqs

This is a text file with a list of bigrams (here meaning two characters) and the frequency with which they appear next to each other in the `training_text`, one bigram per line.

## training_text.unigram_freqs

This is a text file with a list of unigrams (characters) and the frequency with which they appear next to each other in the `training_text`, one unigram per line.

## word.bigrams

This is a text file with a list of bigrams (here meaning two words) separated by a space, one per line, sorted by how often they appear next to each other (most common at the top).

## numbers, punc, config, unicharambigs

These files are all combined directly into the final training. See the [TrainingTesseract](TrainingTesseract) page for details of their function and how to use them.

# Options in `language-specific.sh`

Optionally you can set some training options, as well as set default options for training your language (such as fonts to use), by editing the `training/language-specific.sh` script.

To set options for your language, look towards the end of `language-specific.sh` where variables are set according to the language code (the `set_lang_specific_parameters()` function).

## Fonts

You can either set the fonts to use as an argument to tesstrain.sh (as `--fontlist 'Font 1' 'Font 2'`) or by specifying the fonts in `language-specific.sh`.

## Other options

For other variables that can be set, you're best off just reading the `set_lang_specific_parameters()` function to see what they do, and `tesstrain_utils.sh` to see exactly how they are used.

# tesstrain_utils.sh

Note that the majority of the work that `tesstrain.sh` does is actually imported from the [training/tesstrain_utils.sh](https://github.com/tesseract-ocr/tesseract/blob/3.05/training/tesstrain_utils.sh) file, so if you're curious about exactly what it is doing, or want to change its behaviour, look there.
