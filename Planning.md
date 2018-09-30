# Tesseract release planning

Here we can plan the next releases of Tesseract.

## 4.0.0

That will be the next release. 

See also the discussion for [issue #1423](https://github.com/tesseract-ocr/tesseract/issues/1423).

### Open issues which should be fixed

* #### Issues with the "bug" label (see [list here](https://github.com/tesseract-ocr/tesseract/labels/bug))

* #### Segmentation fault when training from .lstm extracted from tessdata/eng.traineddata [Issue 1573](https://github.com/tesseract-ocr/tesseract/issues/1573)

* #### Report a warning when the Tesseract initialisation code detects an unsupported locale setting. (See [comment](https://github.com/tesseract-ocr/tesseract/issues/1010#issuecomment-379208967))

* #### Segfault on using -psm 0 when using fast eng.traineddata [Issue 1167](https://github.com/tesseract-ocr/tesseract/issues/1167)

* #### combine_lang_model does not print correct usage help [Issue 1375](https://github.com/tesseract-ocr/tesseract/issues/1375)

* #### Insufficient error message when output file cannot be created [Issue 1424](https://github.com/tesseract-ocr/tesseract/issues/1424)

* #### “no best words!!” on mixed language (fra+ara) items (see [issue 235](https://github.com/tesseract-ocr/tesseract/issues/235))

* #### mgr_.Init(traineddata_path.c_str()):Error:Assert failed: #1075 (see [issue 1075](https://github.com/tesseract-ocr/tesseract/issues/1075))

* #### Some images translated to text using Tesseract 4 throw an error ... (see [issue 1205](https://github.com/tesseract-ocr/tesseract/issues/1205))

### Features wanted for this release

* #### Script for installing only selected languages from github (see [issue](https://github.com/tesseract-ocr/tesseract/issues/1440))

### To be discussed

Depending on available resources and opinions, these suggestions will either be added to the planning for the next or a future release or abandoned.

* #### Enhance --list-langs to show additional information for scripts and languages like legacy / LSTM, version <br/>
  This will make the command slower, because each file must be opened and parsed. Add this as --list-langs-details or as --list-lang-details for one language file based on lang-code?

* #### --list-langs should also display the directory it is using

* #### Fix the autotools build so that the debug mode uses -O0 as intended

* #### Add option to optionally select implementation for dot product (CPU, SSE, AVX, ...)

* #### Relative includes for traineddata 
  tessedit_load_sublangs should search for the sublangs relative to the parent, not starting in tessdata dir.

* #### More fixes for compiler warnings and issues reported by Coverity Scan

* #### Add a simple bash script for building tesseract

* #### New traineddata format 
  In addition to the current proprietary format Tesseract could also support ZIP archives (see [discussion](https://github.com/tesseract-ocr/tesseract/pull/911)).
A possible implementation using libarchive is [available](https://github.com/stweil/tesseract/tree/libarchive), but needs more testing.

* #### "Training light" - Learning by doing (see [issue](https://github.com/tesseract-ocr/tesseract/issues/1442))

* #### Modify text2image to use PrepareDistortedPix() [#1052](https://github.com/tesseract-ocr/tesseract/issues/1052)

* #### Schedule date

### Regression of features from 3.0x

Tesseract 4.0 should be a full replacement for Tesseract 3.05 and have the same features when used with the old OCR engine (`--oem 0`). The following regressions still need verification (are they really regressions, or are they just missing features for LSTM):

* #### User Words (See [comment](https://github.com/tesseract-ocr/tesseract/issues/403#issuecomment-265579471))

* #### User Patterns (See [issue](https://github.com/tesseract-ocr/tesseract/issues/960))

### Features from 3.0x which are missing for LSTM

These features still work with the old OCR engine (`--oem 0`), but are missing and desired for LSTM.

* #### Black list / White list (See [issue](https://github.com/tesseract-ocr/tesseract/issues/751)). Here is a [workaround](https://github.com/tesseract-ocr/tesseract/issues/751#issuecomment-333904808).

* #### hOCR font info (See [comment](https://github.com/tesseract-ocr/tesseract/issues/1074#issuecomment-3278142444))

## Future release
Here we collect important issues and features for the release(s) following 4.0.0.

* #### New LSTM-based OSD detector (see [comment](https://github.com/tesseract-ocr/tesseract/issues/707#issuecomment-374465989)).

* #### Remove Legacy Tesseract Engine (see [issue](https://github.com/tesseract-ocr/tesseract/issues/707))

* #### Better Multi-language implementation for training (See [comment](https://github.com/tesseract-ocr/langdata/issues/83#issuecomment-375027879))

* #### ARM SIMD support for dot product [#519](https://github.com/tesseract-ocr/tesseract/issues/519)

* #### Using OpenMP for dot product [#983](https://github.com/tesseract-ocr/tesseract/issues/983)

* #### Remove deprecated code 
  This does not include OpenCL or the old Tesseract engine.

* #### Tesseract creates output for missing input (see [issue 1023](https://github.com/tesseract-ocr/tesseract/issues/1023)).
  Mostly solved, but could be improved.


* ####  Issue 1353: Patch for /training/tessopt.cpp (see [pull request 13](https://github.com/tesseract-ocr/tesseract/pull/13))
  It looks like it is not possible to run more than one training in the same process. The pull request describes a possible fix, but does not include a complete implementation (low priority).