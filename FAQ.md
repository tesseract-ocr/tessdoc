# Frequently Asked Questions

# Tesseract FAQs

A collection of frequently asked questions and the answers, or pointers to them. If you have question, please post it to forums. Wiki comments are for wiki commenting and not for Troubleshooting.

# Rules and advices

  * If you found a bug - please create issue: Please make sure you are able to replicate problem with tesseract executables on Linux or Windows. For other platforms or external/your programs (including tesseract wrappers) please use tesseract forums.
  * Use the latest official release (optionally: try to check if problem is not solved in svn version).
  * Don't mix tesseracts version language files.
  * If you have a question - put it to tesseract [user](http://groups.google.com/group/tesseract-ocr/) or [developer](http://groups.google.com/group/tesseract-dev/) forum.
  * Do not ask for support in comments - it will be deleted.
  * Post example files e.g. if you have problem with training. Just posting error messages is not sufficient if you used input file. Source of problem is hidden in input files usually.
  * Do not post programs or libraries (e.g. program for editing box files) - post link where they can be downloaded
  * Try to find optimal format for example images - 20Mb image is not helpful. Multi-page tiff useful only in case you have problem with multi-page functionality. E.g. 2 colour png provide same information as truecolour uncompressed tiff (tesseract will convert it to 2 colours anyway).
  * Copy error message from terminal/console/command line windows (yes, it is possible on windows too) instead of sending screen-shot.
  * Read wiki, search issues (also closed), search in tesseract forum before you post your issues/question. Maybe it was solved already.

# What is the description of issue statutes?

### Open Statuses

| **Status** | **Description** |
|:-----------|:----------------|
| New        | Issues has not had initial review yet |
| Accepted   | Problem reproduced / Need acknowledged |
| Started    | Work on this issue has begun |
| Look-here-for-help | Read this if you have the same problem! |

### Closed Statuses

| **Status** | **Description** |
|:-----------|:----------------|
| Fixed      | Developer made requested changes, QA should verify |
| Verified   | QA has verified that the fix worked |
| Invalid    | This was not a valid issue report |
| Duplicate  | This report duplicates an existing issue |
| WontFix    | We decided to not take action on this issues |
| WorksForMe | Can't reproduce the bug |
| No-Longer-an-issue | Problem went away as solution was already found |

# Can I increase speed of OCR?

If you are processing several  images you can run tesseract in parallel with [GNU Parallel](http://www.gnu.org/software/parallel/).
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


# Windows: tesseract closes automatically right after launching

Tesseract is a command line program, so you need to run it from the [command line](http://commandwindows.com/). If you need program with a graphical interface there are several available from the [3rdParty](http://code.google.com/p/tesseract-ocr/wiki/3rdParty#GUI) page.

# What output formats can Tesseract produce?

Tesseract's standard output is plain txt file (utf-8 encoded, with '\n' as [end-of-line marker](http://en.wikipedia.org/wiki/Newline)).

With the configfile 'hocr' tesseract will produce xhtml output compliant with [hocr specification](https://docs.google.com/document/preview?id=1QQnIQtvdAC_8n92-LhwPcjtAUFwBlzE8EWnKAxlgVf0&pli=1) (the input image name must be ASCII if operation system use other than utf-8 encoding for filesystem names - see [issue 809](http://code.google.com/p/tesseract-ocr/issues/detail?id=809) for some details).

# libtesseract.so.3: cannot open shared object file

Run 'sudo ldconfig' after 'sudo make install'. See [issue 621](http://code.google.com/p/tesseract-ocr/issues/detail?id=621).

# Tesseract does not work

Please ensure there is only one installation of tesseract e.g. there are reported problems(in case of shared build) if tesseract 3.01 and 3.02 are installed on the same computer. See e.g. [issue 793](http://code.google.com/p/tesseract-ocr/issues/detail?id=793)

# Error in pixReadStream:

If you see this error, than you have problem with leptonica installation - e.g. there is missing support for your image format. Usually needed image library was not installed properly during leptonica build or there is some configure problem within leptonica.
> Please check issues
[340](http://code.google.com/p/tesseract-ocr/issues/detail?id=340), [391](http://code.google.com/p/tesseract-ocr/issues/detail?id=391) and [443](http://code.google.com/p/tesseract-ocr/issues/detail?id=443)

# Can't open eng.unicharset?

You don't have language training data installed. Read the [ReadMe](https://github.com/tesseract-ocr/tesseract/blob/master/README.md) wiki page.

# leptonica library missing

If get this error message when you run `./configure` and your leptonica header files are located in `/usr/local/include` (e.g. you installed leptonica to `/usr/local`) than run:

```
LIBLEPT_HEADERSDIR=/usr/local/include ./configure
```

or:

```
CPPFLAGS="-I/usr/local/include" LDFLAGS="-L/usr/local/lib" ./configure
```

# Can't read compressed Tiff files

I get this error message:
```
read_tif_image:Error:Illegal image format:Compression
```

Windows (Visual C++):
Libtiff support can be added in either VC++6 or VC++Express with the following:

Goto the [Windows download for libtiff](http://gnuwin32.sourceforge.net/packages/tiff.htm) and follow these steps:
```
Download and run the setup program.
Add the paths for include and library files in tools/options/directories
Add HAVE_LIBTIFF to the preprocessor definitions.
Add libtiff.lib to the list of libraries.
Rebuild.
Make libtiff3.dll be in your path somewhere.
This is done by control panel/system/advanced/environment variables and adding c:/program files/gnuwin32/bin to PATH.
Keep your fingers crossed...
```

Non-Windows (and Cygwin): Install **libtiff-dev.** Procedure differs from OS to OS, but on many something like
```
sudo apt-get install libtiff-dev
```
or some variant thereof should do the trick, **before** running configure.


# Can I use tesseract for barcode recognition?

No. Tesseract is for text recognition.

# No output with color images

There have been several bug reports of blank or garbage output with color images, both with and without libtiff. Here is the most up-to-date information (last update 23 Sep 2008):

Without libtiff, Tesseract only reads uncompressed tiff files. Even then it won't read 32 bit tiff files correctly. Will be fixed in 2.04. (Meaning that it will correctly handle most image depths (except 16 bit) with libtiff.

With libtiff, Tesseract reads compressed tiff files, but can't handle **any** color: 24 or 32 bit. It can only read 1 bit binary images or 8 bit greyscale. (No color maps!) Fixed in 2.04.

The API (TessBaseAPI) should be OK with 1, 8, 24 or 32 bit images.

# Does it support multi-page tiff files?

Only with 2.03 and later, and only if you have libtiff installed. See Compressed Tiff above.

# Why doesn't viewer/svutil.cpp compile?

This file is the single greatest cause of portability issues, because it is the interface to a viewer running in an external process. If you can get it to compile on your system, please report an issue logging what you had to change, but please only for the current version. If you can't get it to compile, you can define GRAPHICS\_DISABLED in your compiler (for all the source) and it will comment out all the hard-to-compile code and disable the viewer functionality, which most people don't use anyway.

On Unix-like systems, the configure script can be instructed to disable graphics like this:

```
configure --disable-graphics
```

# Where are the training tools for Ubuntu 14.04 ?

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

# How do I Edit Box files used in training?

There are a variety of programs to help with this, see [the AddOns page](AddOns#Tesseract_box_editors_and_traning_tools).

# Utf8 buffer too big, size=xx (Error during training)

There is an upper limit of 30 bytes for the utf-8 representation of each recognizable unit (character/grapheme/glyph). It can't easily be increased. Check your box file for strangely long strings.


# How do I recognize only digits?

## Tesseract 2.03

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
**Warning:** Until the old and new config variables get merged, you **must** have the `nobatch` parameter too.

## Tesseract 3

A digits config file is already created, so just run a tesseract command like this:
```
tesseract imagename outputbase digits
```


# How do I add just one character or one font to my favourite language, without having to retrain from scratch?

There not possible to add just one character or font. You need to retrain from scratch. See the TrainingTesseract wiki.

# How do I produce searchable PDF output?

Searchable PDF output is a standard feature as of Tesseract version 3.03.

```
tesseract phototest.tif phototest pdf
```


# Is there a Minimum Text Size? (It won't read screen text!)

There is a minimum text size for reasonable accuracy. You have to consider resolution as well as point size. Accuracy drops off below 10pt x 300dpi, rapidly below 8pt x 300dpi. A quick check is to count the pixels of the x-height of your characters. (X-height is the height of the lower case x.) At 10pt x 300dpi x-heights are typically about 20 pixels, although this can vary dramatically from font to font. Below an x-height of 10 pixels, you have very little chance of accurate results, and below about 8 pixels, most of the text will be "noise removed".

# Why is the output is empty or of poor quality?

Read the [ImproveQuality](ImproveQuality) wiki page.

# How do I generate the language data files?

Read the [TrainingTesseract](TrainingTesseract) wiki page.

# How do I unpack or alter existing language data files?

Use the combine\_tessdata command. See the [combine\_tessdata manual page](http://tesseract-ocr.googlecode.com/svn-history/trunk/doc/combine_tessdata.1.html) for details on its usage.

# How do I provide my own dictionary?

## Tesseract 2

Easy: Replace `tessdata/eng.user-words` with your own word list, in the same format - UTF8 text, one word per line.

More difficult, but better for a large dictionary: Replace `tessdata/eng.word-dawg` with one created from your own word list, using wordlist2dawg. See the [TrainingTesseract](TrainingTesseract) wiki page for details.

## Tesseract 3

To add an extra word list, create a .user-words file as explained in [tesseract(1)](http://tesseract-ocr.googlecode.com/svn/trunk/doc/tesseract.1.html#_config_files_and_augmenting_with_user_data).

If you want to replace the whole dictionary, you will need to unpack the .traineddata file, create a new word-dawg file, and then pack the files back into a .traineddata file. See [TrainingTesseract](TrainingTesseract) for more details.


# wordlist2dawg doesn't work!

There is a memory problem with the 2.03 wordlist2dawg. If you don't have something more than 1GB of memory, then your system grinds to a halt and it runs very slowly.
Reduce both max\_num\_edges and reserved\_edges by a factor of 10 at line 39-40 of training/wordlist2dawg.cpp and rebuild.

If you successfully create a new dawg, and then it doesn't load, due to the error:
```
Error: trying to read a DAWG '%s' that contains %d edges while the maximum is %d.
```
Then try changing the value of MAX\_NUM\_EDGES\_IN\_SQUISHED\_DAWG\_FILE in dawg.h.

# How to increase the trust in/strength of the dictionary?

For tesseract-ocr < 3.01 try upping NON\_WERD and GARBAGE\_STRING in dict/permute.cpp to maybe 3 or even 5.

For tesseract-ocr >= 3.01 try increasing the variables language\_model\_penalty\_non\_freq\_dict\_word and language\_model\_penalty\_non\_dict\_word in a config file. By default they are 0.1 and 0.15 respectively.

For tesseract-ocr 2.0x: If the text fonts you are recognizing are significantly different from your training data, and you don't mind a slow-down, you could also try lowering ClassPrunerThreshold in classify/intmatcher.cpp to about 200 from 229. These measures should all improve the power of the dictionary to resolve words from non-words.

Of course any changes that up the power of the dictionary also up the ability to hallucinate dictionary words. If this is a problem, keep short words out of your dictionary, and don't add a vast list of words that are rarely used if they increase the number of ambiguities with more frequent words.

To go the opposite way and turn off the dictionary, you can either delete the appropriate dawg(s) from the traineddata file using combine\_tessdata, or set the appropriate load\_type\_dawg parameter to false, but this must be done with a config file and the version of Init that takes a configs argument. It cannot be done by SetVariable, because the parameter is controlling initialization. type may be one of punc, system, number, bigram, freq, unambig.

# What are configs and how can I have more?

Config is an overloaded word in tesseract. One meaning is a file of [control parameters](ControlParams) used for debugging or modifying its behaviour, such as tessdata/configs/segdemo.

The other meaning is used in training and in the classifier:

A config represents a (potentially) different shape of a character from a different font. The MAX\_NUM\_CONFIGS limit applies to the number of different files on the command line of mftraining containing samples of any one character, as each file is assumed to represent a different font. There is currently (2.03) a limit of 32 configs. You can get away with more than 32 files on the mftraining command line if not all the files contain all the characters.

Other ways to fix the problem:

If files contain very similar looking samples, then you can cat them together to make a single file to reduce the total number of files. DON'T do this if the characters in two files look very different.

Increase MAX\_NUM\_CONFIGS (in classify/intproto.h) There are consequences. You will make inttemp files generated with a different value of MAX\_NUM\_CONFIGS unreadable. We are working towards overcoming this weakness for version 3.0. Will not be in 2.04 though. Also, classification will be slower and use more memory.

# There are inconsistent results from tesseract when the same TessBaseAPI object is used for decoding multiple images

Try to clean adaptive data with `ClearAdaptiveClassifier()` or turn off adaptive classifier with config variables:
```
classify_enable_learning 0
classify_enable_adaptive_matcher 0
```

See also discussion on [tesseract forum](https://groups.google.com/d/topic/tesseract-ocr/ByGJhocI9qQ)

# [Diacritics](http://en.wikipedia.org/wiki/Diacritic) above and below glyph are ignored/cause garbage output

Try to increase default value (1.25) of textord\_min\_linesize to higher value. Some users report good results with value 2.5.

# Where is the documentation?

You're looking at it. If things aren't clear, search on the [Tesseract Google Group](http://groups.google.com/group/tesseract-ocr/) or ask us there. If you want to help us write more, please do, and post it to the group!

# How can I try the next version?

Periodically stable versions go to the downloads page. Between releases, and in particular, just before a new release, the latest code is available from svn. You can find the source here: http://code.google.com/p/tesseract-ocr/source/checkout where you can check it out either by command line, or by following the link to the howto on using various client programs and plugins.

# actual\_tessdata\_num\_entries_<= TESSDATA\_NUM\_ENTRIES:Error:Assert failed:in file ..\ccutil\tessdatamanager.cpp, line 55_

If you get error during running **tesseract**, please check if you use correct version of traineddata (e.g. 3.00 with 3.01). You can not use 3.01 traineddata with tesseract 3.00.

# last\_char == '\n':Error:Assert failed:in file ..\ccutil\tessdatamanager.cpp, line 95

If you get error during running **combine\_tessdata**:

This indicates your lang.unicharambigs is missing empty line at the end of file.

# Error: Illegal min or max specification

This can happend if number format ("locale" on linux or "Regional and Language Options" in Windows) is different than English format. Solution is to set your locale (in code) of LC\_NUMERIC to "C"  before calling tesseract. In some cases you need to include locale.h:
```
#include <locale.h>
setlocale (LC_NUMERIC, "C");
```

Other option is to adjust your user locale/regional settings.

See also information in issues [250](http://code.google.com/p/tesseract-ocr/issues/detail?id=250) and [228](http://code.google.com/p/tesseract-ocr/issues/detail?id=228)

# Error: X classes in inttemp while unicharset contains Y unichars.

(Where Y != X)
There are 2 possibilities:
X ~= Y, usually with X < Y: Usually caused by a failed training process. Look for FATALITY messages from the tr file generation process. Looks like the training process failed to pick up some samples of some characters, and they didn't make it into the inttemp file (in mftraining) because there was no entry in the tr file. There are bad problems with applybox that make this a problem for a lot of people. The character samples need to be spaced out.

X a wild number (very large + or -) and Y a sane number between 100 and a few thousand, depending on the language: Corrupt inttemp file, or (if you have **NOT** trained youself) your hardware has a funny endian architecture that is not automatically detected. Big-endian or Little-endian 32 and 64 bit **SHOULD** work, but mixed endian (0x12345678 -> 0x56 0x78 0x12 0x13 or similar) will **NOT** work. Get a sensible hardware architecture, or retrain yourself. Then your inttemp will match the hardware.

# Error: Size of unicharset is greater than MAX\_NUM\_CLASSES

Just increase MAX\_NUM\_CLASSES (in dict/matchdefs.h) for your build. See issues [670](https://code.google.com/p/tesseract-ocr/issues/detail?id=670) and [743](https://code.google.com/p/tesseract-ocr/issues/detail?id=743)

# How can I make the error messages go to tesseract.log instead of stderr?

To restore the old behaviour of writing to tesseract.log instead of writing to the console window, you need a text file that contains this:

debug\_file tesseract.log

call the file 'logfile' and put it in tessdata/configs/
Then add logfile to the end of your command line.

# How can I supress tesseract info line?

See [issue 579](http://code.google.com/p/tesseract-ocr/issues/detail?id=579). On linux you can redirect stderr and stdout output to /dev/null. E.g.:
```
tesseract phototest.tif phototest 1>/dev/null 2>&1
```
With tesseract 3.02 you can use config "quiet". E.g.:
```
tesseract phototest.tif phototest quiet
```

**Warning:** Both options will cause that you will not see error message if there is any.

# How can I get the coordinates and confidence of each character?

There are two options. If you would rather not get into programming, you can use Tesseract's hocr output format (read the [Tesseract manual page](http://tesseract-ocr.googlecode.com/svn-history/trunk/doc/tesseract.1.html) for details). If you are comfortable programming, use the [Tesseract API](http://code.google.com/p/tesseract-ocr/source/browse/trunk/api/baseapi.h).


# Issues with older versions of tesseract
_(informations from issue tracker with Status: Look-here-for-help.)_

## How to port Tesseract engine into vb6 project?

See suggestions in [issue 42](http://code.google.com/p/tesseract-ocr/issues/detail?id=42).

## Delphi wrapper for tessdll.dll

Have a look  at [Addon Wiki](AddOns) or see comments in [issue 88](http://code.google.com/p/tesseract-ocr/issues/detail?id=88).

## In-complete OCR result

See suggestions in [issue 44](http://code.google.com/p/tesseract-ocr/issues/detail?id=44).

## error LNK2001: unresolved external symbol "public: static char **cdecl TessBaseAPI::TesseractRect(unsigned char const**,int,int,int,int,int,int)" (?TesseractRect@TessBaseAPI@@SAPADPBEHHHHHH@Z)

If you are using version 2.04 and VC++ 6 add a #define TESSDLL\_IMPORTS before you include baseapi.h. (see [issue 297](http://code.google.com/p/tesseract-ocr/issues/detail?id=297)

## box overlaps no blobs or blobs in multiple rows error when training

If you get this error try to use pagesegmenation value 5 or 6. E.g.:
```
tesseract input_image output -psm 6 batch.nochop makebox
```
Or have a look at other suggestions in [issue 471](http://code.google.com/p/tesseract-ocr/issues/detail?id=471)

## Training failed  with error message "mf.cpp:78: FEATURE\_SET\_STRUCT**ExtractMicros..."**

See suggestions how to improve input image in [issue 488](http://code.google.com/p/tesseract-ocr/issues/detail?id=488).

## error message: Font id = -1/0, class id = 1/105 on sample 0

This means that font name is not in font\_properties or font\_properties does not meet [requirements](TrainingTesseract#Requirements_for_text_input_files)

# Can I use Tesseract for handwriting recognition?

You can, but it won't work very well, as Tesseract is designed for printed text. Take a look at the [Lipi Toolkit](http://lipitk.sourceforge.net/) project instead.

# My question isn't in here!

Try searching the forum: http://groups.google.com/group/tesseract-ocr as your question may have come up before even if it is not listed here.