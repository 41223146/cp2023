#include <stdio.h>
#include <gd.h>

#define WIDTH 600
#define HEIGHT 400
#define RED 0xD21C1C   // Red color
#define WHITE 0xFFFFFF // White color
#define GREEN 0x318B41  // Corrected Green color

void drawHungaryFlag() {
    gdImagePtr im;
    FILE *output;

    im = gdImageCreateTrueColor(WIDTH, HEIGHT);
    output = fopen("hungary_flag.png", "wb");

    // Allocate red, white, and green colors
    int redIndex = gdImageColorAllocate(im, (RED >> 16) & 0xFF, (RED >> 8) & 0xFF, RED & 0xFF);
    int whiteIndex = gdImageColorAllocate(im, (WHITE >> 16) & 0xFF, (WHITE >> 8) & 0xFF, WHITE & 0xFF);
    int greenIndex = gdImageColorAllocate(im, (GREEN >> 16) & 0xFF, (GREEN >> 8) & 0xFF, GREEN & 0xFF);

    // Draw red upper third
    gdImageFilledRectangle(im, 0, 0, WIDTH - 1, HEIGHT / 3 - 1, redIndex);

    // Draw white middle third
    gdImageFilledRectangle(im, 0, HEIGHT / 3, WIDTH - 1, 2 * HEIGHT / 3 - 1, whiteIndex);

    // Draw green lower third
    gdImageFilledRectangle(im, 0, 2 * HEIGHT / 3, WIDTH - 1, HEIGHT - 1, greenIndex);

    // Save the image
    gdImagePng(im, output);
    fclose(output);
    gdImageDestroy(im);
}

int main() {
    drawHungaryFlag();
    return 0;
}
