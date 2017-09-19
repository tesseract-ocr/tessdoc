For GUI interface to Tesseract and other 3rd Party projects, please see [User Projects - 3rd Party](https://github.com/tesseract-ocr/tesseract/wiki/User-Projects-%E2%80%93-3rdParty)

# External tools, wrappers and training projects for Tesseract

## Tesseract box editors and training tools

Platform support depends on used language and experience of user.

### For Tesseract-OCR 3.0x


#### Box file editors

| **Name** | **Last update** | **Language** | Multipage support |
|:---------|:----------------|:-------------|:------------------|
| [jTessBoxEditor](http://vietocr.sourceforge.net/training.html) | January 2017      | Java         | yes               |
| [QT Box Editor](http://zdenop.github.com/qt-box-editor/) | July 2013       | C++, Qt4/Qt5 | yes               |
| [tesseract-box-editor](https://github.com/scotts48/tesseract-box-editor) | Feb 2013        | .NET 4       | yes               |
| [Tesseract-OCR boxfile AJAX editor](http://pp19dd.com/tesseract-ocr-chopper/) | March 2012      | online tool  |
| [cowboxer](http://code.google.com/p/cowboxer/) | Jan 2012        | C++, Qt4     | no                |
| [moshPyTT ](http://code.google.com/p/moshpytt/) | Feb 2011        | Python, GTK2 | no                |
| [pytesseracttrainer](http://code.google.com/p/pytesseracttrainer/) | Jan 2011        | Python, GTK2 | no                |


### For Tesseract-OCR 2.0x


#### Box file editors

| **Name** | **Last update** | **Language** |
|:---------|:----------------|:-------------|
| [Tesseract-OCR boxfile AJAX editor](http://pp19dd.com/tesseract-ocr-chopper/) | March 2012      | online tool  |
| [owlboxer](http://code.google.com/p/owlboxer/) | Jul 2010        | C++, Qt4     |
| [Tessboxer](http://sites.google.com/site/spilkaondrej) | Jun 2009        | .NET         |
| [boxfilereader.php](http://tesseract-ocr.googlecode.com/files/boxfilereader.php) | Mar 2009        |  php         |
| [tessboxes](http://www.lbreyer.com/tessboxes.html) | Nov 2008        | C            |
| [JTesseract](http://code.google.com/p/jtesseract/) |  Oct 2008       | C#           |
| [wx-tetra](http://code.google.com/p/wx-tetra/) | Sep 2008        | perl, wx     |
| [bbtesseract](http://code.google.com/p/bbtesseract/) | Jul 2008        | VB.NET 2008  |


## Other Training Tools
     
  *  [jTessBoxEditor](http://vietocr.sourceforge.net/training.html) | Box Editor and Training Tool    

  * [MzTesseract](https://github.com/mazluta/MzTesseract) - MS Windows program that can train new langauge from top to bottom
  * [FrankenPlus](https://github.com/this-is-ari/python-tesseract-3.02-training) - tool for creating font training for Tesseract OCR engine from page images. More information about Franken+ is at at [IT'S ALIVE!](http://emop.tamu.edu/node/54Franken+:) and [Franken+ homepage](http://dh-emopweb.tamu.edu/Franken+/).
  * [python-tesseract-3.02-training](https://github.com/this-is-ari/python-tesseract-3.02-training) - script to automate the generation of Tesseract 3.02 training files
  * [tesseract-box-file](https://code.google.com/p/tesseract-box-file/) - autoit script to make editing the box file easier
  * [Serak Tesseract Trainer for Tesseract 3.02](https://code.google.com/p/serak-tesseract-trainer/) - a front end GUI for training tesseract 3.02
  * [BoxMaker](http://reza1615.github.com/index.html) is online tool for generating image&box pair. Offline version is available in download section of [PersianOCR project](https://github.com/reza1615/PersianOcr/downloads)
  * [boxFactory](http://www.dinosaursandmoustaches.com/boxFactory.php) is a tool for quickly creating box files to train the Tesseract OCR engine. You can identify characters in the image by simply drawing boxes around them..
  * https://github.com/BaltoRouberol/TesseractTrainer - TesseractTrainer is a simple Python API, taking over the tedious process of manually training Tesseract3
  * [tess\_school](https://github.com/ddohler/tess_school) - a set of handy scripts to make the tesseract training process a bit easier
  * [txt2img](http://code.google.com/p/txt2img/): Qt GUI application that generate image and box file based on text imput
  * [DangAmbigs Generator](http://www.cs.toronto.edu/~mreimer/tesseract.html): Creates a DangAmbigs file automatically given a set of OCR text output and correct text. _Requirements:_ Python
  * [train.ps1](http://sourceforge.net/p/vietocr/code/HEAD/tree/jTessBoxEditor/trunk/tools/): Windows powershell script for Automate Tesseract 3.01 language data pack generation process.
  * [Update unicharambigs.exe](http://code.google.com/p/tesseract-ocr/issues/detail?id=544): A small (windows) C# program for editing "lang.unicharambigs" file
  * [train\_tess.pl](http://code.google.com/p/tesseract-ocr/issues/detail?id=640): perl script to facilitate training
  * [boxedit](https://github.com/danvk/boxedit/) A web-based editor for Tesseract box files
  * [TrainYourTesseract](http://trainyourtesseract.com) | Free online "no-hassle" TTF file to trainedata converter 


## Community training projects

  * **Tesseract-MICR-OCR**: https://github.com/BigPino67/Tesseract-MICR-OCR
  * **MRZ**: https://groups.google.com/group/tesseract-ocr/attach/10d7c711c9cc80/mrz.traineddata
  * **Latin**: https://github.com/ryanfb/latinocr-lattraining
  * **tesseract-georgian**: https://github.com/ddohler/tesseract-georgian
  * **Polish Fraktur**: training as [result of the IMPACT project](http://dl.psnc.pl/activities/projekty/impact/results/), [trained dataset](http://dl.psnc.pl/download/tesseract_traineddata.zip)
  * **Ancient Greek**: http://ancientgreekocr.org
  * **Indic**: http://code.google.com/p/tesseractindic/, https://github.com/debayan/Tesseract-Indic-OCR/, http://code.google.com/p/parichit/ (All are Obsolete)
  * **Indic-OCR** http://indic-ocr.github.io/tessdata/ 
  * **Irish uncial**: https://github.com/jimregan/tesseract-gle-uncial
  * **Polish**: http://code.google.com/p/tesseract-polish/
  * **Fraktur** (dan, deu, swe):  https://github.com/paalberti/tesseract-dan-fraktur
  * **Hebrew**: http://roidayan.com/wordpress/?p=26, http://code.google.com/p/tesseract-ocr/issues/detail?id=432
  * **Myanmar**: http://code.google.com/p/myaocr/
  * **Persian (Farsi)**: https://github.com/reza1615/PersianOcr
  * **7 segments font**: https://github.com/arturaugusto/display_ocr/tree/master/letsgodigital

## Ports

  * [Project Naptha](http://projectnaptha.com/)
   * [tesseract.js-core](https://github.com/naptha/tesseract.js-core) - Emscripten port of Tesseract C++ API
   * [tesseract.js](https://github.com/naptha/tesseract.js) - Pure Javascript OCR

## Tesseract wrappers

### Tesseract 3.0x

**C wrapper**:
  * Tesseract versions 3.02 and up include [C API](https://github.com/tesseract-ocr/tesseract/blob/master/api/capi.h)
  * for 3.00 (and 3.01?) see http://code.google.com/p/ocrivist/source/browse/#svn%2Ftessintf where is C wrapper with Freepascal bindings

**.Net**:
  * [charlesw/tesseract](https://github.com/charlesw/tesseract) - project offers also [tesseract-ocr 64bit Windows library](https://github.com/charlesw/tesseract/tree/master/src/lib/TesseractOcr/x64)
  * http://code.google.com/p/tesseractdotnet/

**Python**:
  * [tesserocr](https://github.com/sirfz/tesserocr) - A Python wrapper (Pillow-friendly) for the tesseract-ocr API
  * [pyocr](https://github.com/jflesch/pyocr) - A python wrapper for Tesseract and Cuneiform
  * [tesserwrap](https://github.com/gregjurman/tesserwrap) - Python bindings to the Tesseract API
  * [tesseract-sip](https://github.com/virtuald/python-tesseract-sip) - A python SIP wrapper for libtesseract (Apache license)
  * http://code.google.com/p/pytess/ - A simple SWIG-based interface to Tesseract
  * http://code.google.com/p/python-tesseract/ is a wrapper class for Tesseract OCR that allows any conventional image files (SWIG based)

**R**: 
  * [tesseract](https://cran.r-project.org/package=tesseract) Bindings to the C++ API for the R programming language


**Ruby**:
  * [ruby-tesseract-ocr](https://github.com/meh/ruby-tesseract-ocr/) - wrapper for tesseract 3.0x using the C++ API
  * [rtesseract](https://github.com/dannnylo/rtesseract)

**Java**: [tess4j](https://github.com/nguyenq/tess4j) - JNA wrapper. Docs and discussions - http://tess4j.sourceforge.net/

**Node.js**
  * [penteract](https://github.com/kaelzhang/node-penteract) - The native node.js bindings to the Tesseract OCR project.

**PHP**:
  * [tesseract-ocr-for-php](https://github.com/thiagoalessio/tesseract-ocr-for-php)
  * https://code.google.com/p/php-tesseract/

**Objective-C**:
  * [Tesseract-OCR-iOS](https://github.com/gali8/Tesseract-OCR-iOS) 
  * [tesseract-ios](https://github.com/ldiqual/tesseract-ios)

**Clojure**: [clj-tesseract](https://github.com/antoniogarrote/clj-tesseract)

### Tesseract 2.0x

**Python**:
  * https://github.com/hoffstaetter/python-tesseract/wiki
  * http://code.google.com/p/pytesser/
  * http://code.google.com/p/tesseract-python (pytesser clone)
  * https://github.com/hoffstaetter/python-tesseract/wiki
  * http://pokerai.org/pf3/viewtopic.php?f=3&t=2677&start=0&st=0&sk=t&sd=a
  * [patches of SWIG wrapper](http://code.google.com/p/tesseract-ocr/issues/detail?id=77) for python

**.NET**: http://www.pixel-technology.com/freeware/tessnet2/

**Java**: [tess4j (0.4)](https://github.com/nguyenq/tess4j) - JNA wrapper. Docs and discussions - http://tess4j.sourceforge.net/