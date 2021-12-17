#pragma once

#include "stdint.h"

class LineairRegression {
    public:
        static float get_slope(uint8_t* yval, int count, bool* error = nullptr);
};