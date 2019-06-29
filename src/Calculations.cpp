#include <math.h>
#include "../include/Calculations.hpp"

unsigned Calculations::factorial(unsigned n) {
    if (n == 0)
        return (0);
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

float Calculations::get_binomial_coeff(int total_dices, int identical_obj) {
    float result = factorial(total_dices);

    if (total_dices == identical_obj)
        return (1);
    float b = (factorial(identical_obj) * (factorial(total_dices - identical_obj)));
    return (result / b);
}

float Calculations::get_binomial_proba(int total_dices, int identical_obj) {
    float result = pow(5 , (total_dices - identical_obj));

    if (total_dices == identical_obj)
        return (1);
    float a = factorial(total_dices);
    float b = (factorial(identical_obj) * (factorial(total_dices - identical_obj)));
    return (result * (a / b));
}
