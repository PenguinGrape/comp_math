#include <iostream>


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Using:\n" << argv[0] << " TYPE\nTypes:\nH - harmonic\nL - logarithmic" << std::endl;
        return 0;
    }
    if (argv[1][0] != 'H' && argv[1][0] != 'L') {
        std::cerr << "There is no such type";
        return 1;
    }
    int n;
    std::cout << "Enter the number of row members" << std::endl;
    std::cin >> n;
    if (argv[1][0] == 'L') {
        double x, tmp;
        std::cout << "Logarithmic: ln(1+x). Enter x, -1 < x <= 1" << std::endl;
        std::cin >> x;
        if ((x <= -1) || (x > 1)) {
            std::cerr << "x should be -1 < x <= 1" << std::endl;
            return 1;
        }
        double res = 0.0, d = 1.0;
        tmp = x;
        for (int i = 1; i < n + 1; i++) {
            if (i % 2) {
                res += tmp / d;
            } else {
                res -= tmp / d;
            }
            tmp *= x;
            d++;
        }
        std::cout << "Result is " << res << std::endl;
    }
    else if (argv[1][0] == 'H') {
        double x, tmp;
        std::cout << "Harmonic: sin(x). Enter x" << std::endl;
        std::cin >> x;
        double res = 0.0, d = 1.0;
        tmp = x;
        for (int i = 1; i < n * 2; i += 2) {
            if ((i / 2) % 2) {
                res -= tmp / d;
            } else {
                res += tmp / d;
            }
            std::cout << x << " " << tmp << " " << d << " " << res << std::endl;
            tmp *= x * x;
            d *= (i + 1) * (i + 2);
        }
        std::cout << "Result is " << res << std::endl;
    }
    return 0;
}