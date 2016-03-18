## [Tesseract 'man' page](https://github.com/tesseract-ocr/tesseract/blob/master/doc/tesseract.1.asc)

## Tesseract --help

    Usage:
      tesseract --help | --help-psm | --version
      tesseract  --list-langs [--tessdata-dir PATH]
      tesseract  --print-parameters [options...] [configfile...]
      tesseract  imagename|stdin outputbase|stdout [options...] [configfile...]
    
    OCR options:
      --tessdata-dir PATH   Specify the location of tessdata path.
      --user-words PATH     Specify the location of user words file.
      --user-patterns PATH  Specify the location of user patterns file.
      -l LANG[+LANG]        Specify language(s) used for OCR.
      -c VAR=VALUE          Set value for config variables.
                            Multiple -c arguments are allowed.
      -psm NUM              Specify page segmentation mode.
    NOTE: These options must occur before any configfile.
    
    Page segmentation modes:
      0    Orientation and script detection (OSD) only.
      1    Automatic page segmentation with OSD.
      2    Automatic page segmentation, but no OSD, or OCR.
      3    Fully automatic page segmentation, but no OSD. (Default)
      4    Assume a single column of text of variable sizes.
      5    Assume a single uniform block of vertically aligned text.
      6    Assume a single uniform block of text.
      7    Treat the image as a single text line.
      8    Treat the image as a single word.
      9    Treat the image as a single word in a circle.
     10    Treat the image as a single character.
    
    Single options:
      -h, --help            Show this help message.
      --help-psm            Show page segmentation modes.
      -v, --version         Show version information.
      --list-langs          List available languages for tesseract engine.
      --print-parameters    Print tesseract parameters to stdout.

## Simplest Invocation to OCR an image

    tesseract imagename outputbase

This uses **English** as the default language and 3 as the Page Segmentation Mode. The default output format is **text**.

osd.traineddata, for Orientation and Segmentation and eng.traineddata and other language data files for English should be in the "tessdata" directory. TESSDATA_PREFIX environment variable should be set to the parent directory of "tessdata" directory. 

The following command would give the same result as above, if eng.traineddata and osd.traineddata files are in /usr/share/tessdata directory.

    tesseract --tessdata-dir /usr/share imagename outputbase -l eng psm 3
____________________________________

Following examples use this image which has text in multiple languages.

