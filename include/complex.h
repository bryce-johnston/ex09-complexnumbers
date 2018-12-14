
#ifndef EX09_COMPLEXNUMBERS_COMPLEX_H
#define EX09_COMPLEXNUMBERS_COMPLEX_H

#include <iostream>
namespace edu{ namespace vcccd{ namespace vc{ namespace csv13{
    class Complex{
    public:
        double real;
        const double i;
        Complex(double r, double i);
        Complex(double r);
        double const getRealPart();
        double const getImaginaryPart();
        friend Complex operator + (Complex &, Complex &);
        friend Complex operator - (Complex &, Complex &);
        friend Complex operator * (Complex &, Complex &);
        friend Complex operator == (Complex &, Complex &);
        friend Complex operator != (Complex &, Complex &);
        friend std::ostream operator << (std::ostream &output, Complex &);
        friend std::istream operator >> (std::istream &input, Complex &);
    };
}}}}

#endif //EX09_COMPLEXNUMBERS_COMPLEX_H
