#include <stdio.h>
#include <gd.h>

#define WIDTH 600
#define HEIGHT 400
#define RED 0xBF0A30    // Red color
#define WHITE 0xFFFFFF  // White color

void drawLatviaFlag() {
    gdImagePtr im;
    FILE *output;

    im = gdImageCreateTrueColor(WIDTH, HEIGHT);
    output = fopen("latvia_flag.png", "wb");

    // Allocate red and white colors
    int redIndex = gdImageColorAllocate(im, (RED >> 16) & 0xFF, (RED >> 8) & 0xFF, RED & 0xFF);
    int whiteIndex = gdImageColorAllocate(im, (WHITE >> 16) & 0xFF, (WHITE >> 8) & 0xFF, WHITE & 0xFF);

    // Draw red upper half
    gdImageFilledRectangle(im, 0, 0, WIDTH - 1, HEIGHT / 2 - 1, redIndex);

    // Draw red lower half
    gdImageFilledRectangle(im, 0, HEIGHT / 2, WIDTH - 1, HEIGHT - 1, redIndex);

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
