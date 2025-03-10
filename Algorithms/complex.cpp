#include <iostream>
#include <cmath>

class complex
{
public:
    float re;
    float im;
    complex(const complex &obj)
    {
        re = obj.re;
        im = obj.im;
    }
    complex(const float re = 0, const float im = 0)
    {
        this->re = re;
        this->im = im;
    }

    complex &conj() const;
    double &arg();
    double &arg_deg();
    // complex &operator+(const complex &b);
    // complex &operator-(const complex &b);

    friend complex &operator+(const complex &a, const complex &b);
    friend complex &operator+(const complex &a, const complex &b);


    complex &operator+(const float b);
    complex &operator-(const float b);

    friend complex &operator*(const complex &a, const complex &b);
    friend complex &operator/(const complex &a, const complex &b);

    complex &operator^(int n){
        complex obj(*this);
        for(; n; n--)obj = obj * obj;
        return obj;  
    }


    friend std::ostream &operator<<(std::ostream &out, const complex &obj);
    friend std::istream &operator>>(std::istream &in, const complex &obj);


}; // end of complex class

complex &complex::conj() const{
    complex new_this(this->re, -(this->im));
    return new_this;
}
double &complex::arg(){
    double result = atan((this->im/this->re));
    return result;
}
double &complex::arg_deg(){
    double result = atan((this->im/this->re)) * 180 / 3.14159265358979;
    return result;
}





complex &operator+(const complex &a, const complex &b){
    float re = (float)a.re + b.re; float im = (float) a.im+ b.im;
    complex new_obj(re, im);
    return new_obj;
}

complex &operator-(const complex &a, const complex &b){
    float re = (float)a.re - b.re; float im = (float) a.im - b.im;
    complex new_obj(re, im);
    return new_obj;
}



complex &operator*(const complex &a, const complex &b)
{
    complex new_this((a.re * b.re) - (a.im * b.im), (a.im * b.re) + (a.re * b.im));
    return new_this;
}
complex &operator/(const complex &a, const complex &b){
    complex new_this = (complex) a * b.conj();
    float denominator = b.re*b.re + b.im*b.im;
    new_this.re /= denominator; new_this.im /= denominator;
}

std::ostream &operator<<(std::ostream &out, const complex &obj)
{
    out << obj.re << " + i" << (float)obj.im;
    return out;
}
std::istream &operator>>(std::istream &in, complex &obj)
{
    float re{};
    float im{};
    in >> re >> im;
    if (in)
    {
        obj = complex(re, im);
    }
    return in;
}

int main(){
    complex z1 {1,4};
    complex z2 {1,4};
    complex z3 (z1 + z2);
    std::cout << z2.conj();
}