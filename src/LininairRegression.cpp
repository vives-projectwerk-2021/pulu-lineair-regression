#include "LineairRegression.h"


/*
 *  Functie die lineaire regressie zal toepassen op een reeks data.
 *  De functie geeft de rico terug als een float. Count is het aantal elementen in reeks data.
 *  Om deze waarde mee te geven kunnen je volgende constructie gebruiken: sizeof(yval)/sizeof(yval[1]).
 */
float get_rico(int* yval, int count, bool* error = nullptr) {
    
    int max_value = *std::max_element(yval,yval + count);
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