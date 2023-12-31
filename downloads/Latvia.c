#include <stdio.h>
#include <gd.h>

#define WIDTH 600
#define HEIGHT 400
#define DEEPER_RED 0x800000  // Deeper Red color
#define WHITE 0xFFFFFF       // White color

void drawLatviaFlag() {
    gdImagePtr im;
    FILE *output;

    im = gdImageCreateTrueColor(WIDTH, HEIGHT);
    output = fopen("latvia_flag.png", "wb");

    // Allocate deeper red and white colors
    int deeperRedIndex = gdImageColorAllocate(im, (DEEPER_RED >> 16) & 0xFF, (DEEPER_RED >> 8) & 0xFF, DEEPER_RED & 0xFF);
    int whiteIndex = gdImageColorAllocate(im, (WHITE >> 16) & 0xFF, (WHITE >> 8) & 0xFF, WHITE & 0xFF);

    // Draw deeper red upper half
    gdImageFilledRectangle(im, 0, 0, WIDTH - 1, HEIGHT / 2 - 1, deeperRedIndex);

    // Draw deeper red lower half
    gdImageFilledRectangle(im, 0, HEIGHT / 2, WIDTH - 1, HEIGHT - 1, deeperRedIndex);

    // Draw white horizontal stripe (centered vertically)
    int whiteHeight = HEIGHT / 5;  // adjust the height as needed
    int whiteY = (HEIGHT - whiteHeight) / 2;

    // Ensure white stripe does not exceed the image height
    if (whiteY + whiteHeight > HEIGHT)
        whiteHeight = HEIGHT - whiteY;

    gdImageFilledRectangle(im, 0, whiteY, WIDTH - 1, whiteY + whiteHeight - 1, whiteIndex);

    // Save the image
    gdImagePng(im, output);
    fclose(output);
    gdImageDestroy(im);
}

int main() {
    drawLatviaFlag();
    return 0;
}
