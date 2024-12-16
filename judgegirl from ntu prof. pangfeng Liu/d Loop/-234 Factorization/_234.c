#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* factor(int c, int *arrsize) {
    int size = (int)sqrt((double)abs(c));
    int maxsize = 300;
    int *arr = malloc(maxsize * sizeof(int));

    if (c == 0) {
        arr[0] = -1;
        *arrsize = 1;
        return arr;
    }

    int count = 0;
    
    for (int i = 1; i <= size; i++) {
        if (c % i == 0) {
            arr[count++] = i;
            arr[count++] = -i;
            if (c != i * i) {
                arr[count++] = c / i;
                arr[count++] = -(c / i);
            }
        }
    }
    *arrsize = count;

    return arr;
}

void reorder(int *d, int *e, int *f) {
    if (*d > *f) {
        int temp = *d;
        *d = *f;
        *f = temp;
    }
    if (*d > *e) {
        int temp = *d;
        *d = *e;
        *e = temp;
    }
    if (*e > *f) {
        int temp = *e;
        *e = *f;
        *f = temp;
    }
}

void quadratic_equation(int a, int b, int *e, int *f, int *found) {
    double discriminant = a * a - 4 * b;

    if (discriminant >= 0) {
        double temp_e = (-a + sqrt(discriminant)) / 2;
        double temp_f = (-a - sqrt(discriminant)) / 2;

        if (fabs(temp_e - (int)round(temp_e)) < 1e-10 &&
            fabs(temp_f - (int)round(temp_f)) < 1e-10   ) {

            //  (x -   e )(x -   f )
            // =(x + (-e))(x + (-f))
                    
            *e = -(int)temp_e;
            *f = -(int)temp_f;

            *found = 1;
        }
    }
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int d = 0, e = 0, f = 0;
    int found = 0;

    //   x^3 + a           x^2 +  b             x + c
    // = x^3 + (d + e + f) x^2 + (de + ef + fd) x + def

    // check if c == 0 , b == 0
    if (c == 0) {
        if (b == 0) {
            // x^2(x + d)
            d = a;
            reorder(&d, &e, &f);
            found = 1;
        } else {
            // x(x + e)(x + f)
            quadratic_equation(a, b, &e, &f, &found);
            if (found == 1) {
                reorder(&d, &e, &f);
            }
        }
    }

    if (!found) {
        int arrsize;
        int *factor_c_arr = factor(c, &arrsize);

        for (int i = 0; i < arrsize && !found; i++) {

            // = (x + d)(x^2 + (a - d)x + (b - ad + d^2))

            d = factor_c_arr[i];
            int temp_a = a - d;
            int temp_b = b - (a * d) + (d * d);

            if (d * temp_b != c) {
                continue;
            } // this step is easy to overlook!!
            
            // = x^2 + (temp_a)x + (temp_b)

            quadratic_equation(temp_a, temp_b, &e, &f, &found);
            
            if (found == 1) {
                break;
            }
        }

        reorder(&d, &e, &f);
        free(factor_c_arr);
    }
   
    printf("%d %d %d\n", d, e, f);
    return 0;
}