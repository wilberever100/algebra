#include <iostream>
#include<vector>
#include <NTL/ZZ.h>
using namespace std;



ZZ digitos(ZZ a){
    ZZ dig=to_ZZ(1);
    while(a/ZZ(10)>0)
    {
        a=a/ZZ(10);
        dig++;
    }return dig;
}

ZZ MOD(ZZ a,ZZ b){
    ZZ r=a-(a/b)*b;
	if(r<0){
		r=r+b;
	}
	return r;
}
ZZ factor(ZZ numero){
	ZZ i=to_ZZ(2);
	while(i<=numero)
	{
		if(MOD(numero,i)==to_ZZ(0))  //a%b=0, implica que b es factor de a.
		{
			return i;
		}
		i++;  //Incrementamos indice.
	}
}
ZZ modulo(ZZ a,ZZ b){
	ZZ r=a-(a/b)*b;
	if(r<0){
		r=r+b;
	}
	return r;
}

ZZ mod_inverso(ZZ a,ZZ b){
	ZZ p0=to_ZZ(0),p1=to_ZZ(1),pn=to_ZZ(0),q,cont=to_ZZ(0),total;
	ZZ r=a,modin=b;
    if(modulo(a,b)==to_ZZ(1))
        return to_ZZ(1);
	if((modulo(b,a))==to_ZZ(0)){return to_ZZ(0);}

	else{
        r=modulo(a,b);
        while(r>to_ZZ(1)){
            cont=cont+1;
            total=b;
            b=r;
            q=(total/b);
            r=modulo(total,b);
            pn=modulo((p0-p1*q),modin);
            p0=p1;
            p1=pn;
        }
        if(r!=to_ZZ(1)){return to_ZZ(0);}
	}
	return pn;
}


bool esprimo(ZZ n){
    ZZ a=to_ZZ(0);
    for(ZZ i=to_ZZ(1);i<(n+1);i++){
         if(n%i==to_ZZ(0)){
             a++;
            }
         }
         if(a!=to_ZZ(2)){
            return false;
         }else{return true;};
}
ZZ mcd(ZZ dividendo,ZZ divisor){
    ZZ residuo=MOD(dividendo,divisor);
    while(residuo>to_ZZ(0)){
        dividendo=divisor;
        divisor=residuo;
        residuo=MOD(dividendo,divisor);
    }
    return divisor;
}
ZZ potencia(ZZ a, ZZ b){
    ZZ r=modulo(b,to_ZZ(2)),acum=to_ZZ(1),anterior=a,mult;
    while(b!=to_ZZ(0)){
        if(r!=to_ZZ(0)){
            acum=anterior*acum;

        }

        mult=anterior*anterior;
        anterior=mult;
        b=b/2;
        r=b%2;
    }return acum;
}
ZZ potenciamod(ZZ a, ZZ b,ZZ n){
	ZZ r=modulo(b,to_ZZ(2)),nuevomodu=to_ZZ(1),modu=modulo(a,n),antmod=a;
	while(b!=to_ZZ(0)){
		//cout<<"modu "<<modu<<endl;
		//cout<<"r "<<r<<endl;
		if(r!=to_ZZ(0)){
			antmod=nuevomodu;
			nuevomodu=MOD((antmod*modu),n);
			//cout<<"modu "<<modu<<endl;
			//cout<<"antmod "<<antmod<<endl;
			//cout<<"nuevomod "<<nuevomodu<<endl;
		}
		modu=modulo(modu*modu,n);
		b=b/2;
		r=b%2;
	}return nuevomodu;
}





