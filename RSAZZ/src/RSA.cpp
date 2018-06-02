#include "RSA.h"
#include <../externo.h>
#include <time.h>

RSA::RSA()
{
    generarClave();
    phi=(clave_a-1)*(clave_b-1);
    alfabetosdig=digitos(alfabetolargo);
    ndig=digitos(n);
    //ctor
}

RSA::RSA(ZZ publi, ZZ ene)
{
    n=ene;
    clave_a=factor(ene);
    clave_b=n/clave_a;

    phi=(clave_a-1)*(clave_b-1);
    e=publi;
    d=mod_inverso(e,phi);
    alfabetosdig=digitos(alfabetolargo);
    ndig=digitos(n);

    //dtor
}
void RSA::generarClave(){
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
    while((e<to_ZZ(2))&&(e>phi)&&(mcd(e,phi)!=1)){
        e=rand() % alfabeto.size();

    }d=mod_inverso(e,n);
    cout<<phi<<endl;
    cout<<clave_a<<" "<<clave_b<<endl;
    cout<<"clave publica: "<<e<<" N: "<<n<<" d: "<<d<<endl;
}

string RSA::cifrar(string palabra){
    ZZ pos;
    string spos,zero="0",temp,previo;
    ZZ palabralargo=to_ZZ(palabra.size());
    int tempo;
    for(long i=0; i<palabralargo;i++){//cout<<"alfabeto letra: " <<alfabeto.find(palabra[i]);

        //pos=potenciamod(alfabeto.find(palabra[i]),e,n);
        tempo=alfabeto.find(palabra[i]);
        pos=ZZ(tempo);

        spos=to_string(tempo);
        if(digitos(pos)<alfabetosdig){
            temp="";
            for(ZZ j=to_ZZ(0);j<alfabetosdig-digitos(pos);j++){
                temp=temp+zero;
            }spos=temp+spos;
        }
        //cout<<"pos: " <<pos<<endl;
        previo=previo+spos;
        spos="";

    }while(modulo(to_ZZ(previo.length()),ndig-1)!=0){
            previo=previo+to_string(alfabeto.find('W'));
        }


    //SEGUNDA PARTE
    for(long i=0; i<previo.length();i++){
        spos="";

        for(ZZ j=to_ZZ(0);j<ndig-1;j++){
            spos=spos+previo[i];
            i++;
        }i--;

        tempo=stoi(spos);
        pos=conv<ZZ>(tempo);
        pos=potenciamod(pos,e,n);
        tempo=conv<int>(pos);
        spos=to_string(tempo);
        if(digitos(pos)<ndig){
            temp="";
            for(ZZ j=to_ZZ(0);j<ndig-digitos(pos);j++){
                temp=temp+zero;
            }spos=temp+spos;
        }
        cifrado=cifrado+spos;

    }
    return cifrado;
}

string RSA::descifrar(string nuevo){

    //descifrado=cifrado;
    ZZ pos;
    int tempo;
    palabra=nuevo;
    ZZ palabralargo=to_ZZ(palabra.size());
    string temp,spos,previo,zero="0";
    for(long i=0; i<palabralargo;i++){//cout<<"alfabeto letra: " <<alfabeto.find(palabra[i]);
        spos="";
        for(long j=0;j<ndig;j++){
            spos=spos+palabra[i];
            i++;
        }i--;
        tempo=stoi(spos);
        pos=conv<ZZ>(tempo);
        pos=potenciamod(pos,d,n);
        //cout<<"position "<<alfabeto.find(palabra[i])<<endl;
        tempo=conv<int>(pos);
        spos=to_string(tempo);
        if(digitos(pos)<ndig-1){
            temp="";
            for(long j=0;j<ndig-1-digitos(pos);j++){
                temp=temp+zero;
            }spos=temp+spos;
        }
        previo=previo+spos;

    }
    for(long i=0,k; i<previo.length();i++){
        spos="";

        for(long j=0;j<alfabetosdig;j++){
            spos=spos+previo[i];
            i++;
        }i--;

        k=stoi(spos);
        descifrado=descifrado+alfabeto[k];

    }


    return descifrado;
}
