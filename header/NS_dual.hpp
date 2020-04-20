// ---------------------------------------------------------------------------------------------------
// NS_dual VERSION 1.1.0
// Latest Edit: 20/04/11.
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
#include "../LibMK4/integ.hpp"
using namespace LibMK4;
using namespace std;

/*----------------------------------------------------------------
 　Dual-numberクラス
 -----------------------------------------------------------------*/
class dual{
public:
    double value;
    double diff;
    dual(){}
    dual(double x, double y=1.0) : value(x), diff(y){}
    dual& operator+= (dual y);
    dual& operator-= (dual y);
    dual& operator*= (double y);
    dual& operator/= (double y);
    dual operator- () const;
};


/*----------------------------------------------------------------
   代数構造の再定義
 -----------------------------------------------------------------*/
dual operator+(dual x, dual y){
    dual ref;
    ref.value = x.value + y.value;
    ref.diff = x.diff + y.diff;
    return ref;
}

dual operator-(dual x, dual y){
    dual ref;
    ref.value = x.value - y.value;
    ref.diff = x.diff - y.diff;
    return ref;
}

dual operator+(double x, dual y){
    dual ref;
    ref.value = x + y.value;
    ref.diff = y.diff;
    return ref;
}

dual operator-(double x, dual y){
    dual ref;
    ref.value = x - y.value;
    ref.diff = - y.diff;
    return ref;
}

dual operator+(dual x, double y){
    dual ref;
    ref.value = x.value + y;
    ref.diff =  x.diff;
    return ref;
}

dual operator-(dual x, double y){
    dual ref;
    ref.value = x.value - y;
    ref.diff = x.diff;
    return ref;
}

dual dual::operator- () const{
	dual ref;
	ref.value = -value;
	ref.diff = -diff;
	return ref;
}

dual operator*(dual x, dual y){
    dual ref;
    ref.value = x.value * y.value;
    ref.diff = x.diff*y.value  + x.value* y.diff;
    return ref;
}

dual operator*(double x, dual y){
    dual ref;
    ref.value = x * y.value;
    ref.diff = x * y.diff;
    return ref;
}

dual operator*(dual y, double x){
    dual ref;
    ref.value = x * y.value;
    ref.diff = x * y.diff;
    return ref;
}

dual operator/(dual x, double y){
    dual ref;
    ref.value = x.value / y;
    ref.diff = x.diff / y;
    return ref;
}

dual operator/(dual x, dual y){
    dual ref;
    ref.value = x.value / y.value;
    ref.diff = ( y.value * x.diff - x.value * y.diff ) / ( y.value * y.value );
    return ref;
}

dual operator/(double x, dual y){
    dual ref;
    ref.value = x / y.value;
    ref.diff =  ( - x * y.diff ) / ( y.value * y.value );
    return ref;
}

dual exp(dual x){
    dual ref;
    ref.value =  exp(x.value);
    ref.diff = exp(x.value) * x.diff;
    return ref;
}

dual sin(dual x){
    dual ref;
    ref.value = sin(x.value);
    ref.diff = cos(x.value) * x.diff;
    return ref;
}

dual cos(dual x){
    dual ref;
    ref.value = cos(x.value);
    ref.diff = -sin(x.value) * x.diff;
    return ref;
}

dual tan(dual x){
    dual ref;
    ref.value = tan(x.value);
    ref.diff = 1.0 / ( cos(x.value) * cos(x.value) ) * x.diff;
    return ref;
}

dual log(dual x){
    dual ref;
    ref.value = log(x.value);
    ref.diff = 1.0/(x.value)*x.diff;
    return ref;
}

dual sqrt(dual x){
    dual ref;
    ref.value = sqrt(x.value);
    ref.diff = 0.5 / sqrt(x.value) * x.diff;
    return ref;
}

dual sinh(dual x){
    dual ref;
    ref.value = sinh(x.value);
    ref.diff = cosh(x.value) * x.diff;
    return ref;
}

dual cosh(dual x){
    dual ref;
    ref.value = cosh(x.value);
    ref.diff = sinh(x.value) * x.diff;
    return ref;
}

dual tanh(dual x){
    dual ref;
    ref.value = tanh(x.value);
    ref.diff = 1.0 / ( cosh(x.value) * cosh(x.value) ) * x.diff;
    return ref;
}

/*----------------------------------------------------------------
   論理演算子の再定義
 -----------------------------------------------------------------*/
bool operator> (dual x, dual y){
	return (x.value > y.value);
}

bool operator> (double x,dual y){
	return (x > y.value);
}

bool operator> (dual x, double y){
	return (x.value > y);
}

bool operator>= (double x, dual y){
	return (x >= y.value);
}

bool operator>= (dual x, double y){
	return (x.value >= y);
}

bool operator< (dual x, dual y){
	return (x.value < y.value);
}

bool operator< (double x, dual y){
	return (x < y.value);
}

bool operator< (dual x, double y){
	return (x.value < y);
}

bool operator<= (dual x, dual y){
	return (x.value <= y.value);
}

bool operator<= (double x, dual y){
	return (x <= y.value);
}

bool operator<= (dual x, double y){
	return (x.value <= y);
}

bool operator== (dual x, dual y){
	return (x.value == y.value);
}

bool operator== (double x, dual y){
	return (x == y.value);
}

bool operator== (dual x, double y){
	return (x.value == y);
}

bool operator!= (dual x, dual y){
	return (x.value != y.value);
}

bool operator!= (double x, dual y){
	return (x != y.value);
}

bool operator!= (dual x, double y){
	return (x.value != y);
}

dual& dual::operator+= (dual y){
	value += y.value;
	diff += y.diff;
	return *this;
}
dual& dual::operator-= (dual y){
	value -= y.value;
	diff -= y.diff;
	return *this;
}

dual& dual::operator*= (double y){
	value *= y;
	diff *= y;
	return *this;
}

dual& dual::operator/= (double y){
	value /= y;
	diff /= y;
	return *this;
}

dual fabs(dual x){
	dual ref;
	if (x < 0.0) ref = 0.0-x;
	else ref = x;
	return ref;
}
