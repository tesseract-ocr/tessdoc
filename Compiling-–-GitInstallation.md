# Installing Tesseract from Git
These are the instructions for installing Tesseract from the git repository. You should be ready to face unexpected problems.

## Installing With Autoconf Tools
In order to do this; you must have aclocal, autoheader, autoconf, automake, libtool, leptonica, and pkg-config installed. In addition, you need a C++ compiler.

On Debian or Ubuntu, you can probably install all required packages like this:
```
apt-get install autoconf automake g++ libtool libleptonica-dev make pkg-config
```

The optional manpages are built with asciidoc:
```
apt-get install --no-install-recommends asciidoc
```

If you want to build the Tesseract training tools as well, you'll also require Pango:
```
apt-get install libpango1.0-dev
```

---

Afterwards, to clone the master branch to your computer, do this:
```
git clone https://github.com/tesseract-ocr/tesseract.git tesseract-ocr
```

or to make a shallow clone with commit history truncated to the latest commit only:
```
git clone --depth 1  https://github.com/tesseract-ocr/tesseract.git tesseract-ocr
```

or to clone a different branch/version:
```
git clone https://github.com/tesseract-ocr/tesseract.git --branch <branchName> --single-branch tesseract-ocr
```

---
**Note:** Leptonica v1.74 needs to be manually compiled from source available at [DanBloomberg/leptonica](https://github.com/DanBloomberg/leptonica).

Finally, run these:
```
    cd tesseract-ocr
    ./autogen.sh
    ./configure
    make
    sudo make install
    sudo ldconfig
```

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

### Debug Builds
Such builds produce Tesseract binaries which run very slowly. They are not useful for production, but good to find or analyze software problems. This is a proven build sequence:

    cd tesseract-ocr
    ./autogen.sh
    mkdir -p bin/debug
    cd bin/debug
    ../../configure --enable-debug --disable-shared 'CXXFLAGS=-g -O0 -Wall -Wextra -Wpedantic -fsanitize=address -fsanitize=leak -fsanitize=undefined -fstack-protector-strong -ftrapv'
    make training
    cd ../..

This activates debug code, does not use a shared Tesseract library (that makes it possible to run `tesseract` without installation), disables compiler optimizations (allows better debugging with `gdb`), enables lots of compiler warnings and enables several run time checks.


### Profiling Builds
Such builds can be used to investigate performance problems. Tesseract will run slower than without profiling, but with acceptable speed. This is a proven build sequence:

    cd tesseract-ocr
    ./autogen.sh
    mkdir -p bin/profiling
    cd bin/profiling
    ../../configure --disable-shared 'CXXFLAGS=-g -p -O2 -Wall -Wextra -Wpedantic'
    make training
    cd ../..

This does not use a shared Tesseract library (that makes it possible to run `tesseract` without installation),
enables profiling code,
enables compiler optimizations and enables lots of compiler warnings.

Optionally this can also be used with debug code by adding `--enable-debug` and replacing `-O2` by `-O0`.

The profiling code creates a file named `gmon.out` in the current directory when Tesseract terminates.
GNU gprof is used to show the profiling information from that file.


## Training Tools
See [Building the training tools](https://github.com/tesseract-ocr/tesseract/wiki/Training-Tesseract#building-the-training-tools).

## Building using Windows Visual Studio
See [Compiling for Windows](https://github.com/tesseract-ocr/tesseract/wiki/Compiling#windows).