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

training/tesstrain.sh --fonts_dir /usr/share/fonts --lang nor \
   --linedata_only --noextract_font_properties \
   --langdata_dir ../langdata --tessdata_dir ./tessdata \
   --fontlist "Arial" \
   --output_dir ~/tesstutorial/noreval
 
mkdir -p ~/tesstutorial/nor_layer 
 
combine_tessdata -e ../tessdata/nor.traineddata \
  ~/tesstutorial/nor_layer/nor.lstm

 lstmtraining -U ~/tesstutorial/nor/nor.unicharset \
  --script_dir ../langdata  --debug_interval 0 \
  --continue_from ~/tesstutorial/nor_layer/nor.lstm \
  --append_index 5 --net_spec '[Lfx256 O1c105]' \
  --model_output ~/tesstutorial/nor_layer/norlayer \
  --train_listfile ~/tesstutorial/nor/nor.training_files.txt \
  --eval_listfile ~/tesstutorial/noreval/nor.training_files.txt \
  --max_iterations 5000
    
lstmtraining --model_output ~/tesstutorial/nor_layer/norlayer.lstm \
  --continue_from ~/tesstutorial/nor_layer/norlayer_checkpoint \
  --stop_training

cp ../tessdata/nor.traineddata ./tessdata
  
combine_tessdata -o ./tessdata/nor.traineddata \
~/tesstutorial/nor_layer/norlayer.lstm \
  ~/tesstutorial/nor/nor.lstm-number-dawg \
  ~/tesstutorial/nor/nor.lstm-punc-dawg \
  ~/tesstutorial/nor/nor.lstm-word-dawg    

```

The following section displays some of the console output from the above training.

```
$ mkdir -p ~/tesstutorial/nor_layer
$ combine_tessdata -e ../tessdata/nor.traineddata \
>   ~/tesstutorial/nor_layer/nor.lstm
Extracting tessdata components from ../tessdata/nor.traineddata
Wrote /home/shree/tesstutorial/nor_layer/nor.lstm
$  lstmtraining -U ~/tesstutorial/nor/nor.unicharset \
>   --script_dir ../langdata  --debug_interval 0 \
>   --continue_from ~/tesstutorial/nor_layer/nor.lstm \
>   --append_index 5 --net_spec '[Lfx256 O1c105]' \
>   --model_output ~/tesstutorial/nor_layer/norlayer \
>   --train_listfile ~/tesstutorial/nor/nor.training_files.txt \
>   --max_iterations 50000
Loaded file /home/shree/tesstutorial/nor_layer/nor.lstm, unpacking...
Warning: LSTMTrainer deserialized an LSTMRecognizer!
Continuing from /home/shree/tesstutorial/nor_layer/nor.lstm
Other case É of é is not in unicharset
Other case Ö of ö is not in unicharset
Other case Ä of ä is not in unicharset
Appending a new network to an old one!!Setting unichar properties
Setting properties for script Common
Setting properties for script Latin
Warning: given outputs 105 not equal to unicharset of 101.
Num outputs,weights in serial:
  Lfx256:256, 394240
  Fc101:101, 25957
Total weights = 420197
Built network:[1,0,0,1[C5,5Ft16]Mp3,3Lfys64Lfx128Lrx128Lfx256Fc101] from request [Lfx256 O1c105]
Training parameters:
  Debug interval = 0, weights = 0.1, learning rate = 0.0001, momentum=0.9
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Arial_Bold.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Arial.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Arial_Bold_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Arial_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Century_Schoolbook_L_Medium.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Century_Schoolbook_L_Bold.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Century_Schoolbook_L_Bold_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Courier_New_Bold.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Century_Schoolbook_L_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Courier_New_Bold_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Courier_New.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Courier_New_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Georgia_Bold.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Georgia_Bold_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Georgia.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Georgia_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Times_New_Roman_Bold.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Times_New_Roman_Bold_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Times_New_Roman.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Times_New_Roman_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Trebuchet_MS_Bold.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Trebuchet_MS_Bold_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Trebuchet_MS.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Trebuchet_MS_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.URW_Bookman_L_Bold.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.URW_Bookman_L_Bold_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.URW_Bookman_L_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Verdana_Bold.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Verdana_Bold_Italic.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Verdana.exp0.lstmf
Loaded 241/241 pages (1-241) of document /home/shree/tesstutorial/nor/nor.Verdana_Italic.exp0.lstmf
At iteration 100/100/100, Mean rms=6.173%, delta=57.061%, char train=121.258%, word train=100%, skip ratio=0%,  New worst char error = 121.258 wrote checkpoint.

At iteration 200/200/200, Mean rms=5.509%, delta=43.627%, char train=102.285%, word train=99.873%, skip ratio=0%,  New worst char error = 102.285 wrote checkpoint.

