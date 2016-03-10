# [Tesseract 'man' page](https://github.com/tesseract-ocr/tesseract/blob/master/doc/tesseract.1.asc)

# Tesseract --help

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

# Simplest Invocation to OCR an image

    tesseract imagename outputbase

# Using One Language

# Using Multiple Languages

# Using different Page Segmentation Modes

# Searchable pdf ouptput

# HOCR output

# TSV output (only available in 3.05-dev in master branch)





