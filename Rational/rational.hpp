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
#include <cstring>


class Rational {
    
private: int n, z;
    
public:
    Rational (int zaehler, int nenner = 1)
//    :
//    z{ [zaehler, nenner](){
//        int g = std::gcd(zaehler, nenner);
//        return zaehler/g;}() }
//    ,
//    n{ [zaehler, nenner](){
//        int g = std::gcd(zaehler, nenner);
//        return nenner/g;}() }
//    {}
    {
        int g = std::gcd(zaehler, nenner);
        z = zaehler/g;
        n = nenner/g;
    }
    
    Rational operator+(Rational r) {
        int hn = n/std::gcd(n, r.n) * r.n;
        int z1 = hn/n * z;
        int z2 = hn/r.n * r.z;
        
        return Rational(z1 + z2, hn);
    }

    Rational operator*(Rational r) {
        return Rational(z * r.z, n * r.n);
    }
    
    Rational operator/(Rational r) {
        return Rational(z * r.n, n * r.z);
    }
    
    Rational inverse() {
        //return Rational(1)/(*this);
        return Rational(n,z);
    }
    
    friend std::ostream& operator<<(std::ostream& o, const Rational& r) {
        return o<<r.to_string();
    }
    
    std::string to_string() const {
        using namespace std::string_literals;
        std::string s("(");
        s+=std::to_string(z); s+="/";
        s+=std::to_string(n); s+=")";
        return s;
    }
    
    operator double() const {
        return 1. * z / n;
    }
    
};

inline Rational operator "" _Q(const char* literal, size_t l) {
    std::string slit(literal);
    auto p = slit.find("/");
    int z = std::stoi(slit.substr(0, p));
    int n = std::stoi(slit.substr(p+1, std::string::npos));
    return Rational(z, n);
}

inline Rational operator "" _Q(unsigned long long z) {
    return Rational(z);
}

#endif /* rational_hpp */
