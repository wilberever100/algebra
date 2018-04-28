#include <iostream>
#include<afin.h>
#include<string>
using namespace std;

int main()
{
    afin afin_;
    string b,a,nuevo;
    cout<< "escriba su frase a cifrar: ";
    getline(cin,b);
    a=afin_.cifrar(b);
    cout<< "su clave cifrada es: "<<a<<endl;
    nuevo=afin_.descifrar();
    cout<<"el descifrado es "<<nuevo<<endl;



    //a=39 b=99 mensaje:
    //b.descifrar();
    //cout<< "su clave descifrada es: "<<afin_.AUTO_descifrar(a)<<endl;//MIO

//    b="wXpBIX yhqXuPmFqEJycWGvyJjJ";
//    cout<< "su clave descifrada es: "<<afin_.descifrar(b,97,76)<<endl;//MIO

//    b="fAjOKaeSKrOjKoA AKSErONKrAbAEKeErSbSEKSNKSErOKAnRreNWbObKjSEKVAiKOKoA SNrORKoA AKESKjjO OKiAK SKjjO AKONsSjKiKSNKSErOKAnARreNWbObKNAESKaeSKEWVSKSEKnOROKSEArAKiKSEAKNObOK OE";
//    cout<< "su clave descifrada es: "<<afin_.descifrar(b,15387,8832)<<endl;//Angel

//    b="p,Lxf,S;LAcX.PcXPLR;.acT,ST.;dL PLX.a;ceP,RXPLSTLX.af dPcL PdLWPQX XSPSTdL TRe;cPdLSTL ;dL,X,;dLSTLAcX.PcXPMLA;cLT  ;NLWT.;dLacTaPcPS;LTdePLdTRRX;,LSTL TRefcPdLaPcPL,X,;dLT,L PLRfP LdTLac;a;,T,LSXdeX,e;dLeTie;dLjLYfTV;dLcT PRX;,PS;dLR;,LRPSPLf,;LSTLT  ;dNLRfjPLUX,P XSPSLTdL PL.Pj;cLSTdT,g; efcPLST L,X,;LeP,e;LP L TTcLR;.;LP LR;.acT,STcL ;L TS;Mp,Lxf,S;LAcX.PcXPLR;.acT,ST.;dL PLX.a;ceP,RXPLSTLX.af dPcL PdLWPQX XSPSTdL TRe;cPdLSTL ;dL,X,;dLSTLAcX.PcXPMLA;cLT  ;NLWT.;dLacTaPcPS;LTdePLdTRRX;,LSTL TRefcPdLaPcPL,X,;dLT,L PLRfP LdTLac;a;,T,LSXdeX,e;dLeTie;dLjLYfTV;dLcT PRX;,PS;dLR;,LRPSPLf,;LSTLT  ;dNLRfjPLUX,P XSPSLTdL PL.Pj;cLSTdT,g; efcPLST L,X,;LeP,e;LP L TTcLR;.;LP LR;.acT,STcL ;L TS;M";
//    cout<< "su clave descifrada es: "<<afin_.descifrar(b,15513,31177)<<endl;//YESSICA


    return 0;
}
