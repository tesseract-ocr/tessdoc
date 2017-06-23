# Compilation guide for various platforms

**Note:** This wiki expects you to be familiar with compiling software on your operation system.

# Table of contents
* [Linux](https://github.com/tesseract-ocr/tesseract/wiki/Compiling#linux)
* [Windows](https://github.com/tesseract-ocr/tesseract/wiki/Compiling#windows)
* [macOS](https://github.com/tesseract-ocr/tesseract/wiki/Compiling#macos)
* [Common Errors](https://github.com/tesseract-ocr/tesseract/wiki/Compiling#common-errors)
* [Miscellaneous](https://github.com/tesseract-ocr/tesseract/wiki/Compiling#miscellaneous)

# Linux

The build instructions for Linux also apply to other UNIX like operating systems.

## Dependencies

* A compiler for C and C++: GCC or Clang
* GNU Autotools: autoconf, automake, libtool
* autoconf-archive
* pkg-config
* [Leptonica](http://www.leptonica.org/)
* libpng, libjpeg, libtiff

### Ubuntu

If they are not already installed, you need the following libraries (Ubuntu 16.04/14.04):
```
sudo apt-get install g++ # or clang++ (presumably)
sudo apt-get install autoconf automake libtool
sudo apt-get install autoconf-archive
sudo apt-get install pkg-config
sudo apt-get install libpng12-dev
sudo apt-get install libjpeg8-dev
sudo apt-get install libtiff5-dev
sudo apt-get install zlib1g-dev
```
if you plan to install the training tools, you also need the following libraries: 
```
sudo apt-get install libicu-dev
sudo apt-get install libpango1.0-dev
sudo apt-get install libcairo2-dev
```

You also need to install [Leptonica](http://www.leptonica.org/).

One option is to install the distro's Leptonica package: 

```
sudo apt-get install libleptonica-dev
```

**but if you are using an oldish version of Linux, the Leptonica version may be too old, so you will need to build from source.**

Tesseract versions and the minimum version of Leptonica required:

**Tesseract** | **Leptonica** | **Ubuntu**
:-------------------: | :---------------------------------------: | :---------
4.00 | 1.74.2 | Must build from source 
3.05 | 1.74.0 | Must build from source 
3.04 | 1.71 | [Ubuntu 16.04](http://packages.ubuntu.com/xenial/libtesseract3)
3.03 | 1.70 | [Ubuntu 14.04](http://packages.ubuntu.com/trusty/libtesseract3)
3.02 | 1.69 | [Ubuntu 12.04](http://packages.ubuntu.com/precise/libtesseract3)
3.01 | 1.67 |

The sources are at http://www.leptonica.org/. The instructions at [Leptonica README](http://www.leptonica.org/source/README.html) are clear, but basically it is as described in [Compilation](#Compilation) below.

Ensure that the development headers for Leptonica are installed before compiling Tesseract. Note that if building Leptonica from source, you may need to ensure that /usr/local/lib is in your library path. This is a standard Linux bug, and the information at [Stackoverflow](http://stackoverflow.com/questions/4743233/is-usr-local-lib-searched-for-shared-libraries) is very helpful.

## Installing Tesseract from Git

Please follow instructions in [https://github.com/tesseract-ocr/tesseract/wiki/Compiling--GitInstallation](https://github.com/tesseract-ocr/tesseract/wiki/Compiling-%E2%80%93-GitInstallation)

Also read [Install Instructions](https://github.com/tesseract-ocr/tesseract/blob/master/INSTALL.GIT.md)

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


## Video representation of the Compiling process for Tesseract 4.0 and Leptonica 1.7.4 on Ubuntu 16.xx

  * Video [Build from Source Leptonica 1.7.4](https://www.youtube.com/watch?v=vOdnt2h1U8U)
  * Video [Build from Source Tesseract-OCR 4.0](https://www.youtube.com/watch?v=WZLJucXZy-g)


## Language Data

  * Download the [data file(s) for the language(s) you interest in](https://github.com/tesseract-ocr/tesseract/wiki/Data-Files).
  * Move it to the `tessdata` directory (e.g. 'mv tessdata $TESSDATA\_PREFIX' if defined `TESSDATA_PREFIX`)

You can also use:
```
export TESSDATA_PREFIX=/some/path/to/tessdata
```
to point to your tessdata directory (example: if your tessdata path is '/usr/local/share/tessdata' you have to use 'export TESSDATA\_PREFIX='/usr/local/share/').


# Windows

## master branch, 3.05 and later

#### Using Tesseract

**!!! IMPORTANT !!!** To use Tesseract in your application (to include tess or to link it into your app) see this very simple example https://github.com/tesseract-ocr/tesseract/wiki/User-App-Example.

#### Build the latest library

1. [Download](https://cppan.org/client/cppan-master-Windows-client.zip) the latest CPPAN (C++ Archive Network `https://cppan.org/`) client from `https://cppan.org/client/`.
2. Run `cppan --build pvt.cppan.demo.google.tesseract.tesseract-master`.

#### Build training tools

Today it is possible to build a full set of tess training tools on Windows with Visual Studio.
The latest versions (Win10, VS2015/VS2017) are preferable.

To do this:

1. [Download](https://cppan.org/client/cppan-master-Windows-client.zip) the latest CPPAN (C++ Archive Network `https://cppan.org/`) client from `https://cppan.org/client/`.
2. Run `cppan --build pvt.cppan.demo.google.tesseract-master`.

#### Develop Tesseract

**For development purposes** of Tesseract itself do the next steps:

1. Download and install Git, CMake and put them in PATH.
2. [Download](https://cppan.org/client/cppan-master-Windows-client.zip) the latest CPPAN (C++ Archive Network `https://cppan.org/`) client from `https://cppan.org/client/`. CPPAN is a source package distribution system. Add CPPAN client in PATH too. (VS2015 redist is required.)
3. If you have a release archive, unpack it to `tesseract` dir. 

If you're using master branch (4.0) run

   ```
   git clone https://github.com/tesseract-ocr/tesseract tesseract
   ```

4. Run

    ```
    cd tesseract
    cppan
    mkdir build && cd build
    cmake ..
    ```

5. Build a solution (`tesseract.sln`) in your Visual Studio version.

**For development purposes** of training tools after cloning a repo from previous paragraph, run 
```
cppan --build .
```

You'll see a solution link appeared in the root directory of Tesseract.

## Building for x64 platform

If you're building with cppan+cmake, run cmake as follows:
```
mkdir win64 && cd win64
cppan ..
cmake .. -G "Visual Studio 14 2015 Win64"
```

If you're building with cppan, edit cppan.yml and uncomment this line:
```
#generator: Visual Studio 14 2015 Win64 -> generator: Visual Studio 14 2015 Win64
```

Then run `cppan --generate .` - it will create a solution link for you.

(For VS2017, use '15 2017' instead of '14 2015'.)

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

Windows relevant files are located in vs2008 directory (e.g. 'tesseract-3.01\vs2008'). The same build process as usual applies: Open tesseract.sln with VC++Express 2008 and build all (or just Tesseract.) It should compile (in at least release mode) without having to install anything further. The dll dependencies and Leptonica are included. Output will be in tesseract-3.01\vs2008\bin (or tesseract-3.01\vs2008\bin.rd or tesseract-3.01\vs2008\bin.dbg based on configuration build).

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

To build tesseract-ocr from the GitHub source, create a PKGBUILD with the following commands.

```
#
_realname=tesseract-ocr
pkgbase=mingw-w64-${_realname}-git
pkgname="${MINGW_PACKAGE_PREFIX}-${_realname}"
provides=("${MINGW_PACKAGE_PREFIX}-${_realname}")
replaces=("${MINGW_PACKAGE_PREFIX}-${_realname}")
pkgver=1310.60176fc
pkgrel=1
pkgdesc="Tesseract OCR (mingw-w64)"
arch=('any')
url="https://github.com/tesseract-ocr/tesseract"
license=("Apache License 2.0")
makedepends=("${MINGW_PACKAGE_PREFIX}-gcc" "${MINGW_PACKAGE_PREFIX}-pkg-config")
depends=(${MINGW_PACKAGE_PREFIX}-cairo
	 ${MINGW_PACKAGE_PREFIX}-cairomm
	 ${MINGW_PACKAGE_PREFIX}-fontconfig
         ${MINGW_PACKAGE_PREFIX}-gcc-libs
         ${MINGW_PACKAGE_PREFIX}-icu
	 icu-devel
	 git
         ${MINGW_PACKAGE_PREFIX}-leptonica
         ${MINGW_PACKAGE_PREFIX}-pango
	 ${MINGW_PACKAGE_PREFIX}-pangomm
	 ${MINGW_PACKAGE_PREFIX}-tesseract-data-eng
         ${MINGW_PACKAGE_PREFIX}-zlib)
options=('!libtool' '!emptydirs' '!strip' 'debug')
source=("tesseract"::"git+https://github.com/tesseract-ocr/tesseract.git#branch=master"
        https://github.com/tesseract-ocr/tessdata/raw/master/osd.traineddata)
sha256sums=('SKIP'
            '9cf5d576fcc47564f11265841e5ca839001e7e6f38ff7f7aacf46d15a96b00ff')
pkgver() {
  cd "${srcdir}/tesseract"
  printf "%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}
prepare() {
  cd "${srcdir}/tesseract"
  ./autogen.sh
}
build() {
  [[ -d "${srcdir}/build-${MINGW_CHOST}" ]] && rm -rf "${srcdir}/build-${MINGW_CHOST}"
  mkdir "${srcdir}/build-${MINGW_CHOST}"
  cd "${srcdir}/build-${MINGW_CHOST}"
  local -a extra_config
  if check_option "debug" "y"; then
    extra_config+=( --enable-debug )
  fi
  "${srcdir}/tesseract"/configure \
    --build=${MINGW_CHOST} \
    --host=${MINGW_CHOST} \
    --target=${MINGW_CHOST} \
    --prefix=${MINGW_PREFIX} \
    LIBLEPT_HEADERSDIR=${MINGW_PREFIX}/include \
    "${extra_config[@]}"
  make
}
package() {
  cd "${srcdir}/build-${MINGW_CHOST}"
  make DESTDIR="${pkgdir}" install
  make training
  make DESTDIR="${pkgdir}" training-install
  mkdir -p ${pkgdir}${MINGW_PREFIX}/share/tessdata
  install -Dm0644 ${srcdir}/osd.traineddata ${pkgdir}${MINGW_PREFIX}/share/tessdata/osd.traineddata
}

```
build and install as follows:

```
cd MINGW-packages/mingw-w64-tesseract-ocr
makepkg-mingw -sLf
pacman -U mingw-w64-*-tesseract-ocr-*-any.pkg.tar.xz
```

## Cygwin

For Cygwin have a look at blog [How to build Tesseract on Cygwin](http://vorba.ch/2014/tesseract-cygwin.html).
Simon Eigeldinger has provided binaries [tesseract compiled by cygwin](http://domasofan.spdns.eu/tesseract/).

On cygwin Marco Atzeri has packaged Tesseract as well as the training utilities for 3.04.00 along with some training data. Instruction for cygwin installation is here:
https://cygwin.com/cygwin-ug-net/setup-net.html

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

## macOS with Fink
Fink (as of 2017-04) neither provides Leptonica nor the packages needed for the Tesseract training tools,
so it cannot be recommended for building Tesseract.

## macOS with MacPorts

### Install required packages

```
sudo port install autoconf autoconf-archive automake libtool
sudo port install pkgconfig
sudo port install leptonica
```

### Compilation
```
  git clone https://github.com/tesseract-ocr/tesseract.git
  cd tesseract
  ./autogen.sh
  ./configure --with-extra-libraries=/opt/local/lib
  make
  sudo make install
```

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
./configure \
    --with-extra-libraries=/opt/local/lib \
    --with-extra-includes=/opt/local/include \
    LDFLAGS=-L/opt/local/lib \
    CPPFLAGS=-I/opt/local/include
make
sudo make install

make training
sudo make training-install
```

## macOS with Homebrew

### Install dependencies

```
brew install automake autoconf autoconf-archive libtool
brew install pkgconfig
brew install icu4c
brew install leptonica
brew install gcc
```

### Compile

As of January 2017, the clang builds but OpenMP will only use a single thread, reducing performance. For best results, use gcc.

The exact values of ``CPPFLAGS`` and ``LDFLAGS`` can be read from ``brew info icu4c``.

```bash
git clone https://github.com/tesseract-ocr/tesseract/
cd tesseract
./autogen.sh
./configure CC=gcc-6 CXX=g++-6 CPPFLAGS=-I/usr/local/opt/icu4c/include LDFLAGS=-L/usr/local/opt/icu4c/lib
make -j
sudo make install  # if desired
make training
```

# Common Errors

* To fix this error
```
./configure: line 4237: syntax error near unexpected token `-mavx,'
./configure: line 4237: `AX_CHECK_COMPILE_FLAG(-mavx, avx=1, avx=0)'
```
ensure that `autoconf-archive` is installed. Don't forget to run `./autogen.sh` after the installation of `autoconf-archive`.

* If configure fails with such error "configure: error: Leptonica 1.74 or higher is required." Try to install libleptonica-dev package.

* If you are sure you have installed leptonica (for example in /usr/local) then probably pkg-config is not looking at your install folder (check with `pkg-config --variable pc_path pkg-config`). 

A solution is to set PKG_CONFIG_PATH : example :`PKG_CONFIG_PATH=/usr/local/lib/pkgconfig`

* On some systems autotools does not create m4 directory automatically (giving the error: "configure: error: cannot find macro directory 'm4'"). 

In this case you must create m4 directory (`mkdir m4`), and then rerun the above commands starting with ./configure.


# Miscellaneous

* [Standalone Tesseract build bash script](http://pastebin.com/VnGLHfbr)
