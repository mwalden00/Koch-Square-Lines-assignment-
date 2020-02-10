#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw_line_1(int x0, int y0, int x1, int y1, screen s, color c);
void draw_line_2(int x0, int y0, int x1, int y1, screen s, color c);
void draw_line_8(int x0, int y0, int x1, int y1, screen s, color c);
void draw_line_7(int x0, int y0, int x1, int y1, screen s, color c);
void draw_line_h(int x0, int x1, int y, screen s, color c);
void draw_line_v(int y0, int y1, int x, screen s, color c);

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if (x0 > x1) {
    draw_line(x1,y1,x0,y0,s,c);
    return;
  }
  if (y1 == y0) draw_line_h(x0,x1,y0,s,c);
  else if (x1 == x0) draw_line_v(y0,y1,x0,s,c);
  else if (y1 > y0){
    if ((y1 - y0) > (x1 - x0)) draw_line_2(x0,y0,x1,y1,s,c);
    else draw_line_1(x0,y0,x1,y1,s,c);
  } else {
    if ((y0-y1) > (x1 - x0)) draw_line_7(x0,y0,x1,y1,s,c);
    else draw_line_8(x0,y0,x1,y1,s,c);
  }
}

void draw_line_1(int x0, int y0, int x1, int y1, screen s, color c) {
  int x,y;
  x = x0;
  y = y0;
  int A,B;
  A = y1 - y;
  B = x - x1;
  int d;
  d = 2*A + B;
  while (x <= x1) {
    plot(s,c,x,y);
    if (d>0){
      y++;
      d+=2*B;
    }
    x++;
    d+=2*A;
  }
} // Octant 1 implementation

void draw_line_2(int x0, int y0, int x1, int y1, screen s, color c) {
  int x,y;
  x = x0;
  y = y0;
  int A,B;
  A = x1 - x;
  B = y - y1;
  int d;
  d = 2*A + B;
  while (y <= y1) {
    plot(s,c,x,y);
    if (d>0){
      x++;
      d+=2*B;
    }
    y++;
    d+=2*A;
  }
} // Octant 2 implementation

void draw_line_8(int x0, int y0, int x1, int y1, screen s, color c) {
  int x,y;
  x = x0;
  y = y0;
  int A,B;
  A = y - y1;
  B = x - x1;
  int d;
  d = 2*A + B;
  while (x <= x1) {
    plot(s,c,x,y);
    if (d>0){
      y--;
      d+=2*B;
    }
    x++;
    d+=2*A;
  }
} // Octant 8 implementation

void draw_line_7(int x0, int y0, int x1, int y1, screen s, color c) {
  int x,y;
  x = x0;
  y = y0;
  int A,B;
  A = x1 - x;
  B = y1 - y;
  int d;
  d = 2*A + B;
  while (y >= y1) {
    plot(s,c,x,y);
    if (d>0){
      x++;
      d+=2*B;
    }
    y--;
    d+=2*A;
  }
}

void draw_line_h(int x0, int x1, int y, screen s, color c) {
  int x;
  x = x0;
  while (x <= x1) {
    plot(s,c,x,y);
    x++;
  }
}

void draw_line_v(int y0, int y1, int x, screen s, color c) {
  int y;
  y = y0;
  while (y <= y1) {
    plot(s,c,x,y);
    y++;
  }
}
