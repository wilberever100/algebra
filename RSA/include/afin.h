#ifndef AFIN_H
#define AFIN_H
#include<string>
using namespace std;

class afin
{
private:
    string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ.,-_()abcdefghijklmnopqrstuvwxyz 0123456789";
    int n,d,e,phi,ndig;

    int clave_a,clave_b;
    int alfabetolargo=alfabeto.length();
    int alfabetosdig;
    void generarClave();
public:
    string cifrado,palabra;
    string descifrado;
    afin();

    afin(int,int);
    string cifrar(string);
    string descifrar(string);

};

#endif // AFIN_H
