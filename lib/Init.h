#ifndef     INIT_HEADER
#define     INIT_HEADER 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Custom Header File Includes
#include "../lib/ImagMathLib/ImagMathLib.h"
#define ORIG_ENAB   0
void print_map(int m_width, int m_height, ComplexNum map[m_width][m_height]);
void MandelbrotMath(ComplexNum *map, int iter, ComplexNum origin);
void MandelbrotTest();
void MandelbrotTest2(double x, double z);
#else
fprintf(stderr, "Another Instance Detected.");
#endif