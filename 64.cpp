#include <iostream>
#include <vector>
#include <complex>
#include <cmath>


std::complex<double> operator!(std::complex<double> x) {
    return { x.real(), -x.imag() };
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Using:\n" << argv[0] << " N" << std::endl;
        return 1;
    }
    long n = strtol(argv[1], nullptr, 10);
    if (n <= 0) {
        std::cout << "Invalid N";
    }
    std::vector<std::vector<std::complex<double>>> result;
    for (int i = 0; i < n; i++) {
        std::vector<std::complex<double>> t;
        for (int j = 0; j < n; j++) {
            std::complex<double> c(0, 1);
            t.push_back(exp(c * (-2 * M_PI * i * j / (double)n))/sqrt((double)n));
        }
        result.push_back(t);
    }
    for (auto& a : result) {
        for (auto& b : a) {
            std::cout << b << ' ' << std::flush;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::complex<double> t;
            for (int r = 0; r < n; r++) {
                t += result[i][r] * !result[j][r];
            }
            std::cout << t << ' ' << std::flush;
        }
        std::cout << std::endl;
    }

    return 0;
}