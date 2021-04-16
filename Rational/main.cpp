//
//  main.cpp
//  Rational
//
//  Created by Klaus Ahrens on 19.03.21.
//

#include <cstdlib>
#include <iostream>
#include "rational.hpp"

int main() {
    using Rational = Rational<long>;
    auto r1 = Rational{22,7};
    const auto d1 = to_double(r1);
    std::cout << r1 << "\n" << d1 << "\n";
    auto r2 = Rational{22,7};
    
    std::cout << r1+r2 << "\n";
    
    return 0;
}
