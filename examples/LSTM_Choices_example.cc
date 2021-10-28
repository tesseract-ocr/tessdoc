#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
int main()
{
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
// Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
// Open input image with leptonica library
  Pix *image = pixRead("choices.png");
  api->SetImage(image);
// Set lstm_choice_mode to alternative symbol choices per character, bbox is at word level.
  api->SetVariable("lstm_choice_mode", "2");
  api->Recognize(0);
  tesseract::PageIteratorLevel level = tesseract::RIL_WORD;
  tesseract::ResultIterator* res_it = api->GetIterator();
// Get confidence level for alternative symbol choices. Code is based on 
// https://github.com/tesseract-ocr/tesseract/blob/main/src/api/hocrrenderer.cpp#L325-L344
  std::vector<std::vector<std::pair<const char*, float>>>* choiceMap = nullptr;
  if (res_it != 0) {
    do {
      const char* word;
      float conf;
      int x1, y1, x2, y2, tcnt = 1, gcnt = 1, wcnt = 0;
     res_it->BoundingBox(level, &x1, &y1, &x2, &y2);
     choiceMap = res_it->GetBestLSTMSymbolChoices();
      for (auto timestep : *choiceMap) {
        if (timestep.size() > 0) {
          for (auto & j : timestep) {
            conf = int(j.second * 100);
            word =  j.first;
            printf("%d  symbol: '%s';  \tconf: %.2f; BoundingBox: %d,%d,%d,%d;\n",
                        wcnt, word, conf, x1, y1, x2, y2);
           gcnt++;
          }
          tcnt++;
        }
      wcnt++;
      printf("\n");
      }
    } while (res_it->Next(level));
  }
// Destroy used object and release memory
    api->End();
    pixDestroy(&image);
    return 0;
}
