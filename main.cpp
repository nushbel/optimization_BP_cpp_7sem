#include <iostream>
#include "Function.h"
#include "stopCrit.h"
#include "area.h"
#include "gradientDescent.h"
#include "randomSearch.h"

int main() {
    std::cout << "Choose function from list" << std::endl;
    std::cout << "1. f(x, y) = x^2 + y^2" << std::endl;
    std::cout << "2. f(x, y) = y^2 + cos(x + y)" << std::endl;
    std::cout << "3. f(x, y, z) = x^2 + y^2 + z^2" << std::endl;
    std::cout << "Type function number" << std::endl;
    int funcNum;
    std::cin >> funcNum;
    Function *f;
    int areaNum;
    int dim = 0;
    std::vector<double> left = {0};
    std::vector<double> right = {0};

    std::vector<double> z = {0};

    area a(left, right);
    switch (funcNum) {
        case 1:
        {
            f = new Function1();
            dim = 2;
            std::cout << "Choose area from list" << std::endl;
            std::cout << "1. x \in (-10, 10), y \in (-10, 10)" << std::endl;
            std::cout << "Type area number" << std::endl;
            std::cin >> areaNum;
            switch (areaNum) {
                case 1:
                {
                    left = {-10, -10};
                    right = {10, 10};
                    a.left = left;
                    a.right = right;
                    z = {6, 7};
                    break;
                }
            }
            break;

        }
        case 2:
        {
            f = new Function2();
            dim = 2;
            std::cout << "Choose area from list" << std::endl;
            std::cout << "1. x \in (1, 6), y \in (-2, 2)" << std::endl;
            std::cout << "Type area number" << std::endl;
            std::cin >> areaNum;
            switch (areaNum) {
                case 1:
                {
                    left = {1, -2};
                    right = {6, 2};
                    a.left = left;
                    a.right = right;
                    z = {4, 1.5};
                    break;
                }
            }
            break;
        }
        case 3:
        {
            f = new Function3();
            dim = 3;
            std::cout << "Choose area from list" << std::endl;
            std::cout << "1. x \in (-10, 10), y \in (-10, 10), z \in (-10, 10)" << std::endl;
            std::cout << "Type area number" << std::endl;
            std::cin >> areaNum;
            switch (areaNum) {
                case 1:
                {
                    left = {-10, -10, -10};
                    right = {10, 10, 10};
                    a.left = left;
                    a.right = right;
                    z = {5, 5, 5};
                    break;
                }
            }
            break;
        }
    }

    stopCrit* stop = new stopCritEpsilon(f);
    optimizationMethod* opt;
    std::cout << "Choose optimization method" << std::endl;
    std::cout << "1. Gradient descent" << std::endl;
    std::cout << "2. Random search" << std::endl;
    int methodNum;
    std::cout << "Type method number" << std::endl;
    std::cin >> methodNum;
    switch (methodNum) {
        case 1:
        {
            opt = new gradientDescent(&a, stop, f);
            break;
        }
        case 2:
        {
            opt = new randomSearch(&a, stop, f);
            break;
        }
    }


    std::cout << "-----Result-----" << std::endl;
    int iterNum = 0;
    std::vector<double> result = opt->argMin(z, iterNum);
    std::cout << "number of iteration: " << iterNum << std::endl;
    std::cout << "arg min f(x): (";

    for (int i = 0; i < dim; ++i) {
        std::cout << (result[i]) << " ";
    }
    std::cout  << ")" << std::endl;

    double fInArgMin = f->eval(result);
    std::cout  << "f(x) in arg min f(x): " << fInArgMin << std::endl;

    return 0;
}
