//
//  main.cpp
//  Rational
//
//  Created by Klaus Ahrens on 19.03.21.
//

#include <iostream>
#include "rational.hpp"

int main(int argc, const char * argv[]) {
    
    auto r1 ="22/7"_Q;
    double d1 = r1;
    std::cout << r1 << "\n" << d1 << "\n";
    
    const auto r2 = 22_Q/7_Q;
    double d2 = r2;

    std::cout << r2 << "\n" << d2 << "\n";

    Rational r3 = Rational(44);
    return 0;
}
