Please read [TrainingTesseract 4.00](https://github.com/tesseract-ocr/tesseract/wiki/TrainingTesseract-4.00) before trying the following.

Have copies of the 4.0.0 alpha langdata, tessdata and tesseract-ocr repositories in the following directory structure.

```
./langdata
./tessdata
./tesseract-ocr
./tesseract-ocr/tessdata
./tesseract-ocr/tessdata/configs/
```
Check that lstm.train is available under configs.

Setup appropriate TESSDATA_PREFIX directory.
```
cp ./tessdata/eng.traineddata ./tesseract-ocr/tessdata
cp ./tessdata/hin.traineddata ./tesseract-ocr/tessdata/bih.traineddata
```

Change to the tesseract-ocr directory and then follow the given commands.

```
cd ./tesseract-ocr

training/tesstrain.sh --fonts_dir /usr/share/fonts --lang bih  --linedata_only \
  --langdata_dir ../langdata --tessdata_dir ./tessdata \
  --fontlist "Lohit Devanagari" \
  --output_dir ~/tesstutorial/bihtest
```
This creates the .lstmf files in the output directory using the given training_text. The box/tiff pairs are created in a /tmp/<tmpdir>/hin/ directory and are not copied to the output directory.
```
mkdir -p ~/tesstutorial/bihlayer_from_hin 

combine_tessdata -e ../tessdata/hin.traineddata \
  ~/tesstutorial/bihlayer_from_hin/hin.lstm
  
training/lstmtraining -U ~/tesstutorial/bihtest/bih.unicharset \
  --script_dir ../langdata --debug_interval 0 \
  --continue_from   ~/tesstutorial/bihlayer_from_hin/hin.lstm \
  --append_index 5 --net_spec '[Lfx256 O1c105]' \
  --model_output ~/tesstutorial/bihlayer_from_hin/bihlayer \
  --train_listfile ~/tesstutorial/bihtest/bih.training_files.txt \
  --eval_listfile ~/tesstutorial/bihtest/bih.training_files.txt \
  --max_iterations 50000
```
The above commands extract the existing LSTM model for Hindi from ./tessdata and changes the top layer for it for Bihari using the .lstmf files created earlier, given in the train_listfile. As an alternate to --targer_error_rate <error-rate> one can use --max_iterations <iterations>.

This process can be stopped at any time. Giving the command again restarts the process. The --model_output directory holds the intermittent 'best' language models and the latest checkpoint for the training so far.
``` 
lstmtraining --model_output ~/tesstutorial/bihlayer_from_hin/bihlayer.lstm \
  --continue_from ~/tesstutorial/bihlayer_from_hin/bihlayer_checkpoint \
  --stop_training
```
The above command creates the new LSTM model from the finetuning output.
```
combine_tessdata -o ./tessdata/bih.traineddata \
  ~/tesstutorial/bihlayer_from_hin/bihlayer.lstm \
  ~/tesstutorial/bihtest/bih.lstm-number-dawg \
  ~/tesstutorial/bihtest/bih.lstm-punc-dawg \
  ~/tesstutorial/bihtest/bih.lstm-word-dawg 
```  
Finally, the new LSTM model and new dawg files can be combined with the existing Bihari traineddata (hin.traineddata copied as bih.traineddata) in ./tesseract-ocr/tessdata using the above command. The old bih.traineddata file in ./tesseract-ocr/tessdata is renamed.

```
training/lstmeval --model ~/tesstutorial/bihlayer_from_hin/hin.lstm \
  --eval_listfile ~/tesstutorial/bihtest/hin.training_files.txt  
  
training/lstmeval --model ~/tesstutorial/bihlayer_from_hin/bihlayer_checkpoint \
  --eval_listfile ~/tesstutorial/bihtest/hin.training_files.txt  
  
training/lstmeval --model ~/tesstutorial/bihlayer_from_hin/bihlayer.lstm \
  --eval_listfile ~/tesstutorial/bihtest/hin.training_files.txt  
``` 

The above three commands evaluate the LSTM models, 
first with the original Hindi LSTM model copied for Bihari, 
second with the checkpoint model created by replacing top layer and 
third with the Bihari model created from the above checkpoint.
Results of 2 and 3 should be the same and be an improvement over 1.

