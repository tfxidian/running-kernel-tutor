
#ifndef __COMPLEX__
#define __COMPLEX__

#include <cmath>

//class complex;

template<typename T>
class complex{

public:
    complex(T r = 0, T i = 0)
        :re(r),im(i)
    { }
    complex& operator += (const complex&);
    T real() const{return re;}
    T imag() const {return im;}

private:
    T re, im;

    friend complex& __doap(complex*, const complex&);
};


#endif // __COMPLEX__
