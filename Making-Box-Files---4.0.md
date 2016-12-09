The required format for LSTM 4.0alpha is still the tiff/box file pair, except that the boxes only need to cover a textline instead of individual characters. 'Newline' boxes with tab as the character must be inserted between textlines to indicate the end-of-line. 

The following are example of 4.0 box tiff pairs created as part of LSTM training tutorial.

* [Box File](https://github.com/Shreeshrii/tessdata4alpha/blob/master/eng.Impact_Condensed.exp0.box)
* [Tif Image](https://github.com/Shreeshrii/tessdata4alpha/blob/master/eng.Impact_Condensed.exp0.tif)

See 
https://github.com/tesseract-ocr/tesseract/wiki/TrainingTesseract-4.00#creating-training-data for more details.