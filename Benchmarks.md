This page is dedicated to benchmarking various tesseract version and options.
As input image for testing is used image from [issue 236](https://github.com/tesseract-ocr/tesseract/issues/263).

# Information about testing enviroment
* Windows 10 64bit
* compiler: VS 2019
* CPU: Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz 6 cores
* memory: 16GB RAM

# tesseract version info
 information provided by `tesseract -v`

## 3.05

```sh
tesseract 3.05.02
 leptonica-1.83.0 (Dec 17 2021, 17:33:37) [MSC v.1929 LIB Release x64]
  libgif 5.2.1 : libjpeg 6b (libjpeg-turbo 2.0.91) : libpng 1.6.37 : libtiff 4.3.0 : zlib 1.2.11 : libwebp 1.2.0 : libopenjp2 2.4.0
```

## 4.1

### No AVX  support

```sh
tesseract 4.1.3
 leptonica-1.83.0 (Dec 17 2021, 17:33:37) [MSC v.1929 LIB Release x64]
  libgif 5.2.1 : libjpeg 6b (libjpeg-turbo 2.0.91) : libpng 1.6.37 : libtiff 4.3.0 : zlib 1.2.11 : libwebp 1.2.0 : libopenjp2 2.4.0
 Found libarchive 3.5.1 zlib/1.2.11 liblzma/5.2.4 bz2lib/1.0.6 libzstd/1.4.9
```

## 5.0

### AVX supported + OpenMP

```sh
tesseract 5.0.1
 leptonica-1.83.0 (Dec 17 2021, 17:33:37) [MSC v.1929 LIB Release x64]
  libgif 5.2.1 : libjpeg 6b (libjpeg-turbo 2.0.91) : libpng 1.6.37 : libtiff 4.3.0 : zlib 1.2.11 : libwebp 1.2.0 : libopenjp2 2.4.0
 Found AVX2
 Found AVX
 Found FMA
 Found SSE4.1
 Found libarchive 3.5.1 zlib/1.2.11 liblzma/5.2.4 bz2lib/1.0.6 libzstd/1.4.9
 Found libcurl/7.75.0 zlib/1.2.11 libssh2/1.10.1_DEV
 ```
 
 ### AVX supported with VS autoparalalization support 
 
 build with: `cmake -E env CXXFLAGS="/Qpar /fp:fast" cmake ..`
 
 ```sh
 tesseract 5.0.1
 leptonica-1.83.0 (Dec 17 2021, 17:33:37) [MSC v.1929 LIB Release x64]
  libgif 5.2.1 : libjpeg 6b (libjpeg-turbo 2.0.91) : libpng 1.6.37 : libtiff 4.3.0 : zlib 1.2.11 : libwebp 1.2.0 : libopenjp2 2.4.0
 Found AVX2
 Found AVX
 Found FMA
 Found SSE4.1
 Found libarchive 3.5.1 zlib/1.2.11 liblzma/5.2.4 bz2lib/1.0.6 libzstd/1.4.9
 Found libcurl/7.75.0 zlib/1.2.11 libssh2/1.10.1_DEV
 ```
 
 ### AVX supported + OpenMP
  
 ```sh
 tesseract 5.0.1
 leptonica-1.83.0 (Dec 17 2021, 17:33:37) [MSC v.1929 LIB Release x64]
  libgif 5.2.1 : libjpeg 6b (libjpeg-turbo 2.0.91) : libpng 1.6.37 : libtiff 4.3.0 : zlib 1.2.11 : libwebp 1.2.0 : libopenjp2 2.4.0
 Found AVX2
 Found AVX
 Found FMA
 Found SSE4.1
 Found OpenMP 2019
 Found libarchive 3.5.1 zlib/1.2.11 liblzma/5.2.4 bz2lib/1.0.6 libzstd/1.4.9
 Found libcurl/7.75.0 zlib/1.2.11 libssh2/1.10.1_DEV
  ```
 
