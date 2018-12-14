#include <iostream>
namespace edu{ namespace vcccd{ namespace vc{ namespace csv13{
    class Complex{
    public:
        double real;
        double i;
        Complex(double r, double i){
            this->real = r;
            this->i = i;
        }
        Complex(double r){
            this->real = r;
            this->i = 0.0;
        }
        double getRealPart(){
            return this->real;
        }
        double getImaginaryPart(){
            return this->i;
        }
        friend Complex operator + (Complex &, Complex &);
        friend Complex operator - (Complex &, Complex &);
        friend Complex operator * (Complex &, Complex &);
        friend Complex operator == (Complex &, Complex &);
        friend Complex operator != (Complex &, Complex &);
        friend std::ostream operator << (std::ostream &output, Complex &);
        friend std::istream operator >> (std::istream &input, Complex &);
    };
    using namespace edu::vcccd::vc::csv13;
    Complex operator + (Complex &c1, Complex &c2){
        return Complex(c1.getRealPart() + c2.getRealPart(), c1.getImaginaryPart() + c2.getImaginaryPart());
    }
    Complex operator - (Complex &c1, Complex &c2){
        return Complex(c1.getRealPart() - c2.getRealPart(), c1.getImaginaryPart() - c2.getImaginaryPart());
    }
    Complex operator * (Complex &c1, Complex &c2){
        return Complex(c1.getRealPart() * c2.getRealPart(), c1.getImaginaryPart() * c2.getImaginaryPart());
    }
    Complex operator == (Complex &c1, Complex &c2){
        if(c1.getRealPart() == c2.getRealPart() && c1.getImaginaryPart() == c2.getImaginaryPart()){
            return true;
        } else {
            return false;
        }
    }
    Complex operator != (Complex &c1, Complex &c2){
        if(c1.getRealPart() == c2.getRealPart() && c1.getImaginaryPart() == c2.getImaginaryPart()){
            return false;
        } else {
            return true;
        }
    }
    std::ostream & operator << (std::ostream &output, const Complex &c){
        if(c.getRealPart() == 0 && c.getImaginaryPart() != 0) {
            output << c.getImaginaryPart();
        } else if (c.getRealPart() != 0 && c.getImaginaryPart() == 0){
            output << c.getRealPart();
        } else if (c.getRealPart() != 0 && c.getImaginaryPart() > 0){
            output << c.getRealPart() << " + " << c.getImaginaryPart();
        } else if (c.getRealPart() != 0 && c.getImaginaryPart() < 0){
            output << c.getRealPart() << " - " << c.getImaginaryPart();
        }
        return output;
    }
    std::istream & operator >> (std::istream &input, Complex &c){
        input >> c.real;
        input >> c.i;
        return input;
    }
}}}}
