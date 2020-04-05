// ---------------------------------------------------------------------------------------------------
// NS_Hyper_dual VERSION 1.0.0
// Latest Edit: 20/04/04.
//
// Copyright (C) 2020 Nonaka Soshi †
// † Master of Science, Department of Physics, Osaka University, Japan.
//
// Pleare e_mail me for any inquiry : sou.235711_at_gmail.com ( exchange: _at_ -> @ )
// And the first time I corded this is 2020/04/04.
//---------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*----------------------------------------------------------------
 　Hyper-dual-numberクラス
 -----------------------------------------------------------------*/
class hyper_dual{
public:
    double value1, value2, value3, value4;
    hyper_dual(){}
    hyper_dual(double x, double y=1.0, double z=1.0, double q=1.0) : value1(x), value2(y), value3(z), value4(q){}

    double difdif(){
        return value4 - value2;
    }
    double dif(){
        return value2;
    }

};

/*----------------------------------------------------------------
   代数構造の再定義
 -----------------------------------------------------------------*/
hyper_dual operator+(hyper_dual x, hyper_dual y){
    hyper_dual ref;
    ref.value1 = x.value1 + y.value1;
    ref.value2 = x.value2 + y.value2;
    ref.value3 = x.value3 + y.value3;
    ref.value4 = x.value4 + y.value4;
    return ref;
}

hyper_dual operator-(hyper_dual x, hyper_dual y){
    hyper_dual ref;
    ref.value1 = x.value1 - y.value1;
    ref.value2 = x.value2 - y.value2;
    ref.value3 = x.value3 - y.value3;
    ref.value4 = x.value4 - y.value4;
    return ref;
}

hyper_dual operator+(double x, hyper_dual y){
    hyper_dual ref;
    ref.value1 = x + y.value1;
    ref.value2 = y.value2;
    ref.value3 = y.value3;
    ref.value4 = y.value4;
    return ref;
}

hyper_dual operator-(double x, hyper_dual y){
    hyper_dual ref;
    ref.value1 = x - y.value1;
    ref.value2 = -y.value2;
    ref.value3 = -y.value3;
    ref.value4 = -y.value4;
    return ref;
}

hyper_dual operator+(hyper_dual x, double y){
    hyper_dual ref;
    ref.value1 = x.value1 + y;
    ref.value2 = x.value2 ;
    ref.value3 = x.value3 ;
    ref.value4 = x.value4 ;
    return ref;
}

hyper_dual operator-(hyper_dual x, double y){
    hyper_dual ref;
    ref.value1 = x.value1 - y;
    ref.value2 = x.value2 ;
    ref.value3 = x.value3 ;
    ref.value4 = x.value4 ;
    return ref;
}

hyper_dual operator*(hyper_dual x, hyper_dual y){
    hyper_dual ref;
    ref.value1 = x.value1 * y.value1;
    ref.value2 = x.value1 * y.value2 + x.value2 * y.value1;
    ref.value3 = x.value1 * y.value3 + x.value3 * y.value1;
    ref.value4 = x.value1 * y.value4 + x.value2 * y.value3 + x.value3 * y.value2 + x.value4 * y.value1;
    return ref;
}

hyper_dual operator*(double x, hyper_dual y){
    hyper_dual ref;
    ref.value1 = x * y.value1;
    ref.value2 = x * y.value2;
    ref.value3 = x * y.value3;
    ref.value4 = x * y.value4;
    return ref;
}

hyper_dual operator*(hyper_dual x, double y){
    hyper_dual ref;
    ref.value1 = x.value1 * y;
    ref.value2 = x.value2 * y;
    ref.value3 = x.value3 * y;
    ref.value4 = x.value4 * y;
    return ref;
}

hyper_dual operator/(hyper_dual x, double y){
    hyper_dual ref;
    ref.value1 = x.value1 / y;
    ref.value2 = x.value2 / y;
    ref.value3 = x.value3 / y;
    ref.value4 = x.value4 / y;
    return ref;
}

