# Pulu Linear Regression

In this repository you will find the library that calculates the slope of an array.
We use this library to calculate the slope of the battery level of the pulu project.

## Usage

This library has one method. This method is called get_rico().
To use this method you can just give an array with it and his length.
An example of the usage can be found below:

```C++
bool err;
int y[] = {1, 1, 1, 1, 1, 1, 1};
float slope = LineairRegression::get_rico(y,sizeof(y)/sizeof(y[0]),&err);
```

Your result will be in the variable slope.
