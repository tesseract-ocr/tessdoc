## Errors during LSTM Training

See  Ray Smith's notes in  [tess4/TrainingTesseract 4.00](TrainingTesseract-4.00.md),
specifically the section on [errors](TrainingTesseract-4.00.md#error-messages-from-training).

## Errors related to Tesseract API

### Error if locale settings are not equal to "C"

Normal C++ programs like those which are built for tesseract automatically
set the locale "C".

There can be different locale settings if the tesseract library is used
in other software.

A wrong locale can cause wrong results from sscanf which is used at
different places in the tesseract code, so make sure that we have the
right locale settings and fail if that is not the case.

```
!strcmp(locale, "C"):Error:Assert failed:in file baseapi.cpp, line 192
```

You have to find out whether "C" works with your code or you must restore
the original locale after calling the Tesseract API.


## Errors related to Tesseract CLI

