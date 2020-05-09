#include <iostream>
#include <iomanip>
#include <cerrno>


double factorial(int n) {
    double res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}


int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Using:\n" << argv[0] << " N h x0\nN - кол-во узлов\nh - шаг" << std::endl;
        return 1;
    }
    unsigned int n;
    double h, x0, x;
    n = strtol(argv[1], nullptr, 10);
    h = strtod(argv[2], nullptr);
    x0 = strtod(argv[3], nullptr);
    if (n == 0 || h == 0) {
        std::cout << "RTFM!" << std::endl;
        return 1;
    }
    if (x0 == 0 && argv[3][0] != '0') {
        std::cerr << "Invalid x0!" << std::endl;
    }
    if (errno == ERANGE) {
        std::cout << "Too big value" << std::endl;
        return 1;
    }
    auto y = new double [n];
    std::cout << "Now enter y values" << std::endl;
    for (unsigned int i = 0; i < n; i++) {
        std::cin >> y[i];
    }
    auto d = new double* [n];
    for (unsigned int i = 0; i < n; i++) {
        d[i] = new double [n];
    }
    double q0, q;
    for (unsigned int i = 0; i < n - 1; i++) {
        d[i][0] = y[i + 1] - y[i];
    }
    int k = 2;
    std::cout << "I'm ok!" << std::endl;
    for (unsigned int i = 1; i < n; i++) {
        for (unsigned int j = 0; j < n - k; j++) {
            d[j][i] = d[j + 1][i - 1] - d[j][i - 1];
        }
        k++;
    }
    std::cout << "Enter argument" << std::endl;
    std::cin >> x;
    q0 = (x - x0)/h;
    q = q0;
    double result = y[0] + d[0][0] * q0;
    k = 2;
    for (unsigned int i = 1; i < n - 1; i++) {
        q *= (q0 - i);
        result += (d[0][i] * q) / factorial(k);
        k++;
    }
    std::cout << std::setprecision(10);
    std::cout << result << std::endl;
    return 0;
}
