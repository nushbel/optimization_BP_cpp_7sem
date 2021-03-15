
#include "gradientDescent.h"
#include <iostream>

std::vector<double> gradientDescent::argMin(std::vector<double> x, int& iterNum)
{
    int n = x.size();
    std::vector<double> xNext = x;
    for (int i = 0; i < n; ++i)
    {
        xNext[i] = x[i] - alpha * f->calculateGradient(x)[i];
    }
    while (!(stop->stopCheck(x, xNext)) && iterNum < 10000)
    {
        //alpha /= 2;
        x = xNext;
        for (int i = 0; i < n; ++i)
        {
            xNext[i] = x[i] - alpha * f->calculateGradient(x)[i];
        }
        ++iterNum;
    }
    return x;
}