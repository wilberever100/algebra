#include <iostream>
int resto_chino(vector<int> a, vector<int> p){
    int acum=1,acumsuma=0;
    vector<int>q,pes;
    for(int elemento:p){
        acum=acum*elemento;
    }
    for(int i=0;i<p.size();i++){
        pes.push_back(acum/p[i]);
        q.push_back(mod_inverso(acum/p[i],p[i]));
    }

    for(int i=0;i<p.size();i++){

        acumsuma=modulo(acumsuma+modulo((modulo(a[i],acum)*modulo(pes[i],acum)*modulo(q[i],acum)),acum),acum);
    }



    return acumsuma;
}
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
