------------------------------------
## For training Neural net based LSTM Tesseract 4.00 see [Training Tesseract 4.00](../TrainingTesseract-4.00.md)
-------------------------------------
## How to use the tools provided to train Tesseract 2.x for a new language?

**NOTE:** These instructions are for an older version of Tesseract. Training instructions for more recent versions are [here](TrainingTesseract.md).

  * [Introduction](#introduction)
  * [Background and Limitations](#background-and-limitations)
  * [Data files required](#data-files-required)
  * [Training Procedure](#training-procedure)
    * [Generate Training Images](#generate-training-images)
    * [Make Box Files](#make-box-files)
      * [Bootstrapping a new character set](#bootstrapping-a-new-character-set)
      * [Tif/Box pairs provided!](#tifbox-pairs-provided)
    * [Run Tesseract for Training](#run-tesseract-for-training)
    * [Clustering](#clustering)
    * [Compute the Character Set](#compute-the-character-set)
    * [Dictionary Data](#dictionary-data)
    * [The last file](#the-last-file)
  * [Putting it all together](#putting-it-all-together)

# Introduction

Tesseract 2.0 is fully trainable. This page describes the training process, provides some guidelines on applicability to various languages, and what to expect from the results.


# Background and Limitations

Tesseract was originally designed to recognize English text only. Efforts have been made to modify the engine and its training system to make them able to deal with other languages and UTF-8 characters. Tesseract 2.0 can handle any Unicode characters (coded with UTF-8), but there are limits as to the range of languages that it will be successful with, so please take this section into account before building up your hopes that it will work well on your particular language!

Tesseract can only handle left-to-right languages. While you can get something out with a right-to-left language, the output file will be ordered as if the text were left-to-right. Top-to-bottom languages will currently be hopeless.

Tesseract is unlikely to be able to handle connected scripts like Arabic. It will take some specialized algorithms to handle this case, and right now it doesn't have them.

Tesseract is likely to be so slow with large character set languages (like Chinese) that it is probably not going to be useful. There also still need to be some code changes to accommodate languages with more than 256 characters.

Any language that has different punctuation and numbers is going to be disadvantaged by some of the hard-coded algorithms that assume ASCII punctuation and digits.

# Data files required

To train for another language, you have to create 8 data files in the `tessdata` subdirectory. The naming convention is `languagecode.file_name` Language codes follow the ISO 639-3 standard. The 8 files used for English are:
  * `tessdata/eng.freq-dawg`
  * `tessdata/eng.word-dawg`
  * `tessdata/eng.user-words`
  * `tessdata/eng.inttemp`
  * `tessdata/eng.normproto`
  * `tessdata/eng.pffmtable`
  * `tessdata/eng.unicharset`
  * `tessdata/eng.DangAmbigs`

How little can you get away with?

You **must** create inttemp, normproto, pffmtable, freq-dawg, word-dawg and unicharset using the procedure described below. If you are only trying to recognize a limited range of fonts (like a single font for instance), then a single training page might be enough. DangAmbigs and user-words may be empty files. The dictionary files freq-dawg and word-dawg don't have to be given many words if you don't have a wordlist to hand, but accuracy will be lower than if you have a decent sized (10s of thousands for English say) dictionary, but for 2.04 and below at least, empty dawg files and dawgs with no words are NOT allowed.

# Training Procedure

Some of the procedure is inevitably manual. As much automated help as possible is provided. More automated tools may appear in the future. The tools referenced below are all built in the training subdirectory.

## Generate Training Images

The first step is to determine the full character set to be used, and prepare a text or word processor file containing a set of examples. The most important points to bear in mind when creating a training file are:
  * Make sure there are a minimum number of samples of each character. 10 is good, but 5 is OK for rare characters.
  * There should be more samples of the more frequent characters - at least 20.
  * Don't make the mistake of grouping all the non-letters together. Make the text more realistic. For example, **The quick brown fox jumps over the lazy dog. 0123456789 !@#$%^&(),.[]{}<>/?** is terrible. Much better is **The (quick) [brown] {fox} jumps! over the $3,456.78 `<lazy>` #90 dog & duck/goose, as 12.5% of E-mail from aspammer@website.com is spam?** This gives the textline finding code a much better chance of getting sensible baseline metrics for the special characters.
  * It is **ABSOLUTELY VITAL** to space out the text a bit when printing, so up the inter-character and inter-line spacing in your word processor. Not spacing text out sufficiently will cause "FAILURE! box overlaps no blobs or blobs in multiple rows" errors during tr file generation, which leads to FATALITY - 0 labeled samples of "x", which leads to "Error: X classes in inttemp while unicharset contains Y unichars" and you can't use your nice new data files.
  * The training data currently needs to fit in a single tiff image, but it may be multi-page tiff (if you have libtiff installed).
  * There is no need to train with multiple sizes. 10 point will do. (An exception to this is very small text. If you want to recognize text with an x-height smaller than about 15 pixels, you should either train it specifically or scale your images before trying to recognize them.)
  * **DO NOT MIX FONTS ON A PAGE** (In a single .tr file to be precise.) This will cause features to be dropped at clustering, which leads to recognition errors.
  * The example boxtiff files on the downloads page will help if you are not sure how to format your training data.

Next print and scan (or use some electronic rendering method) to create an image of your training page. Up to 32 training images can be used. It is best to create pages in a mix of fonts and styles, including italic and bold.

**NOTE:** training from real images is actually quite hard, due to the spacing-out requirements. This will be improved in a future release. For now it is much easier if you can print/scan your own training text.

You will also need to save your training image as a UTF-8 text file for use in the next step where you have to insert the codes into another file.

**Clarification for large amounts of training data**
The 32 images limit is for the number of **FONTS.** Each font may be put in a single multi-page tiff **(only if you are using libtiff!)** and the box file can be modified to specify the page number for each character after the coordinates. Thus an arbitrarily large amount of training data may be created for any given font, allowing training for large character-set languages. An alternative to multi-page tiffs is to create many single-page tiffs for a single font, and then you must cat together the tr files for each font into several single-font tr files. In any case, the input tr files to mftraining must each contain a single font, and the order files are given to mftraining must match the order they are given to unicharset\_extractor.

## Make Box Files

For the next step below, Tesseract needs a 'box' file to go with each training image. The box file is a text file that lists the characters in the training image, in order, one per line, with the coordinates of the bounding box around the image. Tesseract 2.0 has a mode in which it will output a text file of the required format, but if the character set is different to its current training, it will naturally have the text incorrect. So the key process here is to manually edit the file to put the correct characters in it.

Run Tesseract on each of your training images using this command line:
```
tesseract fontfile.tif fontfile batch.nochop makebox
```

You then have to rename `fontfile.txt` to `fontfile.box`.

Now the hard part. You have to edit the file fontfile.box and put the UTF-8 codes for each character in the file at the start of each line, in place of the incorrect character put there by Tesseract. Example: The distribution includes an image eurotext.tif. Running the above command produces a text file that includes the following lines (lines 142-155):

```
s 734 491 751 516
p 753 483 776 515
r 779 492 796 516
i 799 492 810 525
n 814 492 837 516
g 839 483 862 516
t 865 491 878 520
u 101 452 122 483
b 126 453 146 486
e 149 452 168 477
r 172 453 187 476
d 211 450 232 483
e 236 450 255 474
n 259 451 281 474
```

Since Tesseract was run in English mode, it does not correctly recognize the umlaut. This character needs to be corrected using a suitable editor. An editor that understands UTF-8 should be used for this purpose. HTML editors are usually a good choice. (Mozilla on Linux allows you to edit UTF-8 text files directly from the browser. Firefox and IE do not let you do this. MS Word is very good at handling different text encodings, and Notepad++ is another editor that understands UTF-8.) Linux and Windows both have a character map that can be used for copying characters that cannot be typed. In this case the u needs to be changed to Ã¼.

In theory, each line in the box file should represent one of the characters from your training file, but if you have a horizontally broken character, such as the lower double quote â€ž it will probably have 2 boxes that need to be merged!

Example: lines 117-130:

```
D 101 503 131 534
e 135 501 154 527
r 158 503 173 526
, 197 496 205 507
, 206 496 214 508
s 220 499 236 524
c 239 499 258 523
h 262 500 284 532
n 288 500 310 524
e 313 499 332 523
l 336 500 347 533
l 352 500 363 532
e 367 499 386 524
" 389 520 407 532
```

As you can see, the low double quote character has been expressed as two single commas. The bounding boxes must be merged as follows:
  * First number (left) take the minimum of the two lines (197)
  * Second number (bottom) take the minimum of the two lines (496)
  * Third number (right) take the maximum of the two lines (214)
  * Fourth number (top) take the maximum of the two lines (508)

This gives:

```
D 101 503 131 534
e 135 501 154 527
r 158 503 173 526
â€ž 197 496 214 508
s 220 499 236 524
c 239 499 258 523
h 262 500 284 532
n 288 500 310 524
e 313 499 332 523
l 336 500 347 533
l 352 500 363 532
e 367 499 386 524
" 389 520 407 532
```

If you didn't successfully space out the characters on the training image, some may have been joined into a single box. In this case, you can either remake the images with better spacing and start again, or if the pair is common, put both characters at the start of the line, leaving the bounding box to represent them both. (As of 2.04, there is a limit of 24 bytes for the description of a "character". This will allow you between 6 and 24 unicodes to describe the character, depending on where your codes sit in the unicode set. If anyone hits this limit, please file an issue describing your situation.)

**Note** that the coordinate system used in the box file has (0,0) at the bottom-left.

If you have an editor that understands UTF-8, this process will be a lot easier than if it doesn't, as each UTF-8 character has up to 4 bytes to code it, and dumb editors will show you all the bytes separately.

There are several visual tools for editing box file - please check [../AddOns](AddOns.md#For_Tesseract-OCR_2.0x).

### Bootstrapping a new character set

If you are trying to train a new character set, it is a good idea to put in the effort on a single font to get one good box file, run the rest of the training process, and then use Tesseract in your new language to make the rest of the box files as follows:
```
tesseract fontfile.tif fontfile -l yournewlanguage batch.nochop makebox
```
This should make the 2nd box file easier to make, as there is a good chance that Tesseract will recognize most of the text correctly. You can always iterate this sequence adding more fonts to he training set (i.e. to the command line of mfTraining and cnTraining below) as you make them, but note that there is no incremental training mode that allows you to add new training data to existing sets. This means that each time you run mfTraining and cnTraining you are making new data files from scratch from the tr files you give on the command line, and these programs cannot take an existing intproto/pffmtable/normproto and add to them directly.

### Tif/Box pairs provided!

The Tif/Box file pairs are on the downloads page. (Note the tiff files are G4 compressed
to save space, so you will have to have libtiff or uncompress them first). You could
follow the following process to make better training data for your own language or
subset of an existing language, or add different characters/shapes to an existing language:
  1. Filter the box files, keeping lines for only the characters you want.
  1. Run tesseract for training (below).
  1. Cat the .tr files from multiple languages for each font to get the character set that you want and add the .tr files from your own fonts or characters.
  1. Cat the filtered box files in an identical way to the .tr files for handing off to unicharset\_extractor.
  1. Run the rest of the training process.
Caution! This is not quite as simple as it sounds! cntraining and mftraining can only
take up to 32 .tr files, so you must cat all the files from multiple languages for the
same font together to make 32 language-combined, but font-individual files.
The characters found in the tr files **must** match the sequence
of characters found in the box files when given to unicharset\_extractor, so you have to
cat the box files together in the **same order** as the tr files.
The command lines for cn/mftraining and unicharset\_extractor must be given the .tr
and .box files (respectively) in the **same order** just in case you have different
filterings for the different fonts.
There may be a program available to do all this and pick out the characters in
the style of character map. This might make the whole thing easier.

## Run Tesseract for Training

For each of your training image, boxfile pairs, run Tesseract in training mode:
```
tesseract fontfile.tif junk nobatch box.train
```

OR

```
tesseract fontfile.tif junk nobatch box.train.stderr
```

The first form sends all the errors to tesseract.log (on all platforms) like it did on windows versions 2.03 and below. With box.train.stderr, all errors are sent to stderr, on all platforms, just like it did on non-windows platforms for versions 2.03 and below.

Note that the box filename must match the tif filename, including the path, or Tesseract won't find it. The output of this step is `fontfile.tr` which contains the features of each character of the training page. Note also that the output name is derived from the input image name, not the normal output name, shown here as `junk`. junk.txt will also be written with a single newline and no text.

**Important** Check for errors in the output from apply\_box. If there are FATALITIES reported, then there is no point continuing with the training process until you fix the box file. The new box.train.stderr config file makes is easier to choose the location of the output. A FATALITY usually indicates that this step failed to find any training samples of one of the characters listed in your box file. Either the coordinates are wrong, or there is something wrong with the image of the character concerned. If there is no workable sample of a character, it can't be recognized, and the generated inttemp file won't match the unicharset file later and Tesseract will abort.

Another error that can occur **that is also fatal and needs attention** is an error about "Box file format error on line n". If preceded by "Bad utf-8 char..." then the UTF-8 codes are incorrect and need to be fixed. The error "utf-8 string too long..." indicates that you have exceeded the 8 (v2.01) byte limit on a character description. If you need a description longer than 8 bytes, please file an issue. Box file format errors without either of the above errors indicate either something wrong with the bounding box integers, or possibly a blank line in the box file. Blank lines are actually harmless, and the error can be ignored in this case. They could be ignored by the code, but it doesn't ignore them in case there is something unintentional wrong with the box file.

There is no need to edit the content of the fontfile.tr file. The font name inside it need not be set. For the curious, here is some information on the format:
```
Every character in the box file has a corresponding set of entries in
the .tr file (in order) like this
UnknownFont <UTF-8 code(s)> 2
mf <number of features>
x y length dir 0 0
... (there are a set of these determined by <number of features>
above)
cn 1
ypos length x2ndmoment y2ndmoment

The mf features are polygon segments of the outline normalized to the
1st and 2nd moments.
x= x position [-0.5.0.5]
y = y position [-0.25, 0.75]
length is the length of the polygon segment [0,1.0]
dir is the direction of the segment [0,1.0]

The cn feature is to correct for the moment normalization to
distinguish position and size (eg c vs C and , vs ')
```

## Clustering

When the character features of all the training pages have been extracted, we need to cluster them to create the prototypes. The character shape features can be clustered using the `mftraining` and `cntraining` programs:

```
mftraining fontfile_1.tr fontfile_2.tr ...
```

This will output two data files: `inttemp` (the shape prototypes) and `pffmtable` (the number of expected features for each character). (A third file called `Microfeat` is also written by this program, but it is not used.)

```
cntraining fontfile_1.tr fontfile_2.tr ...
```

This will output the `normproto` data file (the character normalization sensitivity prototypes).

## Compute the Character Set

Tesseract needs to know the set of possible characters it can output. To generate the `unicharset` data file, use the `unicharset_extractor` program on the same training pages bounding box files as used for clustering:

```
unicharset_extractor fontfile_1.box fontfile_2.box ...
```

Tesseract needs to have access to character properties isalpha, isdigit, isupper, islower. This data must be encoded in the `unicharset` data file. Each line of this file corresponds to one character. The character in UTF-8 is followed by a hexadecimal number representing a binary mask that encodes the properties. Each bit corresponds to a property. If the bit is set to 1, it means that the property is true. The bit ordering is (from least significant bit to most significant bit): isalpha, islower, isupper, isdigit.

Example:

  * ';' is not an alphabetic character, a lower case character, an upper case character nor a digit. Its properties are thus represented by the binary number 0000 (0 in hexadecimal).
  * 'b' is an alphabetic character and a lower case character. Its properties are thus represented by the binary number 0011 (3 in hexadecimal).
  * 'W' is an alphabetic character and an upper case character. Its properties are thus represented by the binary number 0101 (5 in hexadecimal).
  * '7' is just a digit. Its properties are thus represented by the binary number 1000 (8 in hexadecimal).

```
; 0
b 3
W 5
7 8
```

If your system supports the wctype functions, these values will be set automatically by unicharset\_extractor **and there is no need to edit the unicharset file.** On some older systems (eg Windows 95), the unicharset file must be edited by hand to add these property description codes.

**NOTE** The unicharset file must be regenerated whenever inttemp, normproto and pffmtable are generated (i.e. they must **all** be recreated when the box file is changed) as they have to be in sync. The lines in unicharset must be in the correct order, as inttemp stores an index into unicharset and the actual characters returned by the classifier come from unicharset at the given index.

## Dictionary Data

Tesseract uses 3 dictionary files for each language. Two of the files are coded as a Directed Acyclic Word Graph (DAWG), and the other is a plain UTF-8 text file. To make the DAWG dictionary files, you first need a wordlist for your language. The wordlist is formatted as a UTF-8 text file with one word per line. Split the wordlist into two sets: the frequent words, and the rest of the words, and then use `wordlist2dawg` to make the DAWG files:

```
wordlist2dawg frequent_words_list freq-dawg
wordlist2dawg words_list word-dawg
```

**NOTE: wordlists must contain at least one word!** Empty files and dictionaries with no words are **not** currently supported! (Surely you know at least one word to be recognized.)

If words always have some punctuation in them, like google.com then it is a good idea to include them in the dictionary.

The third dictionary file is called user-words and is usually empty.

## The last file

The final data file that Tesseract uses is called DangAmbigs. It represents the intrinsic ambiguity between characters or sets of characters, and is currently entirely manually generated. To understand the file format, look at the following example:

```
1       m       2       r n
3       i i i   1       m
```

The first field is the number of characters in the second field. The 3rd field is the number of characters in the 4th field. As with the other files, this is a UTF-8 format file, and therefore each character may be represented by multiple bytes. The first line shows that the pair 'rn' may sometimes be recognized incorrectly as 'm'. The second line shows that the character 'm' may sometimes be recognized incorrectly as the sequence 'iii'
Note that the characters on both sides should occur in unicharset. This file cannot be used to translate characters from one set to another.

The DangAmbigs file may also be empty.

# Putting it all together

That is all there is to it! All you need to do now is collect together all 8 files and rename them with a `lang.` prefix, where lang is the 3-letter code for your language taken from http://en.wikipedia.org/wiki/List_of_ISO_639-2_codes and put them in your tessdata directory. Tesseract can then recognize text in your language (in theory) with the following:
```
tesseract image.tif output -l lang
```

(Actually, you can use any string you like for the language code, but if you want anybody else to be able to use it easily, ISO 639 is the way to go.)
