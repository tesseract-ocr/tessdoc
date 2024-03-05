# Installing Tesseract from Git
##### Table of Contents  
* [Installing With Autoconf Tools](#installing-with-autoconf-tools)
  * [Build with Training Tools](#build-with-training-tools)
  * [Build with TensorFlow](#build-with-tensorflow)
  * [Unit test builds](#unit-test-builds)
  * [Debug builds](#debug-builds)
  * [Profiling builds](#profiling-builds)
  * [Release Builds for Mass Production](#release-builds-for-mass-production)
  * [Builds for fuzzing](#builds-for-fuzzing)
  * [Post Install Instructions for Language Traineddata](#post-install-instructions)
* [Building using Windows Visual Studio](#building-using-windows-visual-studio)

These are the instructions for installing Tesseract from the git repository. You should be ready to face unexpected problems.
[C++ compiler with good C++17 support](https://en.wikipedia.org/wiki/C%2B%2B17#Compiler_support) is required for building Tesseract from source.

## Installing With Autoconf Tools

In order to do this; you must have automake, libtool, leptonica, make and pkg-config installed. In addition, you need Git and a C++ compiler.

On Debian or Ubuntu, you can probably install all required packages like this:
```
apt-get install automake ca-certificates g++ git libtool libleptonica-dev make pkg-config
```

The optional manpages are built with asciidoc:
```
apt-get install --no-install-recommends asciidoc docbook-xsl xsltproc
```

If you want to build the Tesseract training tools as well, you'll also require Pango:
```
apt-get install libpango1.0-dev
```

---

Afterwards, to clone the master branch to your computer, do this:
```
git clone https://github.com/tesseract-ocr/tesseract.git
```

or to make a shallow clone with commit history truncated to the latest commit only:
```
git clone --depth 1  https://github.com/tesseract-ocr/tesseract.git
```

or to clone a different branch/version:
```
git clone https://github.com/tesseract-ocr/tesseract.git --branch <branchName> --single-branch
```

**Note:** You may have problems with building the latest version on GitHub. If this is the case, download one of the latest *released* versions instead, from here: https://github.com/tesseract-ocr/tesseract/releases.

---
**Note:** Tesseract requires Leptonica v1.74 or newer. If your system has only older versions of Leptonica, you must compile it manually from source available at [DanBloomberg/leptonica](https://github.com/DanBloomberg/leptonica).

Finally, run these:
```
    cd tesseract
    ./autogen.sh
    ./configure
    make
    sudo make install
    sudo ldconfig
```

IMPORTANT: See section **"[Post-Install Instructions](#post-install-instructions)"** below.

If you get this error:
```
make  all-recursive
Making all in ccstruct
/bin/sh ../libtool --tag=CXX   --mode=compile g++ -DHAVE_CONFIG_H -I. -
I..  -I../ccutil -I../cutil -I../image -I../viewer -I/opt/local/
include -I/usr/local/include/leptonica  -g -O2 -MT blobbox.lo -MD -MP -
MF .deps/blobbox.Tpo -c -o blobbox.lo blobbox.cpp
mv -f .deps/blobbox.Tpo .deps/blobbox.Plo
mv: rename .deps/blobbox.Tpo to .deps/blobbox.Plo: No such file or
directory
make[3]: *** [blobbox.lo] Error 1
make[2]: *** [all-recursive] Error 1
make[1]: *** [all-recursive] Error 1
make: *** [all] Error 2
```

Try to run `autoreconf -i` after running `./autogen.sh`.

### Build with Training Tools

The above does not build the Tesseract training tools.
If you plan to install the training tools, you also need the following libraries:

```
sudo apt-get install libicu-dev
sudo apt-get install libpango1.0-dev
sudo apt-get install libcairo2-dev
```

To build Tesseract with training tools, run the following:

```
    cd tesseract
    ./autogen.sh
    ./configure
    make
    sudo make install
    sudo ldconfig
    make training
    sudo make training-install
```
You can specify extra options for configure, as needed. eg.

`./configure  --disable-openmp --disable-debug --disable-opencl --disable-graphics --disable-shared 'CXXFLAGS=-g -O2 -Wall -Wextra -Wpedantic'`

### Post-Install Instructions

There are two parts to install for Tesseract, the **engine** itself, and the **traineddata for a language**.

The above installation commands install the Tesseract engine and training tools. They also install the config files eg. those needed for output such as `pdf, tsv, hocr, alto`, or those for creating box files such as `lstmbox, wordstrbox`. 
In addition to these, **traineddata** for a language is needed to recognize the text in images. 

Three types of **traineddata** files ([tessdata](https://github.com/tesseract-ocr/tessdata), [tessdata_best](https://github.com/tesseract-ocr/tessdata_best) and [tessdata_fast](https://github.com/tesseract-ocr/tessdata_fast)) for over 130 languages and over 35 scripts are available in tesseract-ocr GitHub repos.

When building from source on Linux, the tessdata configs will be installed in `/usr/local/share/tessdata` unless you used `./configure --prefix=/usr`. Once installation of tesseract is complete, **don't forget to** download the language traineddata files required by you and place them in this tessdata directory (`/usr/local/share/tessdata`). 

If you want support for both the legacy (--oem 0) and LSTM (--oem 1) engine, download the traineddata files from [tessdata](https://github.com/tesseract-ocr/tessdata).

Use traineddata files from [tessdata_best](https://github.com/tesseract-ocr/tessdata_best) or [tessdata_fast](https://github.com/tesseract-ocr/tessdata_fast) if you only want support for LSTM engine (--oem 1).

Please make sure to use the download link or wget the `raw` file. eg. Here is the direct download link for [eng.traineddata from tessdata repo which supports both the legacy and LSTM engines of tesseract](https://github.com/tesseract-ocr/tessdata/raw/master/eng.traineddata). 

Now you are ready to use `tesseract`! 

A python3 script for downloading traineddata files is available from https://github.com/zdenop/tessdata_downloader

If you want to put the traineddata files in a different directory than the directory that was defined during installation i.e. `/usr/local/share/tessdata` then you need to set a local variable called `TESSDATA_PREFIX` to point to the tesseract `tessdata` directory. 

1. Ex: on Linux Ubuntu, modify your `~/.bashrc` file by adding the following to the bottom of it. Modify the path according to your situation: 

           export TESSDATA_PREFIX="/home/$USER/Downloads/tesseract/tesseract-4.1.0/tessdata" 

1. Then, close and re-open your terminal for it to take effect, or just call `. ~/.bashrc` or `export ~/.bashrc` (same thing) for it to take effect immediately in your current terminal.

1. Place any language training data you need into this `tessdata` folder as well. For example, the English one is called `eng.traineddata`. Download it [from the tessdata repository here](https://github.com/tesseract-ocr/tessdata), and move it to your `tessdata` directory you just specified in your `TESSDATA_PREFIX` variable above. 

### Build with TensorFlow

Building with TensorFlow requires additional packages for Protocol Buffers and TensorFlow.
On Debian or Ubuntu, you can probably install them like this:

    apt-get install libprotoc-dev libtensorflow-dev

All builds will automatically build Tesseract and the training tools with TensorFlow if the necessary development files are found. This can be overridden:

    # Enforce build with TensorFlow (will fail if requirements are not met).
    ./configure --with-tensorflow [...]

    # Don't build with TensorFlow.
    ./configure --without-tensorflow [...]

Build support with TensorFlow is a new feature in Git master. The resulting code is still untested.


### Unit test builds

Such builds can be used to run the automated regression tests, which have additional requirements. This includes the additional dependencies for the training tools (as mentioned above), and downloading all git submodules, as well as the model repositories (`*.traineddata`):

    # Clone the Tesseract source tree:
    git clone https://github.com/tesseract-ocr/tesseract.git
    # Clone repositories with model files (from the same directory):
    git clone https://github.com/tesseract-ocr/tessdata.git
    git clone https://github.com/tesseract-ocr/tessdata_best.git
    git clone https://github.com/tesseract-ocr/tessdata_fast.git
    git clone https://github.com/tesseract-ocr/langdata_lstm.git
    # Change to the Tesseract source tree and get all submodules:
    cd tesseract
    git submodule update --init
    # Build the training tools (see above). Here we use a release built with sanitizers:
    ./autogen.sh
    mkdir -p bin/unittest
    cd bin/unittest
    ../../configure --disable-shared 'CXXFLAGS=-g -O2 -Wall -Wextra -Wpedantic -fsanitize=address,undefined -fstack-protector-strong -ftrapv'
    make training
    # Run the unit tests:
    make check
    cd ../..

This will create log files for all unit tests, both individual and accumulated, under `bin/unittest/unittest`. They can also be run standalone, for example

    bin/unittest/unittest/stringrenderer_test

Failed tests will show prominently as segfaults or SIGILL handlers (depending on the platform).


### Debug Builds

Such builds produce Tesseract binaries which run very slowly. They are not useful for production, but good to find or analyze software problems. This is a proven build sequence:

    cd tesseract
    ./autogen.sh
    mkdir -p bin/debug
    cd bin/debug
    ../../configure --enable-debug --disable-shared 'CXXFLAGS=-g -O0 -Wall -Wextra -Wpedantic -fsanitize=address,undefined -fstack-protector-strong -ftrapv'
    # Build tesseract and training tools. Run `make` if you don't need the training tools.
    make training
    cd ../..

This activates debug code, does not use a shared Tesseract library (that makes it possible to run `tesseract` without installation), disables compiler optimizations (allows better debugging with `gdb`), enables lots of compiler warnings and enables several run time checks.


### Profiling Builds
Such builds can be used to investigate performance problems. Tesseract will run slower than without profiling, but with acceptable speed. This is a proven build sequence:

    cd tesseract
    ./autogen.sh
    mkdir -p bin/profiling
    cd bin/profiling
    ../../configure --disable-shared 'CXXFLAGS=-g -p -O2 -Wall -Wextra -Wpedantic'
    # Build tesseract and training tools. Run `make` if you don't need the training tools.
    make training
    cd ../..

This does not use a shared Tesseract library (that makes it possible to run `tesseract` without installation),
enables profiling code,
enables compiler optimizations and enables lots of compiler warnings.

Optionally this can also be used with debug code by adding `--enable-debug` and replacing `-O2` by `-O0`.

The profiling code creates a file named `gmon.out` in the current directory when Tesseract terminates.
GNU gprof is used to show the profiling information from that file.


### Release Builds for Mass Production

The default build creates a Tesseract executable which is fine for processing of single images. Tesseract then uses 4 CPU cores to get an OCR result as fast as possible.

For mass production with hundreds or thousands of images that default is bad because the multi threaded execution has a very large overhead. It is better to run single threaded instances of Tesseract, so that every available CPU core will process a different image.

This is a proven build sequence:

    cd tesseract
    ./autogen.sh
    mkdir -p bin/release
    cd bin/release
    ../../configure --disable-openmp --disable-shared 'CXXFLAGS=-g -O2 -fno-math-errno -Wall -Wextra -Wpedantic'
    # Build tesseract and training tools. Run `make` if you don't need the training tools.
    make training
    cd ../..

This disabled OpenMP (multi threading), does not use a shared Tesseract library (that makes it possible to run `tesseract` without installation), enables compiler optimizations,
disables setting of `errno` for mathematical functions (faster execution!) and enables lots of compiler warnings.

### Builds for fuzzing

Fuzzing is used to test the Tesseract API for bugs. Tesseract uses [OSS-Fuzz](https://oss-fuzz.com/),
but fuzzing can also run locally. A newer Clang++ compiler is required.

Build example (fix the value of CXX for the available clang++):

    cd tesseract
    ./autogen.sh
    mkdir -p bin/fuzzer
    cd bin/fuzzer
    ../../configure --disable-openmp --disable-shared CXX=clang++-7 CXXFLAGS='-g -O2 -Wall -Wextra -Wpedantic -D_GLIBCXX_DEBUG -fsanitize=fuzzer-no-link,address,undefined'
    # Build the fuzzer executable.
    make fuzzer-api
    cd ../..

Example (Show help information):

    bin/fuzzer/fuzzer-api -help=1

Example (Run the fuzzer with a known test case):

    bin/fuzzer/fuzzer-api clusterfuzz-testcase-minimized-fuzzer-api-5670045835853824

Example (Run the fuzzer to find new bugs):

    nice bin/fuzzer/fuzzer-api -jobs=16 -workers=16

## Building using Windows Visual Studio

See [Compiling for Windows](Compiling.md#windows).
