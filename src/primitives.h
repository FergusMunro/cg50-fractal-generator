#pragma once

typedef struct {
  unsigned short x;
  unsigned short y;
} point;

void plot(point p, unsigned short color);
void drawLine(point p1, point p2, unsigned short color);
