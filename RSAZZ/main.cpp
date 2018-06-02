#include <NTL/ZZ.h>
#include<string>
#include "RSA.h"
using namespace std;
using namespace NTL;

ZZ multiplicar(ZZ& a, ZZ& b){
    ZZ c;
    c=a+b;
    return c;
}

int main()
{
    string b,a,nuevo,c;
    ZZ num1=to_ZZ(3), num2=to_ZZ(1003);
    b="Pero ni uno valiente, para hacerle ternura";

    RSA afin_(num1,num2);
    c=afin_.cifrar(b);
    cout<<c<<endl;
    cout<<afin_.descifrar(c)<<endl;
    return 0;
}
