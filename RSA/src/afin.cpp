#include "afin.h"
#include<string>
#include "euclides.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

afin::afin(){

    generarClave();
    phi=(clave_a-1)*(clave_b-1);
    alfabetosdig=digitos(alfabetolargo);
    ndig=digitos(n);
}

afin::afin(int publi,int ene){
    n=ene;
    clave_a=factor(ene);
    clave_b=n/clave_a;

    phi=(clave_a-1)*(clave_b-1);
    e=publi;
    d=mod_inverso(e,phi);
    alfabetosdig=digitos(alfabetolargo);
    ndig=digitos(n);

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
    n=clave_a*clave_b;
    e=rand() % alfabeto.size();
    phi=(clave_a-1)*(clave_b-1);
    while((e<2)&&(e>phi)&&(mcd(e,phi)!=1)){
        e=rand() % alfabeto.size();

    }d=mod_inverso(e,n);
    cout<<phi<<endl;
    cout<<clave_a<<" "<<clave_b<<endl;
    cout<<"clave publica: "<<e<<" N: "<<n<<" d: "<<d<<endl;
}

string afin::cifrar(string palabra){
    int pos;
    string spos,zero="0",temp,previo;
    int palabralargo=palabra.size();
    for(int i=0; i<palabralargo;i++){//cout<<"alfabeto letra: " <<alfabeto.find(palabra[i]);

        //pos=potenciamod(alfabeto.find(palabra[i]),e,n);
        pos=alfabeto.find(palabra[i]);

        spos=to_string(pos);
        if(digitos(pos)<alfabetosdig){
            temp="";
            for(int j=0;j<alfabetosdig-digitos(pos);j++){
                temp=temp+zero;
            }spos=temp+spos;
        }
        //cout<<"pos: " <<pos<<endl;
        previo=previo+spos;
        spos="";

    }while(MOD(previo.length(),ndig-1)!=0){
            previo=previo+to_string(alfabeto.find('W'));
        }


    //SEGUNDA PARTE
    for(int i=0; i<previo.length();i++){
        spos="";

        for(int j=0;j<ndig-1;j++){
            spos=spos+previo[i];
            i++;
        }i--;

        pos=stoi(spos);

        pos=potenciamod(pos,e,n);
        spos=to_string(pos);
        if(digitos(pos)<ndig){
            temp="";
            for(int j=0;j<ndig-digitos(pos);j++){
                temp=temp+zero;
            }spos=temp+spos;
        }
        cifrado=cifrado+spos;

    }
    return cifrado;
}

string afin::descifrar(string nuevo){

    //descifrado=cifrado;
    int pos,tempo;
    palabra=nuevo;
    int palabralargo=palabra.size();
    string temp,spos,previo,zero="0";
    for(int i=0; i<palabralargo;i++){//cout<<"alfabeto letra: " <<alfabeto.find(palabra[i]);
        spos="";
        for(int j=0;j<ndig;j++){
            spos=spos+palabra[i];
            i++;
        }i--;
        pos=stoi(spos);
        pos=potenciamod(pos,d,n);
        //cout<<"position "<<alfabeto.find(palabra[i])<<endl;
        spos=to_string(pos);
        if(digitos(pos)<ndig-1){
            temp="";
            for(int j=0;j<ndig-1-digitos(pos);j++){
                temp=temp+zero;
            }spos=temp+spos;
        }
        previo=previo+spos;

    }
    for(int i=0; i<previo.length();i++){
        spos="";

        for(int j=0;j<alfabetosdig;j++){
            spos=spos+previo[i];
            i++;
        }i--;

        pos=stoi(spos);
        descifrado=descifrado+alfabeto[pos];

    }


    return descifrado;
}


