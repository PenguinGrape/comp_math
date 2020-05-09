#include <iostream>
#include <vector>
#include <complex>
#include <cmath>


std::complex<double> operator!(std::complex<double> x) {
    return { x.real(), -x.imag() };
}


std::vector<std::vector<std::complex<double>>> operator*(std::vector<std::vector<std::complex<double>>> l, std::vector<std::vector<std::complex<double>>> r) {
    if (l[0].size() != r.size()) {
        throw std::exception();
    }
    std::vector<std::vector<std::complex<double>>> result;
    for (int i = 0; i < l.size(); i++) {
        std::vector<std::complex<double>> tt;
        for (int j = 0; j < r[0].size(); j++) {
            std::complex<double> t = 0;
            for (int n = 0; n < l[0].size(); n++) {
                t = t + l[i][n] * r[n][j];
            }
            tt.push_back(t);
        }
        result.push_back(tt);
    }
    return result;
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
    std::vector<std::vector<std::complex<double>>> base;
    std::cout << "Enter complex numbers like this: (r,i)" << std::endl;
    for (int i = 0; i < n; i++) {
        std::complex<double> x;
        std::cin >> x;
        base.push_back(std::vector<std::complex<double>>{ {x}});
    }
    std::vector<std::vector<std::complex<double>>> matrix;
    for (int i = 0; i < n; i++) {
        std::vector<std::complex<double>> t;
        for (int j = 0; j < n; j++) {
            std::complex<double> c(0, 1);
            t.push_back(exp(c * (-2 * M_PI * i * j / (double)n))/sqrt((double)n));
        }
        matrix.push_back(t);
    }
    for (auto& a : matrix * std::vector<std::vector<std::complex<double>>>{base}) {
        for (auto& b : a) {
            std::cout << b << ' ' << std::flush;
        }
        std::cout << std::endl;
    }
    std::vector<std::vector<std::complex<double>>> check;
    for (int i = 0; i < n; i++) {
        std::vector<std::complex<double>> t;
        t.reserve(n);
        for (int j = 0; j < n; j++) {
            t.push_back(!matrix[j][i]);
        }
        check.push_back(t);
    }
    std::cout << std::endl;
    for (auto& a :check * (matrix * std::vector<std::vector<std::complex<double>>>{base})) {
        for (auto& b : a) {
            std::cout << b << ' ' << std::flush;
        }
        std::cout << std::endl;
    }
    return 0;
}