#pragma once

#include <cstdio>

class LineairRegression {
    private:
        float mean(int* values, int count);
    public:
        float get_rico(int* xval, int* yval, int count);
};