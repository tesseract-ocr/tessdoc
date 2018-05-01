# Frequently Asked Questions

A collection of frequently asked questions and the answers, or pointers to them for **Tesseract 4.0.0**.

For the older version of the FAQ pertaining to Tesseract 2.0x, 3.0x and 4.00.00alpha, please see [FAQ Old](FAQ-Old).

***

If you have a question which is not answered by the FAQ, Wiki pages and Issues, please search in the [users mailing-list/forum](https://groups.google.com/d/forum/tesseract-ocr) before posting it there.

If you think you found a bug in Tesseract, please search existing [issues](https://github.com/tesseract-ocr/tesseract/issues). If you find an existing similar issue, please add to it, otherwise create a [new issue](https://github.com/tesseract-ocr/tesseract/issues/new).

Read the [CONTRIBUTING](https://github.com/tesseract-ocr/tesseract/blob/master/CONTRIBUTING.md) guide before you report an issue in GitHub or ask a question in the forum.

***

(Please note, this page is currently being updated for 4.0.0).
# Q&A

## How do I get Tesseract 4.0.0?

See [Tesseract Wiki Home](https://github.com/tesseract-ocr/tesseract/wiki) page for details.

## Which language models are available for Tesseract 4.0.0?

See Tesseract man page for the list of [languages](https://github.com/tesseract-ocr/tesseract/blob/master/doc/tesseract.1.asc#languages) and [scripts](https://github.com/tesseract-ocr/tesseract/blob/master/doc/tesseract.1.asc#scripts) supported by Tesseract4.0.0.

See the [Tesseract Wiki Data Files](https://github.com/tesseract-ocr/tesseract/wiki/Data-Files#updated-data-files-for-version-400-september-15-2017) page for information regarding the language models available for Tesseract 4.0.0.

## What output formats can Tesseract produce?

* txt
* pdf
* hocr
* tsv
* pdf with text layer only

Tesseract's standard output is a plain txt file (utf-8 encoded, with '\n' as [end-of-line marker](http://en.wikipedia.org/wiki/Newline)) and 'FF' as a form feed character after each page.

With the configfile 'pdf' tesseract will produce searchable PDF containing pages images with a hidden, searchable text layer.

With the configfile 'hocr' tesseract will produce XHTML output compliant with the [hOCR specification](https://docs.google.com/document/preview?id=1QQnIQtvdAC_8n92-LhwPcjtAUFwBlzE8EWnKAxlgVf0&pli=1) (the input image name must be ASCII if the operating system use something other than utf-8 encoding for filenames - see [issue 809](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=809) for some details). 

With the configfile 'tsv' tesseract will produce [tab-separated values](https://en.wikipedia.org/wiki/Tab-separated_values) file.

`tesseract -c textonly_pdf=1` will produce a text-only PDF which can be merged with an images-only PDF. See [issue 660](https://github.com/tesseract-ocr/tesseract/issues/660#issuecomment-385669193) for related discussion and utility for merging the PDFs.

## How do I run Tesseract 4.0.0 from the command line?

See [Tesseract Wiki Command Line Usage](https://github.com/tesseract-ocr/tesseract/wiki/Command-Line-Usage) page for information on how to run Tesseract from the command line.

`tesseract --help` will provide the most recent help information for the installed version.

## How to process multiple images in a single run?

Prepare a text file that has the path to each image:

```
path/to/1.png
path/to/2.png
path/to/3.tiff
```

Save it, and then give its name as input file to Tesseract.

`tesseract savedlist output`

## What page separators are used in txt output by Tesseract 4.0.0?

Each page will be terminated by the FF character by default for text output. 

Setting `page_separator` to the LF character would restore the old behaviour of adding an empty line at the end of each page.

Setting `page_separator` to an empty string would omit page separators.

## How do I use Tesseract 4.0.0 using the API?

See [Tesseract Wiki API examples](https://github.com/tesseract-ocr/tesseract/wiki/APIExample) page for sample programs for using the API.

## How do I improve OCR results?

You should note that in many cases, in order to get better OCR results, you'll need to [improve the quality](https://github.com/tesseract-ocr/tesseract/wiki/ImproveQuality) of the input image you are giving Tesseract.

## Can I increase speed of OCR?

If you are running Tesseract 4, you can use the "fast" integer models.

Tesseract 4 also uses up to four CPU threads while processing a page, so it will be faster than Tesseract 3 for a single page. 

If your computer has only two CPU cores, then running four threads will slow down things significantly and it would be better to use a single thread or maybe a maximum of two threads! Using a single thread eliminates the computation overhead of multithreading and is also the best solution for processing lots of images by running one Tesseract process per CPU core. 

Set the maximum number of threads using the environment variable `OMP_THREAD_LIMIT`. 

To disable multithreading, use `OMP_THREAD_LIMIT=1`.

## How do I train Tesseract 4.0.0 LSTM Engine?

Tesseract can be trained to recognize other languages or finetune existing language models. See [Tesseract Wiki Training Tesseract 4.00](https://github.com/tesseract-ocr/tesseract/wiki/TrainingTesseract-4.00) page for information on training the LSTM engine. 

Please note that currently LSTM training is only supported using synthetic images created using a UTF-8 training text and unicode fonts to render the text.

## There are inconsistent results from tesseract when the same TessBaseAPI object is used for decoding multiple images

Try to clear the adaptive data with `ClearAdaptiveClassifier()` or turn off the adaptive classifier with config variables:
```
classify_enable_learning 0
classify_enable_adaptive_matcher 0
```

See also the discussion on the [tesseract forum](https://groups.google.com/d/topic/tesseract-ocr/ByGJhocI9qQ)

## How can I make the error messages go to tesseract.log instead of stderr?

To restore the old behaviour of writing to tesseract.log instead of writing to the console window, you need a text file that contains this:

debug\_file tesseract.log

call the file 'logfile' and put it in tessdata/configs/
Then add logfile to the end of your command line.

## How can I suppress tesseract info line?

See [issue 579](https://web.archive.org/web/*/http://code.google.com/p/tesseract-ocr/issues/detail?id=579). On linux you can redirect stderr and stdout output to /dev/null. E.g.:
```
tesseract phototest.tif phototest 1>/dev/null 2>&1
```
With tesseract 3.02 you can use config "quiet". E.g.:
```
tesseract phototest.tif phototest quiet
```

**Warning:** Both options will cause you to not see the error message if there is one.

## How do I produce searchable PDF output?

Searchable PDF output is a standard feature as of Tesseract version 3.03. Use the `pdf` config file like this:

```
tesseract phototest.tif phototest pdf
```

## The searchable PDF seems to contain only spaces or spaces between the letters of words

There may be nothing wrong with the PDF itself, but its hidden, searchable text layer may be not understood by your PDF reader. For example, Preview.app in Mac OS X is well known for having problems like this, and might "see" only spaces and no text. Try using Adobe Acrobat Reader instead.


## How to do streaming of images to pdf using Tesseract?

Let's say you have an amazing but slow multipage scanning device. It would be 
nice to OCR during scanning. In this example, the scanning program is sending 
image filenames to Tesseract as they are produced. Tesseract streams a 
searchable PDF to stdout. 

```
scanimage --batch --batch-print | tesseract -c stream_filelist=true - - pdf > output.pdf
```

## Can I use Tesseract for handwriting recognition?

You can, but it won't work very well, as Tesseract is designed for printed text. Take a look at the [Lipi Toolkit](http://lipitk.sourceforge.net/) project instead.

## Can I use tesseract for barcode recognition?

No. Tesseract is for text recognition.

## Where is the documentation?

You're looking at it. If things aren't clear, search on the [Tesseract Google Group](http://groups.google.com/group/tesseract-ocr/) or ask us there. If you want to help us write more, please do, and post it to the group!

## How can I try the next version?

Periodically stable versions go to the downloads page. Between releases, and in particular, just before a new release, the latest code is available from git. You can find the source here: https://github.com/tesseract-ocr/tesseract.git where you can check it out either by command line, or by following the link to the howto on using various client programs and plugins.

## How do I compare different versions of Tesseract

If you want to have several version of tesseract (e.g. you want to compare OCR result) I would suggest you to compile them from source (e.g. in /usr/src) and not install them. If you want to test particular version you can run it this way:

```
/usr/src/tesseract-3.03/api/tesseract eurotext.tif eurotext
/usr/src/tesseract-ocr.3.02/api/tesseract eurotext.tif eurotext
```

/usr/src/tesseract-3.03/api/tesseract is shell wrapper script, and it will take care that correct shared library is used (without installation...).

## My question isn't in here!

Try searching the forum: http://groups.google.com/group/tesseract-ocr as well as open and closed issues on GitHub: https://github.com/tesseract-ocr/tesseract/issues, as your question may have come up before even if it is not listed here.