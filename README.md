# Tesseract User Manual

## Introduction

Tesseract is an open source [text recognition (OCR)](https://en.wikipedia.org/wiki/Optical_character_recognition) Engine, available under the [Apache 2.0 license.](http://www.apache.org/licenses/LICENSE-2.0). The current official release is [4.1.1](https://github.com/tesseract-ocr/tesseract/releases/tag/4.1.1). The [master branch on Github](https://github.com/tesseract-ocr/tesseract.git) can be used by those who want the latest 5.0.0.Alpha code for LSTM (--oem 1) and legacy (--oem 0) Tesseract. The [3.05 branch on GitHub](https://github.com/tesseract-ocr/tesseract/tree/3.05) can be used by those who want the bug fixes for [3.05.02](https://github.com/tesseract-ocr/tesseract/releases/tag/3.05.02) release for legacy Tesseract. 

Tesseract can be used directly via command line, or (for programmers) using an [API](https://github.com/tesseract-ocr/tesseract/blob/master/include/tesseract/baseapi.h) to extract printed text from images. It supports a wide variety of languages. Tesseract doesn't have a built-in GUI, but there are several available from the [3rdParty](User-Projects-–-3rdParty.md) page.

Tesseract can be used in your own project, under the terms of the [Apache License 2.0.](http://www.apache.org/licenses/LICENSE-2.0) It has a fully featured API, and can be compiled for a variety of targets including Android and the iPhone. See the [3rdParty](User-Projects-–-3rdParty.md) page for a sample of what has been done with it. 

If you have a question, first read the [documentation](https://tesseract-ocr.github.io/), particularly the [FAQ](FAQ.md) to see if your problem is addressed there. If not, search the [Tesseract user forum](http://groups.google.com/group/tesseract-ocr) or the
[Tesseract developer forum](http://groups.google.com/group/tesseract-dev), and if you still can't find what you need, please ask us there.

Also, it is free software, so if you want to pitch in and help, please do!
If you find a bug and fix it yourself, the best thing to do is to attach the patch to your bug report in the [Issues List](https://github.com/tesseract-ocr/tesseract/issues).

This user manual is for Tesseract versions 4.x.x and 5.0.0.Alpha. For versions 3.05.02 and older, see the [documentation for old versions](OldVersionDocs.md).

### Releases and Changelog

- [Release Planning](Planning.md)
- [Downloads](Downloads.md)
- [Releases](https://github.com/tesseract-ocr/tesseract/releases)
- [Release Notes](ReleaseNotes.md)
- [API/ABI changes review for Tesseract](https://abi-laboratory.pro/?view=timeline&l=tesseract)
- [Changelog](https://github.com/tesseract-ocr/tesseract/blob/master/ChangeLog)
- [4.0x-Changelog](4.0x-Changelog.md)

### Compiling and Installation
- [Compiling-–-GitInstallation](Compiling-–-GitInstallation.md)
- [Compiling](Compiling.md)
- [Installation](Installation.md)
- [4.0-Docker-Containers](4.0-Docker-Containers.md)

### Language Traineddata Files
- [Data-Files-Contributions](Data-Files-Contributions.md)
- [Data-Files-in-different-versions](Data-Files-in-different-versions.md)
- [Data-Files-in-tessdata_fast](Data-Files-in-tessdata_fast.md)
- [Data-Files](Data-Files.md)

### Usage
- [ImproveQuality](ImproveQuality.md)
- [APIExample-user_patterns](APIExample-user_patterns.md)
- [APIExample](APIExample.md)
- [Command-Line-Usage](Command-Line-Usage.md)
- [User-App-Example](User-App-Example.md)
- [ViewerDebugging](ViewerDebugging.md)
- [4.0x-Common-Errors-and-Resolutions](4.0x-Common-Errors-and-Resolutions.md)
- [Frequently Asked Qustions](FAQ.md)

### Testing
- [TestingTesseract](TestingTesseract.md)
- [UNLV-Testing-of-Tesseract](UNLV-Testing-of-Tesseract.md)

### Technical Information
- [TesseractOpenCL](TesseractOpenCL.md)
- [NeuralNetsInTesseract4.00](NeuralNetsInTesseract4.00.md)
- [VGSLSpecs](VGSLSpecs.md)### Technical Information

### Training
- [4.0-Accuracy-and-Performance](4.0-Accuracy-and-Performance.md)
- [4.0-with-LSTM](4.0-with-LSTM.md)
- [Documentation](Documentation.md)
- [Fonts](Fonts.md)
- [LSTM Training from Images and Groundtruth Transcription](https://github.com/tesseract-ocr/tesstrain)
- [Making-Box-Files---4.0](Making-Box-Files---4.0.md)
- [Technical-Documentation](Technical-Documentation.md)
- [The-Hallucination-Effect](The-Hallucination-Effect.md)
- [Training-Tesseract](Training-Tesseract.md)
- [TrainingTesseract-4.00---Finetune](TrainingTesseract-4.00---Finetune.md)
- [TrainingTesseract-4.00](TrainingTesseract-4.00.md)

### External Projects
- [AddOns](AddOns.md)
- [User-Projects-–-3rdParty](User-Projects-–-3rdParty.md)

### User Manual for Old Versions

- [Tesseract 3 Documentation](OldVersionDocs.md)