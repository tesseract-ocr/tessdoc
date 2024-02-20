/*
  Windows compile example:
  
  SET TESS_INSTALLATION=C:/win64
  SET OPENCV_INSTALLATION=C:/opencv/build
  cl OpenCV_example.cc -I %TESS_INSTALLATION%/include -I %OPENCV_INSTALLATION%/include /link /LIBPATH:%TESS_INSTALLATION%/lib /LIBPATH:%OPENCV_INSTALLATION%/x64/vc14/lib tesseract51.lib leptonica-1.83.0.lib opencv_world460.lib /machine:x64
  
*/

#include <leptonica/allheaders.h>
#include <opencv2/opencv.hpp>
#include <string>
#include <tesseract/baseapi.h>

int main(int argc, char *argv[]) {

  std::string outText, imPath = argv[1];
  cv::Mat im = cv::imread(imPath, cv::IMREAD_COLOR);
  tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

  api->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
  api->SetPageSegMode(tesseract::PSM_AUTO);
  api->SetImage(im.data, im.cols, im.rows, 3, im.step);
  outText = std::string(api->GetUTF8Text());
  std::cout << outText;
  api->End();
  delete api;
  return 0;
}
