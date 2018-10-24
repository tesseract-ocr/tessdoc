# Improving the quality of the output

There are a variety of reasons you might not get good quality output from Tesseract. It's important to note that unless you're using a very unusual font or a new language retraining Tesseract is unlikely to help.


* [Image processing](#image-processing)
  * [Rescaling](#rescaling)
  * [Binarisation](#binarisation)
  * [Noise Removal](#noise-removal)
  * [Rotation / Deskewing](#rotation--deskewing)
  * [Borders](#Borders)
  * [Tools / Libraries](#tools--libraries)
  * [Examples](#examples)
* [Page segmentation method](#page-segmentation-method)
* [Dictionaries, word lists, and patterns](#dictionaries-word-lists-and-patterns)
* [Still having problems?](#still-having-problems)


## Image processing

Tesseract does various image processing operations internally (using the Leptonica library) before doing the actual OCR. It generally does a very good job of this, but there will inevitably be cases where it isn't good enough, which can result in a significant reduction in accuracy.

You can see how Tesseract has processed the image by using the [configuration variable](ControlParams) `tessedit_write_images` to `true` when running Tesseract. If the resulting `tessinput.tif` file looks problematic, try some of these image processing operations before passing the image to Tesseract. 

### Rescaling

Tesseract works best on images which have a DPI of at least 300 dpi, so it may be beneficial to resize images. For more information see [the FAQ](FAQ#is-there-a-minimum-text-size-it-wont-read-screen-text).

### Binarisation

![binarisation.png](https://github.com/tesseract-ocr/tesseract/wiki/binarisation.png)

This is converting an image to black and white. Tesseract does this internally, but the result can be suboptimal, particularly if the page background is of uneven darkness.


### Noise Removal

![noise.png](https://github.com/tesseract-ocr/tesseract/wiki/noise.png)

Noise is random variation of brightness or colour in an image, that can make the text of the image more difficult to read. Certain types of noise cannot be removed by Tesseract in the binarisation step, which can cause accuracy rates to drop.


### Rotation / Deskewing

![skew-linedetection.png](https://github.com/tesseract-ocr/tesseract/wiki/skew-linedetection.png)

A skewed image is when a page has been scanned when not straight. The quality of Tesseract's line segmentation reduces significantly if a page is too skewed, which severely impacts the quality of the OCR. To address this rotating the page image so that the text lines are horizontal.


### Borders

#### Scanning border Removal
![borders.png](https://github.com/tesseract-ocr/tesseract/wiki/borders.png)

Scanned pages often have dark borders around them. These can be erroneously picked up as extra characters, especially if they vary in shape and gradation.

#### Missing borders

If you are OCR just text area without any border, tesseract could have problems with it. See for some details in [tesseract user forum](https://groups.google.com/forum/?utm_medium=email&utm_source=footer#!msg/tesseract-ocr/v26a-RYPSOE/2Sppq61GBwAJ)[#427](https://github.com/tesseract-ocr/tesseract/issues/427) . You can easy add small border (e.g. 10 pt) with [ImageMagick®](http://imagemagick.org/script/index.php):
```
convert  427-1.jpg  -bordercolor White -border 10x10 427-1b.jpg
```

### Tools / Libraries

* [Leptonica](http://leptonica.com)
* [OpenCV](http://opencv.org/)
* [Scan Tailor](http://scantailor.sourceforge.net/)
* [ImageMagick](http://www.imagemagick.org)
* [unpaper](https://www.flameeyes.eu/projects/unpaper)
* [ImageJ](http://rsb.info.nih.gov/ij/)
* [Gimp](http://www.gimp.org)

### Examples

If you need an example how to improve image quality programmatically, have a look at this examples:

  * [OpenCV - Rotation (Deskewing)](http://felix.abecassis.me/2011/10/opencv-rotation-deskewing/) - c++ example
  * [Fred's ImageMagick TEXTCLEANER](http://www.fmwconcepts.com/imagemagick/textcleaner/index.php) - bash script for processing a scanned document of text to clean the text background.
  * [rotation\_spacing.py](https://gist.github.com/endolith/334196bac1cac45a4893#) - python script for automatic detection of rotation and line spacing of an image of text
  * [crop\_morphology.py](https://github.com/danvk/oldnyc/blob/master/ocr/tess/crop_morphology.py) - [Finding blocks of text in an image using Python, OpenCV and numpy](http://www.danvk.org/2015/01/07/finding-blocks-of-text-in-an-image-using-python-opencv-and-numpy.html)
  * [Credit card OCR with OpenCV and Python](https://www.pyimagesearch.com/2017/07/17/credit-card-ocr-with-opencv-and-python)


## Page segmentation method

By default Tesseract expects a page of text when it segments an image. If you're just seeking to OCR a small region try a different segmentation mode, using the `--psm` argument. Note that adding a white border to text which is too tightly cropped may also help, see [issue 398](https://web.archive.org/web/20151209085049/https://code.google.com/p/tesseract-ocr/issues/detail?id=398).

To see a complete list of supported page segmentation modes, use `tesseract -h`. Here's the list as of 3.21:

```
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
 11    Sparse text. Find as much text as possible in no particular order.
 12    Sparse text with OSD.
 13    Raw line. Treat the image as a single text line,
			bypassing hacks that are Tesseract-specific.
```

## Dictionaries, word lists, and patterns

By default Tesseract is optimized to recognize sentences of words. If you're trying to recognize something else, like receipts, price lists, or codes, there are a few things you can do to improve the accuracy of your results, as well as double-checking that the appropriate [segmentation method](#page-segmentation-method) is selected.

Disabling the dictionaries Tesseract uses should increase recognition if most of your text isn't dictionary words. They can be disabled by setting the both of the [configuration variables](ControlParams) `load_system_dawg` and `load_freq_dawg` to `false`.

It is also possible to add words to the word list Tesseract uses to help recognition, or to add common character patterns, which can further help to improve accuracy if you have a good idea of the sort of input you expect. This is explained in more detail in the [Tesseract manual](https://github.com/tesseract-ocr/tesseract/blob/master/doc/tesseract.1.asc#config-files-and-augmenting-with-user-data).

If you know you will only encounter a subset of the characters available in the language, such as only digits, you can use the `tessedit_char_whitelist` [configuration variable](ControlParams). See the [FAQ for an example](FAQ#how-do-i-recognize-only-digits).


## Still having problems?

If you've tried the above and are still getting low accuracy results, [ask on the forum](https://groups.google.com/forum/?fromgroups#!forum/tesseract-ocr) for help, ideally posting an example image.
