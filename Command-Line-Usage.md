## [Tesseract 'man' page](https://github.com/tesseract-ocr/tesseract/blob/master/doc/tesseract.1.asc)

## Tesseract --help

    Usage:
      tesseract --help | --help-psm | --version
      tesseract  --list-langs [--tessdata-dir PATH]
      tesseract  --print-parameters [options...] [configfile...]
      tesseract  imagename|stdin outputbase|stdout [options...] [configfile...]
    
    OCR options:
      --tessdata-dir PATH   Specify the location of tessdata path.
      --user-words PATH     Specify the location of user words file.
      --user-patterns PATH  Specify the location of user patterns file.
      -l LANG[+LANG]        Specify language(s) used for OCR.
      -c VAR=VALUE          Set value for config variables.
                            Multiple -c arguments are allowed.
      -psm NUM              Specify page segmentation mode.
    NOTE: These options must occur before any configfile.
    
    Page segmentation modes:
      0    Orientation and script detection (OSD) only.
      1    Automatic page segmentation with OSD.
      2    Automatic page segmentation, but no OSD, or OCR.
      3    Fully automatic page segmentation, but no OSD. (Default)
      4    Assume a single column of text of variable sizes.
      5    Assume a single uniform block of vertically aligned text.
      6    Assume a single uniform block of text.
      7    Treat the image as a single text line.
      8    Treat the image as a single word.
      9    Treat the image as a single word in a circle.
     10    Treat the image as a single character.
    
    Single options:
      -h, --help            Show this help message.
      --help-psm            Show page segmentation modes.
      -v, --version         Show version information.
      --list-langs          List available languages for tesseract engine.
      --print-parameters    Print tesseract parameters to stdout.

## Simplest Invocation to OCR an image

    tesseract imagename outputbase

This uses **English** as the default language and 3 as the Page Segmentation Mode. The default output format is **text**.

osd.traineddata, for Orientation and Segmentation and eng.traineddata and other language data files for English should be in the "tessdata" directory. TESSDATA_PREFIX environment variable should be set to the parent directory of "tessdata" directory. 

The following command would give the same result as above, if eng.traineddata and osd.traineddata files are in /usr/share/tessdata directory.

    tesseract --tessdata-dir /usr/share imagename outputbase -l eng psm 3

## Using One Language

    tesseract  --tessdata-dir /usr/share ./testing/phototest.tif ./testing/phototest  -l eng

![alt text](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")

![eurotext.png](http://dev.blog.fairway.ne.jp/wp-content/uploads/2014/04/eurotext.png)

## Using Multiple Languages

    tesseract  --tessdata-dir /usr/share ./testing/eurotext.png ./testing/eurotext-engdeu -l eng+deu

The output can be different based on the order of languages, so -l eng+deu can give different result than -l deu+eng.

## Using different Page Segmentation Modes

    tesseract   --tessdata-dir /usr/share testing/san002.tif testing/san002-psm3 -l san 

    tesseract   --tessdata-dir /usr/share testing/san002.tif testing/san002-psm6 -l san -psm 6 

## Searchable pdf ouptput

## HOCR output

## TSV output (only available in 3.05-dev in master branch)




