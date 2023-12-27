#ifndef     IMAG_MATH_LIB
#define     IMAG_MATH_LIB   1
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define PI  3.14159265358979323846
/**
 * Insert struct definitions/functions
*/
typedef struct ComplexNum
{
    double real_part;
    double imag_part;
} ComplexNum;

ComplexNum construct_pair(double real_comp, double imag_comp);

/**
 * Finds the dot product of 2 vectors
 * ------------------------------------
 * Arguments 2 equal-length vectors POINTERS, length L
 * 
 * FORMULA SUM(A1*B1+A2*B2+...+A(N)*B(N))
 * Takes the address of 2 equal length vectors of the same
 * type and multiplies each element of the vector and sums the
 * products together to create a scalar object
*/
double dot_product(struct ComplexNum *a, struct ComplexNum *b);

/**
 * Returns the square of a double
 * -------------------------------------
 * Arguments sqr(double inp)
 * 
 * Takes the input and multiplies it by itself to find it's
 * respective square.
*/
double sqr(double inp);

/**
 * Manipulates Input Vector to Unit Length
 * -------------------------------------------------------
 * 
 * Finds the magnitude of the vector and divides each component
 * by the magnitude to create a new vector of length 1 (unit).
 * The purpose is to find a vector that maintains direction, but
 * is of length one.
*/
void normalize_vec(struct ComplexNum *a);

/**
 * Returns Vector of unit length from a 2D (complex) input
 * -------------------------------------------------------
 * 
 * Finds the magnitude of the vector and divides each component
 * by the magnitude to create a new vector of length 1 (unit).
 * The purpose is to find a vector that maintains direction, but
 * is of length one.
*/
ComplexNum normal_vec(struct ComplexNum *a);

/**
 * Generates the Cross Product for 2 Complex Inputs
 * -------------------------------------------------------
 * 
 * Takes two vectors of type ComplexNumber *a, *b and
 * returns the resulting pointer to the
 * vector of the cross product between the 
 * two vector inputs.
*/
ComplexNum cross_product(struct ComplexNum *a, struct ComplexNum *b);

/**
 * TODO: Implement Euler exponential function
*/
ComplexNum euler_exp(ComplexNum *a, ComplexNum *b);

double vec_magnitude(struct ComplexNum *a);

double vec_angle(struct ComplexNum *a);

double vec_angle_deg(struct ComplexNum *a);

ComplexNum vec_add(struct ComplexNum *a, struct ComplexNum *b);

ComplexNum vec_sub(struct ComplexNum *a, struct ComplexNum *b);

ComplexNum complex_mult(struct ComplexNum *a, struct ComplexNum *b);

void complex_stack_mult(ComplexNum *a, ComplexNum *b);

void vec_stack_add(ComplexNum *a, ComplexNum *b);

void vec_stack_abs(ComplexNum *a);

double two_dim_cross_product(ComplexNum *a, ComplexNum *b);
#endif
