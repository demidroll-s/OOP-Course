#include "rational.h"

int main() {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3;
    r3 = r1 + r2;
    std::cout << r3 << std::endl; // 5/6
    r3 = r1 - r2;
    std::cout << r3 << std::endl; // 1/6
    r3 = r1 * r2;
    std::cout << r3 << std::endl; // 1/6
    r3 = r1 / r2;
    std::cout << r3 << std::endl; // 3/2

    r1.add(r2);
    std::cout << r1 << std::endl; // 5/6
    r1.sub(r2);
    std::cout << r1 << std::endl; // 1/2
    double x = r1.to_double();
    std::cout << x << std::endl;

    return 0;
}