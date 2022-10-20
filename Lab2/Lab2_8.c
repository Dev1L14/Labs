#include <stdio.h>
#include <math.h>
#define EPSILON 0.0000000001

double f(double x) {
    return x*x - 5 * (sin(x));
}

double dichotomy(double a, double b){
    if((b-a)<EPSILON){
        a = a + b;
        b = a - b;
        a = a-b;
    }
    double c = 0.0;
    do{
        c = (a + b) / 2.0;
        if(f(c) * f(a) < EPSILON) b = c;
        else a = c;
    }
    while(fabs(a-b) >= EPSILON);
    return c;
}

int main() {
    printf("\nX: %lf\n", dichotomy((double)2.0, (double)10.0));
}