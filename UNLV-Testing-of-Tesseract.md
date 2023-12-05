# How to run UNLV tests on Tesseract

## Introduction

Tesseract 2.0+ provided scripts that make it possible to run some of the UNLV tests published in the Fourth Annual Test of OCR Accuracy.
See [AT-1995.pdf](https://github.com/tesseract-ocr/docs/blob/main/AT-1995.pdf) (originally available at http://www.isri.unlv.edu/). The main purpose of providing these test scripts is to enable Tesseract users to verify that their installation is correct, and that no architecture-specific problems are causing bad recognition accuracy. It also serves as a benchmark to demonstrate accuracy improvements of each version. Developers working on Tesseract may find the benchmarking tools useful for measuring experimental new modules.

Note that **some** architecture-specific variation is bound to occur. Most of these should be caused by varying treatment and optimization of floating-point arithmetic between compilers. It is also possible of course that there are memory initialization errors that show up as differences between architectures, but we claim to have found most of these already in the unicodeization process.

## Caveat

The UNLV images are G4 compressed, so you must build Tesseract with TIFF support, but all recent versions include libtiff by default. 

Windows users also have to have some unix shell script capability, perhaps via cygwin or equivalent.

## Images

The current scripts only cover tests of the 3B test sets (ie 300 dpi bitonal). The adaptive thresholding in the open-source Tesseract is not the same as in the original as the original adaptive thresholding was not included in the open source release, so the 8 bit grey image tests would not compare correctly, and the other resolutions, while interesting, do not really serve a useful regression testing purpose.

## Running the tests

See [README file for UNLV tests](https://github.com/tesseract-ocr/test/blob/main/unlvtests/README.md) for the current instructions on how to run the tests for Tesseract 4.

## Example Results

Here are some of the results of the 1995 test, taken from [AT-1995.pdf](https://github.com/tesseract-ocr/docs/blob/main/AT-1995.pdf) and reformatted to match the output of the Tesseract test tools:

```
Testid  Testset Character               Word                    Non-stopword
                Errors  Acc     Change  Errors  Acc     Change  Errors  Acc     Change
1995    bus.3B  5959    98.14%  0.00%   1631    96.83%  0.00%   1293    95.73%  0.00%
1995    doe3.3B 36349   97.52%  0.00%   7826    96.34%  0.00%   7042    94.87%  0.00%
1995    mag.3B  15043   97.74%  0.00%   4566    96.01%  0.00%   3379    94.99%  0.00%
1995    news.3B 6432    98.69%  0.00%   1946    97.68%  0.00%   1502    96.94%  0.00%
```

(The change column is for the recent tests, and measures the change over these 1995 results.)

The results of Tesseract 2.00 compiled with gcc 4.0.3-1ubuntu5 are:

```
Testid  Testset Character               Word                    Non-stopword
                Errors  Acc     Change  Errors  Acc     Change  Errors  Acc     Change
gcc4.0  bus.3B  6259    98.04%  5.03%   1691    96.71%  3.68%   1313    95.66   1.55%
gcc4.0  doe3.3B 28850   98.03%  -20.63% 7863    96.32%  0.47%   6688    95.13   -5.03%
gcc4.0  mag.3B  14815   97.78%  -1.52%  4396    96.16%  -3.72%  3124    95.37   -7.55%
gcc4.0  news.3B 7533    98.47%  17.12%  1758    97.91%  -9.66%  1220    97.51   -18.77%
gcc4.0  Total   57457   -       -9.92%  15708   -       -1.63%  12345   -       -6.59%
```

The change column shows wild variation in accuracy over the 1995 results, with a 20% reduction in character errors on the doe3.3B test set, but a 17% increase in character errors on the news.3B test set. Since the engine has been completely retrained since the 1995 tests, and it is now running on a different processor with a different compiler, it is difficult to pin down the cause of this wild variation. (It may also be partly due to the absence of the Aspirin package.)

To illustrate what a difference the compiler makes, here are the results from the same code compiled with gcc 4.1.1:

```
Testid  Testset Character               Word                    Non-stopword
                Errors  Acc     Change  Errors  Acc     Change  Errors  Acc     Change
gcc4.1  bus.3B  6258    98.04%  5.02%   1690    96.72%  3.62%   1312    95.67   1.47%
gcc4.1  doe3.3B 28589   98.05%  -21.35% 7864    96.32%  0.49%   6692    95.12   -4.97%
gcc4.1  mag.3B  14800   97.78%  -1.62%  4394    96.16%  -3.77%  3123    95.37   -7.58%
gcc4.1  news.3B 7524    98.47%  16.98%  1759    97.91%  -9.61%  1220    97.51   -18.77%
gcc4.1  Total   57171   -       -10.37% 15707   -       -1.64%  12347   -       -6.58%
```

The error rates are not that different, but there is a slight difference. In contrast, the same code built with VisualC++ Express gives this:

```
Testid  Testset Character               Word                    Non-stopword
                Errors  Acc     Change  Errors  Acc     Change  Errors  Acc     Change
vc++exp bus.3B  6270    98.04%  5.22%   1695    96.71%  3.92%   1315    95.66   1.70%
vc++exp doe3.3B 29098   98.01%  -19.95% 8246    96.14%  5.37%   7038    94.87   -0.06%
vc++exp mag.3B  14981   97.75%  -0.41%  4435    96.12%  -2.87%  3157    95.32   -6.57%
vc++exp news.3B 7548    98.47%  17.35%  1763    97.90%  -9.40%  1224    97.51   -18.51%
vc++exp Total   57897   -       -9.23%  16139   -       1.06%   12734   -       -3.65%
```

This shows a fairly large increase in error rate, and this is after eliminating some use of floating point arithmetic from the code. More dramatically different though, is Visual C++6, which measures up with slightly better word accuracy, but worse character accuracy:

```
Testid  Testset Character               Word                    Non-stopword
                Errors  Acc     Change  Errors  Acc     Change  Errors  Acc     Change
vc6     bus.3B  6298    98.03%  5.69%   1696    96.70%  3.99%   1317    95.65   1.86%
vc6     doe3.3B 29745   97.97%  -18.17% 8105    96.20%  3.57%   6894    94.98   -2.10%
vc6     mag.3B  15036   97.74%  -0.05%  4448    96.11%  -2.58%  3165    95.31   -6.33%
vc6     news.3B 7531    98.47%  17.09%  1745    97.92%  -10.33% 1210    97.53   -19.44%
vc6     Total   58610   -       -8.11%  15994   -       0.16%   12586   -       -4.77%
```

Future work may be directed at making these discrepancies smaller, if not eliminating them completely, on the grounds that where there is variation, there is room for improvement...



### Results for more recent versions of Tesseract [by Tom Morris](https://groups.google.com/forum/#!searchin/tesseract-dev/bus.3B%7Csort:date/tesseract-dev/LErriuT-sck/B5PR0QaCGwAJ)

All compiled with Apple C compiler Apple LLVM version 7.0.2 (clang-700.1.81) with target x86_64-apple-darwin14.3.0.

```
Testid  Testset Character               Word                    Non-stopword
                Errors  Acc     Change  Errors  Acc     Change  Errors  Acc     Change
3.04.01 bus.3B  8816    97.24%  47.94%  2221    95.68%  36.17%  1629    94.62   25.99%
3.04.01 doe3.3B 48306   96.70%  32.89%  9903    95.36%  26.54%  9020    93.43   28.09%
3.04.01 mag.3B  30860   95.37%  105.15% 7034    93.85%  54.05%  5228    92.25   54.72%
3.04.01 news.3B 19073   96.12%  196.53% 3432    95.92%  76.36%  2685    94.53   78.76%
3.04.01 Total   107055  -       67.84%  22590   -       41.46%  18562   -       40.45%
```

```
Testid  Testset Character               Word                    Non-stopword
                Errors  Acc     Change  Errors  Acc     Change  Errors  Acc     Change
3.03rc1	bus.3B	8816	97.24%	47.94%	2221	95.68%	36.17%	1629	94.62	25.99%
3.03rc1	doe3.3B	48306	96.70%	32.89%	9903	95.36%	26.54%	9020	93.43	28.09%
3.03rc1	mag.3B	30860	95.37%	105.15%	7034	93.85%	54.05%	5228	92.25	54.72%
3.03rc1	news.3B	19073	96.12%	196.53%	3432	95.92%	76.36%	2685	94.53	78.76%
3.03rc1	Total	107055	-	67.84%	22590	-	41.46%	18562	-	40.45%
```

```
Testid  Testset Character               Word                    Non-stopword
                Errors  Acc     Change  Errors  Acc     Change  Errors  Acc     Change
3.02.02	bus.3B	6039	98.11%	1.34%	1541	97.01%	-5.52%	1240	95.90	-4.10%
3.02.02	doe3.3B	35988	97.54%	-0.99%	8482	96.03%	8.38%	7640	94.43	8.49%
3.02.02	mag.3B	14367	97.84%	-4.49%	3891	96.60%	-14.78%	3024	95.52	-10.51%
3.02.02	news.3B	7148	98.55%	11.13%	1484	98.23%	-23.74%	1152	97.65	-23.30%
3.02.02	Total	63542	-	-0.38%	15398	-	-3.58%	13056	-	-1.21%
```

```
Testid  Testset Character               Word                    Non-stopword
                Errors  Acc     Change  Errors  Acc     Change  Errors  Acc     Change
3.01	bus.3B	22384	93.00%	275.63%	2253	95.62%	38.14%	1863	93.85	44.08%
3.01	doe3.3B	301312	79.41%	728.94%	13924	93.48%	77.92%	11665	91.50	65.65%
3.01	mag.3B	160024	75.98%	963.78%	10698	90.65%	134.30%	7261	89.24	114.89%
3.01	news.3B	43454	91.17%	575.59%	3469	95.87%	78.26%	2380	95.15	58.46%
3.01	Total	527174	-	726.51%	30344	-	90.02%	23169	-	75.31%
```

```
Testid  Testset Character               Word                    Non-stopword
                Errors  Acc     Change  Errors  Acc     Change  Errors  Acc     Change
2.04	bus.3B	6422	97.99%	7.77%	1750	96.60%	7.30%	1361	95.51	5.26%
2.04	doe3.3B	29514	97.98%	-18.80%	7963	96.27%	1.75%	6762	95.07	-3.98%
2.04	mag.3B	14568	97.81%	-3.16%	4289	96.25%	-6.07%	3053	95.47	-9.65%
2.04	news.3B	7655	98.44%	19.01%	1730	97.94%	-11.10%	1208	97.54	-19.57%
2.04	Total	58159	-	-8.82%	15732	-	-1.48%	12384	-	-6.30%
```





# How to use OCR Evaluation Tools by Nick White

## Introduction

Nick White had forked a repository of the ISRI OCR evaluation tools to make them work easily with UTF-8, and included some helper scripts.

```
git clone https://ancientgreekocr.org/ocr-evaluation-tools.git
Tools to test OCR accuracy.
```

Of particular relevance here is the 'tessaccsummary' script, which when given a directory of images and corresponding ground truth text and a .traineddata file will OCR each page and print the accuracy, and an average summary at the end. 

