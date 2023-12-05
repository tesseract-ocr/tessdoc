# A list of useful control parameters and config files

# Introduction

Tesseract is extremely flexible, if you know how to control it. There is a large number of control parameters to modify its behaviour. While these change from time to time, most of them are fairly stable. List of all parameters with default value and short description can be retrieved with:
```
tesseract --print-parameters
```

There are 3 different types:

### Init only

Characterized by **INIT** in its initialization macro.
These parameters can **only** be set at the ` TessBaseAPI::Init ` function that takes a list of config files.

*NOTE*: You can't change init only parameter with tesseract executable option `-c`.


The rest can be set through ` TessBaseAPI::SetVariable ` and make 2 further groups:

### General parameters

Control many different aspects of Tesseract's functionality.

### Debug parameters

Contain debug in their name, control huge amounts of optional debug text and graphical output as Tesseract works.


# Useful parameters

Note that the default value may change; check the source code if you need to be sure of it.

| **Name** | **Type** | **Default value** | **Init only** | **Description** |
|:---------|:---------|:------------------|:--------------|:----------------|
| ` load_system_dawg ` | boolean (0/1) | 1                 | Yes           | Controls whether or not to load the main dictionary for the selected language. |
| ` user_words_suffix ` | string   | ""                | Yes           | The extension of the users-words word list file. If non-empty, it will attempt to load the relevant list of words to add to the dictionary for the selected language. Eg if set to ` user-words ` Tesseract will attempt to load ` eng.user-words ` from the tessdata directory at initialization time. |
| ` language_model_penalty_non_dict_word ` | double (0-1) | 0.15              | No            | The penalty to apply to words not in the word\_dawg / user\_words wordlists. |
| ` language_model_penalty_non_freq_dict_word ` | double (0-1) | 0.1               | No            | The penalty to apply to words not in the freq\_dawg wordlist. |

### Useful parameters for Japanese and Chinese

[Some Japanese tesseract user](https://groups.google.com/d/msg/tesseract-ocr/A4IQlslY7hc/d4xK1PoihfMJ) found these parameters helpful for increasing tesseract-ocr (3.02) accuracy for Japanese :

| **Name** | **Suggested value** | **Description** |
|:---------|:--------------------|:----------------|
| chop\_enable | T                   | Chop enable.    |
| use\_new\_state\_cost | F                   | Use new state cost heuristics for segmentation state evaluation |
| segment\_segcost\_rating | F                   | Incorporate segmentation cost in word rating? |
| enable\_new\_segsearch | 0                   | Enable new segmentation search path. It could solve the problem of dividing one character to two characters |
| language\_model\_ngram\_on | 0                   | Turn on/off the use of character ngram model. |
| textord\_force\_make\_prop\_words | F                   | Force proportional word segmentation on all rows. |
| edges\_max\_children\_per\_outline  | 40                  | Max number of children inside a character outline. Increase this value if [some of KANJI characters are not recognized (rejected)](https://web.archive.org/web/*/https://code.google.com/p/tesseract-ocr/issues/detail?id=1022). |