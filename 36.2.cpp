#include <iostream>
#include <cmath>
#include <complex>


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Using: " << argv[0] << " <precision> <limit>" << std::endl;
        return 1;
    }
    std::complex<double> a(-0.5,-0.5);
    std::complex<double> b(-0.5,-0.5);
    std::complex<double> z1(1.0,1.0);
    std::complex<double> z2(1.0,1.0);
    std::complex<double> x3(3.0,0.0);
    std::complex<double> x8(8.0,0.0);
    std::complex<double> x2(2.0,0.0);
    std::complex<double> x5(5.0,0.0);
    std::complex<double> x12(12.0,0.0);
    std::complex<double> x16(16.0,0.0);
    std::complex<double> x7(7.0,0.0);
    unsigned long counter = 0;
    unsigned long limit = strtol(argv[2],nullptr,10);
    double eps = strtod(argv[1], nullptr);
    while (abs(z1) > eps && counter < limit) {
        a = b;
        z1 = pow(a, 5) - x3 * pow(a, 4) + x8 * pow(a, 2) + x2 * a - x7;
        z2 = x5 * pow(a, 4) - x12 * pow(a, 3) + x16 * a + x2;
        b= a - z1 / z2;
        counter++;
    }
    std::cout << b << std::endl;
    return 0;
}
