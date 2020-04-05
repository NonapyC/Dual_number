#include <iostream>
#include <vector>
#include <cmath>
#include "header/NS_dual.hpp"
/*#include "header/nonapy2.hpp"*/
#include "header/NS_Hyperdual.hpp"
using namespace std;
using namespace LibNS2;

double func(double x){
    return  exp(x) / sqrt( sin(x)*sin(x)*sin(x) + cos(x)*cos(x)*cos(x) );
}

double anal1(double x){
    return exp(x) * ( 3.0 * cos(x) + 5.0 * cos(3.0*x) + 9.0*sin(x) + sin(3.0*x) ) / ( 8.0 * sqrt( cube(sin(x)*sin(x)*sin(x) + cos(x)*cos(x)*cos(x)) ) );
}

double anal2(double x){
    return exp(x) * ( 130.0 - 12.0*cos(2.0*x) + 30.0*cos(4.0*x) + 12.0*cos(6.0*x) - 111.0*sin(2.0*x) + 48.0*sin(4.0*x) + 5.0*sin(6.0*x) ) / ( 64.0 * sqrt( sqr( ( cube(sin(x)) + cube(cos(x)) ) ) * cube( cube(sin(x)) + cube(cos(x)) ) ) );
}

dual cube3(dual x){
    return x * x * x;
}

hyper_dual cube4(hyper_dual x){
    return x * x * x;
}

/*----------------------------------------------------------------
 　メイン函数
 -----------------------------------------------------------------*/

int main(){
    double h = 0.00001;
    dual x(1.0);
    hyper_dual xh(1.0);
    dual z = exp(x) / sqrt( cube3(sin(x)) + cube3(cos(x)) ); /*微分する函数*/
    hyper_dual zh = exp(xh) / sqrt( cube4(sin(xh)) + cube4(cos(xh)) ); /*微分する函数*/

    cout << z.value << ", " << zh.dif() << ", " << zh.difdif() << endl;
    cout << func(1.0) << ", " << ( func(1.0 + h) - func(1.0) ) / h << ", " << ( func(1.0 + h) - 2.0 * func(1.0) + func(1.0 - h ) ) / (h*h) << endl;
    cout << func(1.0) << ", " << anal1(1.0) << ", " << anal2(1.0) << endl;

    return 0;
}
