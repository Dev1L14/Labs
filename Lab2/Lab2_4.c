#include <stdio.h>
#include <math.h>
#include <stdarg.h>

double pow_(double number, int power)
{
    if (power == 0)
        return 1;
    else if (power == 1)
        return number;
    else if (power > 1)
        if (power % 2 == 0)
            return pow_(number * number, power / 2);
        else
            return pow_(number * number, power / 2) * number;
    else
        return 1.0 / pow_(number, power * (-1));
}

double avg_geom(int count, ...)
{
    double res = 1.0;
    va_list iter;
    va_start(iter, count);

    for (int i = 0; i < count; i++) {
        res *= va_arg(iter, double);
    }

    va_end(iter);

    if (count % 2 == 0 && res < 0.0)
        return NAN;
    return pow(res, 1.0 / count);
}

int main()
{
    double res = avg_geom(5, (double)-6.0, (double)7.0, (double)8.0, (double)9.0, (double)5.0) ;
    if (isnan(res))
        printf("Error!\n");
    else
        printf("Average geometric: %f\n", res);
    printf("Exponentiation: %f\n", pow_(2, 10));
    return 0;
}
