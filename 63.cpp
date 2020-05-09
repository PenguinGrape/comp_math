#include <iostream>
#include <vector>
#include <cmath>
#include <complex>


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Using:\n" << argv[0] << " N" << std::endl;
        return 1;
    }
    long n = strtol(argv[1], nullptr, 10);
    if (n <= 0) {
        std::cout << "Invalid N";
    }
    std::vector<std::complex<double>> base, result;
    std::cout << "Enter complex numbers like this: (r,i)" << std::endl;
    for (int i = 0; i < n; i++) {
        std::complex<double> x;
        std::cin >> x;
        base.push_back(x);
    }
    std::complex<double> coeff(0, 1);
    coeff *= -2 * M_PI / (double)n;
    for (int i = 0; i < n; i++) {
        std::complex<double> t;
        for (int j = 0; j < n; j++) {
            t += base[j] * exp(coeff * (double)(i * j));
        }
        result.push_back(t);
    }
    for (auto& a : result) {
        std::cout << a << std::endl;
    }
    return 0;
}