------------------------------------
### For training Neural net based LSTM Tesseract 4.00 see [Training Tesseract 4.00](../TrainingTesseract-4.00.md)
-------------------------------------

**NOTE:** The instructions below are for **older** 3.0x versions of Tesseract.

* [Make Box Files](#make-box-files)
  * [Bootstrapping a new character set](#bootstrapping-a-new-character-set)
  * [Tif/Box pairs provided!](#tifbox-pairs-provided)


## Make Box Files

For the [Run Tesseract for Training](Training-Tesseract-3.03–3.05.md#run-tesseract-for-training) step, Tesseract needs a 'box' file to go with each training image.
The box file is a text file that lists the characters in the training image, in order, one per line, with the coordinates of the bounding box around the image. Tesseract 3.0 has a mode in which it will output a text file of the required format, but if the character set is different to its current training, it will naturally have the text incorrect. So the key process here is to manually edit the file to put the correct characters in it.

Run Tesseract on each of your training images using this command line:
```
tesseract [lang].[fontname].exp[num].tif [lang].[fontname].exp[num] batch.nochop makebox
```

e.g.
```
tesseract eng.timesitalic.exp0.tif eng.timesitalic.exp0 batch.nochop makebox
```

Now the hard part. You have to edit the file `[lang].[fontname].exp[num].box` and put the UTF-8 codes for each character in the file at the start of each line, in place of the incorrect character put there by Tesseract. Example: The distribution includes an image eurotext.tif. Running the above command produces a text file that includes the following lines (lines 141-154):

```
s 734 494 751 519 0
p 753 486 776 518 0
r 779 494 796 518 0
i 799 494 810 527 0
n 814 494 837 518 0
g 839 485 862 518 0
t 865 492 878 521 0
u 101 453 122 484 0
b 126 453 146 486 0
e 149 452 168 477 0
r 172 453 187 476 0
d 211 451 232 484 0
e 236 451 255 475 0
n 259 452 281 475 0
```

Since Tesseract was run in English mode, it does not correctly recognize the umlaut. This character needs to be corrected using an editor that supports UTF-8. In this case the `u` needs to be changed to `ü`.

Recommended editors that support UTF-8: Notepad++, gedit, KWrite, Geany, Vim, Emacs, Atom, TextMate,  Sublime Text. Choose one! Linux and Windows both have a character map that can be used for copying characters that cannot be typed.

In theory, each line in the box file should represent one of the characters from your training file, but if you have a horizontally broken character, such as the lower double quote „ it will probably have 2 boxes that need to be merged!

Example: lines 116-129:

```
D 101 504 131 535 0
e 135 502 154 528 0
r 158 503 173 526 0
, 197 498 206 510 0
, 206 497 214 509 0
s 220 501 236 526 0
c 239 501 258 525 0
h 262 502 284 534 0
n 288 501 310 525 0
e 313 500 332 524 0
l 336 501 347 534 0
l 352 500 363 532 0
e 367 499 386 524 0
” 389 520 407 532 0
```

As you can see, the low double quote character has been expressed as two single commas. The bounding boxes must be merged as follows:
  * First number (left) take the minimum of the two lines (197)
  * Second number (bottom) take the minimum of the two lines (497)
  * Third number (right) take the maximum of the two lines (214)
  * Fourth number (top) take the maximum of the two lines (510)

This gives:

```
D 101 504 131 535 0
e 135 502 154 528 0
r 158 503 173 526 0
„ 197 497 214 510 0
s 220 501 236 526 0
c 239 501 258 525 0
h 262 502 284 534 0
n 288 501 310 525 0
e 313 500 332 524 0
l 336 501 347 534 0
l 352 500 363 532 0
e 367 499 386 524 0
” 389 520 407 532 0
```

If you didn't successfully space out the characters on the training image, some may have been joined into a single box. In this case, you can either remake the images with better spacing and start again, or if the pair is common, put both characters at the start of the line, leaving the bounding box to represent them both. (As of 3.00, there is a limit of 24 bytes for the description of a "character". This will allow you between 6 and 24 unicodes to describe the character, depending on where your codes sit in the unicode set. If anyone hits this limit, please file an issue describing your situation.)

**Note** that the coordinate system used in the box file has (0,0) at the **bottom-left.**

The last number on each line is the page number (0-based) of that character in the multi-page tiff file.

There are several visual tools for editing box file.
Please check the [AddOns](../AddOns.md#tesseract-box-editors-and-training-tools) documentation.

### Bootstrapping a new character set

If you are trying to train a new character set, it is a good idea to put in the effort on a single font to get one good box file, run the rest of the training process, and then use Tesseract in your new language to make the rest of the box files as follows:
```
tesseract [lang].[fontname].exp[num].tif [lang].[fontname].exp[num] -l yournewlanguage batch.nochop makebox
```
This should make the 2nd box file easier to make, as there is a good chance that Tesseract will recognize most of the text correctly. You can always iterate this sequence adding more fonts to he training set (i.e. to the command line of `mftraining` and `cntraining` below) as you make them, but note that there is no incremental training mode that allows you to add new training data to existing sets. This means that each time you run `mftraining` and `cntraining` you are making new data files from scratch from the tr files you give on the command line, and these programs cannot take an existing `intproto` / `pffmtable` / `normproto` and add to them directly.

### Tif/Box pairs provided!

Tif/Box file pairs are available in the [Downloads Archive on SourceForge](http://sourceforge.net/projects/tesseract-ocr-alt/files/) for these languages:
[Dutch](https://sourceforge.net/projects/tesseract-ocr-alt/files/boxtiff-2.01.nld.tar.gz/download)
[English](https://sourceforge.net/projects/tesseract-ocr-alt/files/boxtiff-2.01.eng.tar.gz/download)
[French](https://sourceforge.net/projects/tesseract-ocr-alt/files/boxtiff-2.01.fra.tar.gz/download)
[German](https://sourceforge.net/projects/tesseract-ocr-alt/files/boxtiff-2.01.deu.tar.gz/download)
[German-fraktur](https://sourceforge.net/projects/tesseract-ocr-alt/files/boxtiff-2.01.deu-f.tar.gz/download)
[Italian](https://sourceforge.net/projects/tesseract-ocr-alt/files/boxtiff-2.01.ita.tar.gz/download)
[Spanish](https://sourceforge.net/projects/tesseract-ocr-alt/files/boxtiff-2.01.spa.tar.gz/download)

Note the tiff files are G4 compressed
to save space, so you will have to have libtiff or uncompress them first).
