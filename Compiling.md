# Compilation guide for various platforms

**Note:** This wiki expects you to be familiar with compiling software on your operation system.

# Linux / Other Unices

## Dependencies

**Autotools** [Leptonica](http://www.leptonica.org/)

If they are not already installed, you need the following libraries (Ubuntu 16.04/14.04):
```
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
4.00 | 1.74.0 | Must build from source 
3.04 | 1.71 | [Ubuntu 16.04](http://packages.ubuntu.com/xenial/libtesseract3)
3.03 | 1.70 | [Ubuntu 14.04](http://packages.ubuntu.com/trusty/libtesseract3)
3.02 | 1.69 | [Ubuntu 12.04](http://packages.ubuntu.com/precise/libtesseract3)
3.01 | 1.67 |

The sources are at http://www.leptonica.org/. The instructions at [Leptonica README](http://www.leptonica.org/source/README.html) are clear, but basically it is as described in [Compilation](#Compilation) below.

Ensure that the development headers for Leptonica are installed before compiling Tesseract. Note that if building Leptonica from source, you may need to ensure that /usr/local/lib is in your library path. This is a standard Linux bug, and the information at [Stackoverflow](http://stackoverflow.com/questions/4743233/is-usr-local-lib-searched-for-shared-libraries) is very helpful.

## Compilation

Tesseract uses a standard autotools based build system, so the compilation process should be familiar.

```
git clone --depth 1 https://github.com/tesseract-ocr/tesseract.git
cd tesseract
./autogen.sh
./configure --enable-debug
LDFLAGS="-L/usr/local/lib" CFLAGS="-I/usr/local/include" make
sudo make install
sudo ldconfig
```
If configure fails with an error like "syntax error near unexpected token `-mavx,'" and/or AX_CHECK_COMPILE_FLAG(...) then double check you have installed autoconf-archive.

If configure fails with such error "configure: error: Leptonica 1.74 or higher is required. Try to install libleptonica-dev package." and you are sure you have installed leptonica (for example in /usr/local) then probably pkg-config is not looking at your install folder (check with "pkg-config --variable pc_path pkg-config"). A solution is to set PKG_CONFIG_PATH : example :
`PKG_CONFIG_PATH=/usr/local/lib/pkgconfig LIBLEPT_HEADERSDIR=/usr/local/include ./configure --with-extra-includes=/usr/local/include --with-extra-libraries=/usr/local/lib`

Since we have to compile leptonica to use version 1.74, we should use `LDFLAGS="-L/usr/local/lib" CFLAGS="-I/usr/local/include" make` instead of make for tesseract.

On some systems autotools does not create m4 directory automatically (giving the error: "configure: error: cannot find macro directory 'm4'"). In this case you must create m4 directory (`mkdir m4`), and then rerun the above commands starting with ./configure.

If you want the training tools (3.03), you will also need to run the following commands:

```
make training
sudo make training-install
```

Build of training tools is not available if you do not have necessary dependencies (pay attention to messages from ./configure script).

For visual debugging, you also have to build ScrollView.jar. In addition, it is necessary to set the environment variable SCROLLVIEW_PATH to the directory with ScrollView.jar. 

```
make ScrollView.jar
```

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

  * Download the [data file(s) for the language(s) you interest in](https://github.com/tesseract-ocr/tesseract/wiki/Data-Files).
  * Move it to the `tessdata` directory (e.g. 'mv tessdata $TESSDATA\_PREFIX' if defined `TESSDATA_PREFIX`)

You can also use:
```
export TESSDATA_PREFIX=/some/path/to/tessdata
```
to point to your tessdata directory (example: if your tessdata path is '/usr/local/share/tessdata' you have to use 'export TESSDATA\_PREFIX='/usr/local/share/').


# Windows

## master branch, 3.05 and later

#### Using tesseract

**!!! IMPORTANT !!!** To use tesseract in your application (to include tess or to link it into your app) see this very simple example https://github.com/tesseract-ocr/tesseract/wiki/User-App-Example.

#### Build training tools

Today it is possible to build a full set of tess training tools on Windows with Visual Studio.
The latest versions (Win10, VS2015/VS2017) are preferable.

To do this:

1. [Download](https://cppan.org/client/cppan-master-Windows-client.zip) the latest CPPAN (C++ Archive Network `https://cppan.org/`) client from `https://cppan.org/client/`.
2. Run `cppan --build pvt.cppan.demo.google.tesseract-master`.

#### Develop tesseract

**For development purposes** of tesseract itself do the next steps:

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

You'll see a solution link appeared in the root directory of tesseract.

## 3.04.01

If you have Visual Studio 2015, checkout the repository at [Leptonica 1.73 for Visual Studio 2015 which has the solution for Tesseract also] (https://github.com/peirick/VS2015_Tesseract) and click on build_tesseract.bat. After that you still need to download the language packs.

## 3.03rc-1

Have a look at blog [How to build Tesseract 3.03 with Visual Studio 2013](http://vorba.ch/2014/tesseract-3.03-vs2013.html).

## 3.02

For tesseract-ocr 3.02 please follow instruction in [Visual Studio 2008 Developer Notes for Tesseract-OCR](http://tesseract-ocr.googlecode.com/svn/trunk/vs2008/doc/setup.html#using-the-latest-tesseractocr-sources).

## 3.01

Download these packages from the [Downloads Archive on SourceForge](https://sourceforge.net/projects/tesseract-ocr-alt/files/) page:

  * `tesseract-3.01.tar.gz` - Tesseract source
  * `tesseract-3.01-win_vs.zip` - Visual studio (2008 & 2010) solution with necessary libraries
  * `tesseract-ocr-3.01.eng.tar.gz` - English language file for tesseract (or download other language training file)

Unpack them to one directory (e.g. `tesseract-3.01`). Note that `tesseract-ocr-3.01.eng.tar.gz` names the root directory `'tesseract-ocr'` instead of `'tesseract-3.01'`.

Windows relevant files are located in vs2008 directory (e.g. 'tesseract-3.01\vs2008'). The same build process as usual applies: Open tesseract.sln with VC++Express 2008 and build all (or just Tesseract.) It should compile (in at least release mode) without having to install anything further. The dll dependencies and Leptonica are included. Output will be in tesseract-3.01\vs2008\bin (or tesseract-3.01\vs2008\bin.rd or tesseract-3.01\vs2008\bin.dbg based on configuration build).

## Mingw+Msys

For Mingw+Msys have a look at blog [Compiling Leptonica and Tesseract-ocr with Mingw+Msys](http://www.sk-spell.sk.cx/compiling-leptonica-and-tesseract-ocr-with-mingwmsys).

## Msys2 

Download and install Msys2 as given at [MSYS2 installation](https://sourceforge.net/p/msys2/wiki/MSYS2%20installation/)
Also read instructions at [Contributing to MSYS2](https://sourceforge.net/p/msys2/wiki/Contributing%20to%20MSYS2/)

The core packages groups you need to install if you wish to build from PKGBUILDs are:
- base-devel for any building
- msys2-devel for building msys2 packages
- mingw-w64-i686-toolchain for building mingw32 packages
- mingw-w64-x86_64-toolchain for building mingw64 packages

To build the release package, use PKGBUILD from https://github.com/Alexpux/MINGW-packages/tree/master/mingw-w64-tesseract-ocr

To build from the github source, create a PKGBUILD with the following commands.

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

# OS X with MacPorts

(These instructions are probably outdated.)

## Install required packages

```
sudo port install automake autoconf
sudo port install autoconf-archive
sudo port install pkgconfig
sudo port install leptonica
```

## Compilation
```
  git clone git@github.com:tesseract-ocr/tesseract.git
  cd tesseract
  ./autogen.sh
  ./configure --with-extra-libraries=/opt/local/lib
  make
  sudo make install
```

## To install tesseract with training tools

In the above training tools are not installed. You can install not only tesseract but also training tools like below.

### Install packages required by training tools

```
sudo port install cairo pango 
sudo port install icu +devel
```

### Build and Install
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

# macOS with Homebrew

## Install dependencies

```
brew install automake autoconf
brew install autoconf-archive
brew install pkgconfig
brew install leptonica
brew install gcc
```

## Compile

As of November 2016, the build is broken with clang (error on use of `-fopenmp`). These instructions use gcc-6.

```
git clone https://github.com/tesseract-ocr/tesseract/
cd tesseract
./autogen.sh
./configure CC=gcc-6 CXX=g++-6
make -j
sudo make install
```

### Errors
To fix this error
```
./configure: line 4237: syntax error near unexpected token `-mavx,'
./configure: line 4237: `AX_CHECK_COMPILE_FLAG(-mavx, avx=1, avx=0)'
```
ensure that autoconf-archive is installed.

# Miscellaneous

* [Standalone Tesseract build bash script](http://pastebin.com/VnGLHfbr)