![eurotext.png](http://dev.blog.fairway.ne.jp/wp-content/uploads/2014/04/eurotext.png)
## Using One Language

Add '-l LANG' to the command where LANG is three character language code from the list of supported languages. If this is not given then English language is assumed by default.

    tesseract  --tessdata-dir ./ ./testing/eurotext.png ./testing/eurotext-eng -l eng

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

    tesseract  --tessdata-dir ./ ./testing/eurotext.png ./testing/eurotext-engdeu -l eng+deu

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

     tesseract  --tessdata-dir ./ ./testing/bilingual.jpg ./testing/bilingual-enghin -l eng+hin

Output

    हिदीसेअंठौजी
    HINDI To
    
    ENGLISH
    —

Using Hindi as primary language and then English

     tesseract  --tessdata-dir ./ ./testing/bilingual.jpg ./testing/bilingual-hineng -l hin+eng

Output

    हिंदी से अंग्रेजी
    H I N D I T o
    
    E N G L I S H
    —
          
## Searchable pdf output

    tesseract  --tessdata-dir ./ ./testing/eurotext.png ./testing/eurotext-eng -l eng pdf

This creates a pdf with the image and a separate searchable text layer with the recognized text.

## HOCR output

Use 'hocr' config file by adding hocr at the end of the command to get the HOCR output.

    tesseract  --tessdata-dir ./ ./testing/eurotext.png ./testing/eurotext-eng -l eng hocr

Output

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
         <span class='ocr_line' id='line_1_2' title="bbox 104 115 887 165; baseline 0.013 -19; x_size 42; x_descenders 9; x_ascenders 11"><span class='ocrx_word' id='word_1_6' title='bbox 104 115 199 147; x_wconf 91'>Over</span> <span class='ocrx_word' id='word_1_7' title='bbox 224 117 283 148; x_wconf 89'>the</span> <span class='ocrx_word' id='word_1_8' title='bbox 310 117 533 155; x_wconf 88'>$43,456.78</span> <span class='ocrx_word' id='word_1_9' title='bbox 561 121 696 162; x_wconf 92'>&lt;lazy&gt;</span> <span class='ocrx_word' id='word_1_10' title='bbox 722 123 791 154; x_wconf 92'>#90</span> <span class='ocrx_word' id='word_1_11' title='bbox 818 125 887 165; x_wconf 89'>dog</span> 
         </span>
         <span class='ocr_line' id='line_1_3' title="bbox 103 165 835 206; baseline 0.014 -10; x_size 40; x_descenders 8; x_ascenders 9"><span class='ocrx_word' id='word_1_12' title='bbox 103 165 134 196; x_wconf 91'>&amp;</span> <span class='ocrx_word' id='word_1_13' title='bbox 160 166 396 206; x_wconf 88'>duck/goose,</span> <span class='ocrx_word' id='word_1_14' title='bbox 424 178 463 201; x_wconf 92'>as</span> <span class='ocrx_word' id='word_1_15' title='bbox 493 171 614 203; x_wconf 91'>12.5%</span> <span class='ocrx_word' id='word_1_16' title='bbox 638 172 680 204; x_wconf 89'>of</span> <span class='ocrx_word' id='word_1_17' title='bbox 700 174 835 206; x_wconf 91'>E-mail</span> 
         </span>
         <span class='ocr_line' id='line_1_4' title="bbox 103 215 911 264; baseline 0.015 -19; x_size 39; x_descenders 8; x_ascenders 9"><span class='ocrx_word' id='word_1_18' title='bbox 103 215 194 247; x_wconf 89'>from</span> <span class='ocrx_word' id='word_1_19' title='bbox 220 219 716 260; x_wconf 87'>aspammer@website.com</span> <span class='ocrx_word' id='word_1_20' title='bbox 742 223 773 255; x_wconf 93'>is</span> <span class='ocrx_word' id='word_1_21' title='bbox 799 233 911 264; x_wconf 88'>spam.</span> 
         </span>
         <span class='ocr_line' id='line_1_5' title="bbox 102 266 877 314; baseline 0.013 -18; x_size 39; x_descenders 8; x_ascenders 9"><span class='ocrx_word' id='word_1_22' title='bbox 102 266 173 297; x_wconf 89'>Der</span> <span class='ocrx_word' id='word_1_23' title='bbox 198 267 406 302; x_wconf 78'>,,schnelle”</span> <span class='ocrx_word' id='word_1_24' title='bbox 433 269 568 302; x_wconf 91'>braune</span> <span class='ocrx_word' id='word_1_25' title='bbox 594 272 709 304; x_wconf 91'>Fuchs</span> <span class='ocrx_word' id='word_1_26' title='bbox 735 274 877 314; x_wconf 83'>springt</span> 
         </span>
         <span class='ocr_line' id='line_1_6' title="bbox 102 315 918 357; baseline 0.013 -11; x_size 39.311646; x_descenders 8.3116436; x_ascenders 9"><span class='ocrx_word' id='word_1_27' title='bbox 102 315 187 347; x_wconf 75'>ﬁber</span> <span class='ocrx_word' id='word_1_28' title='bbox 212 317 280 348; x_wconf 91'>den</span> <span class='ocrx_word' id='word_1_29' title='bbox 306 318 430 350; x_wconf 86'>faulen</span> <span class='ocrx_word' id='word_1_30' title='bbox 456 320 572 352; x_wconf 92'>Hund.</span> <span class='ocrx_word' id='word_1_31' title='bbox 601 322 648 354; x_wconf 87'>Le</span> <span class='ocrx_word' id='word_1_32' title='bbox 674 324 803 356; x_wconf 87'>renard</span> <span class='ocrx_word' id='word_1_33' title='bbox 827 325 918 357; x_wconf 90'>brun</span> 
         </span>
         <span class='ocr_line' id='line_1_7' title="bbox 101 366 833 409; baseline 0.016 -15; x_size 39; x_descenders 8; x_ascenders 9"><span class='ocrx_word' id='word_1_34' title='bbox 101 366 274 405; x_wconf 88'>«rapide»</span> <span class='ocrx_word' id='word_1_35' title='bbox 302 373 403 400; x_wconf 88'>saute</span> <span class='ocrx_word' id='word_1_36' title='bbox 428 371 641 409; x_wconf 87'>par-dessus</span> <span class='ocrx_word' id='word_1_37' title='bbox 667 372 700 404; x_wconf 91'>le</span> <span class='ocrx_word' id='word_1_38' title='bbox 725 374 833 406; x_wconf 90'>chien</span> 
         </span>
         <span class='ocr_line' id='line_1_8' title="bbox 100 419 859 464; baseline 0.013 -18; x_size 39; x_descenders 8; x_ascenders 8"><span class='ocrx_word' id='word_1_39' title='bbox 100 424 308 454; x_wconf 89'>paresseux.</span> <span class='ocrx_word' id='word_1_40' title='bbox 337 419 384 450; x_wconf 90'>La</span> <span class='ocrx_word' id='word_1_41' title='bbox 409 420 516 459; x_wconf 90'>volpe</span> <span class='ocrx_word' id='word_1_42' title='bbox 543 430 707 455; x_wconf 89'>marrone</span> <span class='ocrx_word' id='word_1_43' title='bbox 733 424 859 464; x_wconf 85'>rapida</span> 
         </span>
         <span class='ocr_line' id='line_1_9' title="bbox 100 466 834 511; baseline 0.014 -15; x_size 40; x_descenders 9; x_ascenders 9"><span class='ocrx_word' id='word_1_44' title='bbox 100 466 192 497; x_wconf 90'>salta</span> <span class='ocrx_word' id='word_1_45' title='bbox 219 475 324 507; x_wconf 90'>sopra</span> <span class='ocrx_word' id='word_1_46' title='bbox 351 468 376 499; x_wconf 90'>i]</span> <span class='ocrx_word' id='word_1_47' title='bbox 403 478 491 501; x_wconf 90'>cane</span> <span class='ocrx_word' id='word_1_48' title='bbox 517 471 633 511; x_wconf 89'>pigro.</span> <span class='ocrx_word' id='word_1_49' title='bbox 662 473 703 504; x_wconf 96'>El</span> <span class='ocrx_word' id='word_1_50' title='bbox 729 482 834 506; x_wconf 88'>zorro</span> 
         </span>
         <span class='ocr_line' id='line_1_10' title="bbox 99 516 833 563; baseline 0.014 -17; x_size 39; x_descenders 8; x_ascenders 9"><span class='ocrx_word' id='word_1_51' title='bbox 99 516 242 548; x_wconf 78'>marrén</span> <span class='ocrx_word' id='word_1_52' title='bbox 268 517 395 557; x_wconf 77'>répido</span> <span class='ocrx_word' id='word_1_53' title='bbox 421 520 513 552; x_wconf 90'>salta</span> <span class='ocrx_word' id='word_1_54' title='bbox 540 521 644 554; x_wconf 93'>sobre</span> <span class='ocrx_word' id='word_1_55' title='bbox 669 523 702 554; x_wconf 90'>el</span> <span class='ocrx_word' id='word_1_56' title='bbox 728 532 833 563; x_wconf 87'>perro</span> 
         </span>
         <span class='ocr_line' id='line_1_11' title="bbox 98 568 829 613; baseline 0.014 -17; x_size 40; x_descenders 8; x_ascenders 10"><span class='ocrx_word' id='word_1_57' title='bbox 98 574 284 604; x_wconf 89'>perezoso.</span> <span class='ocrx_word' id='word_1_58' title='bbox 313 568 342 598; x_wconf 92'>A</span> <span class='ocrx_word' id='word_1_59' title='bbox 369 578 497 609; x_wconf 91'>raposa</span> <span class='ocrx_word' id='word_1_60' title='bbox 523 579 677 604; x_wconf 89'>marrom</span> <span class='ocrx_word' id='word_1_61' title='bbox 703 573 829 613; x_wconf 75'>répida</span> 
         </span>
         <span class='ocr_line' id='line_1_12' title="bbox 98 616 710 661; baseline 0.013 -15; x_size 41; x_descenders 9; x_ascenders 9"><span class='ocrx_word' id='word_1_62' title='bbox 98 616 190 647; x_wconf 86'>salta</span> <span class='ocrx_word' id='word_1_63' title='bbox 217 617 320 649; x_wconf 90'>sobre</span> <span class='ocrx_word' id='word_1_64' title='bbox 346 627 366 650; x_wconf 89'><strong>0</strong></span> <span class='ocrx_word' id='word_1_65' title='bbox 391 621 456 651; x_wconf 72'>C50</span> <span class='ocrx_word' id='word_1_66' title='bbox 481 621 710 661; x_wconf 74'>preguieoso.</span> 
         </span>
        </p>
       </div>
      </div>
     </body>
    </html>
    