hyper_dual operator/(hyper_dual y, hyper_dual x){
    hyper_dual ref;
    ref.value1 = y.value1 / x.value1;
    ref.value2 = ( y.value2/x.value1 - y.value1*x.value2/(x.value1*x.value1) );
    ref.value3 = (-x.value3 * y.value1 / (x.value1*x.value1) + y.value3 / x.value1 );
    ref.value4 = y.value4 / x.value1 - x.value2 * y.value3 / (x.value1*x.value1) - x.value3 * y.value2 / (x.value1*x.value1) - x.value4 * y.value1 / (x.value1*x.value1) + 2.0*x.value2*x.value3*y.value1 / (x.value1*x.value1*x.value1);
    return ref;
}

hyper_dual operator/(double y, hyper_dual x){
    hyper_dual ref;
    ref.value1 = y / x.value1;
    ref.value2 = ( - y * x.value2 / ( x.value1 * x.value1 ) );
    ref.value3 = - x.value3 * y / ( x.value1 * x.value1 );
    ref.value4 = - x.value4 * y / ( x.value1 * x.value1 ) + 2.0*x.value2*x.value3*y / (x.value1*x.value1*x.value1);
    return ref;
}

hyper_dual exp(hyper_dual x){
    hyper_dual ref;
    ref.value1 = exp(x.value1);
    ref.value2 = exp(x.value1) * x.value2;
    ref.value3 = exp(x.value1) * x.value3;
    ref.value4 = x.value4 * exp(x.value1) + x.value2*x.value3*exp(x.value1);
    return ref;
}

hyper_dual sin(hyper_dual x){
    hyper_dual ref;
    ref.value1 = sin(x.value1);
    ref.value2 = cos(x.value1) * x.value2;
    ref.value3 = cos(x.value1) * x.value3;
    ref.value4 = x.value4 * cos(x.value1) - x.value2*x.value3*sin(x.value1);
    return ref;
}

hyper_dual cos(hyper_dual x){
    hyper_dual ref;
    ref.value1 = cos(x.value1);
    ref.value2 = - sin(x.value1) * x.value2;
    ref.value3 = - sin(x.value1) * x.value3;
    ref.value4 = - x.value4 * sin(x.value1) - x.value2*x.value3*cos(x.value1);
    return ref;
}

hyper_dual tan(hyper_dual x){
    hyper_dual ref;
    ref.value1 = tan(x.value1);
    ref.value2 = 1.0 / ( cos(x.value1) * cos(x.value1) ) * x.value2;
    ref.value3 = 1.0 / ( cos(x.value1) * cos(x.value1) ) * x.value3;
    ref.value4 = x.value4 * 1.0 / ( cos(x.value1) * cos(x.value1) ) + x.value2*x.value3*(2.0*tan(x.value1) + 2.0*tan(x.value1)*tan(x.value1)*tan(x.value1));
    return ref;
}

hyper_dual log(hyper_dual x){
    hyper_dual ref;
    ref.value1 = log(x.value1);
    ref.value2 = 1.0 / (x.value1) * x.value2;
    ref.value3 = 1.0 / (x.value1) * x.value3;
    ref.value4 = x.value4 * 1.0 / (x.value1) - x.value2 * x.value3 * 1.0 / ( x.value1 * x.value1 );
    return ref;
}

hyper_dual sqrt(hyper_dual x){
    hyper_dual ref;
    ref.value1 = sqrt(x.value1);
    ref.value2 = 0.5 / sqrt(x.value1) * x.value2;
    ref.value3 = 0.5 / sqrt(x.value1) * x.value3;
    ref.value4 = x.value4 * 0.5 / sqrt(x.value1) - x.value2*x.value3* 0.25 / sqrt(x.value1*x.value1*x.value1);
    return ref;
}

