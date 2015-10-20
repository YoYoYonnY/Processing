#include <stdbool.h>
#include <stdlib.h>

#ifndef __PROCESSING_H__
#define __PROCESSING_H__

typedef unsigned int percentage_t;

typedef struct color_t {
	int red;
	int green;
	int blue;
	int alpha;
} color_t;

typedef enum colormode {
    COLORMODE_RGB
} colormode;
typedef enum blendmode {
    BLENDMODE_NONE
} blendmode;

int width = 384;
int height = 216;

int frameCount = 0;

void    background(color_t color);
void    fill(color_t color);
void    noFill();
void    stroke(color_t color);
void    strokeWeight(size_t thickness);
void    noStroke();

color_t color(int r, int g, int b);
color_t rgba(int r, int g, int b, int a);
color_t hsb(int hue, int saturation, int brightness);
color_t blendColor(color_t color1, color_t color2, blendmode mode);
color_t lerpColor(color_t color1, color_t color2, percentage_t amount);
void    colorMode(
        colormode mode,
        unsigned int flags,
        colorsettings settings);
int     red(color_t color);
int     green(color_t color);
int     blue(color_t color);
int     alpha(color_t color);
int     hue(color_t color);
int     saturation(color_t color);
int     brightness(color_t color);

void    rotate(int angle);
void    scale(int amount);
void    translate(int x, int y);
void    resetMatrix(void);
void    pushMatrix(void);
void    popMatrix(void);

void    text(const char* text, int x, int y);
void    rect(int x, int y, int w, int h);
void    ellipse(int x, int y, int w, int h);
void    triangle(int x1, int y1, int x2, int y2, int x3, int y3);
void    line(int x1, int y1, int x2, int y2);
void    point(int x, int y);
void    arc(int x, int y, int w, int h, int start, int stop);
void    bezier(int x1, int y1, int xc1, int cy1, int xc2, int cy2, int x2, int y2);
void    quad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void    image(image_t image, int x, int y);

void    beginShape(shape_t shape);
void    endShape(shape_t shape);

bool    keypress(key_t key);
bool    keyhold(key_t key);
void    (*draw)(void) = NULL;
void    (*tick)(void) = NULL;
void    (*keypressed)(key_t key) = NULL;
void    (*keyreleased)(key_t key) = NULL;
void    loop(void);
void    noLoop(void);

#endif // __PROCESSING_H__
