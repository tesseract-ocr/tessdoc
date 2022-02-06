# Benchmarks

This page is dedicated to simple benchmarking of various tesseract version and options.
As input image for testing is used image from [issue 236](https://github.com/tesseract-ocr/tesseract/issues/263).


## Results

| Build       | [tessdata_best ](https://github.com/tesseract-ocr/tessdata_best)| [tessdata_fast](https://github.com/tesseract-ocr/tessdata_fast) | [tessdata ](https://github.com/tesseract-ocr/tessdata)|
| ---              |    ---: |   ---: |     ---: |
| 305              |    -    |    -   |  2.4713  |
| 413noavx         | 37.6052 | 5.1589 | 10.1519  |
| 413avx           | 12.7300 | 2.9538 |  4.0860  |
| 501              |  6.1981 | 2.1241 |  2.9107  |
| 501ap            |  6.1369 | 2.1254 |  2.9221  |
| 501openmp        |  3.4590 | 1.9612 |  2.3554  |



## Information about testing enviroment
* Windows 10 64bit
* compiler: VS 2019
* CPU: Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz 6 cores
* memory: 16GB RAM

Tested with python code
```py
import timeit
import time
import os
import pytesseract

start_time = time.time()
tess_exe = r"msvc.v5.openmp\tesseract.exe"
test_image = r"i263_speed.jpg"
os.environ['TESSDATA_PREFIX'] = r"tessdata_best\tessdata"

code_to_test = """
import pytesseract
pytesseract.pytesseract.tesseract_cmd = r"{}"
pytesseract.pytesseract.image_to_string(r"{}", lang = 'eng')
"""

runs = 15
elapsed_time = timeit.timeit(code_to_test.format((tess_exe, test_image), number=runs)/runs
print("\nDuration:", elapsed_time)

```

## Tesseract build info
 information provided by `tesseract -v`

### 3.05

#### 305
It uses the legacy engine.

```sh
tesseract 3.05.02
 leptonica-1.83.0 (Dec 17 2021, 17:33:37) [MSC v.1929 LIB Release x64]
  libgif 5.2.1 : libjpeg 6b (libjpeg-turbo 2.0.91) : libpng 1.6.37 : libtiff 4.3.0 : zlib 1.2.11 : libwebp 1.2.0 : libopenjp2 2.4.0
```

### 4.1

#### 413noavx

Build without AVX2/AVX/SSE4 support

```sh
tesseract 4.1.3
 leptonica-1.83.0 (Dec 17 2021, 17:33:37) [MSC v.1929 LIB Release x64]
  libgif 5.2.1 : libjpeg 6b (libjpeg-turbo 2.0.91) : libpng 1.6.37 : libtiff 4.3.0 : zlib 1.2.11 : libwebp 1.2.0 : libopenjp2 2.4.0
 Found libarchive 3.5.1 zlib/1.2.11 liblzma/5.2.4 bz2lib/1.0.6 libzstd/1.4.9
```

#### 413avx

Build with AVX2/AVX/SSE4 support

```sh
tesseract 4.1.3-1-ge9986
 leptonica-1.83.0 (Jan 26 2022, 19:15:03) [MSC v.1929 LIB Release x64]
  libgif 5.2.1 : libjpeg 6b (libjpeg-turbo 2.0.91) : libpng 1.6.37 : libtiff 4.3.0 : zlib 1.2.11
 Found AVX2
 Found AVX
 Found FMA
 Found SSE
 Found libarchive 3.5.1 zlib/1.2.11 liblzma/5.2.4 bz2lib/1.0.6 libzstd/1.4.9
```

### 5.0

#### 501

AVX2 supported

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
 
 #### 501ap
 
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
 
 #### 501openmp

OpenMP build is know to use huge waste of CPU time. Because several users report problems it is turn off by default in version 5.0.1. For other version (>= 4.x) it is suggested to use enviroment variable `OMP_THREAD_LIMIT=1`. Input from OpenMP experts would be appreciated.

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
 
