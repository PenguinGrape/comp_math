#include <iostream>
#include <complex>
#include <cmath>


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Using: " << argv[0] << " <precision> <limit>" << std::endl;
        return 1;
    }
    std::complex<double> a(-0.1,0.0);
    std::complex<double> b(0.1,0.0);
    std::complex<double> z1(1,1);
    std::complex<double> z2(1,1);
    std::complex<double> x3(3,0);
    std::complex<double> x04(0.4,0);
    std::complex<double> x02(0.2,0);
    std::complex<double> x12(1.2,0);
    unsigned long counter = 0;
    unsigned long limit = strtol(argv[2],nullptr,10);
    double eps = strtod(argv[1], nullptr);
    while (abs(z1) > eps && counter < limit) {
        a = b;
        z1 = pow(a, 3) - x02 * pow(a, 2) + x02 * a + x12;
        z2 = x3 * pow(a, 2) - x04 * a - x02;
        b = a - z1 / z2;
        counter++;
    }
    std::cout << b << std::endl;
}