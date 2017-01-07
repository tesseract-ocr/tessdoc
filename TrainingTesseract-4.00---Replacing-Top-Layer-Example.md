Please see https://github.com/tesseract-ocr/tesseract/wiki/TrainingTesseract-4.00 for details of removing some of the top layers of an existing network model, replacing them with new randomized layers, and training with new data. 

You have to supply a unicharset and net_spec, and you also have to provide a model to --continue_from and --append_index.

---
Have copies of the 4.0.0 alpha langdata, tessdata and tesseract-ocr repositories in the following directory structure.

```
./langdata
./tessdata
./tesseract-ocr
./tesseract-ocr/tessdata
./tesseract-ocr/tessdata/configs/
```
Check that lstm.train is available under configs.

Set up appropriate TESSDATA_PREFIX directory.

Make a copy of Norwegian and English 4.0.0alpha traineddata files in ./tesseract-ocr/tessdata
```
cp ./tessdata/eng.traineddata ./tesseract-ocr/tessdata
cp ./tessdata/nor.traineddata ./tesseract-ocr/tessdata
```

Change to the tesseract-ocr directory.

```
cd ./tesseract-ocr
```
Then follow the given commands.
```
training/tesstrain.sh --fonts_dir /usr/share/fonts --lang nor \
   --linedata_only --noextract_font_properties \
   --langdata_dir ../langdata --tessdata_dir ./tessdata \
   --output_dir ~/tesstutorial/nor
 
mkdir -p ~/tesstutorial/nor_layer 
 
combine_tessdata -e ../tessdata/nor.traineddata \
  ~/tesstutorial/nor_layer/nor.lstm

 lstmtraining -U ~/tesstutorial/nor/nor.unicharset \
  --script_dir ../langdata  --debug_interval 0 \
  --continue_from ~/tesstutorial/nor_layer/nor.lstm \
  --append_index 5 --net_spec '[Lfx256 O1c105]' \
  --model_output ~/tesstutorial/nor_layer/norlayer \
  --train_listfile ~/tesstutorial/nor/nor.training_files.txt \
  --max_iterations 50000 
    
lstmtraining --model_output ~/tesstutorial/nor_layer/norlayer.lstm \
  --continue_from ~/tesstutorial/nor_layer/norlayer0.853_1615.lstm \
  --stop_training

cp ../tessdata/nor.traineddata ./tessdata
  
combine_tessdata -o ./tessdata/nor.traineddata \
~/tesstutorial/nor_layer/norlayer.lstm \
  ~/tesstutorial/nor/nor.lstm-number-dawg \
  ~/tesstutorial/nor/nor.lstm-punc-dawg \
  ~/tesstutorial/nor/nor.lstm-word-dawg    

```