#include "turtle.h"
#include "primitives.h"

void forward(turtle *t, int distance) {
  point original = t->position;

  t->position.x += (int)(sin(t->angle) * distance);
  t->position.y += (int)(cos(t->angle) * distance);

  drawLine(original, t->position, t->color);
}

void go(turtle *t, int distance) {

  t->position.x += (int)(sin(t->angle) * distance);
  t->position.y += (int)(cos(t->angle) * distance);
}

void turn(turtle *t, double angle) { t->angle += angle; }

void push(turtle *t) { useStack(t, 0); }

turtle pop() {
  turtle t;
  return useStack(&t, 1);
}

turtle useStack(turtle *t, unsigned short x) {
  static turtle stack[100];
  static int pointer = -1;

  if (x == 0) {
    pointer++;
    stack[pointer] = *t;
    return *t;
  } else {
    return stack[pointer--];
  }
}
