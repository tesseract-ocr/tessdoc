User patterns can be useful when recognizing ID type of fields which have non-dictionary words but follow specific patterns of alphabets and digits e.g. `\A\A\d\d\d\d\A`  or `\A\A\d\d\d\A`

This wiki page provides a simple example on how to use the tesseract-ocr API (4.x) in C++ for applying `user_patterns` for improving recognition. It is expected that tesseract-ocr is correctly installed including all dependencies.
It is expected the user is familiar with C++, compiling and linking program on their platform.

This is based on [an example provided in tesseract-ocr forum](https://groups.google.com/forum/#!msg/tesseract-ocr/y052O_DwYic/gsJN1NHBfqkJ) and updated for the [recent implementation of the feature for tesseract 4.x](https://github.com/tesseract-ocr/tesseract/pull/2328).

## Requirements

In order to apply `user_patterns` for improving recognition, the following are required.

### user_patterns_file

The `user_patterns_file` should contain one pattern per line in UTF-8 format.  In choosing which patterns to include please be aware of the fact that providing very generic patterns will make tesseract run slower. Best results may be obtained by having a single pattern in the file. 

Details of type of patterns that can be used are given in [trie.h](https://github.com/tesseract-ocr/tesseract/blob/master/src/dict/trie.h#L185). 

#### Example of a user_patterns_file (use UNIX line endings and blank line at end)

Make a text file named `path/to/my.patterns` and put the pattern in it, e.g.

```
\A\A\d\d\d\d\A

```

### config_file

From command line user_patterns can be invoked as follows:

```
tesseract input.tif output --user-patterns user_patterns_file -c lstm_use_matrix=1
```

For the API this information about `user_patterns_file` and config variable `lstm_use_matrix` needs to be specified using a `config_file`. 

#### Example of a config_file(use UNIX line endings and blank line at end)

Make a text file named `path/to/my.patterns.config` and put the following in it, e.g.

```
user_patterns_file path/to/my.patterns
lstm_use_matrix 1

```

## API Example

The following example uses the above `user_patterns_file` and `config_file` with this image (Arial.png).

 <img src="https://user-images.githubusercontent.com/5095331/60698052-34c08680-9f0b-11e9-8c9a-7c1aaa9b1e02.png" height=400>

```
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

int main()
{
    Pix *image;
    char *outText; 
    char *configs[]={"my.patterns.config"};
    int configs_size = 1;
	tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    if (api->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY, configs, configs_size, NULL, NULL, false)) {
      fprintf(stderr, "Could not initialize tesseract.\n");
      exit(1);
    }
    image = pixRead("Arial.png");
    api->SetImage(image);
    outText = api->GetUTF8Text();
    printf(outText);
    api->End();
    delete [] outText;
    pixDestroy(&image);
    return 0;
}

```

Build and Run script

```
#!/bin/bash

export CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:/usr/local/include
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib

g++ -std=c++17  -o my.patterns.api my.patterns.api.cpp   -llept -ltesseract

export TESSDATA_PREFIX=~/tessdata_best

./my.patterns.api > Arial-patterns.txt

diff -u  Arial-patterns.txt  Arial-gt.txt

```

With the user_patterns_file for this image, the recognition is 100% correct. Without it, there are a number of errors.

```
--- Arial-patterns-no.txt       2019-07-05 04:21:04.367188492 +0000
+++ Arial-gt.txt        2019-07-05 04:05:11.000000000 +0000
@@ -1,20 +1,20 @@
 DQ2679M
 LO6217I
 QK2101G
-JBO363H
+JB0363H
 KN2873M
-Z2B0929J
+ZB0929J
 JF3829W
-YNO0584J
-SVv8400Q
+YN0584J
+SV8400Q
 FY4523X
 KS0016J
 OB3016R
 VA4335P
-QHO205V
-UH20932
+QH0205V
+UH2093Z
 GW3760Y
-S02306T
+SO2306T
 XT8204F
-MR6804|
-0OX5866M
+MR6804I
+OX5866M
```