# Compilation guide for various platforms

**Note:** This documentation expects you to be familiar with compiling software on your operating system.

*Use the same tools for building tesseract as you used for [building leptonica](https://github.com/DanBloomberg/leptonica/issues/410).*

There are several (known) toolchains that can help you build the tesseract: [GNU Autotools](https://www.gnu.org/software/automake/manual/html_node/Autotools-Introduction.html), [CMake](https://cmake.org/), [Software Network](https://software-network.org/) (a.k.a. sw) and [vcpkg](https://vcpkg.io/en/). Please have a look at the [tesseract Github Action Worklows](https://github.com/tesseract-ocr/tesseract/tree/main/.github/workflows) if the following instructions are not clear to you.

## Table of contents

* [Linux](Compiling.md#linux)
* [Windows](Compiling.md#windows)
* [macOS](Compiling.md#macos)
* [Android](Compiling.md#android)
* [Common Errors](Compiling.md#common-errors)
* [Miscellaneous](Compiling.md#miscellaneous)


## Linux

To install **Tesseract 4.x** you can simply run the following command on your **Ubuntu 18.xx bionic**:
```
sudo apt install tesseract-ocr
```
If you wish to install the **Developer Tools** which can be used for training, run the following command:
```
sudo apt install libtesseract-dev
```


The following instructions are for building on Linux, which also can be applied to other UNIX like operating systems.


### Dependencies

* A compiler for C and C++: GCC or Clang
* GNU Autotools: autoconf, automake, libtool
* pkg-config
* [Leptonica](http://www.leptonica.org/)
* (optional) zlib, libpng, libjpeg, libtiff, giflib, openjpeg, webp, archive, curl


### Ubuntu

If they are not already installed, you need the following libraries (Ubuntu 16.04/14.04):
```
sudo apt-get install g++ # or clang++ (presumably)
sudo apt-get install autoconf automake libtool
sudo apt-get install pkg-config
sudo apt-get install libpng-dev
sudo apt-get install libjpeg8-dev
sudo apt-get install libtiff5-dev
sudo apt-get install zlib1g-dev
sudo apt-get install libwebpdemux2 libwebp-dev
sudo apt-get install libopenjp2-7-dev
sudo apt-get install libgif-dev
sudo apt-get install libarchive-dev libcurl4-openssl-dev
```
if you plan to install the training tools, you also need the following libraries:
```
sudo apt-get install libicu-dev
sudo apt-get install libpango1.0-dev
sudo apt-get install libcairo2-dev
```


### Leptonica

You also need to install [Leptonica](http://www.leptonica.org/). Ensure that the development headers for Leptonica are installed before compiling Tesseract.

Tesseract versions and the minimum version of Leptonica required:

**Tesseract** | **Leptonica** | **Ubuntu**
:-------------------: | :---------------------------------------: | :---------
4.00 | 1.74.2 | [Ubuntu 18.04](https://packages.ubuntu.com/bionic/tesseract-ocr)
3.05 | 1.74.0 | Must build from source
3.04 | 1.71 | [Ubuntu 16.04](http://packages.ubuntu.com/xenial/tesseract-ocr)
3.03 | 1.70 | [Ubuntu 14.04](http://packages.ubuntu.com/trusty/tesseract-ocr)
3.02 | 1.69 | Ubuntu 12.04
3.01 | 1.67 |

One option is to install the distro's Leptonica package:

```
sudo apt-get install libleptonica-dev
```

**but if you are using an oldish version of Linux, the Leptonica version may be too old, so you will need to build from source.**

The sources are at https://github.com/DanBloomberg/leptonica . The instructions for building are given in [Leptonica README](http://www.leptonica.org/source/README.html).

Note that if building Leptonica from source, you may need to ensure that /usr/local/lib is in your library path. This is a standard Linux bug, and the information at [Stackoverflow](http://stackoverflow.com/questions/4743233/is-usr-local-lib-searched-for-shared-libraries) is very helpful.


## Installing Tesseract from Git

Please follow instructions in [Compiling--GitInstallation](Compiling-%E2%80%93-GitInstallation.md)

Also read [Install Instructions](https://github.com/tesseract-ocr/tesseract/blob/main/INSTALL.GIT.md)


## Install elsewhere / without root

Tesseract can be configured to install anywhere, which makes it possible to install it without root access.

To install it in $HOME/local:

```
./autogen.sh
./configure --prefix=$HOME/local/
make
make install
```

To install it in $HOME/local using Leptonica libraries also installed in $HOME/local:

```
./autogen.sh
LIBLEPT_HEADERSDIR=$HOME/local/include ./configure \
  --prefix=$HOME/local/ --with-extra-libraries=$HOME/local/lib
make
make install
```

In some system, you might also need to specify the path to the `pkg-config` before running the `configure` script:

```
export PKG_CONFIG_PATH=$HOME/local/lib/pkgconfig
```


## Video representation of the Compiling process for Tesseract 4.0 and Leptonica 1.7.4 on Ubuntu 16.xx

  * Video [Build from Source Leptonica 1.7.4](https://www.youtube.com/watch?v=vOdnt2h1U8U)
  * Video [Build from Source Tesseract-OCR 4.0](https://www.youtube.com/watch?v=WZLJucXZy-g)


## Language Data

  * Download the [data file(s) for the language(s) you are interested in](Data-Files.md).
  * Move it to the `tessdata` directory (e.g. `mv tessdata $TESSDATA\_PREFIX` if defined `TESSDATA_PREFIX`)

You can also use:
```
export TESSDATA_PREFIX=/some/path/to/tessdata
```
to point to your tessdata directory (example: if your tessdata path is '/usr/local/share/tessdata' you have to use 'export TESSDATA\_PREFIX='/usr/local/share/').


# Windows

## main branch, 3.05 and later

#### Using Tesseract

**!!! IMPORTANT !!!** To use Tesseract in your application (to include tess or to link it into your app) see this very simple [example](User-App-Example.md).


#### Build the latest library (using Software Network client)

1. [Download](https://software-network.org/client/sw-master-windows-client.zip) the latest SW (Software Network `https://software-network.org/`) client from `https://software-network.org/client/`.
2. Run `sw setup` (may require administrator access)
3. Run `sw build org.sw.demo.google.tesseract.tesseract`.


#### For visual studio project using tesseract

1. Setup [Vcpkg](https://github.com/Microsoft/vcpkg/blob/master/README.md) the Visual C++ Package Manager.
2. Run `vcpkg install tesseract:x64-windows` for 64-bit. Use --head for the master branch.


#### Static linking

To build a self-contained `tesseract.exe` executable (without any DLLs or runtime dependencies), use Vcpkg as above with the following command:

- `vcpkg install tesseract:x64-windows-static` for 64-bit
- `vcpkg install tesseract:x86-windows-static` for 32-bit

Use --head for the main branch. It may still require one DLL for the OpenMP runtime, `vcomp140.dll` (which you can find in the Visual C++ Redistributable 2015).


#### Build training tools

Today it is possible to build a full set of tess training tools on Windows with Visual Studio.
You need to have the latest VS compiler (VS2019/2022 or light VS 2019/2022 build tools distro installed.

To do this:

1. [Download](https://software-network.org/client/) the latest SW (Software Network `https://software-network.org/client/`) client from `https://software-network.org/client/`.
2. Checkout tesseract sources `git clone https://github.com/tesseract-ocr/tesseract tesseract && cd tesseract`.
3. Run `sw build`.
4. Binaries will be available under .sw\out\some hash dir\...


#### Develop Tesseract

**For development purposes** of Tesseract itself do the next steps:

1. Download and install Git, CMake and put them in PATH.
2. [Download](https://software-network.org/client/sw-master-windows-client.zip) the latest SW (Software Network `https://software-network.org/`) client from `https://software-network.org/client/`. SW is a source package distribution system.
3. Add SW client to PATH.
4. Run `sw setup` (may require administrator access)
5. If you have a release archive, unpack it to `tesseract` dir.

If you're using main branch run

   ```
   git clone https://github.com/tesseract-ocr/tesseract tesseract
   ```

6. Run

    ```
    cd tesseract
    mkdir build && cd build
    cmake ..
    ```

7. Build a solution (`tesseract.sln`) in your Visual Studio version.
If you want to build and install from command line (e.g. Release build) you can use this command:
```
cmake --build . --config Release --target install
```
If you want to install to other directory that C:\Program Files (you will need admin right for this), you need to specify install path during configuration:
```
cmake .. -G "Visual Studio 15 2017 Win64" -DCMAKE_INSTALL_PREFIX=inst
```

**For development purposes** of training tools after cloning a repo from previous paragraph, run
```
sw build
```

You'll see a solution link appeared in the root directory of Tesseract.


## Building for x64 platform

#### sw

If you're building with sw+cmake, run cmake as follows:
```
mkdir win64 && cd win64
cmake .. -G "Visual Studio 14 2015 Win64"
```

If you're building with sw run `sw generate`, it will create a solution link for you (not yet implemented!).


## 3.05

If you have Visual Studio 2015, checkout the https://github.com/peirick/VS2015_Tesseract repository for [Visual Studio 2015 Projects for Tessearct and dependencies.](https://github.com/peirick/VS2015_Tesseract) and click on build_tesseract.bat. After that you still need to download the language packs.


## 3.03rc-1

Have a look at blog [How to build Tesseract 3.03 with Visual Studio 2013](http://vorba.ch/2014/tesseract-3.03-vs2013.html).


## 3.02

For tesseract-ocr 3.02 please follow instruction in [Visual Studio 2008 Developer Notes for Tesseract-OCR](http://tesseract-ocr.googlecode.com/svn/trunk/vs2008/doc/setup.html#using-the-latest-tesseractocr-sources).


## 3.01

Download these packages from the [Downloads Archive on SourceForge](https://sourceforge.net/projects/tesseract-ocr-alt/files/) page:

  * `tesseract-3.01.tar.gz` - Tesseract source
  * `tesseract-3.01-win_vs.zip` - Visual studio (2008 & 2010) solution with necessary libraries
  * `tesseract-ocr-3.01.eng.tar.gz` - English language file for Tesseract (or download other language training file)

Unpack them to one directory (e.g. `tesseract-3.01`). Note that `tesseract-ocr-3.01.eng.tar.gz` names the root directory `'tesseract-ocr'` instead of `'tesseract-3.01'`.

Windows relevant files are located in vs2008 directory (e.g. `tesseract-3.01\vs2008`). The same build process as usual applies: Open `tesseract.sln` with VC++Express 2008 and build all (or just Tesseract.) It should compile (in at least release mode) without having to install anything further. The dll dependencies and Leptonica are included. Output will be in `tesseract-3.01\vs2008\bin` (or `tesseract-3.01\vs2008\bin.rd` or `tesseract-3.01\vs2008\bin.dbg` based on configuration build).


## Mingw+Msys

For Mingw+Msys have a look at blog [Compiling Leptonica and Tesseract-ocr with Mingw+Msys](http://www.sk-spell.sk.cx/compiling-leptonica-and-tesseract-ocr-with-mingwmsys).


## Msys2

Download and install MSYS2 Installer from https://msys2.github.io/

The core packages groups you need to install if you wish to build from PKGBUILDs are:
- base-devel for any building
- msys2-devel for building msys2 packages
- mingw-w64-i686-toolchain for building mingw32 packages
- mingw-w64-x86_64-toolchain for building mingw64 packages

To build the tesseract-ocr release package, use PKGBUILD from https://github.com/Alexpux/MINGW-packages/tree/master/mingw-w64-tesseract-ocr


## Cygwin

To build on Cygwin have a look at blog [How to build Tesseract on Cygwin](http://vorba.ch/2014/tesseract-cygwin.html).

Tesseract as well as the training utilities for 3.04.00 onwards are available as Cygwin packages.

```
Tesseract specific packages to be installed:

tesseract-ocr                           3.04.01-1
tesseract-ocr-eng                       3.04-1
tesseract-training-core                 3.04-1
tesseract-training-eng                  3.04-1
tesseract-training-util                 3.04.01-1
```


## Mingw-w64

[Mingw-w64](http://mingw-w64.org/) allows building 32- or 64-bit executables for Windows.
It can be used for native compilations on Windows,
but also for cross compilations on Linux (which are easier and faster than native compilations).
Most large Linux distributions already contain packages with the tools need for a cross build.
Before building Tesseract, it is necessary to build some prerequisites.

For Debian and similar distributions (e. g. Ubuntu), the cross tools can be installed like that:

```
# Development environment targeting 32- and 64-bit Windows (required)
apt-get install mingw-w64
# Development tools for 32- and 64-bit Windows (optional)
apt-get install mingw-w64-tools
```

These prerequisites will be needed:

* libpng, libtiff, zlib (binaries for Mingw-w64 available as part of the GTK+ bundles)
* [libicu](https://github.com/svn2github/icu4c)
* [liblcms2](https://github.com/mm2/Little-CMS)
* [openjpeg](https://github.com/uclouvain/openjpeg)
* [leptonica](https://github.com/DanBloomberg/leptonica/)


# macOS

Typically a package manager like Fink, Homebrew or MacPorts is needed in addition to Apple's Xcode.
Xcode and the related command line tools provides the compiler (`llvm-gcc`) and linker, but also libraries like `zlib`. The package manager provides free software packages which are not part of Xcode.

The Xcode Command Line Tools can be installed by running `xcode-select --install`.

Note that Tesseract 4 can be built with OpenMP support, but that requires additional installations.


## macOS with Fink

Fink (as of 2017-04) neither provides Leptonica nor the packages needed for the Tesseract training tools,
so it cannot be recommended for building Tesseract.


## macOS with MacPorts

### Prepare support for OpenMP (optional)

Install OpenMP:
```
sudo port install libomp
```

The following method which gets, compiles and installs OpenMP manually should no longer be needed:

```
# Install cmake if it is not available.
sudo port install cmake
git clone https://github.com/llvm-mirror/openmp.git
cd openmp
mkdir build
cd build
cmake ..
make
sudo make install
```


### Install required packages

```
sudo port install autoconf \
                  automake \
                  libtool \
                  pkgconfig \
                  leptonica
```


### Compilation

Compilation itself relies on the [Autotools suite](https://github.com/tesseract-ocr/tesseract/issues/1500#issuecomment-394114059):

```
  git clone https://github.com/tesseract-ocr/tesseract.git
  cd tesseract
  ./autogen.sh
  ./configure
  make
  sudo make install
```

If you want support for multithreading, you have to install OpenMP first (see above)
and tell the compiler and linker how to activate OpenMP support.
This is done by adding that information to the options for `configure`:

```
  ./configure CXXFLAGS="-Xpreprocessor -fopenmp -I/opt/local/include/libomp -Wall -O2" LDFLAGS=-L/opt/local/lib/libomp LIBS=-lomp
```

If compilation fails at the `make` command, with `libtool` erring on missing instructions, you may be building with MacPort's `g++` compiler, with [known issues](https://github.com/tesseract-ocr/tesseract/pull/1474). The community recommends to use `clang`, but a workaround for `g++` is to re-configure the build:

    ./configure CXXFLAGS=-Wa,-q

And then proceed with `make`.


### Install Tesseract with training tools

In the above training tools are not installed. You can install not only Tesseract but also training tools like below.


#### Install packages required by training tools

```
sudo port install cairo pango
sudo port install icu +devel
```


#### Build and Install

```
git clone https://github.com/tesseract-ocr/tesseract/
cd tesseract
./autogen.sh
./configure
make training
sudo make install training-install
```

## macOS with Homebrew

### Install dependencies

```
# Packages which are always needed.
brew install automake autoconf libtool
brew install pkgconfig
brew install icu4c
brew install leptonica
# Packages required for training tools.
brew install pango
# Optional packages for extra features.
brew install libarchive
# Optional package for builds using g++.
brew install gcc
```


### Compile

As of January 2017, the clang builds but OpenMP will only use a single thread, potentially reducing performance. If you really need OpenMP, install and use gcc.

```bash
git clone https://github.com/tesseract-ocr/tesseract/
cd tesseract
./autogen.sh
mkdir build
cd build
# Optionally add CXX=g++-8 to the configure command if you really want to use a different compiler.
../configure PKG_CONFIG_PATH=/usr/local/opt/icu4c/lib/pkgconfig:/usr/local/opt/libarchive/lib/pkgconfig:/usr/local/opt/libffi/lib/pkgconfig
make -j
# Optionally install Tesseract.
sudo make install
# Optionally build and install training tools.
make training
sudo make training-install
```


## macOS: building for arm-apple-darwin64

For cross-compiling see discussion in [issue 2334](https://github.com/tesseract-ocr/tesseract/issues/2334#issuecomment-477218027). You need to specify target this way:

```bash
./configure CXX="g++ --target=arm-apple-darwin64"
```


# Android

Tesseract can be built for Android as a static command-line executable `tesseract`, or you can use [Java binding](https://github.com/rmtheis/tess-two) to work with **libtess** from your Android app.

Currently, the easiest build method can be found in a [tess-two fork](https://github.com/alexcohn/tess-two). This fork contains both tesseract and leptonica sources, so that it is enough to download the repository. To build the command-line executable, you don't need Android SDK or Android Studio, only install Android NDK (r.20 has been tested) and run the `ndk-build` command, e.g.:
```
ndk-build -C tess-two-git/tess-two tesseract APP_ABI=arm64-v8a
```
The [4.1 branch](https://github.com/alexcohn/tess-two/tree/4.1) is available, too. Note that performance may be significantly different:
```
> adb shell time tess3 --tessdata-dir tessdata3 eurotext.png txt3
Tesseract Open Source OCR Engine v3.05.00 with Leptonica
    0m05.95s real     0m05.77s user     0m00.17s system

> adb shell time tess4 --tessdata-dir tessdata4 eurotext.png txt4
Tesseract Open Source OCR Engine v4.1.0 with Leptonica
    0m59.07s real     0m58.56s user     0m00.45s system

> adb shell time tess4 --tessdata-dir tessdata3 eurotext.png txt42
Tesseract Open Source OCR Engine v4.1.0 with Leptonica
    0m05.61s real     0m05.37s user     0m00.23s system
```


## Alternative

Another method of compiling is using the project [Building for Android with Docker](https://github.com/rhardih/bad), which at the time of writing can produce shared libraries for the following versions and architectures:

| Arch \ Version | 3.02.02 | 3.05.02 | 4.0.0 | 4.1.0 |
|----------------|---------|---------|-------|-------|
| armv7-a | ✔ | ✔ | ✔ | ✔ |
| arm64-v8a | ✖ | ✔ | ✔ | ✔ |
| x86 | ✔ | ✔ | ✔ | ✔ |

Compilation of dependent libraries, **leptonica** and **tiff**, are included and handled as well.


## Cross compile on Linux with NDK

Another method of compiling is doing it on a Linux machine, with Android NDK r22 (22.1.7171670). This method compiles for following versions and architectures:


| Arch \ Version | 4.1.0 |
|----------------|---------|
| armv7-a | ✔ |
| arm64-v8a | ✔ |
| x86 | ✔ |
| x86_64 | ✔ |


These prerequisites will be needed:
* libjpeg - GitHub branch 2.1.1 - https://github.com/libjpeg-turbo/libjpeg-turbo
* libpng - GitHub branch v1.6.37 - https://github.com/glennrp/libpng
* libtiff - version 4.0.10 downloaded - https://download.osgeo.org/libtiff/
* leptonica - version 1.74.4 downloaded - https://github.com/DanBloomberg/leptonica

Compile Leptonica with:
```
./autobuild
./configure \
    --host=$TARGET \
    --disable-programs \
    --without-giflib \
    --without-libwebp \
    --without-zlib \
    --without-libopenjpeg \
    --prefix $ROOT/output/$OUTARCH/

make -j && make install
```

Compile Tesseract with:
```
export API=23

export TOOLCHAIN=$ANDROID_NDK_HOME_22/toolchains/llvm/prebuilt/linux-x86_64

export ABI_CONFIGURE_HOST=$NDKTARGET
export AR=$TOOLCHAIN/bin/$NDKTARGET-ar
export CC=$TOOLCHAIN/bin/$TARGET$API-clang
export CXX=$TOOLCHAIN/bin/$TARGET$API-clang++
export AS=$CC
export LD=$TOOLCHAIN/bin/$TARGET-ld
export RANLIB=$TOOLCHAIN/bin/$NDKTARGET-ranlib
export STRIP=$TOOLCHAIN/bin/$NDKTARGET-strip

export LEPTONICA_LIBS="-L$ROOT/output/$OUTARCH/lib -llept"
export LEPTONICA_CFLAGS="-I$ROOT/output/$OUTARCH/include/leptonica"
export PKG_CONFIG_PATH="$ROOT/output/$OUTARCH/lib/pkgconfig"

export LIBS="-L$ROOT/output/$OUTARCH/lib"

make clean
./autogen.sh
./configure \
    --host=$TARGET \
    --disable-doc \
    --without-archive \
    --disable-openmp \
    --without-curl \
    --prefix $ROOT/output/$OUTARCH/

make -j
make install
```


# Common Errors

* To fix this error
```
./configure: line 4237: syntax error near unexpected token `-mavx,'
./configure: line 4237: `AX_CHECK_COMPILE_FLAG(-mavx, avx=1, avx=0)'
```
ensure that `autoconf-archive` is installed. Don't forget to run `./autogen.sh` after the installation of `autoconf-archive`. Note this error happens often under CentOS, where `autoconf-archive` is missing and no package is available. [Some projects](https://github.com/ic/autoconf-archive-rpmbuilder) help with installing.

The latest code from GitHub does not require `autoconf-archive`.

* If configure fails with such error "configure: error: Leptonica 1.74 or higher is required." Try to install libleptonica-dev package.

* If you are sure you have installed leptonica (for example in /usr/local) then probably pkg-config is not looking at your install folder (check with `pkg-config --variable pc_path pkg-config`).

A solution is to set PKG_CONFIG_PATH : example :`PKG_CONFIG_PATH=/usr/local/lib/pkgconfig`

* On some systems autotools does not create m4 directory automatically (giving the error: "configure: error: cannot find macro directory 'm4'").

In this case you must create m4 directory (`mkdir m4`), and then rerun the above commands starting with ./configure.


# Miscellaneous

* [Standalone Tesseract build bash script](http://pastebin.com/VnGLHfbr)
