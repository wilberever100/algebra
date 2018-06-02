#include <NTL/ZZ.h>

#ifndef RSA_H
#define RSA_H
#include<string>

using namespace std;
using namespace NTL;

class RSA
{
    private:
        string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ.,-_()abcdefghijklmnopqrstuvwxyz 0123456789";
        ZZ n,d,e,phi,ndig;

        ZZ clave_a,clave_b;
        ZZ alfabetolargo=to_ZZ(alfabeto.length());
        ZZ alfabetosdig;
        void generarClave();
    public:
        string cifrado,palabra;
        string descifrado;
        RSA();

        RSA(ZZ,ZZ);
        string cifrar(string);
        string descifrar(string);

    protected:

    private:
};

#endif // RSA_H
