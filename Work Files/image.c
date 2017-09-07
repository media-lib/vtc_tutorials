#include <stdio.h>
#include <gd.h>
#include <gdfontg.h>

int main(int argc, char *argv[]) {
 gdImagePtr img;
 FILE *fp = {0};
 int width, white, black;

 width = white = black = 0;

 if(argc != 3) {
  fprintf(stderr, "Usage: pngtxt image.png 'Hello world.. !'\n");
  return 1;
 }

 fp = fopen(argv[1], "wb");
 if(fp == NULL) {
  fprintf(stderr, "Error - fopen(%s)\n", argv[1]);
  return 1;
 }

 width = strlen(argv[2]);

 img = gdImageCreate(width * 10, 20);

 white = gdImageColorAllocate(img, 255, 255, 255);
 black = gdImageColorAllocate(img, 0, 0, 0);

 gdImageString(img, gdFontGiant, 2, 1, argv[2], black);

 gdImagePng(img, fp); 

 fclose(fp); 
 gdImageDestroy(img);

 return 0;
}
