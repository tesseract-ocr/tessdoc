#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
int main()
{
    const char* inputfile = "/tesseract/testing/devatest-rotated-270.png";
    PIX *image = pixRead(inputfile);
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    api->Init(NULL, "osd");
// Get OSD - old example code
    tesseract::Orientation orientation;
    tesseract::WritingDirection direction;
    tesseract::TextlineOrder order;
    float deskew_angle;
    api->SetPageSegMode(tesseract::PSM_AUTO_OSD);
    api->SetImage(image);
    api->Recognize(0);
    tesseract::PageIterator* it =  api->AnalyseLayout();
    it->Orientation(&orientation, &direction, &order, &deskew_angle);
    printf("Orientation: %d;\nWritingDirection: %d\nTextlineOrder: %d\n" \
    "Deskew angle: %.4f\n",
    orientation, direction, order, deskew_angle);
//Get OSD - new code
    int orient_deg;
    float orient_conf;
    const char* script_name;
    float script_conf;
    api->DetectOrientationScript(&orient_deg, &orient_conf, &script_name, &script_conf);
    printf("************\n Orientation in degrees: %d\n Orientation confidence: %.2f\n"
    " Script: %s\n Script confidence: %.2f\n",
    orient_deg, orient_conf,
    script_name, script_conf);
    // Destroy used object and release memory
    api->End();
    pixDestroy(&image);
    return 0;
}
