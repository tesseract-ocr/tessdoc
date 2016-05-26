# Release Notes

# Introduction
This page keeps the most up-to-date release notes.

Table of Contents
=================
  * [Tesseract release notes Feb 16 2016 - V3.04.01](#tesseract-release-notes-feb-16-2016---v30401)
  * [Tesseract release notes July 11 2015 - V3.04.00](#tesseract-release-notes-july-11-2015---v30400)
  * [Tesseract release notes Feb 4 2014 - V3.03(rc1)](#tesseract-release-notes-feb-4-2014---v303rc1)
  * [Tesseract release notes Oct 23 2012 - V3.02.02](#tesseract-release-notes-oct-23-2012---v30202)
  * [Tesseract release notes Oct 21 2011 - V3.01](#tesseract-release-notes-oct-21-2011---v301)
  * [Tesseract release notes Sep 30 2010 - V3.00](#tesseract-release-notes-sep-30-2010---v300)
  * [Tesseract release notes June 30 2009 - V2.04](#tesseract-release-notes-june-30-2009---v204)
  * [Tesseract release notes April 22 2008 - V2.03](#tesseract-release-notes-april-22-2008---v203)
  * [Tesseract release notes April 21 2008 - V2.02](#tesseract-release-notes-april-21-2008---v202)
  * [Tesseract release notes Aug 30, 2007 - V2.01](#tesseract-release-notes-aug-30-2007---v201)
  * [Tesseract release notes Jul 18, 2007 - V2.00](#tesseract-release-notes-jul-18-2007---v200)
  * [Tesseract release notes May 15, 2007 - V1.04](#tesseract-release-notes-may-15-2007---v104)


# IN DEVELOPMENT
  * Use Travis CI and Appveyor Continuous Integration services.
  * Added option to build Tesseract with CMake build system.

# Tesseract release notes Feb 16 2016 - V3.04.01
  * Added OSD renderer for psm 0. Works for single page and multi-page images.
  * Improve tesstrain.sh script.
  * Simplify build and run of ScrollView.
  * Improved PDF output for OS X Preview utility.
  * INCOMPATIBLE fix to hOCR line height information - commit [134ebc3](https://github.com/tesseract-ocr/tesseract/commit/134ebc3df39cc2e144eb11575149354bf347def9).
  * Added option to build Tesseract without Cube OCR engine (-DNO_CUBE_BUILD).
  * Enable OpenMP support.

# Tesseract release notes July 11 2015 - V3.04.00
  * Tesseract development is now done with Git and hosted at github.com 
(Previously we used Subversion as a VCS and code.google.com for hosting).
  * Tesseract now requires leptonica 1.71 or a higher version.
  * Removed official support for VS 2008.
  * Major updates to training system as a result of extensive testing on 100 languages.
  * New training data for over 100 languages. Added support for 39 additional scripts/languages: amh, asm, aze_cyrl, bod, bos, ceb, cym, dzo, fas, gle, guj, hat, iku, jav, kat, kat_old, kaz, khm, kir, kur, lao, lat, mar, mya, nep, ori, pan, pus, san, sin, srp_latn, syr, tgk, tir, uig, urd, uzb, uzb_cyrl, yid.
  * Improved performance with PIC compilation option.
  * Significant change to invisible font system in pdf output to improve 
correctness and compatibility with external programs, particularly ghostscript.
  * Improved font identification.
  * Major change to improve layout analysis for heavily diacritic languages: 
Thai, Vietnamese, Kannada, Telugu etc.
  * Fixed problems with shifted baselines so recognition can recover from 
layout analysis errors.
  * Major refactor to improve speed on difficult images, especially when 
running a heap checker.
  * Moved params from global in page layout to tesseractclass.
  * Improved single column layout analysis.
  * Allow ocr output to multiple formats using tesseract command line executable.
  * Fixed issues with mixed eng+ara scripts.
  * Improved script consistency in numbers.
  * Major refactor of control.cpp to enable line recognition.
  * Added tesstrain.sh - a master training script.
  * Added ability to text2image training tool to just list available fonts.
  * Added ability to text2image to underline words.
  * Improved efficiency of image processing for PDF output.
  * Added parameter description for each parameter listed with 'print-parameters' 
command line option.
  * Added font info to hOCR output.
  * Enabled streaming input and output of multi-page documents.
  * Many bug fixes.

# Tesseract release notes Feb 4 2014 - V3.03(rc1)
  * Added OpenCL support (experimental).
  * Added new training tool text2image to generate box/tif file pairs from text and truetype fonts.
  * Added support for PDF output with searchable text.
  * Removed entire IMAGE class and all code in image directory.
  * Tesseract executable: support for output to stdout; limited support for one page images from stdin (especially on Windows)
  * Added Renderer to API to allow document-level processing and output of document formats, like hOCR, PDF.
  * Major refactor of word-level recognition, beam search, eliminating dead code.
  * Refactored classifier to make it easier to add new ones.
  * Generalized feature extractor to allow feature extraction from greyscale.
  * Improved sub/superscript treatment.
  * Improved baseline fit.
  * Added set\_unicharset\_properties to training tools.
  * Many bug fixes.
  * More training source data included.

# Tesseract release notes Oct 23 2012 - V3.02.02
  * Moved ResultIterator/PageIterator to ccmain.
  * Added Right-to-left/Bidi capability in the output iterators for Hebrew/Arabic.
  * Added paragraph detection in layout analysis/post OCR.
  * Fixed inconsistent xheight during training and over-chopping.
  * Added simultaneous multi-language capability.
  * Refactored top-level word recognition module.
  * Added experimental equation detector.
  * Improved handling of resolution from input images.
  * Blamer module added for error analysis.
  * Cleaned up externally used namespace by removing includes from baseapi.h.
  * Removed dead memory management code.
  * Tidied up constraints on control parameters.
  * Added support for ShapeTable in classifier and training.
  * Refactored class pruner.
  * Fixed training leaks and randomness.
  * Major improvements to layout analysis for better image detection, diacritic detection, better textline finding, better tabstop finding.
  * Improved line detection and removal.
  * Added fixed pitch chopper for CJK.
  * Added UNICHARSET to WERD\_CHOICE to make mult-language handling easier.
  * Fixed problems with internally scaled images.
  * Added page and bbox to string in tr files to identify source of training data better.
  * Fixes to Hindi Shiroreka splitter.
  * Added word bigram correction.
  * Reduced stack memory consumption and eliminated some ugly typedefs.
  * Added new uniform classifier API.
  * Added new training error counter.
  * Fixed endian bug in dawg reader.
  * C API (thanks to Tobias Müller)
  * New solution for VS 2008 (thanks to Tom Powers)
  * Many other fixes, including the way in which the chopper finds chops and messes with the outline while it does so.


# Tesseract release notes Oct 21 2011 - V3.01
  * Thread-safety! Moved all critical globals and statics to members of the appropriate class. Tesseract is now thread-safe (multiple instances can be used in parallel in multiple threads.) with the minor exception that some control parameters are still global and affect all threads.
  * Added `Cube`, a new **experimental** recognizer for Arabic and Hindi. Cube can also be used in combination with normal Tesseract for a few other languages with an small improvement in accuracy at the cost of much lower speed. **There is no training module for Cube.**
  * `OcrEngineMode` in `Init` replaces `AccuracyVSpeed` to control cube.
  * Greatly improved segmentation search with consequent accuracy and speed improvements, especially for Chinese.
  * Added `PageIterator` and `ResultIterator` as cleaner ways to get the full results out of Tesseract, that are not currently provided by any of the `TessBaseAPI::Get*` methods. All other methods, such as the `ETEXT_STRUCT` in particular are deprecated and will be deleted in the future.
  * ApplyBoxes totally rewritten to make training easier. It can now cope with touching/overlapping training characters, and a new boxfile format allows word boxes instead of character boxes, BUT to use that you have to have already boostrapped the language with character boxes. "Cyclic dependency" on traineddata.
  * Auto orientation and script detection added to page layout analysis.
  * Deleted **lots** of dead code.
  * Fixxht module replaced with scalable data-driven module.
  * Output font characteristics accuracy improved.
  * Removed the double conversion at each classification.
  * Upgraded oldest structs to be classes and deprecated PBLOB.
  * Removed non-deterministic baseline fit.
  * Added fixed length dawgs for Chinese.
  * Handling of vertical text improved.
  * Handling of leader dots improved.
  * Table detection greatly improved.
  * Fixed a couple of memory leaks.
  * Fixed font labels on output text. (Not perfect, but a lot better than before.)
  * Cleanup and more bug fixes
  * Special treatments for Hindi.
  * Support for build in VS2010 with Microsoft Windows SDK for Windows 7 (thanks to Michael Lutz)


# Tesseract release notes Sep 30 2010 - V3.00
  * Preparations for thread safety:
    * Changed TessBaseAPI methods to be non-static
    * Created a class hierarchy for the directories to hold instance data, and began moving code into the classes.
    * Moved thresholding code to a separate class.
  * Added major new page layout analysis module.
  * Added hOCR output.
  * Added Leptonica as main image I/O and handling. Currently optional, but in future releases linking with Leptonica will be mandatory.
  * Ambiguity table rewritten to allow definite replacements in place of fix\_quotes.
  * Added TessdataManager to combine data files into a single file.
  * Some dead code deleted.
  * VC++6 no longer supported. It can't cope with the use of templates.
  * Many more languages added.
  * Doxygenation of most of the function header comments.

# Tesseract release notes June 30 2009 - V2.04
  * Integrated patches for portability and to remove some of the "access" macros.
  * Removed dependence on lua from the viewer making it a **lot** faster. Also the viewer now compiles and works (on Linux.) Also works on windows via a pre-built ScrollView.jar.
  * Fixed the following issues: 1, 63, 67, 71, 76, 79, 81, 82, 84, 106, 108, 111, 112, 128, 129, 130, 133, 135, 142, 143, 145, 146, 147, 153, 154, 160, 165, 169, 170, 175, 177, 187, 192, 195, 199, 201, 205, 209.
  * This is the last version to support VC++6!
  * This may also be the last version to compile without leptonica!
  * Windows version now outputs to stderr by default, fixing a lot of the problems with lack of visible meaningful error messages.

# Tesseract release notes April 22 2008 - V2.03
2.02 was unrunnable, due to a last-minute "simple" change.
2.03 fixes the problem and also adds an include check for leptonica
to make it more usable.

# Tesseract release notes April 21 2008 - V2.02
  * Improvements to clustering, training and classifier.
  * Major internationalization improvements for large-character-set languages, eg Kannada.
  * Removed some compiler warnings.
  * Added multipage tiff support for training and running.
  * Updated graphics output to talk to new java-based viewer.
  * Added ability to save n-best lists.
  * Added leptonica support for more file types.
  * Improved Init/End to make them safe.
  * Reduced memory use of dictionaries.
  * Added some new APIs to TessBaseAPI.
  * Fixed namespace collisions with jpeg library (INT32).
  * Portability fixes for Windows for new code.
  * Updates to autoconf system for new code.

# Tesseract release notes Aug 30, 2007 - V2.01
(See also release notes for 2.00 below for usage information)

No major functionality change. Just a bunch of bug fixes.
  * Fixed UTF8 input problems with box file reader.
  * Fixed various infinite loops and crashes in dawg code.
  * Removed include of config\_auto.h from host.h.
  * Added automatic wctype encoding to unicharset\_extractor.
  * Fixed dawg table too full error.
  * Removed svn files from tarball.
  * Added new functions to tessdll.
  * Increased maximum utf8 string in a classification result to 8.
  * Added new functionality to TessBaseAPI for Ocropus.

No new data files for the original 6 languages. Use the files from v2.00.
There are new data files for German Fraktur (deu-f) and Brazillian Portuguese (por).

**STOP PRESS** There is a minor bug in unicharset\_extractor. Since this is only applicable to training, the main tarball is fine unless you need to run training, in which case, overwrite your unicharset\_extractor.cpp and unicharset\_extractor.exe with the ones in tesseract-2.01.patch1.tar.gz.

# Tesseract release notes Jul 18, 2007 - V2.00
(See also release notes for 1.04 below for additional usage information)

First release of the International version.
This version recognizes the following languages:
  * English - eng
  * French  - fra
  * Italian - ita
  * German  - deu
  * Spanish - spa
  * Dutch   - nld

The language codes follow ISO 639-2. The default language is English.
To recognize another language:
```
tesseract inputimage outputbase -l langcode
```

To train on a new language, see [TrainingTesseract2](https://github.com/tesseract-ocr/tesseract/wiki/TrainingTesseract2).
More languages will be appearing over time.

List of changes in this release:
  * Converted internal character handling to UTF8.
  * Trained with 6 languages.
  * Added unicharset\_extractor, wordlist2dawg.
  * Added boxfile creation mode.
  * Added UNLV regression test capability.
  * Fixed problems with copyright and registered symbols.
  * Fixed extern "C" declarations problem.
  * Made some improvements to consistency of accuracy across platforms.
  * Added vc++ express support.

**Warning:** Tesseract 2.00 has undergone more compatibility testing than any previous version. There have even been fixes to make the accuracy more consistent across platforms. Having said that, there have been many changes to the code, and portability may have been broken, so 64 bit and Mac platforms may not work or even build as well as before.


# Tesseract release notes May 15, 2007 - V1.04

**Windows users only**

Added a dll interface for windows. Thanks to Glen at Jetsoft for contributing
this. To use the dll, include tessdll.h, import tessdll.lib and put tessdll.dll
somewhere where the system can find it. There is also a small dlltest program
to test the dll. Run with:
```
dlltest phototest.tif phototest.txt
```
It will output the text from phototest.tif with bounding box information.

**New for Windows**

The distribution now includes tesseract.exe and tessdll.dll
which **might** work out of the box! There are no guarantees as you need
VC++6 versions of mfc and crt (at least) for it to work. (Batteries not
included, and certainly no installshield.)

**Important note for anyone building with make: i.e. anyone except devstudio
users**

This release includes new standardization for the data directory. To enable
Tesseract to find its data files, you must either:
```
./configure
make
make install
```
to move the data files to the standard place, or:
```
export TESSDATA_PREFIX="directory in which your tessdata resides/"
```
(or equivalent) in your .profile or whatever or setenv to set the environment
variable. Note that the directory must end in a /

**HAVING tesseract and tessdata IN THE SAME DIRECTORY DOES NOT WORK ANY MORE.**

**All users**

Fixed a bunch of name collisions - mostly with stl.
Made some preliminary changes for unicode compatibility. Includes a new data
file (unicharset) and renaming of the other data files to eng.**to support
different languages.
There are also several other minor bug fixes and portability improvements
for 64 bit, the latest visual studio compiler etc. Thanks to all who have
contributed these fixes.**

NOTE: This is likely to be the last English-only release!
Apologies in advance to non-windows users for bloating the distribution with
windows executables. This will probably get fixed in the next release with
the multi-language capability, since that will also bloat the distribution.