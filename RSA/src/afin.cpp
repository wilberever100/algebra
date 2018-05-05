#include "afin.h"
#include<string>
#include "euclides.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

afin::afin(){

    generarClave();
}
afin::afin(string k){
    generarClave();
    cout<<cifrar(k)<<endl;

}
afin::afin(string mensaje,int a,int b){
    cout<<descifrar(mensaje,a,b)<<endl;
}





void afin::generarClave(){
    srand (time(NULL));
    bool primo;
    clave_a=rand() % alfabeto.size() ;
    primo=esprimo(clave_a);//1-101
    while(primo==false){
        clave_a=rand() % alfabeto.size() ;
        primo=esprimo(clave_a);//1-101
    }
    clave_b=rand() % alfabeto.size() ;
    primo=esprimo(clave_b);//1-101
    while(primo==false){
        clave_b=rand() % alfabeto.size() ;
        primo=esprimo(clave_b);//1-101
    }//1-100
    n=clave_a*clave_b,e=rand() % alfabeto.size();
    int phi=(clave_a-1)*(clave_b-1);
    int d=mod_inverso(e,n);
    while((e>1)&&(e<phi)&&(mcd(e,phi)==1)&&(mcd(e,phi)!=0)&&(d==0)){
        e=rand() % alfabeto.size();
        d=mod_inverso(e,n);
    }
    cout<<phi<<endl;
    cout<<clave_a<<" "<<clave_b<<endl;
    cout<<"clave publica: "<<e<<" N: "<<n<<endl;
}

string afin::cifrar(string palabra){
    int pos;
    int palabralargo=palabra.size();
    for(int i=0; i<palabralargo;i++){//cout<<"alfabeto letra: " <<alfabeto.find(palabra[i]);
        pos=potenciamod(alfabeto.find(palabra[i]),e,n);
        //cout<<"position "<<alfabeto.find(palabra[i])<<endl;
        if(pos>=alfabetolargo)
            //cout<<"pos: " <<pos<<endl;
            pos=MOD(pos,alfabetolargo);

        //cout<<"pos: " <<pos<<endl;
        cifrado=cifrado+alfabeto[pos];

    }
    return cifrado;
}

string afin::descifrar(string nuevo,int clave_a_,int clave_b_){
    d=mod_inverso(clave_a_,clave_b_);
    n=clave_b=clave_b_;
    //descifrado=cifrado;
    int pos;
    palabra=nuevo;
    int palabralargo=palabra.size();

    for(int i=0; i<palabralargo;i++){//cout<<"alfabeto letra: " <<alfabeto.find(palabra[i]);
        pos=potenciamod(alfabeto.find(palabra[i]),d,n);
        //cout<<"position "<<alfabeto.find(palabra[i])<<endl;
        if(pos>=alfabetolargo)
            //cout<<"pos: " <<pos<<endl;
            pos=MOD(pos,alfabetolargo);

        //cout<<"pos: " <<pos<<endl;
        descifrado=descifrado+alfabeto[pos];

    }
    cout<<descifrado<<endl;
    return descifrado;
}


