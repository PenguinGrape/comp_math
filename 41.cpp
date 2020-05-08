#include <iostream>
#include <complex>
#include <cstring>


long m1, n1, m2, n2;


std::complex<double>** enter1st() {
    std::cout << "Enter M and N of 1st matrix: " << std::flush;
    std:: cin >> m1 >> n1;
    std::complex <double> **A;
    A = new std::complex<double> *[m1];
    for (long i = 0; i < m1; i++) {
        A[i] = new std::complex<double> [n1];
    }
    std::cout << "Enter your matrix now" << std::endl;
    for (long i = 0; i < m1; i++) {
        for (long j = 0; j < n1; j++) {
            std::cin >> A[i][j];
        }
    }
    return A;
}


std::complex<double>** enter2nd() {
    std::cout << "Enter M and N of 2nd matrix: " << std::flush;
    std:: cin >> m2 >> n2;
    std::complex <double> **B;
    B = new std::complex<double> *[m2];
    for (long i = 0; i < m2; i++) {
        B[i] = new std::complex<double> [n2];
    }
    std::cout << "And another one" << std::endl;
    for (long i = 0; i < m2; i++) {
        for (long j = 0; j < n2; j++) {
            std::cin >> B[i][j];
        }
    }
    return B;
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage:\n" << argv[0] << " <operation>\nOperations: add, sub, mulcomplex, mulmatrix" << std::endl;
        return 1;
    }
    if (strcmp(argv[1], "add") == 0 || strcmp(argv[1], "sub") == 0) {
        auto A = enter1st();
        auto B = enter2nd();
        if (m1 != m2 || n1 != m1) {
            std::cout << "Operation not permitted!" << std::endl;
            return 1;
        }
        for (long i = 0; i < m1; i++) {
            for (long j = 0; j < n1; j++) {
                if (argv[1][0] == 'a') {
                    std::cout << A[i][j] + B[i][j];
                } else {
                    std::cout << A[i][j] - B[i][j];
                }
                std::cout << " " << std::flush;
            }
            std::cout << std::endl;
        }
        return 0;
    }
    if (strcmp(argv[1], "mulcomplex") == 0) {
        auto A = enter1st();
        std::cout << "Enter complex number: " << std::flush;
        std::complex<double> k;
        std::cin >> k;
        for (long i = 0; i < m1; i++) {
            for (long j = 0; j < n1; j++) {
                std::cout << A[i][j] * k << ' ' << std::flush;
            }
            std::cout << std::endl;
        }
        return 0;
    }
    if (strcmp(argv[1], "mulmatrix") == 0) {
        auto A = enter1st();
        auto B = enter2nd();
        if (m1 != n2) {
            std::cout << "Operation not permitted" << std::endl;
            return 1;
        }
        auto C = new std::complex<double>* [m1];
        for (long i = 0; i < m1; i++) {
            C[i] = new std::complex<double> [m1];
            for (long j = 0; j < m1; j++) {
                C[i][j] = 0;
                for (int k = 0; k < m2; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        for (long i = 0; i < m1; i++) {
            for (long j = 0; j < m1; j++) {
                std::cout << C[i][j] << ' ' << std::flush;
            }
            std::cout << std::endl;
        }
        return 0;
    }
    std::cout << "There is no such operation. RTFM!" << std::endl;
    return 1;
}
