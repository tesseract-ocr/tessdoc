## Traineddata Files for Version 4.00 

We have three sets of .traineddata files for tesseract on GitHub in three separate repositories. 

* https://github.com/tesseract-ocr/tessdata_fast (September 15, 2017, use for OCR)
* https://github.com/tesseract-ocr/tessdata_best (September 15, 2017, use for finetune training)
* https://github.com/tesseract-ocr/tessdata (November 2016, supports legacy tesseract engine also)

When using the models in the **`tessdata_best`** and **`tessdata_fast`** repositories, only the new LSTM-based OCR engine is supported. The legacy tesseract engine is NOT supported with these files, so Tesseract's oem modes '0' and '2' won't work with them. 

## Information specific to tessdata_fast

### Usage

Most users will use **`tessdata_fast`** for OCR as that is what will be shipped as part of Linux distributions and will provide accurate and fast recognition. 

### Version string : 4.00.00alpha : [Network specification]

```
afr		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
amh		: synth20170629
Arabic		: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1]
ara		: synth20170629
Armenian	: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
asm		: synth20170629
aze_cyrl	: synth20170629
aze		: synth20170629
bel		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
Bengali		: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
ben		: synth20170629
bod		: synth20170629
bos		: synth20170629
bre		: synth20170629
bul		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
Canadian_Aboriginal: synth20170629
cat		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1]
ceb		: synth20170629
ces		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1]
Cherokee	: synth20170629
chi_sim		: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
chi_sim_vert	: synth20170629
chi_tra		: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
chi_tra_vert	: synth20170629
chr		: synth20170629
cos		: synth20170629
cym		: synth20170629
Cyrillic	: synth20170629
dan		: synth20170629
deu		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1]
Devanagari	: synth20170629
div		: synth20170629
dzo		: synth20170629
ell		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
eng		: synth20170629
enm		: synth20170629
epo		: synth20170629
est		: synth20170629
Ethiopic	: synth20170629
eus		: synth20170629
fao		: synth20170629
fas		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
fil		: synth20170629
fin		: synth20170629
Fraktur		: synth20170629
fra		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
frk		: synth20170629
frm		: synth20170629
fry		: synth20170629
Georgian	: synth20170629
gla		: synth20170629
gle		: synth20170629
glg		: synth20170629
grc		: synth20170629
Greek		: synth20170629
Gujarati	: synth20170629
guj		: synth20170629
Gurmukhi	: synth20170629
Hangul		: synth20170629
Hangul_vert	: synth20170629
HanS		: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
HanS_vert	: synth20170629
HanT		: synth20170629
HanT_vert	: synth20170629
hat		: synth20170629
Hebrew		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
heb		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
hin		: synth20170629
hrv		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1]
hun		: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1]
hye		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
iku		: synth20170629
ind		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1]
isl		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1]
ita_old		: synth20170629
ita		: synth20170629
Japanese	: synth20170629
Japanese_vert	: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
jav		: synth20170629
jpn		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
jpn_vert	: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
Kannada		: synth20170629
kan		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
kat_old		: synth20170629
kat		: synth20170629
kaz		: synth20170629
Khmer		: synth20170629
khm		: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
kir		: synth20170629
kor		: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
kor_vert	: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1]
kur_ara		: synth20170629
lao		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
Lao		: synth20170629
Latin		: synth20170629
lat		: synth20170629
lav		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1]
lit		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1]
ltz		: synth20170629
Malayalam	: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1]
mal		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
mar		: synth20170629
mkd		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1]
mlt		: synth20170629
mon		: synth20170629
mri		: synth20170629
msa		: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
Myanmar		: synth20170629
mya		: synth20170629
nep		: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1]
nld		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1]
nor		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
oci		: synth20170629
ori		: synth20170629
Oriya		: synth20170629
pan		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
pol		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1]
por		: synth20170629
pus		: synth20170629
que		: synth20170629
ron		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
rus		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1]
san		: synth20170629
Sinhala		: synth20170629
sin		: synth20170629
slk		: synth20170629
slv		: synth20170629
snd		: synth20170629
spa_old		: synth20170629
spa		: synth20170629
sqi		: synth20170629
srp_latn	: synth20170629
srp		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
sun		: synth20170629
swa		: synth20170629
swe		: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
Syriac		: synth20170629
syr		: synth20170629
Tamil		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1]
tam		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
tat		: synth20170629
tel		: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1]
Telugu		: synth20170629	: [1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1]
tgk		: synth20170629
Thaana		: synth20170629
Thai		: synth20170629
tha		: synth20170629
Tibetan		: synth20170629
tir		: synth20170629
ton		: synth20170629
tur		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1]
uig		: synth20170629
ukr		: synth20170629
urd		: synth20170629
uzb_cyrl	: synth20170629
uzb		: synth20170629
Vietnamese	: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
vie		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1]
yid		: synth20170629	: [1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1]
yor		: synth20170629
```