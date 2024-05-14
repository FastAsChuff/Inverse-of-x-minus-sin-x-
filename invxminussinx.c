#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// gcc invxminussinx.c -o invxminussinx.bin -O3 -march=native -Wall -lm

// Inspired by https://math.stackexchange.com/questions/4915679/area-of-the-wet-part-of-a-horizontal-cylinder/4915774#4915774

double xminussinx(double x) {
  return x - sin(x);
} 

double invxminussinx(double y)  {
 // Naive 'Binary Chop' implementation.
 // y = x - sin(x)
 // return x
  double range = 1;
  double left, middle, right;
  left = y-range;
  middle = y;
  right = y+range;
  double middleval = xminussinx(middle);
  int i;
  for (i=0; i<50; i++) {
    if (middleval > y) {
      right = middle;
      middle = (left + right)/2.0f;
      middleval = xminussinx(middle);
    } else {
      left = middle;
      middle = (left + right)/2.0f;
      middleval = xminussinx(middle);
    }
  }
  return middle;
}

int main(int argc, char* argv[])  {
  if (argc < 2) {
    printf("For a real numeric argument y the program displays x such that x - sin(x) = y.\n");
    printf("Usage:- %s y\n", argv[0]);
    exit(0);
  }
  double input = atof(argv[1]);
  double output;
  output = invxminussinx(input);
  printf("%.15lf - sin(%.15lf) = %.15lf  \n", output, output, xminussinx(output));
}
