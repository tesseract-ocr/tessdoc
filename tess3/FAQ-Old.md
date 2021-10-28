This page archives the [FAQ](../FAQ.md) page pertaining to Tesseract 2.0x, 3.0x and 4.00.00alpha as of May 1, 2018.

The main [FAQ](../FAQ.md) page will contain information pertaining to Tesseract 4.0.0 and later.

***

# Frequently Asked Questions

A collection of frequently asked questions and the answers, or pointers to them. If you have a question which is not answered below, please post it to the [forums](https://groups.google.com/d/forum/tesseract-ocr).

  * [Rules and advice](#rules-and-advice)

Table of Contents
=================
  * [Can I increase speed of OCR?](#can-i-increase-speed-of-ocr)
  * [Windows: tesseract closes automatically right after launching](#windows-tesseract-closes-automatically-right-after-launching)
  * [What output formats can Tesseract produce?](#what-output-formats-can-tesseract-produce)
  * [How to interpret hOCR baseline output?](#how-to-interpret-hocr-baseline-output)
  * [libtesseract.so.3: cannot open shared object file](#libtesseractso3-cannot-open-shared-object-file)
  * [Tesseract does not work](#tesseract-does-not-work)
  * [How do I uninstall Tesseract](#how-do-i-uninstall-tesseract)
  * [How do I run multiple versions of Tesseract on same machine](#how-do-i-compare-different-versions-of-tesseract)
  * [Error in pixReadStream:](#error-in-pixreadstream)
  * [Can't open eng.unicharset?](#cant-open-engunicharset)
  * [leptonica library missing](#leptonica-library-missing)
  * [Can't read compressed TIFF files](#cant-read-compressed-tiff-files)
  * [No output with color images](#no-output-with-color-images)
  * [Does it support multi-page TIFF files?](#does-it-support-multi-page-tiff-files)
  * [Why doesn't viewer/svutil.cpp compile?](#why-doesnt-viewersvutilcpp-compile)
  * [Where are the training tools for Ubuntu 14.04 ?](#where-are-the-training-tools-for-ubuntu-1404-)
  * [How do I Edit Box files used in training?](#how-do-i-edit-box-files-used-in-training)
  * [Utf8 buffer too big, size=xx (Error during training)](#utf8-buffer-too-big-sizexx-error-during-training)
  * [How do I recognize only digits?](#how-do-i-recognize-only-digits)
    * [Tesseract 3](#tesseract-3)
    * [Tesseract 2.03](#tesseract-203)
  * [How do I add just one character or one font to my favourite language, without having to retrain from scratch?](#how-do-i-add-just-one-character-or-one-font-to-my-favourite-language-without-having-to-retrain-from-scratch)
  * [How do I produce searchable PDF output?](#how-do-i-produce-searchable-pdf-output)
  * [The produced searchable PDF seems to only contain spaces](#the-produced-searchable-pdf-seems-to-only-contain-spaces)
  * [How to do streaming](#how-to-do-streaming)
  * [Is there a Minimum / Maximum Text Size? (It won't read screen text!)](#is-there-a-minimum--maximum-text-size-it-wont-read-screen-text)
  * [Why is the output empty or of poor quality?](#why-is-the-output-empty-or-of-poor-quality)
  * [How do I generate the language data files?](#how-do-i-generate-the-language-data-files)
  * [How do I unpack or alter existing language data files?](#how-do-i-unpack-or-alter-existing-language-data-files)
  * [How do I provide my own dictionary?](#how-do-i-provide-my-own-dictionary)
    * [Tesseract 3](#tesseract-3-1)
    * [Tesseract 2](#tesseract-2)
  * [wordlist2dawg doesn't work!](#wordlist2dawg-doesnt-work)
  * [How to increase the trust in/strength of the dictionary?](#how-to-increase-the-trust-instrength-of-the-dictionary)
  * [What are configs and how can I have more?](#what-are-configs-and-how-can-i-have-more)
  * [There are inconsistent results from tesseract when the same TessBaseAPI object is used for decoding multiple images](#there-are-inconsistent-results-from-tesseract-when-the-same-tessbaseapi-object-is-used-for-decoding-multiple-images)
  * [Diacritics above and below the glyph are ignored/cause garbage output](#diacritics-above-and-below-the-glyph-are-ignoredcause-garbage-output)
  * [Where is the documentation?](#where-is-the-documentation)
  * [How can I try the next version?](#how-can-i-try-the-next-version)
  * [actual_tessdata_num_entries_&lt;= TESSDATA_NUM_ENTRIES:Error:Assert failed:in file ..\ccutil\tessdatamanager.cpp, line 55_](#actual_tessdata_num_entries_-tessdata_num_entrieserrorassert-failedin-file-ccutiltessdatamanagercpp-line-55_)
  * [last_char == '\n':Error:Assert failed:in file ..\ccutil\tessdatamanager.cpp, line 95](#last_char--nerrorassert-failedin-file-ccutiltessdatamanagercpp-line-95)
  * [Error: Illegal min or max specification](#error-illegal-min-or-max-specification)
  * [Error: X classes in inttemp while unicharset contains Y unichars.](#error-x-classes-in-inttemp-while-unicharset-contains-y-unichars)
  * [Error: Size of unicharset is greater than MAX_NUM_CLASSES](#error-size-of-unicharset-is-greater-than-max_num_classes)
  * [How can I make the error messages go to tesseract.log instead of stderr?](#how-can-i-make-the-error-messages-go-to-tesseractlog-instead-of-stderr)
  * [How can I suppress tesseract info line?](#how-can-i-suppress-tesseract-info-line)
  * [How can I get the coordinates and confidence of each word?](#how-can-i-get-the-coordinates-and-confidence-of-each-word)
  * [How is confidence calculated?](#how-is-confidence-calculated)
  * [Can I use Tesseract for handwriting recognition?](#can-i-use-tesseract-for-handwriting-recognition)
  * [Can I use tesseract for barcode recognition?](#can-i-use-tesseract-for-barcode-recognition)
  * [Issues with older versions of tesseract](#issues-with-older-versions-of-tesseract)
    * [How to port Tesseract engine into vb6 project?](#how-to-port-tesseract-engine-into-vb6-project)
    * [Delphi wrapper for tessdll.dll](#delphi-wrapper-for-tessdlldll)
    * [Incomplete OCR result](#incomplete-ocr-result)
    * [error LNK2001: unresolved external symbol "public: static char cdecl TessBaseAPI::TesseractRect(unsigned char const,int,int,int,int,int,int)"](#error-lnk2001-unresolved-external-symbol-public-static-char-cdecl-tessbaseapitesseractrectunsigned-char-constintintintintintint-tesseractrecttessbaseapisapadpbehhhhhhz)
    * [box overlaps no blobs or blobs in multiple rows error when training](#box-overlaps-no-blobs-or-blobs-in-multiple-rows-error-when-training)
    * [Training failed  with error message "mf.cpp:78: FEATURE_SET_STRUCT\* ExtractMicros..."](#training-failed--with-error-message-mfcpp78-feature_set_struct-extractmicros)
    * [error message: Font id = -1/0, class id = 1/105 on sample 0](#error-message-font-id---10-class-id--1105-on-sample-0)
  * [My question isn't in here!](#my-question-isnt-in-here)

## Rules and advice

If you think you found a bug in Tesseract, please create an issue. Questions should be asked in the [users mailing-list](https://groups.google.com/d/forum/tesseract-ocr).

You **must** read the [CONTRIBUTING](https://github.com/tesseract-ocr/tesseract/blob/main/CONTRIBUTING.md) guide before you report an issue in GitHub or ask a question in the forum.

## Can I increase speed of OCR?

If you are processing several images, you can run tesseract in parallel with [GNU Parallel](http://www.gnu.org/software/parallel/).
E.g. instead of:
```
find . -maxdepth 1 -name "*.tif" -print0 | while IFS= read -r -d '' n; do
    tesseract "$n" "$n" -l eng hocr
    hocr2pdf -i "$n" -n -o "$n.pdf" < "$n.html"
done
```

you can run:

```
parallel "tesseract {} {} -l eng hocr; hocr2pdf -i {} -n -o {}.pdf < {}.html" ::: *.tif
```

Note that this example is a little obsolete. You will get better results having Tesseract
produce one page PDF files in parallel, then splicing them together at the end using QPDF
or similar.
If you are running Tesseract 4, you can use the "fast" models.

Tesseract 4 also uses up to four CPU threads while processing a page, so it will be faster than Tesseract 3 for a single page. If your computer has only two CPU cores, then running four threads will slow down things significantly and it would be better to use a single thread or maybe a maximum of two threads! Using a single thread eliminates the computation overhead of multithreading and is also the best solution for processing lots of images by running one Tesseract process per CPU core. Set the maximum number of threads using the environment variable `OMP_THREAD_LIMIT`. To disable multithreading, use `OMP_THREAD_LIMIT=1`.

## Windows: tesseract closes automatically right after launching

Tesseract is a command line program, so you need to run it from the [command line](http://commandwindows.com/). If you need a program with a graphical interface, there are several available from the [3rdParty](User-Projects-%E2%80%93-3rdParty.md) page.

## What output formats can Tesseract produce?

* txt
* pdf
* hocr
* tsv
* pdf with text layer only

Tesseract can produce plain text, PDF, and HTML output. Tesseract's standard output is a plain txt file (utf-8 encoded, with '\n' as [end-of-line marker](http://en.wikipedia.org/wiki/Newline)).

With the configfile 'hocr' tesseract will produce XHTML output compliant with the [hOCR specification](https://docs.google.com/document/preview?id=1QQnIQtvdAC_8n92-LhwPcjtAUFwBlzE8EWnKAxlgVf0&pli=1) (the input image name must be ASCII if the operating system use something other than utf-8 encoding for filenames - see [issue 809](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=809) for some details).

With the configfile 'pdf' tesseract will produce searchable PDF containing pages images with a hidden, searchable text layer.

## How to interpret hOCR baseline output?

The hOCR output for the first line of eurotext.tif contains the following information:
```
<span class='ocr_line' id='line_1_1' title="bbox 105 66 823 113; baseline 0.015 -18; …
```
bbox is the bounding box of the line in image coordinates (blue). The two numbers for the baseline are the slope (1st number) and constant term (2nd number) of a linear equation describing the baseline relative to the bottom left corner of the bounding box (red). The baseline crosses the y-axis at `-18` and its slope angle is `arctan(0.015) = 0.86°`.
In general, the baseline is described by a polynomial of order `n` with the coefficients `pn … p0` with n = 1 for a linear (i.e. straight) line (see [hOCR spec](https://github.com/kba/hocr-spec/blob/master/hocr-spec.md#3-terminology-and-representation)).
![hOCR baseline](https://cloud.githubusercontent.com/assets/19879328/16414153/6a52a9d4-3d36-11e6-8b0f-ff6faf05fddd.png)

## libtesseract.so.3: cannot open shared object file

Run 'sudo ldconfig' after 'sudo make install'. See [issue 621](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=621).

## Tesseract does not work

Please ensure there is only one installation of tesseract e.g. there are reported problems (in case of shared build) if tesseract 3.01 and 3.02 are installed on the same computer. See e.g. [issue 793](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=793)

## How do I uninstall Tesseract

In the `tesseract-ocr` directory, run:
```
sudo make uninstall
```

If you installed training tools, also run:
```
sudo make training-uninstall
```

## How do I compare different versions of Tesseract

If you want to have several version of tesseract (e.g. you want to compare OCR result) I would suggest you to compile them from source (e.g. in /usr/src) and not install them. If you want to test particular version you can run it this way:

```
/usr/src/tesseract-3.03/api/tesseract eurotext.tif eurotext
/usr/src/tesseract-ocr.3.02/api/tesseract eurotext.tif eurotext
```

/usr/src/tesseract-3.03/api/tesseract is shell wrapper script, and it will take care that correct shared library is used (without installation...).

## Error in pixReadStream:

If you see this error, than you have a problem with your leptonica installation - e.g. there is missing support for your image format. Usually this means the relevant image library was not installed properly during leptonica build or there is some configure problem within leptonica.
> Please check issues
[340](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=340), [391](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=391) and [443](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=443)

## Can't open eng.unicharset?

You don't have language training data installed.
Read the [README](https://github.com/tesseract-ocr/tesseract/blob/main/README.md).

## leptonica library missing

If get this error message when you run `./configure` and your leptonica header files are located in `/usr/local/include` (e.g. you installed leptonica to `/usr/local`) than run:

```
LIBLEPT_HEADERSDIR=/usr/local/include ./configure
```

or:

```
CPPFLAGS="-I/usr/local/include" LDFLAGS="-L/usr/local/lib" ./configure
```

## Can't read compressed TIFF files

I get this error message:
```
read_tif_image:Error:Illegal image format:Compression
```

Windows (Visual C++):
Libtiff support can be added in either VC++6 or VC++Express with the following:

Go to the [Windows download for libtiff](http://gnuwin32.sourceforge.net/packages/tiff.htm) and follow these steps:
```
Download and run the setup program.
Add the paths for include and library files in tools/options/directories
Add HAVE_LIBTIFF to the preprocessor definitions.
Add libtiff.lib to the list of libraries.
Rebuild.
Put libtiff3.dll be in your path somewhere.
This is done by control panel/system/advanced/environment variables and adding c:/program files/gnuwin32/bin to PATH.
Keep your fingers crossed...
```

Non-Windows (and Cygwin): Install **libtiff-dev.** Procedure differs from OS to OS, but on many something like
```
sudo apt-get install libtiff-dev
```
or some variant thereof should do the trick, **before** running configure.

## No output with color images

There have been several bug reports of blank or garbage output with color images, both with and without libtiff. Here is the most up-to-date information (last update 23 Sep 2008):

Without libtiff, Tesseract only reads uncompressed tiff files. Even then it won't read 32 bit tiff files correctly. Will be fixed in 2.04. (Meaning that it will correctly handle most image depths (except 16 bit) with libtiff.

With libtiff, Tesseract reads compressed tiff files, but can't handle **any** color: 24 or 32 bit. It can only read 1 bit binary images or 8 bit greyscale. (No color maps!) Fixed in 2.04.

The API (TessBaseAPI) should be OK with 1, 8, 24 or 32 bit images.

## Does it support multi-page TIFF files?

Yes, with all versions 2.03 and later, as long as you have libtiff installed. See Compressed TIFF above.

## Why doesn't viewer/svutil.cpp compile?

This file is the single greatest cause of portability issues, because it is the interface to a viewer running in an external process. If you can get it to compile on your system, please report an issue logging what you had to change, but please only for the current version. If you can't get it to compile, you can define GRAPHICS\_DISABLED in your compiler (for all the source) and it will comment out all the hard-to-compile code and disable the viewer functionality, which most people don't use anyway.

On Unix-like systems, the configure script can be instructed to disable graphics like this:

```
configure --disable-graphics
```

## Where are the training tools for Ubuntu 14.04 ?

Due to an oversight, training tools do not ship with Ubuntu 14.04.
Either wait for the next Ubuntu release, or use these commands.

```
sudo apt-get build-dep tesseract-ocr
sudo apt-get install devscripts
dget http://http.debian.net/debian/pool/main/t/tesseract/tesseract_3.03.03-1.dsc
tar xvzf tesseract_3.03.03.orig.tar.gz
cd tesseract-3.03
zcat ../tesseract_3.03.03-1.diff.gz | patch -p1
debuild -us -uc
cd ..
sudo dpkg -i *.deb
```

## How do I Edit Box files used in training?

There are a variety of programs to help with this,
see [the AddOns page](../AddOns.md#tesseract-box-editors-and-training-tools).

## Utf8 buffer too big, size=xx (Error during training)

There is an upper limit of 30 bytes for the utf-8 representation of each recognizable unit (character/grapheme/glyph). It can't easily be increased. Check your box file for strangely long strings.


## How do I recognize only digits?

### Tesseract 3

Use the `digits` config file like this:
```
tesseract imagename outputbase digits
```

### Tesseract 2.03

Use
```
TessBaseAPI::SetVariable("tessedit_char_whitelist", "0123456789");
```
BEFORE calling an Init function or put this in a text file called `tessdata/configs/digits`:
```
tessedit_char_whitelist 0123456789
```
and then your command line becomes:
```
tesseract image.tif outputbase nobatch digits
```

**Warning:** In versions 2.03/2.04 (but not in version 3.00 and up), you **must** put `nobatch` before `digits`.

## How do I add just one character or one font to my favourite language, without having to retrain from scratch?

It is not possible to add just one character or font. You need to retrain from scratch.
See the Training Tesseract documentation.

## How do I produce searchable PDF output?

Searchable PDF output is a standard feature as of Tesseract version 3.03. Use the `pdf` config file like this:

```
tesseract phototest.tif phototest pdf
```

## The searchable PDF seems to contain only spaces or spaces between the letters of words

There may be nothing wrong with the PDF itself, but its hidden, searchable text layer may be not understood by your PDF reader. For example, Preview.app in Mac OS X is well known for having problems like this, and might "see" only spaces and no text. Try using Adobe Acrobat Reader instead.


## How to do streaming

Let's say you have an amazing but slow multipage scanning device. It would be
nice to OCR during scanning. In this example, the scanning program is sending
image filenames to Tesseract as they are produced. Tesseract streams a
searchable PDF to stdout. You will need Tesseract v3.04 or later for this feature.

```
scanimage --batch --batch-print | tesseract -c stream_filelist=true - - pdf > output.pdf
```


## Is there a Minimum / Maximum Text Size? (It won't read screen text!)

There is a minimum text size for reasonable accuracy. You have to consider resolution as well as point size. Accuracy drops off below 10pt x 300dpi, rapidly below 8pt x 300dpi. A quick check is to count the pixels of the x-height of your characters. (X-height is the height of the lower case x.) At 10pt x 300dpi x-heights are typically about 20 pixels, although this can vary dramatically from font to font. Below an x-height of 10 pixels, you have very little chance of accurate results, and below about 8 pixels, most of the text will be "noise removed".

Using LSTM there seems also to be a maximum x-height somewhere around 30 px. Above that, Tesseract doesn't produce accurate results. The legacy engine seems to be less prone to this (see https://groups.google.com/forum/#!msg/tesseract-ocr/Wdh_JJwnw94/24JHDYQbBQAJ).

## Why is the output empty or of poor quality?

Read the [ImproveQuality](ImproveQuality) documentation.

## How do I generate the language data files?

Read the [Training Tesseract](TrainingTesseract.md) documentation.

## How do I unpack or alter existing language data files?

Use the combine\_tessdata command. See the [combine\_tessdata manual page](https://github.com/tesseract-ocr/tesseract/blob/main/doc/combine_tessdata.1.asc) for details on its usage.

## How do I provide my own dictionary?

### Tesseract 3

To add an extra word list, create a .user-words file as explained in [tesseract(1)](https://github.com/tesseract-ocr/tesseract/blob/main/doc/tesseract.1.asc#config-files-and-augmenting-with-user-data).

If you want to replace the whole dictionary, you will need to unpack the .traineddata file, create a new word-dawg file, and then pack the files back into a .traineddata file. See [TrainingTesseract](TrainingTesseract.md) for more details.

### Tesseract 2

Easy: Replace `tessdata/eng.user-words` with your own word list, in the same format - UTF8 text, one word per line.

More difficult, but better for a large dictionary:
Replace `tessdata/eng.word-dawg` with one created from your own word list, using wordlist2dawg.
See the [Training Tesseract](TrainingTesseract.md) documentation for details.

## wordlist2dawg doesn't work!

There is a memory problem with the 2.03 wordlist2dawg. If you don't have something more than 1GB of memory, then your system grinds to a halt and it runs very slowly.
Reduce both max\_num\_edges and reserved\_edges by a factor of 10 at line 39-40 of training/wordlist2dawg.cpp and rebuild.

If you successfully create a new dawg, and then it doesn't load, due to the error:
```
Error: trying to read a DAWG '%s' that contains %d edges while the maximum is %d.
```
Then try changing the value of MAX\_NUM\_EDGES\_IN\_SQUISHED\_DAWG\_FILE in dawg.h.

## How to increase the trust in/strength of the dictionary?

For tesseract-ocr < 3.01 try upping NON\_WERD and GARBAGE\_STRING in dict/permute.cpp to maybe 3 or even 5.

For tesseract-ocr >= 3.01 try increasing the variables language\_model\_penalty\_non\_freq\_dict\_word and language\_model\_penalty\_non\_dict\_word in a config file. By default they are 0.1 and 0.15 respectively.

For tesseract-ocr 2.0x: If the text fonts you are recognizing are significantly different from your training data, and you don't mind a slow-down, you could also try lowering ClassPrunerThreshold in classify/intmatcher.cpp to about 200 from 229. These measures should all improve the power of the dictionary to resolve words from non-words.

Of course any changes that up the power of the dictionary also up the ability to hallucinate dictionary words. If this is a problem, keep short words out of your dictionary, and don't add a vast list of words that are rarely used if they increase the number of ambiguities with more frequent words.

To go the opposite way and turn off the dictionary, you can either delete the appropriate dawg(s) from the traineddata file using combine\_tessdata, or set the appropriate load\_type\_dawg parameter to false, but this must be done with a config file and the version of Init that takes a configs argument. It cannot be done by SetVariable, because the parameter is controlling initialization. type may be one of punc, system, number, bigram, freq, unambig.

## What are configs and how can I have more?

Config is an overloaded word in tesseract. One meaning is a file of [control parameters](ControlParams) used for debugging or modifying its behaviour, such as tessdata/configs/segdemo.

The other meaning is used in training and in the classifier:

A config represents a (potentially) different shape of a character from a different font. The MAX\_NUM\_CONFIGS limit applies to the number of different files on the command line of mftraining containing samples of any one character, as each file is assumed to represent a different font. There is currently (2.03) a limit of 32 configs. You can get away with more than 32 files on the mftraining command line if not all the files contain all the characters.

Other ways to fix the problem:

If files contain very similar looking samples, then you can cat them together to make a single file to reduce the total number of files. DON'T do this if the characters in two files look very different.

Increase MAX\_NUM\_CONFIGS (in [intproto.h](https://github.com/tesseract-ocr/tesseract/blob/10f4998aee3ccc68e9c4931ce744dd292ad6ff19/classify/intproto.h#L46)) There are consequences. You will make inttemp files generated with a different value of MAX\_NUM\_CONFIGS unreadable. We are working towards overcoming this weakness for version 3.0. Will not be in 2.04 though. Also, classification will be slower and use more memory.

## There are inconsistent results from tesseract when the same TessBaseAPI object is used for decoding multiple images

Try to clear the adaptive data with `ClearAdaptiveClassifier()` or turn off the adaptive classifier with config variables:
```
classify_enable_learning 0
classify_enable_adaptive_matcher 0
```

See also the discussion on the [tesseract forum](https://groups.google.com/d/topic/tesseract-ocr/ByGJhocI9qQ)

## [Diacritics](http://en.wikipedia.org/wiki/Diacritic) above and below the glyph are ignored/cause garbage output

Try to increase the default value (1.25) of textord\_min\_linesize to higher value. Some users report good results with value 2.5.

## Where is the documentation?

You're looking at it. If things aren't clear, search on the [Tesseract Google Group](http://groups.google.com/group/tesseract-ocr/) or ask us there. If you want to help us write more, please do, and post it to the group!

## How can I try the next version?

Periodically stable versions go to the downloads page. Between releases, and in particular, just before a new release, the latest code is available from git. You can find the source here: https://github.com/tesseract-ocr/tesseract.git where you can check it out either by command line, or by following the link to the howto on using various client programs and plugins.

## actual\_tessdata\_num\_entries_<= TESSDATA\_NUM\_ENTRIES:Error:Assert failed:in file ..\ccutil\tessdatamanager.cpp, line 55_

If you get an error while running **tesseract**, please check if you are using the correct version of traineddata (e.g. 3.00 with 3.01). You can not use 3.01 traineddata with tesseract 3.00.

## last\_char == '\n':Error:Assert failed:in file ..\ccutil\tessdatamanager.cpp, line 95

If you get error during running **combine\_tessdata**:

This indicates that your lang.unicharambigs is missing an empty line at the end of the file.

## Error: Illegal min or max specification

This can happen if number format ("locale" on linux or "Regional and Language Options" in Windows) is different than English format. Solution is to set your locale (in code) of LC\_NUMERIC to "C"  before calling tesseract. In some cases you need to include locale.h:
```
#include <locale.h>
setlocale (LC_NUMERIC, "C");
```

Other option is to adjust your user locale/regional settings.

See also information in issues [250](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=250) and [228](https://web.archive.org/web/20151128085645/http://code.google.com/p/tesseract-ocr/issues/detail?id=228)

## Error: X classes in inttemp while unicharset contains Y unichars.

(Where Y != X)
There are 2 possibilities:
X ~= Y, usually with X < Y: Usually caused by a failed training process. Look for FATALITY messages from the tr file generation process. Looks like the training process failed to pick up some samples of some characters, and they didn't make it into the inttemp file (in mftraining) because there was no entry in the tr file. There are bad problems with applybox that make this a problem for a lot of people. The character samples need to be spaced out.

X a wild number (very large + or -) and Y a sane number between 100 and a few thousand, depending on the language: Corrupt inttemp file, or (if you have **NOT** trained yourself) your hardware has a funny endian architecture that is not automatically detected. Big-endian or Little-endian 32 and 64 bit **SHOULD** work, but mixed endian (0x12345678 -> 0x56 0x78 0x12 0x13 or similar) will **NOT** work. Get a sensible hardware architecture, or retrain yourself. Then your inttemp will match the hardware.

## Error: Size of unicharset is greater than MAX\_NUM\_CLASSES

Just increase MAX\_NUM\_CLASSES (in dict/matchdefs.h) for your build. See issues [670](https://web.archive.org/web/*/https://code.google.com/p/tesseract-ocr/issues/detail?id=670) and [743](https://web.archive.org/web/*/https://code.google.com/p/tesseract-ocr/issues/detail?id=743)

## How can I make the error messages go to tesseract.log instead of stderr?

To restore the old behaviour of writing to tesseract.log instead of writing to the console window, you need a text file that contains this:

debug\_file tesseract.log

call the file 'logfile' and put it in tessdata/configs/
Then add logfile to the end of your command line.

## How can I suppress tesseract info line?

See [issue 579](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=579). On linux you can redirect stderr and stdout output to /dev/null. E.g.:
```
tesseract phototest.tif phototest 1>/dev/null 2>&1
```
With tesseract 3.02 you can use config "quiet". E.g.:
```
tesseract phototest.tif phototest quiet
```

**Warning:** Both options will cause you to not see the error message if there is one.

## How can I get the coordinates and confidence of each word?

There are two options. If you would rather not get into programming, you can use Tesseract's hOCR output format (read the [Tesseract manual page](https://github.com/tesseract-ocr/tesseract/blob/main/doc/tesseract.1.asc) for details). If you are comfortable programming, use the [Tesseract API](https://github.com/tesseract-ocr/tesseract/blob/main/include/tesseract/baseapi.h).

## How is confidence calculated?
* **Character** - Compute a distance measure between 0 and 1 of the character from a training sample:
  * *certainty* = -20 * distance
  * *rating* = distance * outline length
* **Word:**
  * *certainty* = min over word of character certainty.
  * *rating* = sum over word of character rating.

## Can I use Tesseract for handwriting recognition?

You can, but it won't work very well, as Tesseract is designed for printed text. Take a look at the [Lipi Toolkit](http://lipitk.sourceforge.net/) project instead.

## Can I use tesseract for barcode recognition?

No. Tesseract is for text recognition.

## Issues with older versions of tesseract
_(information from issue tracker with Status: Look-here-for-help.)_

### How to port Tesseract engine into vb6 project?

See the suggestions in [issue 42](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=42).

### Delphi wrapper for tessdll.dll

Have a look  at [Addon documentation](AddOns) or see the comments in [issue 88](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=88).

### Incomplete OCR result

See the suggestions in [issue 44](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=44).

### error LNK2001: unresolved external symbol "public: static char **cdecl TessBaseAPI::TesseractRect(unsigned char const**,int,int,int,int,int,int)" (?TesseractRect@TessBaseAPI@@SAPADPBEHHHHHH@Z)

If you are using version 2.04 and VC++ 6 add a #define TESSDLL\_IMPORTS before you include baseapi.h. (see [issue 297](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=297)

### box overlaps no blobs or blobs in multiple rows error when training

If you get this error try to use pagesegmenation value 5 or 6. E.g.:
```
tesseract input_image output -psm 6 batch.nochop makebox
```
Or have a look at other suggestions in [issue 471](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=471)

### Training failed  with error message "mf.cpp:78: FEATURE\_SET\_STRUCT\* ExtractMicros..."

See suggestions on how to improve the input image in [issue 488](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=488).

### error message: Font id = -1/0, class id = 1/105 on sample 0

This means that the font name is not in font\_properties or font\_properties does not meet [requirements](TrainingTesseract.md#Requirements_for_text_input_files)

# My question isn't in here!

Try searching the forum: http://groups.google.com/group/tesseract-ocr as your question may have come up before even if it is not listed here.
