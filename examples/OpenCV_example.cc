#include <string>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

string outText, imPath = argv[1];
Mat im = cv::imread(imPath, IMREAD_COLOR);
tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

api->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
api->SetPageSegMode(tesseract::PSM_AUTO);
api->SetImage(im.data, im.cols, im.rows, 3, im.step);
outText = string(api->GetUTF8Text());
cout << outText;
api->End();
