# Tesseract release planning

Here we can plan the next releases of Tesseract.

## Future releases

Here are some ideas for future Tesseract releases.

* Modernize the code using C++11 (see discussions [here](https://github.com/tesseract-ocr/tesseract/pull/2000#issuecomment-431023531) and [here](https://github.com/tesseract-ocr/tesseract/commit/69a2e94bc52b57ba26081fb43051dacf2fdc56a0)).

* Use llvm's tools: clang-format, clang-tidy, scan-build, sanitizers.

* Replace more Tesseract data types by C++ standard types (`GenericVector`, ...), especially for the API.

* Add json (or xml) output format. It will be used for full ocr and for psm 2 - layout info only.

* Add option to use alternative binarization methods from leptonica.

* Add an option to output separate files for multipage input (out1.hocr, out2.hocr ...).

* Add multi-threading option to the command line (openmp will be disabled at runtime in this mode).

* Explore the option to use Protocol Buffers or FlatBuffers for the traineddata.

* Improve error handling and don't ignore return values from functions (see [discussion](https://github.com/tesseract-ocr/tesseract/issues/99)).

* Replace tprintf etc. by advanced logging API with log levels.

## 5.0.0

### Advanced logging

Requirements (see also [discussion](https://groups.google.com/forum/?utm_medium=email&utm_source=footer#!topic/tesseract-dev/T5esnseEIOM)):

Log levels:

* trace
* debug
* info
* warning
* error
* fatal

Related issues:

* https://github.com/tesseract-ocr/tesseract/issues/1338

Useful links:

* [List of Open Source C++ logging libraries](https://en.cppreference.com/w/cpp/links/libs)

## 4.0.0

See the [release notes](ReleaseNotes.md).

See also the discussion for [issue #1423](https://github.com/tesseract-ocr/tesseract/issues/1423).


### Open issues which should be fixed

* #### Issues with the "bug" label (see [list here](https://github.com/tesseract-ocr/tesseract/labels/bug))

* #### Noise characters recognized with bbox as the entire page [#1192](https://github.com/tesseract-ocr/tesseract/issues/1192)

* #### Segmentation fault when using integer models for LSTM training [#1573](https://github.com/tesseract-ocr/tesseract/issues/1573)

* #### Report a warning when the Tesseract initialisation code detects an unsupported locale setting. (See [comment](https://github.com/tesseract-ocr/tesseract/issues/1010#issuecomment-379208967))

* #### Insufficient error message when output file cannot be created [Issue 1424](https://github.com/tesseract-ocr/tesseract/issues/1424)

* #### “no best words!!” on mixed language (fra+ara) items (see [issue 235](https://github.com/tesseract-ocr/tesseract/issues/235))

* #### mgr_.Init(traineddata_path.c_str()):Error:Assert failed: #1075 (see [issue 1075](https://github.com/tesseract-ocr/tesseract/issues/1075))


### Features wanted for this release

* #### Script for installing only selected languages from github (see [issue](https://github.com/tesseract-ocr/tesseract/issues/1440))
  https://github.com/zdenop/tessdata_downloader


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

[Fixed in 4.1.0](https://github.com/tesseract-ocr/tesseract/pull/2328)


### Features from 3.0x which are missing for LSTM

These features still work with the old OCR engine (`--oem 0`), but are missing and desired for LSTM.

* ~~#### Black list / White list (See [issue](https://github.com/tesseract-ocr/tesseract/issues/751)). Here is a [workaround](https://github.com/tesseract-ocr/tesseract/issues/751#issuecomment-333904808).~~ [Fixed in 4.1.0](https://github.com/tesseract-ocr/tesseract/pull/2294).

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

