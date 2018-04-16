# Tesseract release planning

Here we can plan the next releases of Tesseract.

## 4.0.0

That will be the next release following [4.0.0-beta.1](https://github.com/tesseract-ocr/tesseract/releases/tag/4.0.0-beta.1). It is currently scheduled for May 2018 (see [discussion](https://github.com/tesseract-ocr/tesseract/issues/1423#issuecomment-380103106)). 

See also the discussion for [issue #1423](https://github.com/tesseract-ocr/tesseract/issues/1423).

### Open issues which should be fixed

* #### Tesseract creates output for missing input (see [issue](https://github.com/tesseract-ocr/tesseract/issues/1023))

* #### mgr_.Init(traineddata_path.c_str()):Error:Assert failed: #1075 (see [issue](https://github.com/tesseract-ocr/tesseract/issues/1075))

* #### Some images translated to text using Tesseract 4 throw an error ... (see [issue](https://github.com/tesseract-ocr/tesseract/issues/1205))

* #### Remove deprecated code 
  This does not include OpenCL or the old Tesseract engine. Some recent commits already removed such code.

### Features wanted for this release

* #### Add --version parameter for all command line commands. **[done](https://github.com/tesseract-ocr/tesseract/commit/69c8292d81cbb71d6d422f79c97ef50d2a1da352)**

* #### Script for installing only selected languages from github (see [issue](https://github.com/tesseract-ocr/tesseract/issues/1440))

* #### Update langdata 
  See [discussion](https://github.com/tesseract-ocr/tesseract/issues/1423#issuecomment-380139227).

* #### Rename kur_ara traineddata files
  These traineddata files are for Kurdish written in Latin script not Arabic. See [naming suggestion](https://github.com/tesseract-ocr/langdata/issues/124#issuecomment-380770665).

### Regression of Features from 3.0x

* #### Black list / White list (See [issue](https://github.com/tesseract-ocr/tesseract/issues/751))

* #### User Words (See [comment](https://github.com/tesseract-ocr/tesseract/issues/403#issuecomment-265579471))

* #### User Patterns (See [issue](https://github.com/tesseract-ocr/tesseract/issues/960))

* #### HOCR font info (See [comment](https://github.com/tesseract-ocr/tesseract/issues/1074#issuecomment-3278142444))

### To be discussed

Depending on available resources and opinions, these suggestions will either be added to the planning for the next or a future release or abandoned.

* #### Adding a compile option NO_LEGACY_OCR_ENGINE would be nice

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

* #### Schedule date

## Future release
Here we collect important issues and features for the release(s) following 4.0.0.

* #### New LSTM-based OSD detector (see [comment](https://github.com/tesseract-ocr/tesseract/issues/707#issuecomment-374465989)).

* #### Remove Legacy Tesseract Engine (see [issue](https://github.com/tesseract-ocr/tesseract/issues/707))

* #### Better Multi-language implementation for training (See [comment](https://github.com/tesseract-ocr/langdata/issues/83#issuecomment-375027879))