## TSV output (Currently available in 3.05-dev in master branch on github)

Use 'tsv' config file by adding tsv at the end of the command to get the TSV output.

    tesseract  --tessdata-dir ./ ./testing/eurotext.png ./testing/eurotext-eng -l eng tsv

Output

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
    4	1	1	1	3	0	103	165	733	42	-1	
    5	1	1	1	3	1	103	165	32	32	91	&
    5	1	1	1	3	2	160	166	237	41	88	duck/goose,
    5	1	1	1	3	3	424	178	40	24	92	as
    5	1	1	1	3	4	493	171	122	33	91	12.5%
    5	1	1	1	3	5	638	172	43	33	89	of
    5	1	1	1	3	6	700	174	136	33	91	E-mail
    4	1	1	1	4	0	103	215	809	50	-1	
    5	1	1	1	4	1	103	215	92	33	89	from
    5	1	1	1	4	2	220	219	497	42	87	aspammer@website.com
    5	1	1	1	4	3	742	223	32	33	93	is
    5	1	1	1	4	4	799	233	113	32	88	spam.
    4	1	1	1	5	0	102	266	776	49	-1	
    5	1	1	1	5	1	102	266	72	32	89	Der
    5	1	1	1	5	2	198	267	209	36	78	,,schnelle”
    5	1	1	1	5	3	433	269	136	34	91	braune
    5	1	1	1	5	4	594	272	116	33	91	Fuchs
    5	1	1	1	5	5	735	274	143	41	83	springt
    4	1	1	1	6	0	102	315	817	43	-1	
    5	1	1	1	6	1	102	315	86	33	75	ﬁber
    5	1	1	1	6	2	212	317	69	32	91	den
    5	1	1	1	6	3	306	318	125	33	86	faulen
    5	1	1	1	6	4	456	320	117	33	92	Hund.
    5	1	1	1	6	5	601	322	48	33	87	Le
    5	1	1	1	6	6	674	324	130	33	87	renard
    5	1	1	1	6	7	827	325	92	33	90	brun
    4	1	1	1	7	0	101	366	733	44	-1	
    5	1	1	1	7	1	101	366	174	40	88	«rapide»
    5	1	1	1	7	2	302	373	102	28	88	saute
    5	1	1	1	7	3	428	371	214	39	87	par-dessus
    5	1	1	1	7	4	667	372	34	33	91	le
    5	1	1	1	7	5	725	374	109	33	90	chien
    4	1	1	1	8	0	100	419	760	46	-1	
    5	1	1	1	8	1	100	424	209	31	89	paresseux.
    5	1	1	1	8	2	337	419	48	32	90	La
    5	1	1	1	8	3	409	420	108	40	90	volpe
    5	1	1	1	8	4	543	430	165	26	89	marrone
    5	1	1	1	8	5	733	424	127	41	85	rapida
    4	1	1	1	9	0	100	466	735	46	-1	
    5	1	1	1	9	1	100	466	93	32	90	salta
    5	1	1	1	9	2	219	475	106	33	90	sopra
    5	1	1	1	9	3	351	468	26	32	90	i]
    5	1	1	1	9	4	403	478	89	24	90	cane
    5	1	1	1	9	5	517	471	117	41	89	pigro.
    5	1	1	1	9	6	662	473	42	32	96	El
    5	1	1	1	9	7	729	482	106	25	88	zorro
    4	1	1	1	10	0	99	516	735	48	-1	
    5	1	1	1	10	1	99	516	144	33	78	marrén
    5	1	1	1	10	2	268	517	128	41	77	répido
    5	1	1	1	10	3	421	520	93	33	90	salta
    5	1	1	1	10	4	540	521	105	34	93	sobre
    5	1	1	1	10	5	669	523	34	32	90	el
    5	1	1	1	10	6	728	532	106	32	87	perro
    4	1	1	1	11	0	98	568	732	46	-1	
    5	1	1	1	11	1	98	574	187	31	89	perezoso.
    5	1	1	1	11	2	313	568	30	31	92	A
    5	1	1	1	11	3	369	578	129	32	91	raposa
    5	1	1	1	11	4	523	579	155	26	89	marrom
    5	1	1	1	11	5	703	573	127	41	75	répida
    4	1	1	1	12	0	98	616	613	46	-1	
    5	1	1	1	12	1	98	616	93	32	86	salta
    5	1	1	1	12	2	217	617	104	33	90	sobre
    5	1	1	1	12	3	346	627	21	24	89	0
    5	1	1	1	12	4	391	621	66	31	72	C50
    5	1	1	1	12	5	481	621	230	41	74	preguieoso.

## Using different Page Segmentation Modes

The following examples are using this image with text in Devanagari script and Sanskrit language.

![san002.png] (https://cloud.githubusercontent.com/assets/82178/13678011/81953684-e6ba-11e5-91e8-5c40518e94a6.png)

    tesseract   --tessdata-dir /usr/share testing/san002.png testing/san002-psm6 -l san -psm 6 

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

    tesseract   --tessdata-dir /usr/share testing/san002.png testing/san002-psm3 -l san -psm 3

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
    
            