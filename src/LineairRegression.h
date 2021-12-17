#pragma once

class LineairRegression {
    public:
        static float get_slope(int* yval, int count, bool* error = nullptr);
};