A collection of frequently asked questions and the answers, or pointers to them for **Tesseract 4.0.0**.

For the older version of the FAQ pertaining to Tesseract 2.0x, 3.0x and 4.00.00alpha, please see [FAQ Old](FAQ-Old).

***

If you have a question which is not answered by the FAQ, Wiki pages and Issues, please search in the [users mailing-list/forum](https://groups.google.com/d/forum/tesseract-ocr) before posting it there.

If you think you found a bug in Tesseract, please search existing [issues](https://github.com/tesseract-ocr/tesseract/issues). If you find an existing similar issue, please add to it, otherwise create a [new issue](https://github.com/tesseract-ocr/tesseract/issues/new).

Read the [CONTRIBUTING](https://github.com/tesseract-ocr/tesseract/blob/master/CONTRIBUTING.md) guide before you report an issue in GitHub or ask a question in the forum.

Table of Contents
=================
(Please note, this page is currently being updated for 4.0.0).

* [How do I get tesseract 4.0.0?](#how-do-i-get-tesseract400)
* [Which language models are available for Tesseract 4.0.0?](#which-language-models-are-available-for-tesseract-400)
* [How do I improve OCR results?](#how-do-i-improve-ocr-results)
* [How do I train Tesseract 4.0.0 LSTM Engine?](#how-do-i-train-tesseract-400-lstm-engine)

* [My question isn't in here!](my-question-isnt-in-here)

# Frequently Asked Questions

## How do I get Tesseract 4.0.0?

See [Tesseract Wiki Home](https://github.com/tesseract-ocr/tesseract/wiki) page for details.

## Which language models are available for Tesseract 4.0.0?

See Tesseract man page for the list of [languages](https://github.com/tesseract-ocr/tesseract/blob/master/doc/tesseract.1.asc#languages) and [scripts](https://github.com/tesseract-ocr/tesseract/blob/master/doc/tesseract.1.asc#scripts) supported by Tesseract4.0.0.

See the [Tesseract Wiki Data Files](https://github.com/tesseract-ocr/tesseract/wiki/Data-Files#updated-data-files-for-version-400-september-15-2017) page for information regarding the language models available for Tesseract 4.0.0.

## How do I improve OCR results?

You should note that in many cases, in order to get better OCR results, you'll need to [improve the quality](https://github.com/tesseract-ocr/tesseract/wiki/ImproveQuality) of the input image you are giving Tesseract.

## How do I train Tesseract 4.0.0 LSTM Engine?

Tesseract can be trained to recognize other languages or finetune existing language models. See [Tesseract Wiki Training Tesseract 4.00](https://github.com/tesseract-ocr/tesseract/wiki/TrainingTesseract-4.00) page for information on training the LSTM engine. 

Please note that currently LSTM training is only supported using synthetic images created using a UTF-8 training text and unicode fonts to render the text.

## My question isn't in here!

Try searching the forum: http://groups.google.com/group/tesseract-ocr as well as open and closed issues on GitHub: https://github.com/tesseract-ocr/tesseract/issues, as your question may have come up before even if it is not listed here.