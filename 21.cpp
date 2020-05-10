#include <iostream>


int main() {
    int n, xi;
    std::cout << "Enter max degree" << std::endl;
    std::cin >> n;
    int *inp = new int[n + 1];
    int *result = new int[n + 1];
    std::cout << "Enter coefficients" << std::endl;
    for (int i = 0; i < n + 1; i++) {
        std::cin >> inp[i];
    }
    std::cout << "Enter xi" << std::endl;
    std::cin >> xi;
    result[0] = inp[0];
    for (int i = 1; i < n + 1; i++) {
        result[i] = xi * result[i - 1] + inp[i];
    }
    if (xi < 0) {
        std::cout << "(x+" << -xi << ")(";
    } else {
        std::cout << "(x-" << xi << ")(";
    }
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << "x^" << n - i - 1;
        if ((i + 1 != n) && (result[i+1] >= 0)) {
            std::cout << "+";
        }
    }
    std::cout << ')';
    if (result[n] >= 0) {
        std::cout << '+';
    }
    std::cout << result[n] << std::endl;
    auto check = new int [n + 1];
    std::fill(check, check+n+1, 0);
    for (int i = 0; i < n; i++) {
        check[i + 1] += (-xi * result[i]);
        check[i] += result[i];
    }
    check[n] += result[n];
    for (int i = 0; i < n + 1; i++) {
        if (inp[i] != check[i]) {
            std::cerr << "Result is incorrect!" << std::endl;
            return 1;
        }
    }
    std::cout << "Result is correct!" << std::endl;
    return 0;
}