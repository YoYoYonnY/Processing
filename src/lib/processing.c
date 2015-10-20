#include "processing.h"

struct {
    color_t background_color;
    bool fill;
    bool stroke;
    size_t strokeThickness;
    color_t fillColor;
    color_t strokeColor;
} processing;

void background(color_t color) {
    processing.background_color = color;
}
void fill(color_t color) {
    processing.fill = true;
    processing.fillColor = color;
}
void noFill(color_t color) {
    processing.fill = false;
}
void stroke(color_t color) {
    processing.stroke = true;
    processing.strokeColor = color;
}
void strokeWeight(size_t thickness) {
    processing.strokeThickness = thickness;
}
void noStroke(color_t color) {
    processing.stroke = false;
}

color_t color(int r, int g, int b) {
    color_t color;
    color.red = r;
    color.green = g;
    color.blue = b;
    color.alpha = 255;
    return color;
}
color_t rgba(int r, int g, int b, int a) {
    color_t color;
    color.red = r;
    color.green = g;
    color.blue = b;
    color.alpha = a;
    return color;
}
color_t hsb(int hue, int saturation, int brightness) {
    color_t color;
    // Magic!
    return color;
}
color_t blendColor(color_t color1, color_t color2, blendmode mode) {
    color_t color;
    // Magic!
    return color;
}
color_t lerpColor(color_t color1, color_t color2, percentage_t amount) {
    color_t color;
    // Magic!
    return color;
}
void colorMode(colormode mode, unsigned int flags, colorsettings settings) {
    processing.colorMode = mode;
}
int red(color_t color) {
    return color.red;
}
int green(color_t color) {
    return color.green;
}
int blue(color_t color) {
    return color.blue;
}
int alpha(color_t color) {
    return color.alpha;
}
//TODO: Create this...
int hue(color_t color) {
    return 0;
}
int saturation(color_t color) {
    return 0;
}
int brightness(color_t color) {
    return 0;
}
