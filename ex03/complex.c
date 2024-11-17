#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "complex.h"

typedef struct
{
    double  real;
    double  img;
}complex_t;


//Returns the real part of the complex pointed by c
double get_real(complex_t *c)
{
    return (c->real);
}

//Returns the imaginary part of the complex pointed by c
double get_imaginary(complex_t *c)
{
    return (c->real);
}

//Returns the modulus of the complex pointed by c
//the modulus of the complex a+ib is sqrt(a*a+b*b)
double modulus(complex_t *c)
{
    return (sqrt(c->real * c->real + c->img * c->img));
}

//Returns the argument of the complex pointed by c 
//the argument of the complex a+ib is acos(a/modulus)  ("acos" is the arc cosine function, NOT a*cos!)
double argument(complex_t *c)
{
    return (acos(c->real / modulus(c)));
}

//Returns True if the complex pointed by c1 and the complex pointed by c2 are equals, False otherwise 
bool equals_complex(complex_t *c1, complex_t *c2)
{
    return (c1->real == c2->real && c1->img == c2->img);
}

//Display the complex pointed by c in the following format real +img i
//Examples:
//2.00 +6.00 i
void display_complex(complex_t *c)
{
    printf("%2lf + %2lf i", c->real, c->img);
}

//Fills the complex pointed by new_c with the real part equal to a and imaginary part equal to b
void complex_custom(double a, double b, complex_t *new_c)
{
    *new_c = (complex_t){a, b};
}

//Fills the complex pointed by conjugate  as the conjugate of the complex pointed by c
//The conjugate of a + ib is a − ib.
void conjugate_complex(complex_t *c, complex_t *conjugate)
{
    conjugate->real = c->real;
    conjugate->img = -(c->img);
}

//Computes the complex pointed by res as the sum of the complex pointed by c1 and the complex pointed by c2
// (a+ib) + (c+id) is the complex (a+c)+i(b+d)
void addition_complex(complex_t *c1, complex_t *c2, complex_t *res)
{
    *res = (complex_t){c1->real + c2->real, c1->img + c2->img};
}

//Computes the complex pointed by res as the substraction of the complex pointed by c1 and the complex pointed by c2
//   (a+ib) - (c+id) is the complex (a-c)+i(b-d)
void subtraction_complex(complex_t *c1, complex_t *c2, complex_t *res)
{
    *res = (complex_t){c1->real + c2->real, c1->img - c2->img};
}

//Add the complex pointed by to_be_added to the complex pointed by c 
// Hint: use the addition_complex function to compute c = c + to_be_added
void add_complex(complex_t *c, complex_t *to_be_added)
{
    complex_t   res;

    addition_complex(c, to_be_added, &res);
    *c = res;
}

int main(void) {
    complex_t c1 = (complex_t) {2.0, -6.0};
    printf("%4lf %+4lf i\n",get_real(&(c1)), get_imaginary(&(c1)));
    complex_t c2;
    complex_custom(4.0, 3.0,&(c2)); 
    complex_t c3 = (complex_t) {4.0, 3.0};
    if (!equals_complex(&(c2), &(c3))){
        printf("c2 and c3 are not equal\n");
    }else{
        printf("c2 and c3 are equal\n");
    }
    complex_t c_sum;
    addition_complex(&(c1), &(c2), &(c_sum));
    add_complex(&(c1), &(c2));
    if (!equals_complex(&(c_sum), &(c1))){
        printf("oups\n");
    }

    complex_t c_sub;
    subtraction_complex(&(c1), &(c2), &(c_sub));
    if (!equals_complex(&(c_sub), &(c1))){
        printf("oups\n");
    }
    
    double mod = modulus(&(c1));
    double c_arg = argument(&(c1));
    printf("%lf %lf\n",mod,c_arg);
    complex_t c_conj;
    conjugate_complex(&(c1),&(c_conj));
    display_complex(&(c_conj));
    return EXIT_SUCCESS;
}