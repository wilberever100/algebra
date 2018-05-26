#include <iostream>
#include<vector>
using namespace std;



int digitos(int a){
    int dig=1;
    while(a/10>0)
    {
        a=a/10;
        dig++;
    }return dig;
}

int MOD(int a,int b){
    int r=a-(a/b)*b;
	if(r<0){
		r=r+b;
	}
	return r;
}
int factor(int numero){
	int i=2;
	while(i<=numero)
	{
		if(MOD(numero,i)==0)  //a%b=0, implica que b es factor de a.
		{
			return i;
		}
		i++;  //Incrementamos indice.
	}
}
int modulo(int a,int b){
	int r=a-(a/b)*b;
	if(r<0){
		r=r+b;
	}
	return r;
}

int mod_inverso(int a,int b){
	int p0=0,p1=1,pn=0,q,cont=0,total;
	int r=a,modin=b;

	if((modulo(b,a))==0){return 0;}

	else{
        r=modulo(a,b);
        while(r>1){
            cont=cont+1;
            total=b;
            b=r;
            q=(total/b);
            r=modulo(total,b);
            pn=modulo((p0-p1*q),modin);
            p0=p1;
            p1=pn;
        }
        if(r!=1){return 0;}
	}
	return pn;
}


bool esprimo(int n){
    int a=0;
    for(int i=1;i<(n+1);i++){
         if(n%i==0){
             a++;
            }
         }
         if(a!=2){
            return false;
         }else{return true;};
}
int mcd(int dividendo,int divisor){
    int residuo=MOD(dividendo,divisor);
    while(residuo>0){
        dividendo=divisor;
        divisor=residuo;
        residuo=MOD(dividendo,divisor);
    }
    return divisor;
}
int potencia(int a, int b){
    int r=b%2,acum=1,anterior=a,mult;
    while(b!=0){
        if(r!=0){
            acum=anterior*acum;

        }

        mult=anterior*anterior;
        anterior=mult;
        b=b/2;
        r=b%2;
    }return acum;
}
int potenciamod(int a, int b,int n){
	long int r=b%2,nuevomodu=1,modu=MOD(a,n),antmod=a;
	while(b!=0){
		//cout<<"modu "<<modu<<endl;
		//cout<<"r "<<r<<endl;
		if(r!=0){
			antmod=nuevomodu;
			nuevomodu=MOD((antmod*modu),n);
			//cout<<"modu "<<modu<<endl;
			//cout<<"antmod "<<antmod<<endl;
			//cout<<"nuevomod "<<nuevomodu<<endl;
		}
		modu=MOD(modu*modu,n);
		b=b/2;
		r=b%2;
	}return nuevomodu;
}

int* euclides_extendido(int a,int b){
     int* result=new int[3];

    int x=0,y=0;
    if(b==0)
    {
    result[0]=1;result[1]=0;result[2]=0;
    }
    else
    {
        int x2 = 1, x1 = 0, y2 = 0, y1 = 1;
        int q = 0, r = 0;
        while(b>0)
        {
           q = (a/b);
           r = a - q*b;
           x = x2-q*x1;
           y = y2 - q*y1;

           a = b;
           b = r;
           x2 = x1;
           x1 = x;
           y2 = y1;
           y1 = y;


        }
        result[0]=x2;
        result[1]=y2;
        result[2]=a;
    }
     return result;
}
