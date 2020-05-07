#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cerrno>


using namespace std;


double f (double x) {
    /*
     * pow(x, 3) - pow(x, 2) + 2 * x - 5;
     * 2 * log10(pow(x, 2)) - 5 * pow(log10(x), 2) - 4;
     * 2 * sin(2 * x) - cos(3 * x) - 0.5;
     * 2 * pow(x, 3) - 7* pow(x, 2) - 7 * x - 2.5;
    */
    return pow(5, x) * sqrt(pow(8, x-1)) - 189;
}


double find_root(double a, double b, double precision, unsigned int limit)
{
    double c = a;
    double prev_c = b;
    unsigned int climit = 0;
    while ((abs(c - prev_c) > precision / 2) && (climit < limit)) {
        climit++;
        prev_c = c;
        if (c == a) {
            c = c - (b - c) * f(c) / (f(b) - f(c));
        } else {
            c = c - (c - a) * f(c) / (f(c) - f(a));
        }
        if (f(c)== 0) {
            return c;
        }
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}


int main(int argc, char** argv) {
    if (argc != 5) {
        cout << "Using:\n" << argv[0] << " <left limit> <right limit> <precision> <iteration limit>" << endl;
        return 1;
    }
    double a = strtod(argv[1], nullptr);
    double b = strtod(argv[2], nullptr);
    double precision = strtod(argv[3], nullptr);
    unsigned int limit = strtol(argv[3], nullptr);
    if (errno == ERANGE || precision == 0) {
        cout << "Incorrect input data" << endl;
        return 1;
    }
    if (f(a) * f(b) > 0) {
        cout << "Incorrect interval" << endl;
        return 1;
    }
    cout << find_root(a, b, precision, limit) << endl;
    return 0;
}
