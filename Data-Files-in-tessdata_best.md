## Information specific to tessdata_best

These models were trained by Ray Smith's team at Google in 2017 and contributed to the open
source project.

**`tessdata_best`** is for people willing to trade a lot of speed for slightly better accuracy. It is also
the only set of files which can be used as start_model for certain retraining scenarios for advanced users.

### Version string : 4.00.00alpha : [Network specification] for tessdata_best

By convention the network spec is often appended to the version string, but not always.
In the case of a difference, the spec in `network=[]` is the authority as it was read for the actual model's
network.

There are two sections below: 125 languages, followed by 37 scripts.

### Languages (123 + osd + eq)

All language and script models have the same values for the following parameters which have been removed from the
individual descriptions: `int_mode=0, recoding=1, learning_rate=0.001, momentum=0.5, adam_beta=0.999 `

```
afr
Version:4.00.00alpha:afr:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=286700, sample_iteration=286724, null_char=95
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.001, :2(Maxpool)=0.001, :3:0(Lfys64)=0.001, :4(Lfx96)=0.001, :5:0(Lrx96)=0.001, :6(Lfx512)=0.001, :7(Output)=0.001

amh
Version:4.00.00alpha:amh:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1], iteration=6112200, sample_iteration=6112270, null_char=284
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys48)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx192)=0.000125, :7(Output)=0.000125

ara
Version:4.00.00alpha:ara:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2111400, sample_iteration=2120404, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx512)=0.000176777, :7(Output)=0.000176777

asm
Version:4.00.00alpha:asm:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx64Lrx64Lfx512O1c1], iteration=2758500, sample_iteration=2758570, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=8.83884e-05, :4(Lfx64)=8.83884e-05, :5:0(Lrx64)=8.83884e-05, :6(Lfx512)=8.83884e-05, :7(Output)=8.83884e-05

aze
Version:4.00.00alpha:aze:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=6760000, sample_iteration=6760858, null_char=88
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx192)=0.000125, :7(Output)=0.000125

aze_cyrl
Version:4.00.00alpha:aze_cyrl:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=7665300, sample_iteration=7666563, null_char=88
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

bel
Version:4.00.00alpha:bel:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2014700, sample_iteration=2014972, null_char=95
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.0005, :2(Maxpool)=0.001, :3:0(Lfys64)=0.0005, :4(Lfx96)=0.0005, :5:0(Lrx96)=0.0005, :6(Lfx384)=0.0005, :7(Output)=0.0005

ben
Version:4.00.00alpha:ben:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx64Lrx64Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx64Lrx64Lfx512O1c1], iteration=1534600, sample_iteration=1534685, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx64)=0.00025, :5:0(Lrx64)=0.00025, :6(Lfx512)=0.00025, :7(Output)=0.00025

bod
Version:4.00.00alpha:bod:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3513900, sample_iteration=3524222, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx384)=8.83884e-05, :7(Output)=8.83884e-05

bos
Version:4.00.00alpha:bos:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=3258400, sample_iteration=3258771, null_char=95
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

bre
Version:4.00.00alpha:bre:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx64Lrx64Lfx512O1c1], iteration=14000, sample_iteration=14000, null_char=124
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.001, :2(Maxpool)=0.001, :3:0(Lfys64)=0.001, :4(Lfx64)=0.001, :5:0(Lrx64)=0.001, :6(Lfx512)=0.001, :7(Output)=0.001

bul
Version:4.00.00alpha:bul:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=887500, sample_iteration=887807, null_char=92
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.0005, :2(Maxpool)=0.001, :3:0(Lfys64)=0.0005, :4(Lfx96)=0.0005, :5:0(Lrx96)=0.0005, :6(Lfx384)=0.0005, :7(Output)=0.0005

cat
Version:4.00.00alpha:cat:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1], iteration=2427200, sample_iteration=2427351, null_char=88
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys48)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx192)=0.000353553, :7(Output)=0.000353553

ceb
Version:4.00.00alpha:ceb:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=6718000, sample_iteration=6772655, null_char=73
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

ces
Version:4.00.00alpha:ces:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3211200, sample_iteration=3211404, null_char=121
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

chi_sim
Version:4.00.00alpha:chi_sim:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=1971300, sample_iteration=1976813, null_char=223
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx512)=8.83884e-05, :7(Output)=8.83884e-05

chi_sim_vert
Version:4.00.00alpha:chi_sim_vert:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2335900, sample_iteration=2350219, null_char=223
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx512)=0.000176777, :7(Output)=0.000176777

chi_tra
Version:4.00.00alpha:chi_tra:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=1988000, sample_iteration=1992889, null_char=226
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx512)=0.000125, :7(Output)=0.000125

chi_tra_vert
Version:4.00.00alpha:chi_tra_vert:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=3521300, sample_iteration=3571821, null_char=226
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx512)=0.000176777, :7(Output)=0.000176777

chr
Version:4.00.00alpha:chr:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1], iteration=7847200, sample_iteration=7847486, null_char=102
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys48)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx128)=8.83884e-05, :7(Output)=8.83884e-05

cos
Version:4.00.00alpha:cos:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=5120400, sample_iteration=5120693, null_char=104
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx384)=8.83884e-05, :7(Output)=8.83884e-05

cym
Version:4.00.00alpha:cym:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=4212000, sample_iteration=4212285, null_char=108
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

dan
Version:4.00.00alpha:dan:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2547300, sample_iteration=2547538, null_char=100
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

deu
Version:4.00.00alpha:deu:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3543300, sample_iteration=3543653, null_char=114
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx384)=0.00025, :7(Output)=0.00025

div
Version:4.00.00alpha:div:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=3249400, sample_iteration=3256730, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx192)=0.000353553, :7(Output)=0.000353553

dzo
Version:4.00.00alpha:dzo:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=4258800, sample_iteration=4335799, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=6.25e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=6.25e-05, :4(Lfx96)=6.25e-05, :5:0(Lrx96)=6.25e-05, :6(Lfx192)=6.25e-05, :7(Output)=6.25e-05

ell
Version:4.00.00alpha:ell:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3335500, sample_iteration=3335569, null_char=213
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

eng
Version:4.00.00alpha:eng:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=814100, sample_iteration=814136, null_char=110
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.0005, :2(Maxpool)=0.001, :3:0(Lfys64)=0.0005, :4(Lfx96)=0.0005, :5:0(Lrx96)=0.0005, :6(Lfx512)=0.0005, :7(Output)=0.0005

enm
Version:4.00.00alpha:enm:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2720200, sample_iteration=2721910, null_char=104
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx512)=0.000125, :7(Output)=0.000125

epo
Version:4.00.00alpha:epo:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1], iteration=6842600, sample_iteration=6843069, null_char=101
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=6.25e-05, :2(Maxpool)=0.001, :3:0(Lfys48)=6.25e-05, :4(Lfx96)=6.25e-05, :5:0(Lrx96)=6.25e-05, :6(Lfx192)=6.25e-05, :7(Output)=6.25e-05

equ
Version:Pre-4.0.0+Pre-4.0.0:best2int20180321

est
Version:4.00.00alpha:est:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=1637300, sample_iteration=1637435, null_char=103
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx512)=0.000176777, :7(Output)=0.000176777

eus
Version:4.00.00alpha:eus:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=15200, sample_iteration=15204, null_char=89
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.001, :2(Maxpool)=0.001, :3:0(Lfys64)=0.001, :4(Lfx96)=0.001, :5:0(Lrx96)=0.001, :6(Lfx192)=0.001, :7(Output)=0.001

fao
Version:4.00.00alpha:fao:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2812800, sample_iteration=2812950, null_char=126
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

fas
Version:4.00.00alpha:fas:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=896400, sample_iteration=897843, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx192)=0.00025, :7(Output)=0.00025

fil
Version:4.00.00alpha:fil:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3854100, sample_iteration=3854348, null_char=81
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

fin
Version:4.00.00alpha:fin:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3741900, sample_iteration=3742321, null_char=94
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx384)=0.000125, :7(Output)=0.000125

fra
Version:4.00.00alpha:fra:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1], iteration=3486400, sample_iteration=3486632, null_char=139
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys48)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx192)=0.000125, :7(Output)=0.000125

frk
Version:4.00.00alpha:frk:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3692700, sample_iteration=3692967, null_char=98
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx384)=0.000125, :7(Output)=0.000125

frm
Version:4.00.00alpha:frm:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1], iteration=176600, sample_iteration=176697, null_char=140
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.001, :2(Maxpool)=0.001, :3:0(Lfys64)=0.001, :4(Lfx96)=0.001, :5:0(Lrx96)=0.001, :6(Lfx128)=0.001, :7(Output)=0.001

fry
Version:4.00.00alpha:fry:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3246500, sample_iteration=3246617, null_char=106
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx384)=0.000125, :7(Output)=0.000125

gla
Version:4.00.00alpha:gla:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3365500, sample_iteration=3365659, null_char=104
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx384)=0.00025, :7(Output)=0.00025

gle
Version:4.00.00alpha:gle:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=2457900, sample_iteration=2458041, null_char=91
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx192)=0.00025, :7(Output)=0.00025

glg
Version:4.00.00alpha:glg:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2711300, sample_iteration=2711543, null_char=97
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx512)=0.00025, :7(Output)=0.00025

grc
Version:4.00.00alpha:grc:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=3843500, sample_iteration=3843646, null_char=211
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

guj
Version:4.00.00alpha:guj:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=1447700, sample_iteration=1448272, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx384)=0.000353553, :7(Output)=0.000353553

hat
Version:4.00.00alpha:hat:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2653800, sample_iteration=2653890, null_char=96
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx512)=0.00025, :7(Output)=0.00025

heb
Version:4.00.00alpha:heb:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1], iteration=1568000, sample_iteration=1570525, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000707107, :2(Maxpool)=0.001, :3:0(Lfys48)=0.000707107, :4(Lfx96)=0.000707107, :5:0(Lrx96)=0.000707107, :6(Lfx192)=0.000707107, :7(Output)=0.000707107

hin
Version:4.00.00alpha:hin:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=803600, sample_iteration=803651, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.0005, :2(Maxpool)=0.001, :3:0(Lfys64)=0.0005, :4(Lfx96)=0.0005, :5:0(Lrx96)=0.0005, :6(Lfx512)=0.0005, :7(Output)=0.0005

hrv
Version:4.00.00alpha:hrv:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=4712800, sample_iteration=4713183, null_char=105
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

hun
Version:4.00.00alpha:hun:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2046400, sample_iteration=2046674, null_char=97
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx384)=0.00025, :7(Output)=0.00025

hye
Version:4.00.00alpha:hye:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=1590800, sample_iteration=1591465, null_char=104
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx192)=0.000353553, :7(Output)=0.000353553

iku
Version:4.00.00alpha:iku:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1], iteration=3862400, sample_iteration=3862672, null_char=595
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys48)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

ind
Version:4.00.00alpha:ind:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=876700, sample_iteration=876737, null_char=84
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx384)=0.000353553, :7(Output)=0.000353553

isl
Version:4.00.00alpha:isl:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2355200, sample_iteration=2355391, null_char=110
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx384)=0.000125, :7(Output)=0.000125

ita
Version:4.00.00alpha:ita:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx64Lrx64Lfx384O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx64Lrx64Lfx384O1c1], iteration=1645500, sample_iteration=1645594, null_char=118
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx64)=0.000176777, :5:0(Lrx64)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

ita_old
Version:4.00.00alpha:ita_old:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2975300, sample_iteration=2980533, null_char=117
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx384)=0.000125, :7(Output)=0.000125

jav
Version:4.00.00alpha:jav:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx64Lrx64Lfx384O1c1], iteration=449600, sample_iteration=449630, null_char=92
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000707107, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000707107, :4(Lfx64)=0.000707107, :5:0(Lrx64)=0.000707107, :6(Lfx384)=0.000707107, :7(Output)=0.000707107

jpn
Version:4.00.00alpha:jpn:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2162500, sample_iteration=2166492, null_char=414
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx512)=0.000125, :7(Output)=0.000125

jpn_vert
Version:4.00.00alpha:jpn_vert:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=1874000, sample_iteration=1878622, null_char=414
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx512)=0.000125, :7(Output)=0.000125

kan
Version:4.00.00alpha:kan:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2217600, sample_iteration=2219122, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx384)=0.00025, :7(Output)=0.00025

kat
Version:4.00.00alpha:kat:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1], iteration=5277000, sample_iteration=5286853, null_char=78
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx128)=0.000176777, :7(Output)=0.000176777

kat_old
Version:4.00.00alpha:kat_old:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=6695800, sample_iteration=6695849, null_char=84
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx192)=8.83884e-05, :7(Output)=8.83884e-05

kaz
Version:4.00.00alpha:kaz:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=3952100, sample_iteration=3952887, null_char=116
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

khm
Version:4.00.00alpha:khm:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2208100, sample_iteration=2250468, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx384)=0.00025, :7(Output)=0.00025

kir
Version:4.00.00alpha:kir:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1], iteration=5271100, sample_iteration=5274339, null_char=142
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx128)=0.000176777, :7(Output)=0.000176777

kmr
Version:4.00.00alpha:kur_ara:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2729500, sample_iteration=2731777, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

kor
Version:4.00.00alpha:kor:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]:fixconfig:20180409
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2109500, sample_iteration=2109548, null_char=143
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx512)=0.000125, :7(Output)=0.000125

kor_vert
Version:4.00.00alpha:kor_vert:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=432600, sample_iteration=433382, null_char=147
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000707107, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000707107, :4(Lfx96)=0.000707107, :5:0(Lrx96)=0.000707107, :6(Lfx192)=0.000707107, :7(Output)=0.000707107

lao
Version:4.00.00alpha:lao:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2657200, sample_iteration=2659268, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

lat
Version:4.00.00alpha:lat:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2768500, sample_iteration=2768698, null_char=99
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx384)=0.000125, :7(Output)=0.000125

lav
Version:4.00.00alpha:lav:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=5214000, sample_iteration=5214525, null_char=113
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

lit
Version:4.00.00alpha:lit:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2297800, sample_iteration=2297944, null_char=107
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

ltz
Version:4.00.00alpha:ltz:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=16600, sample_iteration=16602, null_char=86
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.001, :2(Maxpool)=0.001, :3:0(Lfys64)=0.001, :4(Lfx96)=0.001, :5:0(Lrx96)=0.001, :6(Lfx512)=0.001, :7(Output)=0.001

mal
Version:4.00.00alpha:mal:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=673300, sample_iteration=673973, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.0005, :2(Maxpool)=0.001, :3:0(Lfys64)=0.0005, :4(Lfx96)=0.0005, :5:0(Lrx96)=0.0005, :6(Lfx384)=0.0005, :7(Output)=0.0005

mar
Version:4.00.00alpha:mar:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=763200, sample_iteration=763256, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx512)=0.00025, :7(Output)=0.00025

mkd
Version:4.00.00alpha:mkd:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1], iteration=3336200, sample_iteration=3336731, null_char=83
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx128)=0.00025, :7(Output)=0.00025

mlt
Version:4.00.00alpha:mlt:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=4769500, sample_iteration=4770242, null_char=84
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx192)=0.000125, :7(Output)=0.000125

mon
Version:4.00.00alpha:mon:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3913100, sample_iteration=3913523, null_char=96
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

mri
Version:4.00.00alpha:mri:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=6812500, sample_iteration=6812705, null_char=81
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

msa
Version:4.00.00alpha:msa:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=1919100, sample_iteration=1919220, null_char=86
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx384)=0.000353553, :7(Output)=0.000353553

mya
Version:4.00.00alpha:mya:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2609700, sample_iteration=2617837, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx512)=8.83884e-05, :7(Output)=8.83884e-05

nep
Version:4.00.00alpha:nep:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=614300, sample_iteration=614465, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx512)=0.000353553, :7(Output)=0.000353553

nld
Version:4.00.00alpha:nld:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=1291600, sample_iteration=1291688, null_char=149
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx192)=0.000353553, :7(Output)=0.000353553

nor
Version:4.00.00alpha:nor:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=1807700, sample_iteration=1807796, null_char=103
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx512)=0.000353553, :7(Output)=0.000353553

oci
Version:4.00.00alpha:oci:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3059700, sample_iteration=3059833, null_char=128
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

ori
Version:4.00.00alpha:ori:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=4023900, sample_iteration=4026843, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx384)=8.83884e-05, :7(Output)=8.83884e-05

osd
Version:Pre-4.0.0

pan
Version:4.00.00alpha:pan:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=1497500, sample_iteration=1497580, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx512)=0.00025, :7(Output)=0.00025

pol
Version:4.00.00alpha:pol:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2025000, sample_iteration=2025253, null_char=112
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx384)=0.00025, :7(Output)=0.00025

por
Version:4.00.00alpha:por:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx64Lrx64Lfx384O1c1], iteration=3256000, sample_iteration=3256189, null_char=118
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx64)=0.000176777, :5:0(Lrx64)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

pus
Version:4.00.00alpha:pus:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2355400, sample_iteration=2358432, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx512)=8.83884e-05, :7(Output)=8.83884e-05

que
Version:4.00.00alpha:que:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx64Lrx64Lfx384O1c1], iteration=3950200, sample_iteration=3950594, null_char=122
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx64)=0.000176777, :5:0(Lrx64)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

ron
Version:4.00.00alpha:ron:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=1204800, sample_iteration=1204905, null_char=109
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.0005, :2(Maxpool)=0.001, :3:0(Lfys64)=0.0005, :4(Lfx96)=0.0005, :5:0(Lrx96)=0.0005, :6(Lfx384)=0.0005, :7(Output)=0.0005

rus
Version:4.00.00alpha:rus:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2192900, sample_iteration=2193913, null_char=123
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx512)=0.00025, :7(Output)=0.00025

san
Version:4.00.00alpha:san:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1], iteration=200200, sample_iteration=200279, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000707107, :2(Maxpool)=0.001, :3:0(Lfys48)=0.000707107, :4(Lfx96)=0.000707107, :5:0(Lrx96)=0.000707107, :6(Lfx192)=0.000707107, :7(Output)=0.000707107

sin
Version:4.00.00alpha:sin:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=4268500, sample_iteration=4268756, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=6.25e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=6.25e-05, :4(Lfx96)=6.25e-05, :5:0(Lrx96)=6.25e-05, :6(Lfx384)=6.25e-05, :7(Output)=6.25e-05

slk
Version:4.00.00alpha:slk:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=1764000, sample_iteration=1764249, null_char=118
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

slv
Version:4.00.00alpha:slv:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=3729500, sample_iteration=3729842, null_char=91
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx192)=0.000125, :7(Output)=0.000125

snd
Version:4.00.00alpha:snd:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2550300, sample_iteration=2555328, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx512)=8.83884e-05, :7(Output)=8.83884e-05

spa
Version:4.00.00alpha:spa:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2510500, sample_iteration=2510656, null_char=107
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx512)=0.000353553, :7(Output)=0.000353553

spa_old
Version:4.00.00alpha:spa_old:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=1844900, sample_iteration=1845568, null_char=123
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx384)=0.000125, :7(Output)=0.000125

sqi
Version:4.00.00alpha:sqi:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1], iteration=1092600, sample_iteration=1092694, null_char=78
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys48)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx192)=0.00025, :7(Output)=0.00025

srp
Version:4.00.00alpha:srp:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3015300, sample_iteration=3015626, null_char=101
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

srp_latn
Version:4.00.00alpha:srp_latn:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3226700, sample_iteration=3226895, null_char=111
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx384)=0.00025, :7(Output)=0.00025

sun
Version:4.00.00alpha:sun:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=5572000, sample_iteration=5572210, null_char=93
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

swa
Version:4.00.00alpha:swa:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=2668900, sample_iteration=2669094, null_char=81
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

swe
Version:4.00.00alpha:swe:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=1803900, sample_iteration=1804028, null_char=98
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx512)=0.00025, :7(Output)=0.00025

syr
Version:4.00.00alpha:syr:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2731600, sample_iteration=2738621, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx512)=0.000125, :7(Output)=0.000125

tam
Version:4.00.00alpha:tam:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1], iteration=1159800, sample_iteration=1159944, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys48)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx192)=0.000353553, :7(Output)=0.000353553

tat
Version:4.00.00alpha:tat:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3975700, sample_iteration=3975926, null_char=97
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx384)=0.000125, :7(Output)=0.000125

tel
Version:4.00.00alpha:tel:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx64Lrx64Lfx384O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx64Lrx64Lfx384O1c1], iteration=1051100, sample_iteration=1051631, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx64)=0.00025, :5:0(Lrx64)=0.00025, :6(Lfx384)=0.00025, :7(Output)=0.00025

tgk
Version:4.00.00alpha:tgk:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1], iteration=4505600, sample_iteration=4505867, null_char=120
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx128)=0.000176777, :7(Output)=0.000176777

tha
Version:4.00.00alpha:tha:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=1895200, sample_iteration=1897798, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx384)=8.83884e-05, :7(Output)=8.83884e-05

tir
Version:4.00.00alpha:tir:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1], iteration=10498000, sample_iteration=10498000, null_char=267
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys48)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx128)=8.83884e-05, :7(Output)=8.83884e-05

ton
Version:4.00.00alpha:ton:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=4730800, sample_iteration=4730909, null_char=107
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

tur
Version:4.00.00alpha:tur:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=3937500, sample_iteration=3937992, null_char=102
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

uig
Version:4.00.00alpha:uig:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2731200, sample_iteration=2737916, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx512)=0.000125, :7(Output)=0.000125

ukr
Version:4.00.00alpha:ukr:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2955500, sample_iteration=2956188, null_char=90
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx384)=0.000353553, :7(Output)=0.000353553

urd
Version:4.00.00alpha:urd:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3927800, sample_iteration=3938775, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx384)=0.000125, :7(Output)=0.000125

uzb
Version:4.00.00alpha:uzb:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3363200, sample_iteration=3363853, null_char=86
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

uzb_cyrl
Version:4.00.00alpha:uzb_cyrl:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=4993600, sample_iteration=4995772, null_char=92
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

vie
Version:4.00.00alpha:vie:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2163300, sample_iteration=2163320, null_char=268
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx512)=0.000176777, :7(Output)=0.000176777

yid
Version:4.00.00alpha:yid:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx192O1c1], iteration=1500000, sample_iteration=1500759, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys48)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx192)=0.000353553, :7(Output)=0.000353553

yor
Version:4.00.00alpha:yor:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=4201700, sample_iteration=4201736, null_char=100
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx192)=0.000125, :7(Output)=0.000125
```

