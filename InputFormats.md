# Input formats

## Supported input formats

Tesseract uses the [Leptonica](https://github.com/DanBloomberg/leptonica) library to read images in one of these formats:

* PNG - requires libpng, libz
* JPEG - requires libjpeg / libjpeg-turbo
* TIFF - requires libtiff, libz
* JPEG 2000 - requires libopenjp2
* GIF - requires libgif (giflib)
* WebP requires libwebp
* BMP - no library required\*
* PNM - no library required\*

\* Except Leptonica

## Unsupported input formats

If a file format is not supported by Tesseract, you should use a third party software to convert it to another format that is supported by Tesseract.

### PDF

Tesseract does not support reading PDF files.

If you need to OCR PDF files, you should either convert them to another format or use [OCRmyPDF](https://ocrmypdf.readthedocs.io/).

Note: Tesseract does support PDF as an **output** format.

### Animated WebP

Tesseract does not support reading animated WebP files.

### Animated GIF

Tesseract does not support reading animated GIF files.\
If given such a file, Tesseract will only read the first image in the sequence of images contained in the file.

### Other formats

Tesseract does not support these image formats:

* HEIC
* AVIF
* JPEG-XL
