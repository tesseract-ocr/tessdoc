# Introduction

Tesseract is an Open Source [Optical Character Recognition](https://en.wikipedia.org/wiki/Optical_character_recognition) (OCR) Engine, available under the [Apache 2.0 license.](http://www.apache.org/licenses/LICENSE-2.0) It can be used directly, or (for programmers) using an [API](https://github.com/tesseract-ocr/tesseract/blob/master/api/baseapi.h) to extract typed, handwritten or printed text from images. It supports a wide variety of languages.

Tesseract doesn't have a built-in GUI, but there are several available from the [3rdParty](3rdParty) page.

# Installation

There are two parts to install, the engine itself, and the training data for a language.

## Linux

Tesseract is available directly from many Linux distributions. The package is generally called 'tesseract' or 'tesseract-ocr' - search your distribution's repositories to find it. Packages are also generally available for language training data (search the repositories,) but if not you will need to download the appropriate training data ([=< 3.02](https://sourceforge.net/projects/tesseract-ocr-alt/files/?source=navbar) or [the latest from github.com](https://github.com/tesseract-ocr/tessdata)), unpack it, and copy the .traineddata file into the 'tessdata' directory, probably `/usr/share/tesseract-ocr/tessdata` or `/usr/share/tessdata`.

If Tesseract isn't available for your distribution, or you want to use a newer version than they offer, you can [compile your own](Compiling). Note that older versions of Tesseract only supported processing .tiff files.

## Mac OS X

You can install Tesseract using either [MacPorts](https://www.macports.org/) or [Homebrew](http://brew.sh).

####MacPorts
To install Tesseract run this command: 
```
sudo port install tesseract
```
To install any language data, run:
```
sudo port install tesseract-<langcode>
```
List of available langcodes can be found on [MacPorts tesseract page](https://www.macports.org/ports.php?by=name&substr=tesseract-).

####Homebrew
To install Tesseract run this command:
```
brew install tesseract
```

## Windows

An installer is available for Windows from our [download](Downloads) page. This includes the English training data.

If you want to use another language, [download the appropriate training data](https://github.com/tesseract-ocr/tessdata), unpack it using [7-zip](http://www.7-zip.org), and copy the .traineddata file into the 'tessdata' directory, probably `C:\Program Files\Tesseract OCR\tessdata`.

## MSYS2

Install and update MSYS2. 
 Follow instructions at
```
 http://sourceforge.net/p/msys2/wiki/MSYS2%20installation/ 
```

Open an MSYS2 command prompt (or the 32-bit or 64-bit command prompts if you plan on building 32-bit or 64-bit things) from the start menu entries. 

Install {32-bit,64-bit} MinGW-w64 GCC:

```
 pacman -S mingw-w64-{i686,x86_64}-gcc
```

Install tesseract-OCR:

```
 pacman -S mingw-w64-{i686,x86_64}-tesseract-ocr
```

and the data files:

```
 pacman -S mingw-w64-tesseract-ocr-osd mingw-w64-{i686,x86_64}-tesseract-ocr-eng
```

And you're done. 

(These instructions were copied from post by rubenvb at http://stackoverflow.com/questions/29960825/error-during-making-xz-5-2-1-with-mingw-msys )

## Cygwin

Released version >= 3.02 of tesseract-ocr [are part of ](https://mirrors.kernel.org/sourceware/cygwin/x86_64/release/tesseract-ocr/) 64bit [Cygwin](https://www.cygwin.com/)

Instruction for cygwin installation is here:
https://cygwin.com/cygwin-ug-net/setup-net.html

```
Tesseract specific packages to be installed:

tesseract-ocr                           3.04.01-1
tesseract-ocr-eng                       3.04-1
tesseract-training-core                 3.04-1
tesseract-training-eng                  3.04-1
tesseract-training-util                 3.04.01-1
```

## Other Platforms

Tesseract may work on more exotic platforms too. You can either try [compiling it yourself](Compiling), or take a look at the list of [other projects using Tesseract](3rdParty).


# Running Tesseract

Tesseract is a command-line program, so first open a terminal or command prompt. The command is used like this:

```
  tesseract imagename outputbase [-l lang] [-psm pagesegmode] [configfile...]
```

So basic usage to do OCR on an image called 'myscan.png' and save the result to 'out.txt' would be:

```
  tesseract myscan.png out
```

Or to do the same with German:

```
  tesseract myscan.png out -l deu
```

It can even be used with multiple languages traineddata at a time eg. English and German:

```
  tesseract myscan.png out -l eng+deu
```

Tesseract also includes a hOCR mode, which produces a special HTML file with the coordinates of each word. This can be used to create a searchable pdf, using a tool such as [Hocr2PDF](http://exactcode.de/site/open_source/exactimage/hocr2pdf). To use it, use the 'hocr' config option, like this:

```
  tesseract myscan.png out hocr
```

You can also create a searchable pdf directly from tesseract ( versions >=3.03):

```
  tesseract myscan.png out pdf
```

More information about the various options is available in the [Tesseract manpage](https://github.com/tesseract-ocr/tesseract/blob/master/doc/tesseract.1.asc).

# Other Languages

Tesseract has been trained for [many languages] (https://github.com/tesseract-ocr/tesseract/blob/master/doc/tesseract.1.asc#languages), check for your language in the [Tessdata repository]  (https://github.com/tesseract-ocr/tessdata) . 

It can also be trained to support other languages and scripts; for more details see [TrainingTesseract](TrainingTesseract).

# Development

Tesseract can also be used in your own project, under the terms of the [Apache License 2.0.](http://www.apache.org/licenses/LICENSE-2.0) It has a fully featured API, and can be compiled for a variety of targets including Android and the iPhone. See the [3rdParty](3rdParty) page for a sample of what has been done with it.

Also, it's free software, so if you want to pitch in and help, please do!
If you find a bug and fix it yourself, the best thing to do is to attach the patch to your bug report in the [Issues List](https://github.com/tesseract-ocr/tesseract/issues)

# Support

First read the [Wiki](https://github.com/tesseract-ocr/tesseract/wiki), particularly the [FAQ](FAQ) to see if your problem is addressed there. If not, search the the [Tesseract user forum](http://groups.google.com/group/tesseract-ocr) or the [Tesseract developer forum](http://groups.google.com/group/tesseract-dev), and if you still can't find what you need, please ask us there.