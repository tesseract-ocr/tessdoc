# Compilation guide for various platforms

**Note:** This wiki expects you to be familiar with compiling software on your operation system.

# Linux / Other Unices

## Dependencies

**Autotools** [Leptonica](http://www.leptonica.org/)

If they are not already installed, you need the following libraries (Ubuntu):
```
sudo apt-get install autoconf automake libtool
sudo apt-get install libpng12-dev
sudo apt-get install libjpeg62-dev
sudo apt-get install libtiff4-dev
sudo apt-get install zlib1g-dev
sudo apt-get install libicu-dev      # (if you plan to make the training tools)
sudo apt-get install libpango1.0-dev # (if you plan to make the training tools)
sudo apt-get install libcairo2-dev   # (if you plan to make the training tools)
```

You also need to install [Leptonica](http://www.leptonica.org/). There is an apt-get package libleptonica-dev, **but if you are using an oldish version of Linux, the Leptonica version may be too old, so you will need to build from source.**

**3.01 requires at least v1.67 of Leptonica.** 3.02 requires at least v1.69 of Leptonica. (Both available in Ubuntu 12.04 Precise Pangolin.)
**3.03 requires at least v1.70 of Leptonica. (Both available in Ubuntu 14.04 Trusty Tahr.)**
**3.04 requires at least v1.71 of Leptonica.**

The sources are at http://www.leptonica.org/. The instructions at [Leptonica README](http://www.leptonica.org/source/README.html) are clear, but basically it is as described in [Compilation](#Compilation.md) below.

Ensure that the development headers for Leptonica are installed before compiling Tesseract. Note that if building Leptonica from source, you may need to ensure that /usr/local/lib is in your library path. This is a standard Linux bug, and the information at [Stackoverflow](http://stackoverflow.com/questions/4743233/is-usr-local-lib-searched-for-shared-libraries) is very helpful.

## Compilation

Tesseract uses a standard autotools based build system, so the compilation process should be familiar.

```
./autogen.sh
./configure
make
sudo make install
sudo ldconfig
```

On some systems autotools does not create m4 directory automatically (giving the error: "configure: error: cannot find macro directory 'm4'"). In this case you must create m4 directory (`mkdir m4`), and then rerun the above commands starting with ./configure.

If you want the training tools (3.03), you will also need to run the following commands:

```
make training
sudo make training-install
```

Build of training tools is not available if you do not have necessary dependencies (pay attention to messages from ./configure script).


## Install elsewhere / without root

Tesseract can be configured to install anywhere, which makes it possible to install it without root access.

To install it in $HOME/local:

```
./autogen.sh
./configure --prefix=$HOME/local/
make install
```

To install it in $HOME/local using Leptonica libraries also installed in $HOME/local:

```
./autogen.sh
LIBLEPT_HEADERSDIR=$HOME/local/include ./configure \
  --prefix=$HOME/local/ --with-extra-libraries=$HOME/local/lib
make install
```


## Language Data

  1. Download langugage data file (e.g. 'wget http://tesseract-ocr.googlecode.com/files/tesseract-ocr-3.01.eng.tar.gz' for 3.01 version)
  1. Decompress it ('tar xf tesseract-ocr-3.01.eng.tar.gz')
  1. Move it to installation of tessdata (e.g. 'mv tesseract-ocr/tessdata $TESSDATA\_PREFIX' if defined TESSDATA\_PREFIX)

You can also use:
```
export TESSDATA_PREFIX=/some/path/to/tessdata
```
to point to your tessdata directory (example: if your tessdata path is '/usr/local/share/tessdata' you have to use 'export TESSDATA\_PREFIX='/usr/local/share/').


# Windows

## 3.02

For tesseract-ocr 3.02 please follow instruction in [Visual Studio 2008 Developer Notes for Tesseract-OCR](http://tesseract-ocr.googlecode.com/svn/trunk/vs2008/doc/setup.html#using-the-latest-tesseractocr-sources).

## 3.01

Download these packages from the [Downloads](http://code.google.com/p/tesseract-ocr/downloads/list) page:

  * `tesseract-[version].tar.gz` - Tesseract source
  * `tesseract-[version]-win_vs.zip` - Visual studio (2008 & 2010) solution with necessary libraries
  * `tesseract-ocr-[version].eng.tar.gz` - English language file for tesseract (or download other language training file)

Unpack them to one directory (e.g. `tesseract-3.01`). Note that `tesseract-ocr-[version].eng.tar.gz` names the root directory `'tesseract-ocr'` instead of `'tesseract-[version]'`.

Windows relevant files are located in vs2008 directory (e.g. 'tesseract-3.01\vs2008'). The same build process as usual applies: Open tesseract.sln with VC++Express 2008 and build all (or just Tesseract.) It should compile (in at least release mode) without having to install anything further. The dll dependencies and Leptonica are included. Output will be in tesseract-3.01\vs2008\bin (or tesseract-3.01\vs2008\bin.rd or tesseract-3.01\vs2008\bin.dbg based on configuration build).

# 3.03rc-1

Have a look at blog [How to build Tesseract 3.03 with Visual Studio 2013](http://vorba.ch/2014/tesseract-3.03-vs2013.html).

## Mingw+Msys or Cygwin

For Mingw+Msys have a look at blog [Compiling Leptonica and Tesseract-ocr with Mingw+Msys](http://www.sk-spell.sk.cx/compiling-leptonica-and-tesseract-ocr-with-mingwmsys).
For Cygwin have a look at blog [How to build Tesseract on Cygwin](http://vorba.ch/2014/tesseract-cygwin.html).

# Miscellaneous

* [Standalone Tesseract build bash script](http://pastebin.com/VnGLHfbr)