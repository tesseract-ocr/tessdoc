On windows 7,I am trying to use Fast Traineddata files in my java project. But I am getting Invalid Memory access when using it even after setting datapath.

I have tried to use best data files but it also gives same error. Default data files are working but it is huge file so I was going for fast files.

Tesseract tess = new Tesseract();

tess.setDatapath("C:\\Users\\U6070534\\Downloads\\tess4j\\tessdata");
tess.setLanguage("eng");

String inputFilePath = "C:\\Users\\U6070534\\IdeaProjects\\ocrsample\\screenshot\\craft0.png";
    try {
        textpath.add(tess.doOCR(new File(inputFilePath)));
    } catch (TesseractException e1) {
        e1.printStackTrace();
    }
Exception in thread "main" java.lang.Error: Invalid memory access
at com.sun.jna.Native.invokePointer(Native Method)
at com.sun.jna.Function.invokePointer(Function.java:470)
at com.sun.jna.Function.invoke(Function.java:404)
at com.sun.jna.Function.invoke(Function.java:315)
at com.sun.jna.Library$Handler.invoke(Library.java:212)
at com.sun.proxy.$Proxy0.TessBaseAPIGetUTF8Text(Unknown Source)
at net.sourceforge.tess4j.Tesseract.getOCRText(Tesseract.java:437)
at net.sourceforge.tess4j.Tesseract.doOCR(Tesseract.java:292)
at net.sourceforge.tess4j.Tesseract.doOCR(Tesseract.java:213)
at net.sourceforge.tess4j.Tesseract.doOCR(Tesseract.java:197)
at OcrReader.main(OcrReader.java:25)
Failed loading language 'eng'
Tesseract couldn't load any languages!
Process finished with exit code 1