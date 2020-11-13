## Traineddata Files for Version 4.00 +

We have three sets of official .traineddata files trained at Google, for `tesseract` versions 4.00 and above. These are made available in three separate repositories. 

* [tessdata_fast](https://github.com/tesseract-ocr/tessdata_fast) (Sep 2017) best "value for money" in speed vs accuracy, `Integer` models.
* [tessdata_best](https://github.com/tesseract-ocr/tessdata_best) (Sep 2017) best results on Google's eval data, slower, `Float` models. These are the only models that can be used as base for finetune training.
* [tessdata](https://github.com/tesseract-ocr/tessdata) (Nov 2016 and Sep 2017) These have legacy tesseract models from 2016. The LSTM models have been updated with Integer version of tessdata_best LSTM models. (Cube based legacy tesseract models for Hindi, Arabic etc. have been deleted).

When using the traineddata files from the **`tessdata_best`** and **`tessdata_fast`** repositories, only the new LSTM-based OCR engine (--oem 1) is supported. The legacy tesseract engine (--oem 0) is NOT supported with these files, so Tesseract's `oem modes` '0' and '2' won't work with them. 

* [Special Data Files](#special-data-files)
* [Latest Data Files - Sept. 2017](#latest-data-files-september-15-2017)
* [Data Files for Version 4.00 - Nov. 2016](#data-files-for-version-400-november-29-2016)
* [Format of traineddata files](#format-of-traineddata-files)

## Special Data Files

Lang Code | Description | 4.x/3.0x traineddata
:-------- | :---------- | :-------------------
osd | Orientation and script detection | [osd.traineddata](https://github.com/tesseract-ocr/tessdata/raw/3.04.00/osd.traineddata)
equ | Math / equation detection | [equ.traineddata](https://github.com/tesseract-ocr/tessdata/raw/3.04.00/equ.traineddata)

**Note**: These two data files are compatible with older versions of Tesseract. `osd` is compatible with version 3.01 and up, and `equ` is compatible with version 3.02 and up.

## Updated Data Files (September 15, 2017)

We have three sets of .traineddata files on GitHub in three separate repositories. These are compatible with Tesseract 4.0x**+** and 5.0.0.Alpha.

|               | Trained models                                           | Speed                     | Accuracy                                  | Supports legacy | Retrainable |
|---------------|----------------------------------------------------------|---------------------------|-------------------------------------------|-----------------|-------------|
| [tessdata](https://github.com/tesseract-ocr/tessdata)      | Legacy + LSTM (integerized tessdata-best)                | Faster than tessdata-best | Slightly less accurate than tessdata-best | Yes             | No          |
| [tessdata-best](https://github.com/tesseract-ocr/tessdata_best) | LSTM only (based on [langdata](https://github.com/tesseract-ocr/langdata))                            | Slowest                   | Most accurate                             | No              | Yes         |
| [tessdata-fast](https://github.com/tesseract-ocr/tessdata_fast) | Integerized LSTM of a smaller network than tessdata-best | Fastest                   | Least accurate                            | No              | No          |

Most users will want **`tessdata_fast`** and that is what will be shipped as part of Linux distributions. 

**`tessdata_best`** is for people willing to trade a lot of speed for slightly better accuracy. It is also
the only set of files which can be used for certain retraining scenarios for advanced users.

The third set in **`tessdata`** is the only one that supports the legacy recognizer. The 4.00 files from November 2016 have both legacy and older LSTM models. The current set of files in **`tessdata`** have the legacy models and newer LSTM  models (integer versions of 4.00.00 alpha models in tessdata_best).

**Note**: When using the new models in the **`tessdata_best`** and **`tessdata_fast`** repositories, only the new LSTM-based OCR engine is supported. The legacy engine is not supported with these files, so Tesseract's oem modes '0' and '2' won't work with them. 

## Data Files for Version 4.00 (November 29, 2016)

[tessdata tagged 4.0.0](https://github.com/tesseract-ocr/tessdata/releases/tag/4.0.0) has the models from Sept 2017 that have been updated with `Integer` versions of `tessdata_best` LSTM models. This set of traineddata files has support for the legacy recognizer with --oem 0 and for LSTM models with --oem 1.

[tessdata tagged 4.00](https://github.com/tesseract-ocr/tessdata/releases/tag/4.00) has the models from 2016. The individual language files are linked in the table below.

**Note**: The `kur` data file was not updated from 3.04. For Fraktur, use the newer data files from the tessdata_fast or tessdata_best repositories.

Lang Code | Language | 4.0 traineddata
:---------| :------- | :---------------
afr | Afrikaans | [afr.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/afr.traineddata)
amh | Amharic | [amh.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/amh.traineddata)
ara | Arabic | [ara.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/ara.traineddata)
asm | Assamese | [asm.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/asm.traineddata)
aze | Azerbaijani | [aze.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/aze.traineddata)
aze_cyrl | Azerbaijani - Cyrillic | [aze_cyrl.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/aze_cyrl.traineddata)
bel | Belarusian | [bel.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/bel.traineddata)
ben | Bengali | [ben.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/ben.traineddata)
bod | Tibetan | [bod.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/bod.traineddata)
bos | Bosnian | [bos.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/bos.traineddata)
bul | Bulgarian | [bul.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/bul.traineddata)
cat | Catalan; Valencian | [cat.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/cat.traineddata)
ceb | Cebuano | [ceb.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/ceb.traineddata)
ces | Czech | [ces.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/ces.traineddata)
chi_sim | Chinese - Simplified | [chi_sim.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/chi_sim.traineddata)
chi_tra | Chinese - Traditional | [chi_tra.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/chi_tra.traineddata)
chr | Cherokee | [chr.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/chr.traineddata)
cym | Welsh | [cym.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/cym.traineddata)
dan | Danish | [dan.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/dan.traineddata)
deu | German | [deu.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/deu.traineddata)
dzo | Dzongkha | [dzo.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/dzo.traineddata)
ell | Greek, Modern (1453-) | [ell.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/ell.traineddata)
eng | English | [eng.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/eng.traineddata)
enm | English, Middle (1100-1500) | [enm.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/enm.traineddata)
epo | Esperanto | [epo.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/epo.traineddata)
est | Estonian | [est.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/est.traineddata)
eus | Basque | [eus.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/eus.traineddata)
fas | Persian | [fas.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/fas.traineddata)
fin | Finnish | [fin.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/fin.traineddata)
fra | French | [fra.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/fra.traineddata)
frk | German Fraktur | [frk.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/frk.traineddata)
frm | French, Middle (ca. 1400-1600) | [frm.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/frm.traineddata)
gle | Irish | [gle.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/gle.traineddata)
glg | Galician | [glg.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/glg.traineddata)
grc | Greek, Ancient (-1453) | [grc.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/grc.traineddata)
guj | Gujarati | [guj.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/guj.traineddata)
hat | Haitian; Haitian Creole | [hat.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/hat.traineddata)
heb | Hebrew | [heb.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/heb.traineddata)
hin | Hindi | [hin.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/hin.traineddata)
hrv | Croatian | [hrv.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/hrv.traineddata)
hun | Hungarian | [hun.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/hun.traineddata)
iku | Inuktitut | [iku.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/iku.traineddata)
ind | Indonesian | [ind.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/ind.traineddata)
isl | Icelandic | [isl.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/isl.traineddata)
ita | Italian | [ita.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/ita.traineddata)
ita_old | Italian - Old | [ita_old.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/ita_old.traineddata)
jav | Javanese | [jav.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/jav.traineddata)
jpn | Japanese | [jpn.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/jpn.traineddata)
kan | Kannada | [kan.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/kan.traineddata)
kat | Georgian | [kat.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/kat.traineddata)
kat_old | Georgian - Old | [kat_old.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/kat_old.traineddata)
kaz | Kazakh | [kaz.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/kaz.traineddata)
khm | Central Khmer | [khm.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/khm.traineddata)
kir | Kirghiz; Kyrgyz | [kir.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/kir.traineddata)
kor | Korean | [kor.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/kor.traineddata)
kur | Kurdish | [kur.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/kur.traineddata)
lao | Lao | [lao.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/lao.traineddata)
lat | Latin | [lat.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/lat.traineddata)
lav | Latvian | [lav.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/lav.traineddata)
lit | Lithuanian | [lit.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/lit.traineddata)
mal | Malayalam | [mal.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/mal.traineddata)
mar | Marathi | [mar.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/mar.traineddata)
mkd | Macedonian | [mkd.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/mkd.traineddata)
mlt | Maltese | [mlt.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/mlt.traineddata)
msa | Malay | [msa.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/msa.traineddata)
mya | Burmese | [mya.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/mya.traineddata)
nep | Nepali | [nep.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/nep.traineddata)
nld | Dutch; Flemish | [nld.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/nld.traineddata)
nor | Norwegian | [nor.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/nor.traineddata)
ori | Oriya | [ori.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/ori.traineddata)
pan | Panjabi; Punjabi | [pan.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/pan.traineddata)
pol | Polish | [pol.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/pol.traineddata)
por | Portuguese | [por.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/por.traineddata)
pus | Pushto; Pashto | [pus.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/pus.traineddata)
ron | Romanian; Moldavian; Moldovan | [ron.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/ron.traineddata)
rus | Russian | [rus.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/rus.traineddata)
san | Sanskrit | [san.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/san.traineddata)
sin | Sinhala; Sinhalese | [sin.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/sin.traineddata)
slk | Slovak | [slk.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/slk.traineddata)
slv | Slovenian | [slv.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/slv.traineddata)
spa | Spanish; Castilian | [spa.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/spa.traineddata)
spa_old | Spanish; Castilian - Old | [spa_old.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/spa_old.traineddata)
sqi | Albanian | [sqi.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/sqi.traineddata)
srp | Serbian | [srp.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/srp.traineddata)
srp_latn | Serbian - Latin | [srp_latn.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/srp_latn.traineddata)
swa | Swahili | [swa.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/swa.traineddata)
swe | Swedish | [swe.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/swe.traineddata)
syr | Syriac | [syr.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/syr.traineddata)
tam | Tamil | [tam.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/tam.traineddata)
tel | Telugu | [tel.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/tel.traineddata)
tgk | Tajik | [tgk.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/tgk.traineddata)
tgl | Tagalog | [tgl.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/tgl.traineddata)
tha | Thai | [tha.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/tha.traineddata)
tir | Tigrinya | [tir.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/tir.traineddata)
tur | Turkish | [tur.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/tur.traineddata)
uig | Uighur; Uyghur | [uig.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/uig.traineddata)
ukr | Ukrainian | [ukr.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/ukr.traineddata)
urd | Urdu | [urd.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/urd.traineddata)
uzb | Uzbek | [uzb.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/uzb.traineddata)
uzb_cyrl | Uzbek - Cyrillic | [uzb_cyrl.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/uzb_cyrl.traineddata)
vie | Vietnamese | [vie.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/vie.traineddata)
yid | Yiddish | [yid.traineddata](https://github.com/tesseract-ocr/tessdata/raw/4.00/yid.traineddata)

## Format of traineddata files

The `traineddata` file for each language is an archive file in a Tesseract specific format. It contains several uncompressed component files which are needed by the Tesseract OCR process. The program `combine_tessdata` is used to create a `tessdata` file from the component files and can also extract them again like in the following examples:

### Pre 4.0.0 format from Nov 2016 (with both LSTM and Legacy models)

```
combine_tessdata -u eng.traineddata eng.
Extracting tessdata components from eng.traineddata
Wrote eng.unicharset
Wrote eng.unicharambigs
Wrote eng.inttemp
Wrote eng.pffmtable
Wrote eng.normproto
Wrote eng.punc-dawg
Wrote eng.word-dawg
Wrote eng.number-dawg
Wrote eng.freq-dawg
Wrote eng.cube-unicharset
Wrote eng.cube-word-dawg
Wrote eng.shapetable
Wrote eng.bigram-dawg
Wrote eng.lstm
Wrote eng.lstm-punc-dawg
Wrote eng.lstm-word-dawg
Wrote eng.lstm-number-dawg
Wrote eng.version
Version string:Pre-4.0.0
1:unicharset:size=7477, offset=192
2:unicharambigs:size=1047, offset=7669
3:inttemp:size=976552, offset=8716
4:pffmtable:size=844, offset=985268
5:normproto:size=13408, offset=986112
6:punc-dawg:size=4322, offset=999520
7:word-dawg:size=1082890, offset=1003842
8:number-dawg:size=6426, offset=2086732
9:freq-dawg:size=1410, offset=2093158
11:cube-unicharset:size=1511, offset=2094568
12:cube-word-dawg:size=1062106, offset=2096079
13:shapetable:size=63346, offset=3158185
14:bigram-dawg:size=16109842, offset=3221531
17:lstm:size=5390718, offset=19331373
18:lstm-punc-dawg:size=4322, offset=24722091
19:lstm-word-dawg:size=7143578, offset=24726413
20:lstm-number-dawg:size=3530, offset=31869991
23:version:size=9, offset=31873521
```

### 4.00.00alpha LSTM only format

```
combine_tessdata -u eng.traineddata eng.
Extracting tessdata components from eng.traineddata
Wrote eng.lstm
Wrote eng.lstm-punc-dawg
Wrote eng.lstm-word-dawg
Wrote eng.lstm-number-dawg
Wrote eng.lstm-unicharset
Wrote eng.lstm-recoder
Wrote eng.version
Version string:4.00.00alpha:eng:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
17:lstm:size=11689099, offset=192
18:lstm-punc-dawg:size=4322, offset=11689291
19:lstm-word-dawg:size=3694794, offset=11693613
20:lstm-number-dawg:size=4738, offset=15388407
21:lstm-unicharset:size=6360, offset=15393145
22:lstm-recoder:size=1012, offset=15399505
23:version:size=80, offset=15400517
```

### Proposal for compressed traineddata files

There are some proposals to replace the Tesseract archive format by a standard archive format which could also support compression. A [discussion on the tesseract-dev forum](https://groups.google.com/forum/?hl=en#!searchin/tesseract-dev/zip|sort:date/tesseract-dev/U5HSugUeeeI) proposed the ZIP format already in 2014. In 2017 an [experimental implementation](https://github.com/tesseract-ocr/tesseract/pull/911) was provided as a pull request.
