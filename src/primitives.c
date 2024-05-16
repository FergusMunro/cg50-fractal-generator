#include "primitives.h"
#include <fxcg/display.h>

void plot(point p, unsigned short color) {
  unsigned short *s = (unsigned short *)GetVRAMAddress();
  s += (p.y * 384) + p.x;
  *s = color;
}

void drawLine(point p1, point p2, unsigned short color) {
  signed char ix;
  signed char iy;

  // if p1.x == p2.x or p1.y == p2.y, then it does not matter what we set here
  int delta_x = (p2.x > p1.x ? (ix = 1, p2.x - p1.x) : (ix = -1, p1.x - p2.x))
                << 1;
  int delta_y = (p2.y > p1.y ? (iy = 1, p2.y - p1.y) : (iy = -1, p1.y - p2.y))
                << 1;

  plot(p1, color);
  if (delta_x >= delta_y) {
    int error = delta_y - (delta_x >> 1); // error may go below zero
    while (p1.x != p2.x) {
      if (error >= 0) {
        if (error || (ix > 0)) {
          p1.y += iy;
          error -= delta_x;
        } // else do nothing
      }   // else do nothing
      p1.x += ix;
      error += delta_y;
      plot(p1, color);
    }
  } else {
    int error = delta_x - (delta_y >> 1); // error may go below zero
    while (p1.y != p2.y) {
      if (error >= 0) {
        if (error || (iy > 0)) {
          p1.x += ix;
          error -= delta_y;
        } // else do nothing
      }   // else do nothing
      p1.y += iy;
      error += delta_x;
      plot(p1, color);
    }
  }
}
