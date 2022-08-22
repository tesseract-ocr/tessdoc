------------------------------------
## For training Neural net based LSTM Tesseract 4.00 see [Training Tesseract 4.00](../TrainingTesseract-4.00.md)
-------------------------------------

## *How to use the tools provided to train Tesseract 3.03–3.05 for a new language.*

**Important note**: Before you invest time and efforts on training Tesseract, it is highly recommended to read the [ImproveQuality](ImproveQuality.md) page.

Tesseract 3.04 and 3.05 provide a [script](https://github.com/tesseract-ocr/tesseract/blob/3.05/training/tesstrain.sh) for an easy way to execute the various phases of training Tesseract. More information on using it can be found on the [tesstrain.sh](Training-Tesseract-–-tesstrain.sh) page.


[Questions about the training process](#questions-about-the-training-process)  

* [Introduction](#introduction)
* [Background and Limitations](#background-and-limitations)
* [Additional Libraries required](#additional-libraries-required)
* [Building the training tools](#building-the-training-tools)
* [Data files required](#data-files-required)
  * [Requirements for text input files](#requirements-for-text-input-files)
  * [How little can you get away with?](#how-little-can-you-get-away-with)
 
[**Training Procedure**](#training-procedure)
* [Generate Training Images and Box Files](#generate-training-images-and-box-files)
  * [Prepare a text file](#prepare-a-text-file)
  * [Automated method](#automated-method)
  * [Old Manual method](#old-manual-method)
    * [Make Box Files](#make-box-files)
* [Run Tesseract for Training](#run-tesseract-for-training)
* [Generate the unicharset file](#generate-the-unicharset-file)
  * [unicharset_extractor](#unicharset_extractor)
  * [set_unicharset_properties](#set_unicharset_properties)
* [The font_properties file](#the-font_properties-file)
* [Clustering](#clustering)
  * [shapeclustering](#shapeclustering)
  * [mftraining](#mftraining)
  * [cntraining](#cntraining)
* [Dictionary Data (Optional)](#dictionary-data-optional)
* [The unicharambigs file](#the-unicharambigs-file)
* [Putting it all together](#putting-it-all-together)

**Appendices** 
* [The *.tr file format](#the-tr-file-format)
* [The unicharset file format](#the-unicharset-file-format)

# Questions about the training process  

If you had some problems during the training process and you need help, use [tesseract-ocr](https://groups.google.com/forum/#!forum/tesseract-ocr) mailing-list to ask your question(s).

**PLEASE DO NOT** report your problems and ask questions about training as [issues](https://github.com/tesseract-ocr/tesseract/issues)!

# Introduction

Tesseract 3.0x is fully trainable. This page describes the training process, provides some guidelines on applicability to various languages, and what to expect from the results. 

Please check the list of languages for which [traineddata](Data-Files.md) is already available as of release 3.04 before embarking on training.

[3rd Party training tools](../AddOns.md) are also available for training.

# Background and Limitations

Tesseract was originally designed to recognize English text only. Efforts have been made to modify the engine and its training system to make them able to deal with other languages and UTF-8 characters. Tesseract 3.0 can handle any Unicode characters (coded with UTF-8), but there are limits as to the range of languages that it will be successful with, so please take this section into account before building up your hopes that it will work well on your particular language!

Tesseract 3.01 added top-to-bottom languages, and Tesseract 3.02 added Hebrew (right-to-left).

Tesseract currently handles scripts like Arabic and Hindi with an auxiliary engine called cube (included in Tesseract version 3.01 and up). **Don't try to train Tesseract versions earlier than 4.0 for Arabic (same for Persian, Urdu, etc.). It's hopeless.** For 4.0 only train with the [LSTM method](4.0-with-LSTM.md#training-tesseract-lstm-engine).

[Traineddata](Data-Files.md) for additional languages has been provided by Google for the 3.04 release. 

Tesseract is slower with large character set languages (like Chinese), but it seems to work OK.

Tesseract needs to know about different shapes of the same character by having different fonts separated explicitly. The number of fonts is limited to 64 fonts. Note that runtime is heavily dependent on the number of fonts provided, and training more than 32 will result in a significant slow-down.

# Additional Libraries required
Beginning with 3.03, additional libraries are required to build the training tools.
```
sudo apt-get install libicu-dev
sudo apt-get install libpango1.0-dev
sudo apt-get install libcairo2-dev
```

# Building the training tools

Beginning with 3.03, if you're compiling Tesseract from source you need to make and install the training tools with separate make commands. Once the above additional libraries have been installed, run the following from the tesseract source directory:
```
make training
sudo make training-install
```

# Data files required

To train for another language, you have to create some data files in the `tessdata` subdirectory, and then crunch these together into a single file, using `combine_tessdata`. The naming convention is `languagecode.file_name` Language codes for released files follow the ISO 639-3 standard, but any string can be used. The files used for English (3.0x) are:
  * `tessdata/eng.config`
  * `tessdata/eng.unicharset`
  * `tessdata/eng.unicharambigs`
  * `tessdata/eng.inttemp`
  * `tessdata/eng.pffmtable`
  * `tessdata/eng.normproto`
  * `tessdata/eng.punc-dawg`
  * `tessdata/eng.word-dawg`
  * `tessdata/eng.number-dawg`
  * `tessdata/eng.freq-dawg`

... and the final crunched file is:
  * `tessdata/eng.traineddata`

and
  * `tessdata/eng.user-words`
may still be provided separately.

The traineddata file is simply a concatenation of the input files, with a table of contents that contains the offsets of the known file types. See ccutil/tessdatamanager.h in the source code for a list of the currently accepted filenames.

## Requirements for text input files

Text input files (lang.config, lang.unicharambigs, font\_properties, box files, wordlists for dictionaries...) need to meet these criteria:
  * ASCII or UTF-8 encoding without [BOM](http://en.wikipedia.org/wiki/Byte_order_mark)
  * Unix [end-of-line marker](http://en.wikipedia.org/wiki/Newline) ('\n')
  * The last character must be an end of line marker ('\n'). Some text editors will show this as an empty line at the end of file. If you omit this you will get an error message containing `last_char == '\n':Error:Assert failed...`.

## How little can you get away with?

You **must** create `unicharset`, `inttemp`, `normproto`, `pffmtable` using the procedure described below. If you are only trying to recognize a limited range of fonts (like a single font for instance), then a single training page might be enough. The other files do not need to be provided, but will most likely improve accuracy, depending on your application.

# Training Procedure

Some of the procedure is inevitably manual. As much automated help as possible is provided. The tools referenced below are all built in the training subdirectory.

You need to run all commands in the same folder where your input files are located.

## Generate Training Images and Box Files

## Prepare a text file

The first step is to determine the full character set to be used, and prepare a text or word processor file containing a set of examples. The most important points to bear in mind when creating a training file are:

Make sure there are a minimum number of samples of each character. 10 is good, but 5 is OK for rare characters.

There should be more samples of the more frequent characters - at least 20.

Don't make the mistake of grouping all the non-letters together. Make the text more realistic.  
For example:
```
The quick brown fox jumps over the lazy dog. 0123456789 !@#$%^&(),.{}&lt;&gt;/?
```
is terrible! Much better is:
```
The (quick) brown {fox} jumps! over the $3,456.78 &lt;lazy&gt; #90 dog & duck/goose, as 12.5% of E-mail from aspammer@website.com is spam?
```
This gives the text-line finding code a much better chance of getting sensible baseline metrics for the special characters.

### Automated method

*New in 3.03*

Prepare a UTF-8 text file (`training_text.txt`) containing your training text according to the above specification.
Obtain truetype/opentype font files for the fonts that you wish to recognize.
Run the following command for each font in turn to create a matching tif/box file pair.

```
training/text2image --text=training_text.txt --outputbase=[lang].[fontname].exp0 --font='Font Name' --fonts_dir=/path/to/your/fonts
```

Note that the argument to --font may contain spaces, and thus must be quoted. Eg:

```
training/text2image --text=training_text.txt --outputbase=eng.TimesNewRomanBold.exp0 --font='Times New Roman Bold' --fonts_dir=/usr/share/fonts
```
To list all fonts in your system which can render the training text, run:  
```
training/text2image --text=training_text.txt --outputbase=eng --fonts_dir=/usr/share/fonts  --find_fonts --min_coverage=1.0 --render_per_font=false
```
In this example, the `training_text.txt` file contains text written in English. A 'eng.fontlist.txt' file will be created.

There are a lot of other command-line arguments available to `text2image`. Run `text2image --help` to get more information.

If you used `text2image`, you can move to [Run Tesseract for Training](#run-tesseract-for-training) step.

### Old Manual method

  * The training data should be grouped by font. Ideally, all samples of a single font should go in a single tiff file, but this may be multi-page tiff (if you have libtiff or leptonica installed), so the total training data in a single font may be many pages and many 10s of thousands of characters, allowing training for large-character-set languages.
  * There is no need to train with multiple sizes. 10 point will do. (An exception to this is very small text. If you want to recognize text with an x-height smaller than about 15 pixels, you should either train it specifically or scale your images before trying to recognize them.)
  * **DO NOT MIX FONTS IN AN IMAGE FILE** (In a single .tr file to be precise.) This will cause features to be dropped at clustering, which leads to recognition errors.
  * The example boxtiff files on the downloads page will help if you are not sure how to format your training data.

Next print and scan (or use some electronic rendering method) to create an image of your training page. Up to 64 training files can be used (of multiple pages). It is best to create a mix of fonts and styles (but in separate files), including italic and bold.

You will also need to save your training text as a UTF-8 text file for use in the next step where you have to insert the codes into another file.

**Clarification for large amounts of training data**
The 64 images limit is for the number of **FONTS.** Each font should be put in a single multi-page tiff and the box file can be modified to specify the page number for each character after the coordinates. Thus an arbitrarily large amount of training data may be created for any given font, allowing training for large character-set languages. An alternative to multi-page tiffs is to create many single-page tiffs for a single font, and then you must cat together the tr files for each font into several single-font tr files. In any case, the input tr files to mftraining must each contain a single font.

#### Make Box Files

See the separate [Make Box Files](Make-Box-Files.md) page.

## Run Tesseract for Training

For each of your training image, boxfile pairs, run Tesseract in training mode:
```
tesseract [lang].[fontname].exp[num].tif [lang].[fontname].exp[num] box.train
```

or

```
tesseract [lang].[fontname].exp[num].tif [lang].[fontname].exp[num] box.train.stderr
```

**NOTE** that although tesseract requires language data to be present for this step, the language data is not used, so English will do, whatever language you are training.

The first form sends all the errors to a file named tesseract.log. The second form sends all errors to stderr. 

Note that the box filename must match the tif filename, including the path, or Tesseract won't find it. The output of this step is `fontfile.tr` which contains the features of each character of the training page. `[lang].[fontname].exp[num].txt` will also be written with a single newline and no text.

**Important** Check for errors in the output from apply\_box. If there are FATALITIES reported, then there is no point continuing with the training process until you fix the box file. The new box.train.stderr config file makes is easier to choose the location of the output. A FATALITY usually indicates that this step failed to find any training samples of one of the characters listed in your box file. Either the coordinates are wrong, or there is something wrong with the image of the character concerned. If there is no workable sample of a character, it can't be recognized, and the generated inttemp file won't match the unicharset file later and Tesseract will abort.

Another error that can occur **that is also fatal and needs attention** is an error about "Box file format error on line n". If preceded by "Bad utf-8 char..." then the UTF-8 codes are incorrect and need to be fixed. The error "utf-8 string too long..." indicates that you have exceeded the 24 byte limit on a character description. If you need a description longer than 24 bytes, please file an issue.

There is no need to edit the content of the `[lang].[fontname].exp[num].tr` file. The font name inside it need not be set.

For the curious, [here](#the-tr-file-format) is some information on the format. 

## Generate the unicharset file

Tesseract’s unicharset file contains information on each symbol (unichar) the Tesseract OCR engine is trained to recognize.

Currently, generating the `unicharset` file is done in two steps using these commands: `unicharset_extractor` and `set_unicharset_properties`.

**NOTE:** The `unicharset` file must be regenerated whenever `inttemp`, `normproto` and `pffmtable` are generated (i.e. they must **all** be recreated when the box file is changed) as they have to be in sync.

For more details about the `unicharset` file format, see [this appendix](#the-unicharset-file-format).

### unicharset_extractor

Tesseract needs to know the set of possible characters it can output. To generate the `unicharset` data file, use the `unicharset_extractor` program on the box files generated above:

```
unicharset_extractor lang.fontname.exp0.box lang.fontname.exp1.box ...
```

### set\_unicharset\_properties

*New in 3.03*

This tool, together with a set of data files, allow the addition of extra properties in the unicharset, mostly sizes obtained from fonts. 

```
training/set_unicharset_properties -U input_unicharset -O output_unicharset --script_dir=training/langdata
```

`--script_dir` should point to a directory containing the relevant .unicharset file(s) for your training character set. These can be downloaded from [https://github.com/tesseract-ocr/langdata](https://github.com/tesseract-ocr/langdata)).

After running `unicharset_extractor` and `set_unicharset_properties`, you should get a `unicharset` file with all the fields set to the right values, like in this [example](#an-example-of-the-unicharset-file).

## The font\_properties file

Now you need to create a `font_properties` text file. The purpose of this file is to provide font style information that will appear in the output when the font is recognized.

Each line of the `font_properties` file is formatted as follows:
`fontname` `italic` `bold` `fixed` `serif` `fraktur`  
where `fontname` is a string naming the font (no spaces allowed!), and `italic`, `bold`, `fixed`, `serif` and `fraktur` are all simple `0` or `1` flags indicating whether the font has the named property.

**Example**:

```
timesitalic 1 0 0 1 0
```

The `font_properties` file will be used by the `shapeclustering` and `mftraining` commands.

When running `mftraining`, each `fontname` field in the [*.tr file](#the-tr-file-format) must match an `fontname` entry in the `font_properties` file, or `mftraining` will abort.

**Note**: There is a default [font_properties](https://raw.githubusercontent.com/tesseract-ocr/langdata/master/font_properties) file, that covers 3000 fonts (not necessarily accurately) located in the langdata repository.

## Clustering

When the character features of all the training pages have been extracted, we need to cluster them to create the prototypes.

The character shape features can be clustered using the `shapeclustering`, `mftraining` and `cntraining` programs:

### shapeclustering

`shapeclustering` **should not normally be used except for the Indic languages.** (It may be necessary to use `shapeclustering` for Latin-alphabet languages where base characters are combined with two or more non-spacing modifiers, e.g. ḗ, ɔ̄́, r̥̄: this includes, but may not be limited to, Indic languages in Latin transcription. Failure to do so will lead `mftraining` to give an `Assert failed:in file unicharset.cpp` error.)

```
shapeclustering -F font_properties -U unicharset lang.fontname.exp0.tr lang.fontname.exp1.tr ...
```

`shapeclustering` creates a master shape table by shape clustering and writes it to a file named `shapetable`.

### mftraining

```
mftraining -F font_properties -U unicharset -O lang.unicharset lang.fontname.exp0.tr lang.fontname.exp1.tr ...
```

The -U file is the unicharset generated by `unicharset_extractor` above, and lang.unicharset is the output unicharset that will be given to `combine_tessdata`.

`mftraining` will output two other data files: `inttemp` (the shape prototypes) and `pffmtable` (the number of expected features for each character).

**NOTE**: `mftraining` will produce a `shapetable` file if you didn't run `shapeclustering`. You **must** include this `shapetable` in your traineddata file, whether or not `shapeclustering` was used.

### cntraining

```
cntraining lang.fontname.exp0.tr lang.fontname.exp1.tr ...
```

This will output the `normproto` data file (the character normalization sensitivity prototypes).

## Dictionary Data (Optional)

Tesseract uses up to 8 dictionary files for each language. These are all optional, and help Tesseract to decide the likelihood of different possible character combinations.

Seven of the files are coded as a Directed Acyclic Word Graph (DAWG), and the other is a plain UTF-8 text file:

| **Name** | **Type** | **Description** |
|:---------|:---------|:----------------|
| word-dawg | dawg     | A dawg made from dictionary words from the language. |
| freq-dawg | dawg     | A dawg made from the most frequent words which would have gone into word-dawg. |
| punc-dawg | dawg     | A dawg made from punctuation patterns found around words. The _"word"_ part is replaced by a single space. |
| number-dawg | dawg     | A dawg made from tokens which originally contained digits. Each digit is replaced by a space character. |
| bigram-dawg | dawg     | A dawg of word bigrams where the words are separated by a space and each digit is replaced by a _?_. |
| user-words | text     | A list of extra words to add to the dictionary. Usually left empty to be added by users if they require it; see [tesseract(1)](https://github.com/tesseract-ocr/tesseract/blob/13b7900ebf21fbccbc3d89ebf63cc7165b6ae2ca/doc/tesseract.1.asc#config-files-and-augmenting-with-user-data). |

To make the DAWG dictionary files, you first need a wordlist for your language. You may find an appropriate dictionary file to use as the basis for a wordlist from the spellcheckers (e. g. [ispell](http://ficus-www.cs.ucla.edu/geoff/ispell-dictionaries.html), [aspell](http://aspell.net/) or [hunspell](http://hunspell.sourceforge.net/)) - be careful about the license. The wordlist is formatted as a UTF-8 text file with one word per line. Split the wordlist into needed sets e.g.: the frequent words, and the rest of the words, and then use `wordlist2dawg` to make the DAWG files:

```
wordlist2dawg frequent_words_list lang.freq-dawg lang.unicharset
wordlist2dawg words_list lang.word-dawg lang.unicharset
```

For languages written from right to left (RTL), like Arabic and Hebrew, add `-r 1` to the `wordlist2dawg` command.

Other options can be found in [wordlist2dawg Manual Page](https://github.com/tesseract-ocr/tesseract/blob/main/doc/wordlist2dawg.1.asc)

**NOTE:** If a dictionary file is included in the combined traineddata, it must contain at least one entry.  Dictionary files that would otherwise be empty are not required for the `combine_tessdata` step.

Words with unusual spellings should be added to the dictionary files. Unusual spellings can include mixtures of alphabetical characters with punctuation or numeric characters. (E.g. i18n, l10n, google.com, news.bbc.co.uk, io9.com, utf8, ucs2)

If you need example files for dictionary wordlists, uncombine (with [combine\_tessdata](https://github.com/tesseract-ocr/tesseract/blob/main/doc/combine_tessdata.1.asc)) existing language data file (e.g. eng.traineddata) and then extract wordlist with [dawg2wordlist](https://github.com/tesseract-ocr/tesseract/blob/main/doc/dawg2wordlist.1.asc)


## The unicharambigs file

The `unicharambigs` file is a text file that describes possible ambiguities between characters or sets of characters, and is manually generated.

To understand the file format, look at the following example:

```
v1
2       ' '     1       "       1
1       m       2       r n     0
3       i i i   1       m       0
```

The first line is a version identifier.  

The remaining lines are **tab** separated fields, in the following format:  
```
<number of characters for match source> <characters for match source> <number of characters for match target> <characters for match target> <type indicator>
```

Type indicator [could have](https://github.com/tesseract-ocr/tesseract/blob/main/ccutil/ambigs.h#L44) following values:

| **Value** | **Type** | **Description** |
|:----------|:---------|:----------------|
| 0         | A non-mandatory substitution. | This informs tesseract to consider the ambiguity as a hint to the segmentation search that it should continue working if replacement of 'source' with 'target' creates a dictionary word from a non-dictionary word. Dictionary words that can be turned to another dictionary word via the ambiguity will not be used to train the adaptive classifier. |
| 1         | A mandatory substitution. | This informs tesseract to always replace the matched 'source' with the 'target' strings. |

| **Example line** | **Explanation** |
|:-----------------|:----------------|
| 2       ' '     1       "       1 | A double quote (") should be substituted **whenever** 2 consecutive single quotes (') are seen. |
| 1       m       2       r n     0 | The characters 'rn' may sometimes be recognized incorrectly as 'm'. |
| 3       i i i   1       m       0 | The character 'm' may sometimes be recognized incorrectly as the sequence 'iii'. |

Each separate character must be included in the unicharset. That is, all of the characters used must be part of the language that is being trained.

The rules are not bidirectional, so if you want 'rn' to be considered when 'm' is detected and vice versa you need a rule for each.

Version 3.03 and on supports a new, simpler format for the unicharambigs file:

```
v2
'' " 1
m rn 0
iii m 0
```

In this format, the "error" and "correction" are simple UTF-8 strings separated by a space, and, after another space, the same type specifier as v1 (0 for optional and 1 for mandatory substitution). Note the downside of this simpler format is that Tesseract has to encode the UTF-8 strings into the components of the unicharset. In complex scripts, this encoding may be ambiguous. In this case, the encoding is chosen such as to use the least UTF-8 characters for each component, ie the shortest unicharset components will make up the encoding.

Like most other files used in training, the `unicharambigs` file must be encoded as UTF-8, and must end with a newline character.

The `unicharambigs` format is also described in the [unicharambigs(5) man page](https://github.com/tesseract-ocr/tesseract/blob/main/doc/unicharambigs.5.asc).

The `unicharambigs` file may also be non-existent.

# Putting it all together

That is all there is to it! All you need to do now is collect together all the files (`shapetable`, `normproto`, `inttemp`, `pffmtable`, `unicharset`) and rename them with a `lang.` prefix (for example `eng.`), and then run `combine_tessdata` on them as follows:
```
combine_tessdata lang.
```

Although you can use any string you like for the language code, we recommend that you use a 3-letter code 
for your language matching one of the [ISO 639-2 codes](http://en.wikipedia.org/wiki/List_of_ISO_639-2_codes).

The resulting lang.traineddata goes in your tessdata directory. Tesseract can then recognize text in your language (in theory) with the following:
```
tesseract image.tif output -l lang
```

More options of `combine_tessdata` can be found on its [Manual Page](https://github.com/tesseract-ocr/tesseract/blob/main/doc/combine_tessdata.1.asc) or in comment of its [source code](https://github.com/tesseract-ocr/tesseract/blob/main/training/combine_tessdata.cpp#L23).

You can inspect some of the internals of traineddata files in 3rd party online [Traineddata inspector](https://te-traineddata-ui.herokuapp.com).

# Appendices

## The *.tr file format

Every character in the box file has a corresponding set of entries in the .tr file (in order) like this:

```
<fontname> <character> <left> <top> <right> <bottom> <pagenum>
 4
mf <number of features>
<x> <y> <length> <dir> 0 0
...
cn 1
<ypos> <length> <x2ndmoment> <y2ndmoment>
if <number of features>
<x> <y> <dir>
...
tb 1
<bottom> <top> <width>
```

The Micro Features (`mf`) are polygon segments of the outline normalized to the
1st and 2nd moments. The `mf` line will followed by a set of lines determined by \<number of features\>.  
x is x position [-0.5,0.5]  
y is y position [-0.25,0.75]  
length is the length of the polygon segment [0,1.0]  
dir is the direction of the segment [0,1.0]

The Char Norm features (`cn`) are used to correct for the moment normalization to
distinguish position and size (eg `c` vs `C` and `,` vs `'`)

`if` - Int Features 

`tb` - Geo features

## The unicharset file format

Tesseract’s unicharset file contains information on each symbol (unichar) the Tesseract OCR engine is trained to recognize.

The first line of a unicharset file contains the number of unichars in the file. 

After this line, each subsequent line provides information for a single unichar. The first such line contains a placeholder reserved for the space character.

Each unichar is referred to within Tesseract by its Unichar ID, which is the line number (minus 1) within the unicharset file. Therefore, space gets unichar 0.

Each unichar line in the unicharset file should have these space-separated fields:  
`character` `properties` `glyph_metrics` `script` `other_case` `direction` `mirror` `normed_form`

* `character`  
The UTF-8 encoded string to be produced for this unichar.
* `properties`  
An integer mask of character properties, one per bit. From least to most significant bit, these are: isalpha, islower, isupper, isdigit, ispunctuation.
* `glyph_metrics`  
Ten comma-separated integers representing various standards for where this glyph is to be found within a baseline-normalized coordinate system where 128 is normalized to x-height.
  - `min_bottom`, `max_bottom`  
The ranges where the bottom of the character can be found.
  - `min_top`, `max_top`  
The ranges where the top of the character may be found.
  - `min_width`, `max_width`  
Horizontal width of the character.
  - `min_bearing`, `max_bearing`  
How far from the usual start position does the leftmost part of the character begin.
  - `min_advance`, `max_advance`  
How far from the printer’s cell left do we advance to begin the next character.
* `script`  
Name of the script (Latin, Common, Greek, Cyrillic, Han, NULL).
* `other_case`  
The Unichar ID of the other case version of this character (upper or lower).
* `direction`  
The Unicode BiDi direction of this character, as defined by ICU’s enum UCharDirection. (0 = Left to Right, 1 = Right to Left, 2 = European Number…​)
* `mirror`  
The Unichar ID of the BiDirectional mirror of this character. For example the mirror of open paren is close paren, but Latin Capital C has no mirror, so it remains a Latin Capital C.
* `normed_form`  
The UTF-8 representation of a "normalized form" of this unichar for the purpose of blaming a module for errors given ground truth text. For instance, a left or right single quote may normalize to an ASCII quote.

### An example of the unicharset file

```
110
NULL 0 NULL 0
N 5 59,68,216,255,87,236,0,27,104,227 Latin 11 0 1 N
Y 5 59,68,216,255,91,205,0,47,91,223 Latin 33 0 2 Y
1 8 59,69,203,255,45,128,0,66,74,173 Common 3 2 3 1
9 8 18,66,203,255,89,156,0,39,104,173 Common 4 2 4 9
a 3 58,65,186,198,85,164,0,26,97,185 Latin 56 0 5 a
...
```

### More about the `properties` field  

Here is another example. For simplicity only the first two fields in each line are shown in this example. The other fields are omitted.

```
...
; 10 ...
b 3 ...
W 5 ...
7 8 ...
= 0 ...
...
```


**Char** | **Punctuation** | **Digit** | **Upper** | **Lower** |  **Alpha** | **Binary num** |  **Hex.**
:------: | :-------------: | :-------: | :--------: | :------: | :--------: | :------------: | --------:
; | 1 | 0 | 0 | 0 | 0 | 10000 | 10
b | 0 | 0 | 0 | 1 | 1 | 00011 | 3
W | 0 | 0 | 1 | 0 | 1 | 00101 | 5
7 | 0 | 1 | 0 | 0 | 0 | 01000 | 8
= | 0 | 0 | 0 | 0 | 0 | 00000 | 0

In columns 2-6, `0` means 'No', `1` means 'Yes'.
