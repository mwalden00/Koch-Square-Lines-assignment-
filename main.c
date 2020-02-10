#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void koch(int x0, int y0, int x1, int y1, screen s, color c,int i);

int main() {

  /*screen s;
  color c;

  c.red = 255;
  c.green = 255;
  c.blue = 255;
  clear_screen(s);

  koch(0,YRES/2,XRES/2,YRES-1,s,c,1);
  koch(XRES/2,YRES-1,XRES-1,YRES/2,s,c,2);
  koch(XRES-1,YRES/2,XRES/2,0,s,c,3);
  koch(XRES/2,0,0,YRES/2,s,c,4);

  display(s);
  save_extension(s, "lines.png");
  save_ppm(s, "binary.ppm");
  save_ppm_ascii(s, "ascii.ppm");*/

  screen s;
  color c;

  c.red = 0;
  c.green = 255;
  c.blue = 0;

  clear_screen(s);
  //octants 1 and 5
  draw_line(0, 0, XRES-1, YRES-1, s, c);
  draw_line(0, 0, XRES-1, YRES / 2, s, c);
  draw_line(XRES-1, YRES-1, 0, YRES / 2, s, c);

  //octants 8 and 4
  c.blue = 255;
  draw_line(0, YRES-1, XRES-1, 0, s, c);
  draw_line(0, YRES-1, XRES-1, YRES/2, s, c);
  draw_line(XRES-1, 0, 0, YRES/2, s, c);

  //octants 2 and 6
  c.red = 255;
  c.green = 0;
  c.blue = 0;
  draw_line(0, 0, XRES/2, YRES-1, s, c);
  draw_line(XRES-1, YRES-1, XRES/2, 0, s, c);

  //octants 7 and 3
  c.blue = 255;
  draw_line(0, YRES-1, XRES/2, 0, s, c);
  draw_line(XRES-1, 0, XRES/2, YRES-1, s, c);

  //horizontal and vertical
  c.blue = 0;
  c.green = 255;
  draw_line(0, YRES/2, XRES-1, YRES/2, s, c);
  draw_line(XRES/2, 0, XRES/2, YRES-1, s, c);

  display(s);
  save_extension(s, "lines.png");
  save_ppm(s, "binary.ppm");
  save_ppm_ascii(s, "ascii.ppm");
}

void koch(int x0, int y0, int x1, int y1, screen s, color c,int i) {
  float theta = M_PI/3;
  int x2 = (2*x0 + x1)/3;
  int y2 = (2*y0 + y1)/3;
  int x3 = (x0 + 2*x1)/3;
  int y3 = (y0 + 2*y1)/3;
  int x4 = x2 + (x3-x2)*cos(theta) + (y3-y2)*sin(theta);
  int y4 = y2 - (x3-x2)*sin(theta) + (y3-y2)*sin(theta);
  if (i > 0) {
    koch(x0,y0,x2,y2,s,c,i - 1);
    koch(x2,y2,x4,y4,s,c,i - 1);
    koch(x4,y4,x3,y3,s,c,i - 1);
    koch(x3,y3,x1,y1,s,c,i - 1);
  } else {
    draw_line(x0,y0,x2,y2,s,c);
    draw_line(x2,y2,x4,y4,s,c);
    draw_line(x4,y4,x1,y1,s,c);
  }
}
