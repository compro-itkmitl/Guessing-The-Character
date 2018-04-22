#include <stdio.h>
#include <leptonica/allheaders.h>
#include <tesseract/capi.h>
#include <fstream>

void check(const char *errstr) {
	fputs(errstr, stderr);
	exit(1);
}

int main(int argc, char *argv[]) {
	TessBaseAPI *handle;
	PIX *img;
	char *text;

	//check image
	if((img = pixRead("image.png")) == NULL)
		check("Error reading image\n");

	handle = TessBaseAPICreate(); //create base api

	//check baseapi
	if(TessBaseAPIInit3(handle, NULL, "eng") != 0)
		check("Error initialising tesseract\n");

	TessBaseAPISetImage2(handle, img); //set image

	//check recognise
	if(TessBaseAPIRecognize(handle, NULL) != 0)
		check("Error in Tesseract recognition\n");

	//check text
	if((text = TessBaseAPIGetUTF8Text(handle)) == NULL)
		check("Error getting text\n");

	fputs(text, stdout); //output

	//reset data
	TessDeleteText(text);
	TessBaseAPIEnd(handle);
	TessBaseAPIDelete(handle);
	pixDestroy(&img);

	return 0;
}