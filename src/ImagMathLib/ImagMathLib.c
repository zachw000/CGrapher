#include "../../lib/ImagMathLib/ImagMathLib.h"

ComplexNum construct_pair(double real_comp, double imag_comp) {
    ComplexNum cn;
    cn.real_part = real_comp;
    cn.imag_part = imag_comp;

    return cn;
}

vec3 construct_tri(size_t components) {
    vec3 tp;
    double compliment[3] = {0.0, 0.0, 0.0};
    const size_t comp_size = sizeof(components);
    if (sizeof(components) == sizeof(compliment)) {
        compliment[0] = components >> (comp_size / 3);
        components >>= comp_size / 3;
        compliment[1] = components >> (comp_size / 3);
        components >>= comp_size / 3;
        compliment[2] = components >> (comp_size / 3);
        components >>= comp_size / 3;
    } else {
        compliment[0] = 0.0;
        compliment[1] = 0.0;
        compliment[2] = 0.0;
    }

    // assign the variables;
    tp.real_part = compliment[0];
    tp.imag_part = compliment[1];
    tp.z_coord = compliment[2];

    return tp;
}

/**
 * Returns scalar value of the dot product
 */
double dot_product(ComplexNum *a, ComplexNum *b)
{
	return (a->real_part * b->real_part) + (a->imag_part * b->imag_part);
}

double sqr(double inp) { 
    return inp * inp; 
}

void normalize_vec(ComplexNum *a)
{
    double magnitude = vec_magnitude(a);
    a->real_part /= magnitude;
    a->imag_part /= magnitude;
}

ComplexNum normal_vec(ComplexNum *a)
{
    ComplexNum norm_vec;
    norm_vec.real_part = a->real_part;
    norm_vec.imag_part = a->imag_part;
    
    double magnitude = vec_magnitude(a);
    norm_vec.real_part /= magnitude;
    norm_vec.imag_part /= magnitude;

    return norm_vec;
}

vec3 cross_product(vec3 *a, vec3 *b) {
    // TODO: Implement cross product
    // assumes union value of z_coord

    return *a;
}

double two_dim_cross_product(ComplexNum *a, ComplexNum *b) {
    // warning 2D cross product may not work as expected, since there is not always
    // an orthoganal vector in 2D space, returns a scalar value based on position
    // and orientation of the two vectors in 2D, as 2D cross product will always
    // produce a scalar value.
    double cp;
    cp = (a->real_part * b->imag_part) - (a->imag_part * b->real_part);
    return cp;
}

double vec_magnitude(ComplexNum *a) {
    return sqrt(sqr(a->real_part) + sqr(a->imag_part));
}

double vec_angle(ComplexNum *a) {
    double opp = a->imag_part;
    double adj = a->real_part;
    double result = atan2(opp, adj);
    // returns value between 0 and 2pi
    return result > 0 ? result : (2 * PI) + result;
}

double vec_angle_deg(ComplexNum *a) {
    return (180.0 / PI) * vec_angle(a);
}

ComplexNum vec_add(ComplexNum *a, ComplexNum *b) {
    ComplexNum n_vec;
    n_vec.real_part = a->real_part + b->real_part;
    n_vec.imag_part = a->imag_part + b->imag_part;

    return n_vec;
}

ComplexNum vec_sub(ComplexNum *a, ComplexNum *b) {
    ComplexNum n_vec;
    n_vec.real_part = a->real_part - b->real_part;
    n_vec.imag_part = a->imag_part - b->imag_part;

    return n_vec;
}

ComplexNum complex_mult(ComplexNum *a, ComplexNum *b) {
    double a2 = a->real_part;
    double b2 = a->imag_part;
    double c2 = b->real_part;
    double d2 = b->imag_part;
    double real = (a2 * c2) - (b2 * d2);
    double imag = (a2 * d2) + (c2 * b2);

    ComplexNum n_vec;
    n_vec.real_part = real;
    n_vec.imag_part = imag;

    return n_vec;
}

ComplexNum euler_exp(ComplexNum *a, ComplexNum *b) {
    // Gets magnitude of base vector
    // i(a+ib)(c+id)=(ai-b)(c+id)=vec_mult
    /*double r = log(vec_magnitude(a));
    double c = b->real_part;
    double d = b->imag-part;
    ComplexNum imag_comp = vec_mult(construct_pair(a->imag_part * -1, a->real_part), construct_pair(b->real_part, b->imag_part));
    ComplexNum power = construct_pair(r * c + imag_comp.real_part, r * d + imag_comp.imag_part);
    return construct_pair(exp(power.real_part) * (cos(power.imag_part)), exp(power.real_part) * (sin(power.imag_part)));*/
}

void complex_stack_mult(ComplexNum *a, ComplexNum *b) {
    ComplexNum res = complex_mult(a, b);
    a->real_part = res.real_part;
    a->imag_part = res.imag_part;
}

void vec_stack_add(ComplexNum *a, ComplexNum *b) {
    ComplexNum res = vec_add(a, b);
    a->real_part = res.real_part;
    a->imag_part = res.imag_part;
}

void vec_stack_abs(ComplexNum *a) {
    a->real_part = abs(a->real_part);
    a->imag_part = abs(a->imag_part);
}