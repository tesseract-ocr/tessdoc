# Tesseract User Manual

This user manual is for Tesseract versions `4.x.x` and `5.0.0.x`. For versions `3.05.02` and older, see the [documentation for old versions](OldVersionDocs.md).

## Introduction

Tesseract is an open source [text recognition (OCR)](https://en.wikipedia.org/wiki/Optical_character_recognition) Engine, available under the [Apache 2.0 license.](http://www.apache.org/licenses/LICENSE-2.0).
* The current official release is [4.1.1](https://github.com/tesseract-ocr/tesseract/releases/tag/4.1.1).
* The [master branch on Github](https://github.com/tesseract-ocr/tesseract.git) can be used by those who want the latest code for LSTM (--oem 1) and legacy (--oem 0) Tesseract. The master branch is using 5.0.0 versioning because code modernization caused API compatibility issues with 4.x release.
* The [3.05 branch on GitHub](https://github.com/tesseract-ocr/tesseract/tree/3.05) can be used by those who want the bug fixes for [3.05.02](https://github.com/tesseract-ocr/tesseract/releases/tag/3.05.02) release for legacy Tesseract.

Tesseract can be used directly via command line, or (for programmers) using an [API](https://github.com/tesseract-ocr/tesseract/blob/master/include/tesseract/baseapi.h) to extract printed text from images. It supports a [wide variety of languages](Data-Files-in-different-versions.md). Tesseract doesn't have a built-in GUI, but there are several available from the [3rdParty](User-Projects-–-3rdParty.md) page.

Tesseract can be used in your own project, under the terms of the [Apache License 2.0.](http://www.apache.org/licenses/LICENSE-2.0) It has a fully featured API, and can be compiled for a variety of targets including Android and the iPhone. See the [3rdParty](User-Projects-–-3rdParty.md) page for a sample of what has been done with it.

If you have a question, first read the [documentation](https://tesseract-ocr.github.io/), 
particularly the **[FAQ](FAQ.md)** to see if your problem is addressed there. 
If not, search the [Issues List](https://github.com/tesseract-ocr/tesseract/issues), 
[Tesseract user forum](http://groups.google.com/group/tesseract-ocr) and 
[Tesseract developer forum](http://groups.google.com/group/tesseract-dev), 
and if you still can't find what you need, please ask a question in 
[Tesseract user forum Google group](http://groups.google.com/group/tesseract-ocr).

Also, Tesseract is free software, so if you want to pitch in and help, please do!
If you find a bug and fix it yourself, the best thing to do is to attach the patch to your bug report in the [Issues List](https://github.com/tesseract-ocr/tesseract/issues).

## Releases and Changelog

- [Release Planning](Planning.md)
- [API/ABI changes review for Tesseract](https://abi-laboratory.pro/?view=timeline&l=tesseract)
- [Downloads](Downloads.md)
- [Releases](https://github.com/tesseract-ocr/tesseract/releases)
- [Release Notes](ReleaseNotes.md)
- [Changelog](https://github.com/tesseract-ocr/tesseract/blob/master/ChangeLog)
- [4.0x-Changelog](4.0x-Changelog.md)

## 4.0 with LSTM

Tesseract **4.0x+** added a new OCR engine based on LSTM neural networks. It initially works (well) on x86/Linux with official Language Model data available for [100+ languages and 35+ scripts](Data-Files-in-different-versions.md). For detailed information about the different types of models, see [Data Files](Data-Files.md).

Model files for version `4.00` are available from [tessdata tagged 4.00](https://github.com/tesseract-ocr/tessdata/releases/tag/4.00). It has models from November 2016. The individual language file links are available from the following link.
- [tessdata 4.00 November 2016](https://github.com/tesseract-ocr/tessdoc/blob/master/Data-Files.md#data-files-for-version-400-november-29-2016)

Model files for version `4.0.0` and later are available from [tessdata tagged 4.0.0](https://github.com/tesseract-ocr/tessdata/releases/tag/4.0.0). It has legacy models from September 2017 that have been updated with Integer versions of `tessdata_best` LSTM models. This set of traineddata files has support for both the legacy recognizer with `--oem 0` and for LSTM models with `--oem 1`. These models are available from the following Github repo.
- [tessdata](https://github.com/tesseract-ocr/tessdata)

Two more sets of `official` traineddata, trained at Google, are made available in the following Github repos. These do not have the legacy models and only have LSTM models usable with `--oem 1`.

- [tessdata_best](https://github.com/tesseract-ocr/tessdata_best)
- [tessdata_fast](https://github.com/tesseract-ocr/tessdata_fast)

## 5.0.0.x

Tesseract **5.0.0.x** source code is available in the 'master' branch of the [repository](https://github.com/tesseract-ocr/tesseract). The master branch is using `5.0.0` versioning because code modernization caused API incompatibility with 4.x release.

Binaries are available from:
- [Ubuntu - tesseract-ocr-devel PPA](https://launchpad.net/~alex-p/+archive/ubuntu/tesseract-ocr-devel)
- [Debian - notesalexp.org](https://notesalexp.org/tesseract-ocr/)
- [Windows - Tesseract at UB Mannheim](https://github.com/UB-Mannheim/tesseract/wiki)

Language model traineddata files same as listed above for version `4.0.0` can be used with Tesseract `5.0.0.x`. These are available from:
- [tessdata](https://github.com/tesseract-ocr/tessdata)
- [tessdata_best](https://github.com/tesseract-ocr/tessdata_best)
- [tessdata_fast](https://github.com/tesseract-ocr/tessdata_fast)
- [tessdata_contrib](https://github.com/tesseract-ocr/tessdata_contrib)
- [Links to Community Contributions](Data-Files-Contributions.md)

### Compiling and Installation
- [Compiling and GitInstallation](Compiling-–-GitInstallation.md)
- [Compiling](Compiling.md)
- [Installation](Installation.md)
- [Docker Containers](4.0-Docker-Containers.md)

### Usage
- [Tips to Improve Recognition](ImproveQuality.md)
- [Command Line Usage](Command-Line-Usage.md)
- [API Example - user_patterns](APIExample-user_patterns.md)
- [API Example](APIExample.md)
- [User App Example](User-App-Example.md)
- [Viewer Debugging](ViewerDebugging.md)
- [Common Errors and Resolutions](4.0x-Common-Errors-and-Resolutions.md)
- [Frequently Asked Qustions](FAQ.md)

### Technical Information
- [Historical Technical Documentation](tess3/Technical-Documentation.md)
- [API/ABI changes review for Tesseract](https://abi-laboratory.pro/?view=timeline&l=tesseract)
- [Manual Pages](Documentation.md#manual-pages)
- [Source Documentation generated by Doxygen](Documentation.md#source-documentation-generated-by-Doxygen)
- [Neural Nets in Tesseract 4.00](NeuralNetsInTesseract4.00.md)
- [VGSL Specs](VGSLSpecs.md)
- [VGSL Specs info from Tensorflow](https://github.com/mldbai/tensorflow-models/blob/master/street/g3doc/vgslspecs.md)
- [Network spec for tessdata_fast models](Data-Files-in-tessdata_fast.md)
- [Network spec for tessdata_best models](Data-Files-in-tessdata_best.md)
- [DAS 2016 tutorial slides](https://github.com/tesseract-ocr/docs/tree/master/das_tutorial2016)
Slides
[#2](https://github.com/tesseract-ocr/docs/blob/master/das_tutorial2016/2ArchitectureAndDataStructures.pdf),
[#6](https://github.com/tesseract-ocr/docs/blob/master/das_tutorial2016/6ModernizationEfforts.pdf),
[#7](https://github.com/tesseract-ocr/docs/blob/master/das_tutorial2016/7Building%20a%20Multi-Lingual%20OCR%20Engine.pdf)
have information about LSTM integration in Tesseract 4.0x.
- [4.0 Accuracy and Performance](4.0-Accuracy-and-Performance.md)
- [Tesseract OpenCL - Experimental](TesseractOpenCL.md)

### Training for Tesseract 5
- [Train Tesseract LSTM with make from Single Line Images and Groundtruth Transcription](https://github.com/tesseract-ocr/tesstrain)
    * [Example: Training Fraktur with GT4HistOCR](https://github.com/tesseract-ocr/tesstrain/wiki/GT4HistOCR)
    * [Demo of PlusMinus training for Sanskrit](https://github.com/Shreeshrii/tesstrain-sanPlusMinus)

### Training for Tesseract 4
- [TrainingTesseract 4.00 - Detailed Guide by Ray Smith](TrainingTesseract-4.00.md)
    * [Hardware-Software Requirements](TrainingTesseract-4.00.md#hardware-software-requirements)
    * [Training Text Requirements](TrainingTesseract-4.00.md#training-text-requirements)
    * [Fonts](Fonts.md)
    * [Box Files](Make-Box-Files.md)
    * [LSTMTraining Command Line](TrainingTesseract-4.00.md#lstmtraining-command-line)
    * [Error Messages From Training](TrainingTesseract-4.00.md#error-messages-from-training)
    * [The-Hallucination-Effect](The-Hallucination-Effect.md)
- [Links to Community Contributions for Finetune Training](TrainingTesseract-4.00---Finetune.md)
- [Community training tips at tesseract-ocr forum](https://groups.google.com/g/tesseract-ocr/search?q=lorenzo)

### Testing
- [TestingTesseract](TestingTesseract.md)
- [UNLV Testing of Tesseract](UNLV-Testing-of-Tesseract.md)

### External Projects
- [AddOns](AddOns.md)
- [User Projects - 3rdParty](User-Projects-–-3rdParty.md)

### User Manual for Old Versions

- [Tesseract 3 Documentation](OldVersionDocs.md)
