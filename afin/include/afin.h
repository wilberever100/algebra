#ifndef AFIN_H
#define AFIN_H
#include<string>
using namespace std;

class afin
{
private:
    string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ.,-_()abcdefghijklmnopqrstuvwxyz 0123456789";
    int clave_a;
    int clave_b;
    void generarClave();
public:
    string cifrado,palabra;
    string descifrado;
    afin();
    afin(string);
    afin(string,int,int);
    string cifrar(string);
    string descifrar(string, int, int);

};

#endif // AFIN_H
