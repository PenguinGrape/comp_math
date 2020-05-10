#include <iostream>
#include <cmath>

double f(double x) {
    return 2*pow(x,3)+pow(x,2)-7;
    /*
     * 5*cos(3*x)+0.5*x-2
     * pow(x,5)-2*pow(x,4)+6*pow(x,2)+2*x-4
     * pow(x,3)-0.2*pow(x,2)-0.2*x-1.2
     * log(fabs(pow(x,3))+1)+pow(x,3)-2
     */
}


int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cout << "Using:\n" << argv[0] << " <left limit> <right limit> <precision> <iteration limit>" << std::endl;
        return 1;
    }
    double x;
    double a = strtod(argv[1],nullptr);
    double b = strtod(argv[2],nullptr);
    double e = strtod(argv[3],nullptr);
    unsigned long limit = strtol(argv[4], nullptr, 10);
    unsigned long counter = 0;
    while (fabs(a - b) >= e && counter < limit) {
        if ((f(a) > 0 && f((a + b) / 2) < 0) || (f(a) < 0 && f((a + b) / 2) > 0)) {
            b = (a + b) / 2;
        } else {
            if ((f((a + b) / 2) > 0 && f(b) < 0) || (f((a + b) / 2) < 0 && f(b) > 0)) {
                a = (a + b) / 2;
            } else {
                std::cout << "No roots!" << std::endl;
                return 0;
            }
        }
        counter++;
    }
    x = (a + b) / 2;
    std::cout << "x=" << x << " F(x)=" << f(x) << " |a-b|=" << fabs(a - b) << std::endl;
    return 0;
}