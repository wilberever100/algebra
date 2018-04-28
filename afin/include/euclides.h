#include <iostream>
#include<vector>
using namespace std;

int MOD(int a,int b){
    int r=a-(a/b)*b;
	if(r<0){
		r=r+b;
	}
	return r;
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
