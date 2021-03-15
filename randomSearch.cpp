

#include "randomSearch.h"
#include <iostream>
std::mt19937 generator;

std::vector<double> randomSearch::argMin(std::vector<double> x, int& iterNum)
{
    std::vector<std::uniform_real_distribution<>> dist;

    for (int i = 0; i < a->left.size(); ++i)
    {
        std::uniform_real_distribution<> dis(a->left[i], a->right[i]);
        dist.push_back(dis);
    }
    int n = x.size();
    std::vector<double> xNext = x;
    for (int i = 0; i < n; ++i)
    {
        xNext[i] = dist[i](generator);
    }
    //std::cout << "xNext = ";
    for (int i = 0; i < n; ++i)
    {
        //std::cout << xNext[i] << " ";
    }


    while (!(stop->stopCheck(x, xNext)) && iterNum < 10000)
    {
        if (f->eval(xNext) > f->eval(x))
        {
            for (int i = 0; i < n; ++i)
            {
                xNext[i] = dist[i](generator);
            }
        } else {
            x = xNext;
            for (int i = 0; i < n; ++i)
            {
                xNext[i] = dist[i](generator);
            }
        }
        ++iterNum;
    }
    return x;
}