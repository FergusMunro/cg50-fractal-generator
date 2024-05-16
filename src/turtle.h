#pragma once

#include "primitives.h"
#include <math.h>

typedef struct {
  point position;
  double angle;
  unsigned short color;
} turtle;

void forward(turtle *t, int distance);
void go(turtle *t, int distance);
void turn(turtle *t, double angle);

void push(turtle *t);
turtle pop();
turtle useStack(turtle *t, unsigned short x);
