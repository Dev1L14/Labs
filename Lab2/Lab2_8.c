#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x - 5 * (sin(x));
}

double dichotomy(double a, double b, int n){
    double EPSILON = pow(10,-n);
    if((b-a)<EPSILON){
        a = a + b;
        b = a - b;
        a = a-b;
    }
    double c = (a + b) / 2.0;
    if(fabs(f(c))<EPSILON){
        return c;
    }
    do{
        if(f(c) * f(a) < EPSILON) b = c;
        else if(f(c) * f(b) < EPSILON) a = c;
        else{
            return NAN;
        }
        c = (a + b) / 2.0;
    }
    while(fabs(a-b) >= EPSILON);
    return c;
}

int main() {
    double result = dichotomy((double)2.0, (double)10.0, 10);
    if(!isnan(result)) printf("\nSolution for x in given interval is %lf\n", result);
    else printf("No solutions in given interval");
}