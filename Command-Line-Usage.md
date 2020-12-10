# Command Line Usage

## [Tesseract 'man' page](https://github.com/tesseract-ocr/tesseract/blob/master/doc/tesseract.1.asc)

See the [man](https://github.com/tesseract-ocr/tesseract/blob/master/doc/tesseract.1.asc) page for command line syntax and other details.

--------------------------------------------

## Basic Command Line Usage

See [Running Tesseract](https://github.com/tesseract-ocr/tesseract#running-tesseract) for basic command line usage.

## FAQ

See [FAQ](FAQ.md#running-tesseract) for more examples and tips.

--------------------------------------------

## Available OCR Engines in Tesseract 4

   Use `--oem 1` for LSTM, `--oem 0` for Legacy Tesseract. 

   Please note that Legacy Tesseract models are included in traineddata files from [tessdata](https://github.com/tesseract-ocr/tessdata) repo only.

   `tesseract input.tiff output --oem 1 -l eng`

---------------------------------------------

## Simplest Invocation to OCR an image

    tesseract imagename outputbase

This uses **English** as the default language and 3 as the Page Segmentation Mode. The default output format is **text**.

osd.traineddata, for Orientation and Segmentation and eng.traineddata and other language data files for English should be in the "tessdata" directory. TESSDATA_PREFIX environment variable should be set to the parent directory of "tessdata" directory. 

The following command would give the same result as above, if eng.traineddata and osd.traineddata files are in /usr/share/tessdata directory.

    tesseract --tessdata-dir /usr/share imagename outputbase -l eng --psm 3
____________________________________

Following examples use this image which has text in multiple languages.

![eurotext.png](images/eurotext.png)
## Using One Language

Add '-l LANG' to the command where LANG is three character language code from the list of supported languages. If this is not given then English language is assumed by default.

    tesseract testing/eurotext.tif testing/eurotext-eng -l eng

Output 

    The (quick) [brown] {fox} jumps!
    Over the $43,456.78 <lazy> #90 dog
    & duck/goose, as 12.5% of E-mail
    from aspammer@website.com is spam.
    Der ,,schnelle” braune Fuchs springt
    ﬁber den faulen Hund. Le renard brun
    «rapide» saute par-dessus le chien
    paresseux. La volpe marrone rapida
    salta sopra i] cane pigro. El zorro
    marrén répido salta sobre el perro
    perezoso. A raposa marrom répida
    salta sobre 0 C50 preguieoso.

## Using Multiple Languages

Add '-l LANG[+LANG]' to the command line to use multiple languages together for recognition 

    tesseract testing/eurotext.png testing/eurotext-engdeu -l eng+deu

Output

    The (quick) [brown] {fox} jumps!
    Over the $43,456.78 <lazy> #90 dog
    & duck/goose, as 12.5% of E-mail
    from aspammer@website.com is spam.
    Der „schnelle” braune Fuchs springt
    über den faulen Hund. Le renard brun
    «rapide» saute par-dessus le chien
    paresseux. La volpe marrone rapida
    salta sopra il cane pigro. El zorro
    marrön räpido salta sobre el perro
    perezoso. A raposa marrom räpida
    salta sobre o cäo preguieoso.

## Order of multiple languages
    
The output can be different based on the order of languages, so -l eng+hin can give different result than -l hin+eng.

Following examples use a greyscale version of this image which has text in multiple languages - Hindi and English.

![bilingual.jpg](https://i.ytimg.com/vi/Z0qDeKu7TWA/hqdefault.jpg)

Using English as primary language and then Hindi

     tesseract testing/bilingual.jpg testing/bilingual-enghin -l eng+hin

Output

    हिदीसेअंठौजी
    HINDI To
    
    ENGLISH
    —

Using Hindi as primary language and then English

     tesseract testing/bilingual.jpg testing/bilingual-hineng -l hin+eng

Output

    हिंदी से अंग्रेजी
    H I N D I T o
    
    E N G L I S H
    —
          
## Searchable pdf output

    tesseract testing/eurotext.png testing/eurotext-eng -l eng pdf

This creates a pdf with the image and a separate searchable text layer with the recognized text.

    tesseract c:\temp\test_ara.jpg -l ara -psm 3 c:\temp\test_ara pdf

Files are attached (source JPG and output PDF)

![test_ara.jpg](https://cloud.githubusercontent.com/assets/17473681/13320324/bc160e22-dbd0-11e5-8090-6f3728fcc06d.jpg)
![test_ara.pdf](https://github.com/tesseract-ocr/tesseract/files/146534/test_ara.pdf)

## HOCR output

Use 'hocr' config file by adding hocr at the end of the command to get the HOCR output.

    tesseract testing/eurotext.png testing/eurotext-eng -l eng hocr

Partial Output

    <?xml version="1.0" encoding="UTF-8"?>
    <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
        "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
    <html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
     <head>
      <title></title>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
      <meta name='ocr-system' content='tesseract 3.05.00dev' />
      <meta name='ocr-capabilities' content='ocr_page ocr_carea ocr_par ocr_line ocrx_word'/>
    </head>
    <body>
      <div class='ocr_page' id='page_1' title='image "./testing/eurotext.png"; bbox 0 0 1024 800; ppageno 0'>
       <div class='ocr_carea' id='block_1_1' title="bbox 98 66 918 661">
        <p class='ocr_par' id='par_1_1' lang='eng' title="bbox 98 66 918 661">
         <span class='ocr_line' id='line_1_1' title="bbox 105 66 823 113; baseline 0.015 -18; x_size 39; x_descenders 7; x_ascenders 9"><span class='ocrx_word' id='word_1_1' title='bbox 105 66 178 97; x_wconf 90'>The</span> <span class='ocrx_word' id='word_1_2' title='bbox 205 67 347 106; x_wconf 87'><strong>(quick)</strong></span> <span class='ocrx_word' id='word_1_3' title='bbox 376 69 528 109; x_wconf 89'>[brown]</span> <span class='ocrx_word' id='word_1_4' title='bbox 559 71 663 110; x_wconf 89'>{fox}</span> <span class='ocrx_word' id='word_1_5' title='bbox 687 73 823 113; x_wconf 89'>jumps!</span> 
         </span>
        </p>
       </div>
      </div>
     </body>
    </html>
    

## TSV output (Currently available in 3.05-dev in master branch on github)

Use 'tsv' config file by adding tsv at the end of the command to get the TSV output.

    tesseract testing/eurotext.png testing/eurotext-eng -l eng tsv

Partial Output

    level	page_num	block_num	par_num	line_num	word_num	left	top	width	height	conf	text
    1	1	0	0	0	0	0	0	1024	800	-1	
    2	1	1	0	0	0	98	66	821	596	-1	
    3	1	1	1	0	0	98	66	821	596	-1	
    4	1	1	1	1	0	105	66	719	48	-1	
    5	1	1	1	1	1	105	66	74	32	90	The
    5	1	1	1	1	2	205	67	143	40	87	(quick)
    5	1	1	1	1	3	376	69	153	41	89	[brown]
    5	1	1	1	1	4	559	71	105	40	89	{fox}
    5	1	1	1	1	5	687	73	137	41	89	jumps!
    4	1	1	1	2	0	104	115	784	51	-1	
    5	1	1	1	2	1	104	115	96	33	91	Over
    5	1	1	1	2	2	224	117	60	32	89	the
    5	1	1	1	2	3	310	117	224	39	88	$43,456.78
    5	1	1	1	2	4	561	121	136	42	92	<lazy>
    5	1	1	1	2	5	722	123	70	32	92	#90
    5	1	1	1	2	6	818	125	70	41	89	dog
 

## Using different Page Segmentation Modes

The following examples are using this image with text in Devanagari script and Sanskrit language.

![san002.png](https://cloud.githubusercontent.com/assets/82178/13678011/81953684-e6ba-11e5-91e8-5c40518e94a6.png)

    tesseract  testing/san002.png testing/san002-psm6 -l san -psm 6 

Output

    विर्व्य 16
    ज्यालत्रुखीसह्स्रनामक्तोव्रम्- नामाकळिट्. 191
    दुर्गासहस्रनामस्तीत्रम्- १ नामांक्ळिन्नू ॰213
    द्रुर्गासहस्रनत्मस्तीन्रम्- २ नामावळिऽ 238
    द्दुगसिद्द्स्रनत्मक्तोत्रम्दकाराद्दि(३) नामाव'ळिऽ 263
    ट्टुगसिहस्रनामक्तोत्रम्- ४ नामावळिइं 300
    पार्वतीं ह्यो) सहस्रनामातोत्रम्- नामावळिऽ’ 329
    द्दुर्गानवाक्षरीन्निशतींनत्माव'क्ति 355
    द्बुर्गाष्टोत्तरङ्प्तनत्मरतोव्रम्- नामावक्ति 360
    र्व्यत्मामस्वोत्रम्- नामाक्ळिऽ 363
    अन्नपूण्स्सिहस्रनत्मस्तीत्रम्- नामावक्ति 365
    अन्नघूर्गाष्टोत्तस्यातनामस्तीन्रम्- नामावक्ति 394
    क्रुलकुर्व्यसहस्रनत्मक्तोत्रम्- कवचम्… नामावळिथ् 397-
    कुमारींसहृस्रनामक्तोन्नम्- नामावळिय् 432
    गङ्ग’म्यासद्वृस्रनप्मक्तोव्रम्- नाम।वक्ति` 457
    गङ्ग’म्याष्टोत्तराप्तनामप्तोत्रम्- नामावळिऽ 488
    गङ्गादातनप्तास्तोत्रम्- नामावक्ति 491
    यमुनासहस्रनामरतोव्रम्- नम्पावळिय् 493
    'शिवगङ्गासद्दृस्रनत्माव'ळि 517
    गम्पत्रीसह्स्रनत्मक्तोत्रम्- नाम।व'ळिऽ (१) 531

    tesseract testing/san002.png testing/san002-psm3 -l san -psm 3

Output

    ज्यंग्लत्रुखीसह्स्रनामलोत्रम्- नामावळिट्.
    दुर्गासहस्रनामस्तीत्रम्- १ नामाक्ळि
    दुर्गासहस्रनत्मस्तीत्र्दुं'म्- २ नामावळिऽ
    द्बुगसिद्द्स्रनत्मरत्तोत्रम्दकारादि (३) नामावळि
    
    पार्वतीं ह्यो) सहम्रनम्परतोत्रम्- नामावळिऽ’
    
    फुलकुर्व्यसहस्रनत्मक्तोत्रम्-क्ताचम्-नत्माचळिऽ
    
    गम्यत्रीसह्स्रनत्मक्तोत्रम्-नग्मग्वळिऽ(१)
    
    191
    ,213
    
    238
    
    300
    329
    355
    360
    
    363.
    
    365
    
    394
    
    397-
    
    432
    
    457
    
    488
    
    491
    
    493
    
    517
    
    531
