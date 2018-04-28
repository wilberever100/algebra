#include "afin.h"
#include<string>
#include "euclides.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

afin::afin(){
    alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    generarClave();
}

void afin::generarClave(){
    srand (time(NULL));
    clave_a=rand() % alfabeto.size() ;//1-101
    while(mcd(clave_a,alfabeto.size())!=1)
        clave_a=rand() % alfabeto.size() ;//1-101
    clave_b=rand() % alfabeto.size() ;//1-100
    cout<<"a: "<<clave_a<<endl;cout<<"b: "<<clave_b<<endl;
}

string afin::cifrar(string palabra){
    int pos;

    for(int i=0; i<palabra.size();i++){//cout<<"alfabeto letra: " <<alfabeto.find(palabra[i]);
        pos=alfabeto.find(palabra[i])*clave_a;
        //cout<<"position "<<alfabeto.find(palabra[i])<<endl;
        if(pos>=alfabeto.size())
            //cout<<"pos: " <<pos<<endl;
            pos=MOD(pos,alfabeto.size());
        pos=pos+clave_b;
        if(pos>=alfabeto.size()){
            //cout<<"pos: " <<pos<<endl;
            //cifrado=cifrado+alfabeto[MOD(pos,alfabeto.size())];//cout<<"MOD: "<<MOD(pos,alfabeto.size())<<endl;
            pos=MOD(pos,alfabeto.size());
        }
        //cout<<"pos: " <<pos<<endl;
        cifrado=cifrado+alfabeto[pos];

    }
    return cifrado;
}

string afin::descifrar(){
    //clave_a=clave_a_;
    //clave_b=clave_b_;
    descifrado=cifrado;
    int* result_euclides=euclides_extendido(clave_a,alfabeto.size());//cout<<"inversa: "<< result_euclides[0];
    int pos;
    for(int i=0; i<descifrado.size();i++){
        pos=(alfabeto.find(descifrado[i])-clave_b);
        if(pos<0)
            MOD(pos,alfabeto.size());
        pos=pos*result_euclides[0];
        descifrado[i]=alfabeto[MOD(pos,alfabeto.size())];
    }

    delete result_euclides;
    return descifrado;
}

///OPCIONAL PARA AUTODECIFRARSE
/*string afin::AUTO_descifrar(string palabra){
    vector<int>result_euclides=euclides_extendido(clave_a,alfabeto.size());//cout<<"inversa: "<< result_euclides[1];
    int pos;
    for(int i=0; i<palabra.size();i++){
        pos=(alfabeto.find(palabra[i])-clave_b);
        if(pos<0)
            MOD(pos,alfabeto.size());
        pos=pos*result_euclides[1];
        palabra[i]=alfabeto[MOD(pos,alfabeto.size())];
    }
    return palabra;
}*/
