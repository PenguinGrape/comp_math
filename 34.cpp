#include <iostream>
#include <cmath>


double f (double x) {
    return 0.5 * pow(x,2) + 5 * cos(2 * x) - 2;
    /*
     * 2*log(x)-cos(x)
     * 2*pow(x,3)-5*pow(x,2)-1
     * 2*pow(sin(2*x),3)-cos(x)
     * pow(x,5)-3*pow(x,4)+8*pow(x,2)+2*x-7
     */
}


double df (double x) {
    return x + 10 * sin(2 * x);
}


double d2f (double x) {
    return 1 - 20 * cos(2 * x);
}


int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cout << "Using:\n" << argv[0] << " <left limit> <right limit> <precision> <iteration limit>" << std::endl;
        return 1;
    }
    double a = strtod(argv[1],nullptr);
    double b = strtod(argv[2],nullptr);
    double eps = strtod(argv[3],nullptr);
    unsigned long limit = strtol(argv[4], nullptr, 10);
    unsigned long counter = 0;
    double x0, xn;
    if (f(a) * f(b) > 0) {
        std::cerr << "There is no roots!" << std::endl;
        return 1;
    }
    if (f(a) * d2f(a) > 0) {
        x0 = a;
    } else {
        x0 = b;
    }
    xn = x0 - f(x0) / df(x0);
    while (fabs(x0 - xn) > eps && counter < limit) {
        x0 = xn;
        xn = x0 - f(x0) / df(x0);
        counter++;
    }
    std::cout << xn << std::endl;
    return 0;
}