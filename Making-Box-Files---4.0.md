The required format for LSTM 4.0alpha is still the tiff/box file pair, except that the boxes only need to cover a textline instead of individual characters. 'Newline' boxes with tab as the character must be inserted between textlines to indicate the end-of-line. 

The following is example of 4.0 box and image pairs created by text2image/tesstrain.sh.

* [Box File](https://github.com/tesseract-ocr/tesseract/files/1935824/eng.Times_New_Roman.exp0.box.txt)
* [Image](https://user-images.githubusercontent.com/5095331/39097174-8ee9c5d4-4676-11e8-9023-a9657006eabc.png)

See 
https://github.com/tesseract-ocr/tesseract/wiki/TrainingTesseract-4.00#creating-training-data for more details.