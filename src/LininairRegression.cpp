#include "LineairRegression.h"

// bereken het gemiddelde van een array van integers, count = lengte array.
float LineairRegression::mean(int* values, int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += values[i];
    }
    return sum / 10;
}

/*
 *  Functie die lineaire regressie zal toepassen op de 2 data arrays xval en yval.
 *  De functie geeft de rico terug als een float. Count is het aantal elementen in de arrays.
 */
float LineairRegression::get_rico(int* xval, int* yval, int count) {
    float xgem = mean(xval, count);
    float ygem = mean(yval, count);

    float upper_sum = 0;
    float lower_sum = 0;
    for (int i = 0; i < count; i++) {
        upper_sum += (xval[i] - xgem) * (yval[i] - ygem);
        lower_sum += (xval[i] - xgem) * (xval[i] - xgem);
    }

    float b = upper_sum/lower_sum;
    float a = ygem - (b * xgem);

    printf("%fX + %f\n", b, a);
    return b;
}