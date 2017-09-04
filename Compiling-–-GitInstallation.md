# Installing Tesseract from Git
These are the instructions for installing Tesseract from the git repository. You should be ready to face unexpected problems.

## Installing With Autoconf Tools
In order to do this; you must have aclocal, autoheader, autoconf, autoconf-archive, automake, libtool, leptonica, and pkg-config installed. In addition, you need a C++ compiler.

On Debian or Ubuntu, you can probably install all required packages like this:
```
apt-get install autoconf-archive automake g++ libtool libleptonica-dev pkg-config
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

or to clone a diffrent branch/version:
```
git clone https://github.com/tesseract-ocr/tesseract.git --branch <branchName> --single-branch tesseract-ocr
```

---

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

## Training Tools
See [Building the training tools](https://github.com/tesseract-ocr/tesseract/wiki/Training-Tesseract#building-the-training-tools).

## Building using Windows Visual Studio
See [Compiling for Windows](https://github.com/tesseract-ocr/tesseract/wiki/Compiling#windows).