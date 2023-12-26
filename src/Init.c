#include "../lib/Init.h"

void MandelbrotMath(ComplexNum *map, int iter, ComplexNum origin) {
    double vmag = vec_magnitude(map);
    //printf("ITER IS: %d INP IS:%.2f+%.2fi MAGNITUDE IS: %.2f\n", iter, map->real_part, map->imag_part, vmag);
    // Diverges to infinity, does not belong in set
    //if (vmag > 2.25) return;
    // Will converge to zero, will always be in set
    //if (vmag < 1) return;
    if (iter > 0) {
        complex_stack_mult(map, map);
        vec_stack_add(map, &origin);
        iter--;
        MandelbrotMath(map, iter, origin);
    }

    return;
}

void print_map(int m_width, int m_height, ComplexNum map[m_width][m_height]) {
    double scale = 1.0;
    for (int i = 0; i < m_width; i++) {
        for (int k = 0; k < m_height; k++) {
            double vmag = sqr(map[i][k].real_part) + sqr(map[i][k].imag_part);
            /*if (vmag <= 1.0 * scale) {
                printf("\u2588");
            } else if (vmag <= 4 * scale) {
                printf("\u2593");
            } else if (vmag <= 9 * scale) {
                printf("\u2592");
            } else if (vmag <= 16 * scale) {
                printf("\u2591");
            } else if (vmag <= 25 * scale) {
                printf("\u2592");
            } else if (vmag <= 36 * scale) {
                printf("\u2593");
            } else if (vmag <= 49 * scale) {
                printf("\u2592");
            } else if (vmag <= 64 * scale) {
                printf("\u2591");
            } else {
                printf(" ");
            }*/
            if (vmag <= 1.0 * scale) {
                printf("-");
            } else if (vmag <= 4 * scale) {
                printf("+");
            } else if (vmag <= 9 * scale) {
                printf("o");
            } else if (vmag <= 16 * scale) {
                printf("=");
            } else if (vmag <= 25 * scale) {
                printf("&");
            } else if (vmag <= 36 * scale) {
                printf("%%");
            } else if (vmag <= 49 * scale) {
                printf("@");
            } else if (vmag <= 64 * scale) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void MandelbrotTest() {

    // SPIRALS -0.826153702+0.195033632i to -0.807450724+0.2900273i
    int m_width = 100;
    int m_height = 200;
    int iterations = 13;
    double x_scale = 4.0;
    double y_scale = 4.0;
    ComplexNum map[m_width][m_height];
    for (int i = 0; i < m_width; i++) {
        for (int k = 0; k < m_height; k++) {
            map[i][k] = construct_pair(((double)k / (double)m_height) * x_scale - (x_scale / 2), ((double)(m_width - i) / (double)m_width * y_scale - (y_scale / 2)));
        }
    }
    for (int i = 0; i < m_width; i++) {
        for (int k = 0; k < m_height; k++) {
            // creates copy of original so that it may be added back to the squared vector.
            ComplexNum origin = construct_pair(map[i][k].real_part, map[i][k].imag_part);
            MandelbrotMath(&map[i][k], iterations, origin);
        }
    }
    /*
    for (int i = 0; i < m_width; i++) {
        for (int k = 0; k < m_height; k++) {
            printf("%.4f%c%.4fi ",map[i][k].real_part,map[i][k].imag_part >= 0 ? '+' : '-',map[i][k].imag_part);
        }
        printf("\n");
    }
    */
    print_map(m_width, m_height, map);
    printf("\n");
}

void generate_viewport(int m_width, int m_height, ComplexNum *map[m_width][m_height]) {
    // TODO: Implement grid generation with array dimensions of map[m_width][m_height] and
    // store the map in the memory address of the map argument
}

void MandelbrotTest2(double x, double z) {

    // SPIRALS -0.826153702+0.195033632i to -0.807450724+0.2900273i
    int m_width = 100;
    int m_height = 200;
    int iterations = 45;
    
    // Inverse proportional scaling
    double x_scale = 4.0;
    double y_scale = 4.0;

    ComplexNum map[m_width][m_height];

    for (int i = 0; i < m_width; i++) {
        for (int k = 0; k < m_height; k++) {
            map[i][k] = construct_pair(((double)k / (double)m_height) * x_scale - (x_scale / 2), ((double)(m_width - i) / (double)m_width * y_scale - (y_scale / 2)));
        }
    }

    for (int i = 0; i < m_width; i++) {
        for (int k = 0; k < m_height; k++) {
            // creates copy of original so that it may be added back to the squared vector.
            ComplexNum origin = construct_pair(x, z);
            MandelbrotMath(&map[i][k], iterations, origin);
        }
    }
    print_map(m_width, m_height, map);
    printf("\n");
}

int main(int argc, char ** argv)
{
    //printf("Program Successfully Compiled!\nTest 2!\n");
    if (argc == 3) {
        int n = 1;
        int k = 0;
        double tot[] = {0, 0};
        int mult = 1;
        int c_char;
        bool use_ten;
        int ten_pow;
        // Iterate through each passed argument, check for validity
        do
        {
            mult = 1;
            ten_pow = 0;
            use_ten = false;
            while (k < strlen(argv[n])) {
                c_char = (int)argv[n][k];
                //printf("Current Char: %c\tK is: %d\n", argv[n][k], k);
                // if the first char of the argument is '-' negate total value
                if (k == 0 && c_char == '-') {
                    mult = -1;
                    k++;
                    continue;
                }
                if (use_ten) ten_pow--;
                // check if input is between 0-9
                if (c_char == '.' && k != 0 && !use_ten) {
                    use_ten = true;
                } else if (c_char - 48 < 0 || c_char - 48 > 9) {
                    fprintf(stderr, "Invalid input, please enter numbers!\n");
                    return -1;
                } else {
                    tot[n - 1] *= 10;
                    tot[n - 1] += (int)c_char - 48;
                }
                k++;
            }
            tot[n - 1] *= mult;
            tot[n - 1] *= pow(10.0, (double)ten_pow);
            k = 0;
            n++;
        } while (n < argc);

        //printf("TOTALS ARE: %d+%di\n", tot[0], tot[1]);

        ComplexNum cn = construct_pair((double)tot[0], (double)tot[1]);

        // Test data input
        printf("Complex number is: %.2f+%.2fi\n", cn.real_part, cn.imag_part);

        // Test Magnitude
        printf("Vector Magnitude: %.4f\n", vec_magnitude(&cn));

        // Normalize Vector
        ComplexNum vnorm = normal_vec(&cn);
        printf("Vector normal: %.2f+%.2fi\n", vnorm.real_part, vnorm.imag_part);

        // Test Angle Calculation
        //printf("Complex number is: %.2f+%.2fi\n", cn.real_part, cn.imag_part);
        printf("Vector angle (Rad): %.4f / %.3fPI\n", vec_angle(&cn), vec_angle(&cn) / PI);
        printf("Vector angle (Deg): %.4f\n\n", vec_angle_deg(&cn));

        // Test Complex Mult
        ComplexNum cn_squared;
        cn_squared = complex_mult(&cn, &cn);
        printf("Complex number is sq: %.2f+%.2fi\n", cn_squared.real_part, cn_squared.imag_part);

        // Test Magnitude
        printf("Vector Magnitude sq: %.4f\n", vec_magnitude(&cn_squared));

        // Test Angle Calculation
        printf("Vector angle (Rad) sq: %.4f / %.3fPI\n", vec_angle(&cn_squared), vec_angle(&cn_squared) / PI);
        printf("Vector angle (Deg) sq: %.4f\n", vec_angle_deg(&cn_squared));

        // Normalize Vector
        normalize_vec(&cn_squared);
        printf("Vector normal sq: %.2f+%.2fi\n", cn_squared.real_part, cn_squared.imag_part);
        MandelbrotTest2(cn.real_part, cn.imag_part);
    } else {
        MandelbrotTest();
    }
    return 0;
}
