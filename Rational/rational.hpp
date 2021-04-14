//
//  rational.hpp
//  Rational
//
//  Created by Klaus Ahrens on 19.03.21.
//

#ifndef rational_hpp
#define rational_hpp

#include <numeric>
#include <string>
#include <iostream>

template<typename I = int>
class Rational {
    
private: // anyway classes start private
    I n, z;
    
public:
    Rational (int zaehler = 0, int nenner = 1) {
        auto g = std::gcd(zaehler, nenner);
        z = zaehler / g;
        n = nenner / g;
    }
    
    friend Rational operator+(Rational r1, Rational r2)
    {
        int hn = r1.n/std::gcd(r1.n, r2.n) * r2.n;
        int z1 = hn/r1.n * r1.z;
        int z2 = hn/r2.n * r2.z;
        
        return Rational(z1 + z2, hn);
    }
    
    std::string to_string() const;
    
    friend std::ostream& operator<<(std::ostream& o, const Rational& r) {
        return o<<"("<<r.z<<"/"<<r.n<<")";
    }

    operator double() const {
            return 1. * z / n;
    }
};




#endif /* rational_hpp */