### Scripts (37)

All language and script models have the same values for the following parameters which have been removed from the
individual descriptions: `int_mode=0, recoding=1, learning_rate=0.001, momentum=0.5, adam_beta=0.999 `

All scripts except Vietnamese have been trained on multiple languages. Most non-Latin scripts have been trained 
with `eng` as well to improve their robustness.
The list for each script can be found in [script](https://github.com/tesseract-ocr/langdata_lstm/tree/main/script) 
directory of [langdata_lstm](https://github.com/tesseract-ocr/langdata_lstm/) repo in a file name `SCRIPT.langs.txt` 
e.g. 
[Devanagari.langs.txt](https://github.com/tesseract-ocr/langdata_lstm/blob/main/script/Devanagari.langs.txt)

* Latin is all latin-based languages, except `vie`.
* Vietnamese is for latin-based Vietnamese language and does not include `eng`
* [Fraktur](https://github.com/tesseract-ocr/langdata_lstm/blob/main/script/Fraktur.langs.txt) is basically 
  a combination of all the latin-based languages that have an 'old' variant. (`enm+frm+frk+ita_old+spa_old`)
* [Devanagari](https://github.com/tesseract-ocr/langdata_lstm/blob/main/script/Devanagari.langs.txt) is for hin+mar+nep+san+eng.

```
Arabic
Version:4.00.00alpha:Arabic:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2417900, sample_iteration=2421715, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx384)=0.000125, :7(Output)=0.000125

Armenian
Version:4.00.00alpha:Armenian:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=1999200, sample_iteration=1999769, null_char=191
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx512)=0.00025, :7(Output)=0.00025

Bengali
Version:4.00.00alpha:Bengali:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=1118100, sample_iteration=1118153, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx512)=0.000353553, :7(Output)=0.000353553

Canadian_Aboriginal
Version:4.00.00alpha:Canadian_Aboriginal:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=1949300, sample_iteration=1949421, null_char=652
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

Cherokee
Version:4.00.00alpha:Cherokee:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx192O1c1], iteration=7542100, sample_iteration=7542435, null_char=191
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx192)=0.000176777, :7(Output)=0.000176777

Cyrillic
Version:4.00.00alpha:Cyrillic:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3121900, sample_iteration=3122619, null_char=202
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx384)=0.000353553, :7(Output)=0.000353553

Devanagari
Version:4.00.00alpha:Devanagari:synth20170629test

LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx64Lrx64Lfx512O1c1], iteration=2475100, sample_iteration=2475272, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx64)=0.000176777, :5:0(Lrx64)=0.000176777, :6(Lfx512)=0.000176777, :7(Output)=0.000176777

Ethiopic
Version:4.00.00alpha:Ethiopic:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys48Lfx96Lrx96Lfx128O1c1], iteration=149100, sample_iteration=149101, null_char=385
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.001, :2(Maxpool)=0.001, :3:0(Lfys48)=0.001, :4(Lfx96)=0.001, :5:0(Lrx96)=0.001, :6(Lfx128)=0.001, :7(Output)=0.001

Fraktur
Version:4.00.00alpha:Fraktur:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3739900, sample_iteration=3740440, null_char=166
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

Georgian
Version:4.00.00alpha:Georgian:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2308600, sample_iteration=2310386, null_char=225
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx384)=0.000125, :7(Output)=0.000125

Greek
Version:4.00.00alpha:Greek:synth20170629
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=1727400, sample_iteration=1727456, null_char=236
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx384)=0.000353553, :7(Output)=0.000353553

Gujarati
Version:4.00.00alpha:Gujarati:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1], iteration=4569600, sample_iteration=4569934, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx128)=0.000125, :7(Output)=0.000125

Gurmukhi
Version:4.00.00alpha:Gurmukhi:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3177000, sample_iteration=3177347, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

HanS
Version:4.00.00alpha:HanS:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2009700, sample_iteration=2013398, null_char=238
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx512)=0.000125, :7(Output)=0.000125

HanS_vert
Version:4.00.00alpha:HanS_vert:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2966600, sample_iteration=2977655, null_char=238
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx384)=8.83884e-05, :7(Output)=8.83884e-05

HanT
Version:4.00.00alpha:HanT:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2342300, sample_iteration=2346092, null_char=240
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx384)=0.00025, :7(Output)=0.00025

HanT_vert
Version:4.00.00alpha:HanT_vert:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2664100, sample_iteration=2686122, null_char=240
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx384)=0.00025, :7(Output)=0.00025

Hangul
Version:4.00.00alpha:Hangul:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2510300, sample_iteration=2510401, null_char=210
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

Hangul_vert
Version:4.00.00alpha:Hangul_vert:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=881800, sample_iteration=882047, null_char=213
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.0005, :2(Maxpool)=0.001, :3:0(Lfys64)=0.0005, :4(Lfx96)=0.0005, :5:0(Lrx96)=0.0005, :6(Lfx512)=0.0005, :7(Output)=0.0005

Hebrew
Version:4.00.00alpha:Hebrew:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=1902800, sample_iteration=1903513, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000353553, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000353553, :4(Lfx96)=0.000353553, :5:0(Lrx96)=0.000353553, :6(Lfx384)=0.000353553, :7(Output)=0.000353553

Japanese
Version:4.00.00alpha:Japanese:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=1688700, sample_iteration=1690739, null_char=429
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx512)=0.00025, :7(Output)=0.00025

Japanese_vert
Version:4.00.00alpha:Japanese_vert:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2510500, sample_iteration=2514591, null_char=429
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx512)=8.83884e-05, :7(Output)=8.83884e-05

Kannada
Version:4.00.00alpha:Kannada:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=1268000, sample_iteration=1268417, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx384)=0.00025, :7(Output)=0.00025

Khmer
Version:4.00.00alpha:Khmer:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=1697000, sample_iteration=1717762, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx384)=0.00025, :7(Output)=0.00025

Lao
Version:4.00.00alpha:Lao:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=1472500, sample_iteration=1473179, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

Latin
Version:4.00.00alpha:Latin:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2853300, sample_iteration=2853486, null_char=301
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx512)=0.00025, :7(Output)=0.00025

Malayalam
Version:4.00.00alpha:Malayalam:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1], iteration=2943800, sample_iteration=2945329, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx128)=0.00025, :7(Output)=0.00025

Myanmar
Version:4.00.00alpha:Myanmar:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3179300, sample_iteration=3184457, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx384)=0.000176777, :7(Output)=0.000176777

Oriya
Version:4.00.00alpha:Oriya:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=1636900, sample_iteration=1637404, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.00025, :2(Maxpool)=0.001, :3:0(Lfys64)=0.00025, :4(Lfx96)=0.00025, :5:0(Lrx96)=0.00025, :6(Lfx512)=0.00025, :7(Output)=0.00025

Sinhala
Version:4.00.00alpha:Sinhala:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx128O1c1], iteration=244600, sample_iteration=244610, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.001, :2(Maxpool)=0.001, :3:0(Lfys64)=0.001, :4(Lfx96)=0.001, :5:0(Lrx96)=0.001, :6(Lfx128)=0.001, :7(Output)=0.001

Syriac
Version:4.00.00alpha:Syriac:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx64Lrx64Lfx512O1c1], iteration=3512900, sample_iteration=3516598, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx64)=0.000176777, :5:0(Lrx64)=0.000176777, :6(Lfx512)=0.000176777, :7(Output)=0.000176777

Tamil
Version:4.00.00alpha:Tamil:synth20170629:[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,36,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=1435300, sample_iteration=1435431, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000707107, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000707107, :4(Lfx96)=0.000707107, :5:0(Lrx96)=0.000707107, :6(Lfx512)=0.000707107, :7(Output)=0.000707107

Telugu
Version:4.00.00alpha:Telugu:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2842300, sample_iteration=2843033, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=6.25e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=6.25e-05, :4(Lfx96)=6.25e-05, :5:0(Lrx96)=6.25e-05, :6(Lfx384)=6.25e-05, :7(Output)=6.25e-05

Thaana
Version:4.00.00alpha:Thaana:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3214500, sample_iteration=3217590, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=6.25e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=6.25e-05, :4(Lfx96)=6.25e-05, :5:0(Lrx96)=6.25e-05, :6(Lfx384)=6.25e-05, :7(Output)=6.25e-05

Thai
Version:4.00.00alpha:Thai:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=2779100, sample_iteration=2781460, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=8.83884e-05, :2(Maxpool)=0.001, :3:0(Lfys64)=8.83884e-05, :4(Lfx96)=8.83884e-05, :5:0(Lrx96)=8.83884e-05, :6(Lfx384)=8.83884e-05, :7(Output)=8.83884e-05

Tibetan
Version:4.00.00alpha:Tibetan:synth20170629
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx384O1c1], iteration=3447300, sample_iteration=3450348, null_char=2
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000125, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000125, :4(Lfx96)=0.000125, :5:0(Lrx96)=0.000125, :6(Lfx384)=0.000125, :7(Output)=0.000125

Vietnamese
Version:4.00.00alpha:Vietnamese:synth20170629:[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1]
LSTM: network=[1,48,0,1Ct3,3,16Mp3,3Lfys64Lfx96Lrx96Lfx512O1c1], iteration=2347300, sample_iteration=2347307, null_char=268
Layer Learning Rates: :0(Input)=0.001, :1:0(Convolve)=0.001, :1:1(ConvNL)=0.000176777, :2(Maxpool)=0.001, :3:0(Lfys64)=0.000176777, :4(Lfx96)=0.000176777, :5:0(Lrx96)=0.000176777, :6(Lfx512)=0.000176777, :7(Output)=0.000176777

```