2 Percent improvement time=300, best error was 100 @ 0
At iteration 300/300/300, Mean rms=4.804%, delta=33.195%, char train=83.028%, word train=95.586%, skip ratio=0%,  New best char error = 83.028 wrote checkpoint.

2 Percent improvement time=100, best error was 83.028 @ 300
At iteration 400/400/400, Mean rms=4.237%, delta=26.762%, char train=68.349%, word train=85.796%, skip ratio=0%,  New best char error = 68.349 wrote best model:/home/shree/tesstutorial/nor_layer/norlayer68.349_400.lstm wrote checkpoint.
2 Percent improvement time=100, best error was 68.349 @ 400

At iteration 500/500/500, Mean rms=3.798%, delta=22.466%, char train=57.949%, word train=76.222%, skip ratio=0%,  New best char error = 57.949 wrote best model:/home/shree/tesstutorial/nor_layer/norlayer57.949_500.lstm wrote checkpoint.

2 Percent improvement time=100, best error was 57.949 @ 500
At iteration 600/600/600, Mean rms=3.478%, delta=19.53%, char train=50.964%, word train=69.69%, skip ratio=0%,  New best char error = 50.964 wrote best model:/home/shree/tesstutorial/nor_layer/norlayer50.964_600.lstm wrote checkpoint.

2 Percent improvement time=97, best error was 50.964 @ 600
At iteration 697/700/700, Mean rms=3.217%, delta=17.259%, char train=45.254%, word train=63.256%, skip ratio=0%,  New best char error = 45.254 wrote best model:/home/shree/tesstutorial/nor_layer/norlayer45.254_697.lstm wrote checkpoint.

2 Percent improvement time=91, best error was 45.254 @ 697
At iteration 788/800/800, Mean rms=2.98%, delta=15.395%, char train=40.512%, word train=57.614%, skip ratio=0%,  New best char error = 40.512 wrote best model:/home/shree/tesstutorial/nor_layer/norlayer40.512_788.lstm wrote checkpoint.

2 Percent improvement time=78, best error was 40.512 @ 788
At iteration 866/900/900, Mean rms=2.785%, delta=13.893%, char train=36.821%, word train=53.239%, skip ratio=0%,  New best char error = 36.821 wrote best model:/home/shree/tesstutorial/nor_layer/norlayer36.821_866.lstm wrote checkpoint.

2 Percent improvement time=67, best error was 36.821 @ 866
At iteration 933/1000/1000, Mean rms=2.618%, delta=12.657%, char train=33.723%, word train=49.372%, skip ratio=0%,  New best char error = 33.723 wrote best model:/home/shree/tesstutorial/nor_layer/norlayer33.723_933.lstm wrote checkpoint.

2 Percent improvement time=65, best error was 33.723 @ 933
At iteration 998/1100/1100, Mean rms=2.105%, delta=7.091%, char train=22.057%, word train=40.57%, skip ratio=0%,  New best char error = 22.057 wrote best model:/home/shree/tesstutorial/nor_layer/norlayer22.057_998.lstm wrote checkpoint.

2 Percent improvement time=67, best error was 22.057 @ 998
At iteration 1065/1200/1200, Mean rms=1.717%, delta=4.18%, char train=14.09%, word train=31.585%, skip ratio=0%,  New best char error = 14.09 wrote best model:/home/shree/tesstutorial/nor_layer/norlayer14.09_1065.lstm wrote checkpoint.

2 Percent improvement time=61, best error was 14.09 @ 1065
At iteration 1126/1300/1300, Mean rms=1.469%, delta=3.05%, char train=10.061%, word train=23.982%, skip ratio=0%,  New best char error = 10.061 wrote best model:/home/shree/tesstutorial/nor_layer/norlayer10.061_1126.lstm wrote checkpoint.

2 Percent improvement time=46, best error was 10.061 @ 1126
At iteration 1172/1400/1400, Mean rms=1.296%, delta=2.367%, char train=7.89%, word train=18.967%, skip ratio=0%,  New best char error = 7.89 
Transitioned to stage 1 wrote best model:/home/shree/tesstutorial/nor_layer/norlayer7.89_1172.lstm wrote checkpoint.

2 Percent improvement time=90, best error was 10.061 @ 1126
At iteration 1216/1500/1500, Mean rms=1.165%, delta=1.895%, char train=6.419%, word train=15.675%, skip ratio=0%,  New best char error = 6.419 wrote best model:/home/shree/tesstutorial/nor_layer/norlayer6.419_1216.lstm wrote checkpoint.

and so on ..
```

Transitioned to stage 1 message is displayed when Error Rate falls below kStageTransitionThreshold (default value 10%).

LSTM training takes time. The above process took about 9 elapsed hours on a PC. 

Ref: https://github.com/tesseract-ocr/langdata/issues/36