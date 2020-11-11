# Tesseract User Manual

## Tesseract

Tesseract is an open source [text recognition (OCR)](https://en.wikipedia.org/wiki/Optical_character_recognition) Engine, available under the [Apache 2.0 license.](http://www.apache.org/licenses/LICENSE-2.0). The current official release is [4.1.1](https://github.com/tesseract-ocr/tesseract/releases/tag/4.1.1). The [master branch on Github](https://github.com/tesseract-ocr/tesseract.git) can be used by those who want the latest 5.0.0.Alpha code for LSTM (--oem 1) and legacy (--oem 0) Tesseract. The [3.05 branch on GitHub] (https://github.com/tesseract-ocr/tesseract/tree/3.05) can be used by those who want the bug fixes for [3.05.02](https://github.com/tesseract-ocr/tesseract/releases/tag/3.05.02) release for legacy Tesseract. 

Tesseract can be used directly via command line, or (for programmers) using an [API](https://github.com/tesseract-ocr/tesseract/blob/master/include/tesseract/baseapi.h) to extract printed text from images. It supports a wide variety of languages. Tesseract doesn't have a built-in GUI, but there are several available from the [3rdParty](User-Projects-%E2%80%93-3rdParty.md) page.

Tesseract can be used in your own project, under the terms of the [Apache License 2.0.](http://www.apache.org/licenses/LICENSE-2.0) It has a fully featured API, and can be compiled for a variety of targets including Android and the iPhone. See the [3rdParty](User-Projects-%E2%80%93-3rdParty) page for a sample of what has been done with it. 

If you have a question, first read the [documentation](https://tesseract-ocr.github.io/), particularly the [FAQ](FAQ.md) to see if your problem is addressed there. If not, search the [Tesseract user forum](http://groups.google.com/group/tesseract-ocr) or the
[Tesseract developer forum](http://groups.google.com/group/tesseract-dev), and if you still can't find what you need, please ask us there.

Also, it is free software, so if you want to pitch in and help, please do!
If you find a bug and fix it yourself, the best thing to do is to attach the patch to your bug report in the [Issues List](https://github.com/tesseract-ocr/tesseract/issues)

### Documentation

- [Documentation](Documentation.md)
- [Downloads](Downloads.md)
- [FAQ-Old](FAQ-Old.md)
- [Planning](Planning.md)
- [ReleaseNotes](ReleaseNotes.md)
- [Technical-Documentation](Technical-Documentation.md)
- [TesseractOpenCL](TesseractOpenCL.md)

### Build/Installation Instructions

- [Compiling-–-GitInstallation](Compiling-–-GitInstallation.md)
- [Compiling](Compiling.md)
- [Installation](Home.md)

### Usage

- [Command-Line-Usage](Command-Line-Usage.md)
- [Data-Files-in-different-versions](Data-Files-in-different-versions.md)
- [ImproveQuality](ImproveQuality.md)

### Testing

- [TestingTesseract](TestingTesseract.md)
- [UNLV-Testing-of-Tesseract](UNLV-Testing-of-Tesseract.md)

### Training

- [Training-Tesseract](Training-Tesseract.md)
- [ViewerDebugging](ViewerDebugging.md)

### Examples

- [APIExample-user_patterns](APIExample-user_patterns.md)
- [APIExample](APIExample.md)
- [User-App-Example](User-App-Example.md)

### External Projects

- [AddOns](AddOns.md)
- [User-Projects-–-3rdParty](User-Projects-–-3rdParty.md)

## Tesseract 5 Alpha (git master branch)

- [LSTM Training from Images and Groundtruth Transcription](https://github.com/tesseract-ocr/tesstrain)

## Tesseract 4

- [4.0-with-LSTM](4.0-with-LSTM.md)
- [NeuralNetsInTesseract4.00](NeuralNetsInTesseract4.00.md)
- [VGSLSpecs](VGSLSpecs.md)
- [4.0x-Changelog](4.0x-Changelog.md)
- [4.0-Accuracy-and-Performance](4.0-Accuracy-and-Performance.md)

### Tesseract 4 Build/Installation

- [4.0-Docker-Containers](4.0-Docker-Containers.md)
- [Home](Home.md)

### Tesseract 4 Traineddata Files

- [Data-Files](Data-Files.md)
- [Data-Files-in-tessdata_fast](Data-Files-in-tessdata_fast.md)
- [Data-Files-Contributions](Data-Files-Contributions.md)

### Tesseract 4 LSTM Training

- [TrainingTesseract-4.00](TrainingTesseract-4.00.md)
- [TrainingTesseract-4.00---Finetune](TrainingTesseract-4.00---Finetune.md)
- [4.0x-Common-Errors-and-Resolutions](4.0x-Common-Errors-and-Resolutions.md)
- [Fonts](Fonts.md)
- [Making-Box-Files---4.0](Making-Box-Files---4.0.md)
- [The-Hallucination-Effect](The-Hallucination-Effect.md)

### Old Versions

- [Tesseract 3 Documentation](OldVersionDocs.md)