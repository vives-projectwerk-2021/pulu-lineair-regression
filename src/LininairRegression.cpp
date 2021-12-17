#include "LineairRegression.h"
#include <cstdint>
#include <algorithm>
#include <cstdio>

/*
 *  Function that will do linear regression on a serie of data.
 *  The function returns the slope as float. Count is the amount of points in the serie.
 *  To give this value to the function you can use the following syntax: count = sizeof(yval)/sizeof(yval[0]).
 */
float LineairRegression::get_slope(uint8_t* yval, int count, bool* error) {
    
    uint8_t max_value = *std::max_element(yval,yval + count);
    if(max_value*max_value > UINT32_MAX/count)
    {
        // ERROR HANDLING
        if(error != nullptr) *error = true;
        return 0;
    }
    else
    {
        uint32_t xsum = 0;
        uint32_t ysum = 0;
        uint32_t xysum = 0;
        uint32_t powxsum = 0;
        for (int i = 0; i < count; i++) {
            xsum += i;
            ysum += yval[i];
            xysum += i*yval[i];
            powxsum += i*i;
        }
        
        int32_t nominator = ((count*xysum) - (xsum * ysum));
        int32_t denominator = ((count*powxsum)-(xsum*xsum));

        if(error != nullptr) *error = false;

        return 1.0*nominator/denominator;
    }
    
}