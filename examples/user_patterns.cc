#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

int main()
{
    Pix *image;
    char *outText;
    char *configs[]={"path/to/my.patterns.config"};
    int configs_size = 1;
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    if (api->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY, configs, configs_size, NULL, NULL, false)) {
      fprintf(stderr, "Could not initialize tesseract.\n");
      exit(1);
    }
    image = pixRead("Arial.png");
    api->SetImage(image);
    outText = api->GetUTF8Text();
    printf(outText);
    api->End();
    delete [] outText;
    pixDestroy(&image);
    return 0;
}
