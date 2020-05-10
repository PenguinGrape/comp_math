#include <iostream>
#include <exception>
#include <cmath>


double Iter(double F(double x), double x0, const double eps, const unsigned long limit) {
    double x1;
    unsigned long counter = 0;
    if (F(x0) != x0) {
        while (counter < limit) {
            x1 = F(x0);
            if (fabs(x1 - x0) <= eps) {
                break;
            }
            x0 = x1;
            if ((x1 != 0) && x1 / x1 == 0) {
                std::cerr << "Error: Divergency" << std::endl;
                throw std::exception();
            }
            counter++;
        }
    } else {
        std::cout << "msg: x0 = x" << std::endl;
        x1 = x0;
    }
    return x1;
}


double F1(double x) {
    // cos(x) = 0.1
    return (cos(x) - 0.1 + x);
}


double F2(double x) {
    // x^3 + x = 1000
    // x^3 = 1000 - x
    return (pow((1000 - x), (1.0/3)));
}


double F3(double x) {
    // x^5 - x^4 - x^2 -x - 5 = 0
    // x^4 + x^2 + x + 5 = x^5
    return (pow((pow(x,4) + pow(x,2) + x + 5), (1.0/5)));
}


double F4(double x) {
    //x^3 - x - 1 = 0
    //x^3 = x + 1
    return (pow((x + 1), (1.0 / 3)));
}


double F5(double x) {
    //ln(x) + x = 2.25
    //x = sqrt(2.25x - ln(x)x)
    return (sqrt(2.25*x - log(x)*x));
}


int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Using:\n" << argv[0] << " <start point> <precision> <iteration limit>" << std::endl;
        return 1;
    }
    double x0 = strtod(argv[1], nullptr);
    double eps = strtod(argv[2], nullptr);
    unsigned long limit = strtol(argv[3], nullptr, 10);
    double xF1 = Iter(F1, x0, eps, limit);
    std::cout << "xF1 = " << xF1 << std::endl;
    double xF2 = Iter(F2, x0, eps, limit);
    std::cout << "xF2 = " << xF2 << std::endl;
    double xF3 = Iter(F3, x0, eps, limit);
    std::cout << "xF3 = " << xF3 << std::endl;
    double xF4 = Iter(F4, x0, eps, limit);
    std::cout << "xF4 = " << xF4 << std::endl;
    double xF5 = Iter(F5, 1.5, eps, limit);
    std::cout << "xF5 = " << xF5 << std::endl;
    return 0;
}