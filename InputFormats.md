# Input formats

## Supported input formats

Tesseract uses the [Leptonica](https://github.com/DanBloomberg/leptonica) library to read images with one of these formats:

* PNG
* JPEG
* TIFF
* JPEG 2000
* GIF
* WebP (including animated WebP)

## Unsupported input formats

If a file format is not suppprted by Tesseract, you should use a third party software to convert it to another format that is supported by Tesseract.

### PDF

Tesseract does not support reading PDF files.

If you need to OCR PDF files, you should either convert them to another format or use [OCRmyPDF](https://ocrmypdf.readthedocs.io/).

Note: Tesseract does support PDF as an **output** format.

### Animated GIF

Tesseract does not support reading animated GIFs files. When given such a file, Tesseract will read only the first image in the sequence of images contained inside the file.

### Other formats

Tesserct does not support the HEIC and the AVIF formats.
