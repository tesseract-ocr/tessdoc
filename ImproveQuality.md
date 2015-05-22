# Improving the quality of the output

There are a variety of reasons you might not get good quality output from Tesseract. It's important to note that unless you're using a very unusual font or a new language retraining Tesseract is unlikely to help.



## DPI

Tesseract works best with text using a DPI of at least 300 dpi, so it may be beneficial to resize images. For more information see [the FAQ](FAQ#is-there-a-minimum-text-size-it-wont-read-screen-text).

## Image processing

Tesseract does various image processing operations internally (using the Leptonica library) before doing the actual OCR. It generally does a very good job of this, but there will inevitably be cases where it isn't good enough, which can result in a significant reduction in accuracy.

You can see how Tesseract has processed the image by using the [configuration variable](ControlParams) `tessedit_write_images` to `true` when running Tesseract. If the resulting `tessinput.tif` file looks problematic, try some of these image processing operations before passing the image to Tesseract, whether with a dedicated postprocessing tool like [Scan Tailor](http://scantailor.sourceforge.net/) or [unpaper](https://www.flameeyes.eu/projects/unpaper), using a graphics editor like [ImageJ](http://rsb.info.nih.gov/ij/) or [Gimp](http://www.gimp.org), with a batch image editor like [ImageMagick](http://www.imagemagick.org), or in code using an image processing library like [Leptonica](http://leptonica.com).

### Binarisation

![binarisation.png](https://github.com/tesseract-ocr/tesseract/wiki/binarisation.png)

This is converting an image to black and white. Tesseract does this internally, but it can make mistakes, particularly if the page background is of uneven darkness.


### Noise

![noise.png](https://github.com/tesseract-ocr/tesseract/wiki/noise.png)

Noise is random variation of brightness or colour in an image, that can make the text of the image more difficult to read. Certain types of noise cannot be removed by Tesseract in the binarisation step, which can cause accuracy rates to drop.


### Orientation / Skew

![skew-linedetection.png](https://github.com/tesseract-ocr/tesseract/wiki/skew-linedetection.png)

This is when an page has been scanned when not straight. The quality of Tesseract's line segmentation reduces significantly if a page is too skewed, which severely impacts the quality of the OCR. To address this rotating the page image so that the text lines are horizontal.


### Borders

![borders.png](https://github.com/tesseract-ocr/tesseract/wiki/borders.png)

Scanned pages often have dark borders around them. These can be erroneously picked up as extra characters, especially if they vary in shape and gradation.


## Segmentation method

By default Tesseract expects a page of text when it segments an image. If you're just seeking to OCR a small region try a different segmentation mode, using the `-psm` argument. Note that adding a border to the text may also help, see [issue 398](https://code.google.com/p/tesseract-ocr/issues/detail?id=398).


## Dictionaries, word lists, and patterns

By default Tesseract is optimised to recognise sentences of words. If you're trying to recognise something else, like receipts, price lists, or codes, there are a few things you can do to improve the accuracy of your results, as well as double-checking that the appropriate [segmentation method](#Segmentation_method) is selected.

Disabling the dictionaries Tesseract uses should increase recognition if most of your text isn't dictionary words. They can be disabled by setting the both of the [configuration variables](ControlParams) `load_system_dawg` and `load_freq_dawg` to `false`.

It is also possible to add words to the word list Tesseract uses to help recognition, or to add common character patterns, which can further help to improve accuracy if you have a good idea of the sort of input you expect. This is explained in more detail in the [Tesseract manual](http://tesseract-ocr.googlecode.com/svn-history/trunk/doc/tesseract.1.html#_config_files_and_augmenting_with_user_data).

If you know you will only encounter a subset of the characters available in the language, such as only digits, you can use the `tessedit_char_whitelist` [configuration variable](ControlParams). See the [FAQ for an example](FAQ#how-do-i-recognize-only-digits).


## Examples

If you need an example how to improve image quality programmatically, have a look at this examples:

  * [OpenCV - Rotation (Deskewing)](http://felix.abecassis.me/2011/10/opencv-rotation-deskewing/) - c++ example
  * [Fred's ImageMagick TEXTCLEANER](http://www.fmwconcepts.com/imagemagick/textcleaner/index.php) - bash script for processesing a scanned document of text to clean the text background.
  * [rotation\_spacing.py](https://gist.github.com/endolith/334196bac1cac45a4893#) - python script for automatic detection of rotation and line spacing of an image of text


## Still having problems?

If you've tried the above and are still getting low accuracy results, [ask on the forum](https://groups.google.com/forum/?fromgroups#!forum/tesseract-ocr) for help, ideally posting an example image.