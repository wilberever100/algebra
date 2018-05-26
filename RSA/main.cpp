#include <iostream>
#include<afin.h>
#include<string>
using namespace std;

int main()
{

    string b,a,nuevo,c;
    //cout<< "escriba su frase a cifrar: ";
    //getline(cin,b);
    //b="La encriptación o cifrado de archivos, es un procedimiento que vuelve completamente ilegibles los datos de un documento o de cualquier archivo. De esta manera, el archivo se vuelve prácticamente inservible para un usuario no autorizado a leerlo, ya que incluso si lo ha interceptado o lo ha copiado, si no cuenta con el password correspondiente, no podrá leerlo o visualizarlo.";
    b="AB C182";
    //a=afin_.cifrar(b);
    //cout<< "su clave cifrada es: "<<a<<endl;
    afin afin_(3,1003);
    c=afin_.cifrar(b);
    cout<<c<<endl;
    cout<<afin_.descifrar(c)<<endl;
    //c="Rc2v QjIR cQIl 2I2QIUjchI2hv2cjQvI_IUA2vU2X 2RjIQvhIPIv  I2kXv2_Xvy_v2QIPRyv cPv  v2Iyv,IEyvU2yIU2hc IU2hv2X 2hIQXPv  I2I2hv2QXcykXIvj2cjQvI_IM2ov2vU c2Pc vjcA2vy2cjQvI_I2Uv2_Xvy_v2RjlQ IQcPv  v2I Uvj_IEyv2Rcjc2X 2XUXcjII2 I2cX IjIochI2c2yvvjyIA2bc2kXv2I QyXUI2UI2yI2vc2I  vjQvR chI2I2yI2vc2QIRIchIA2UI2 I2QXv  c2QI 2vy2RcUUQIjh2QIjjvURI hIv  vA2 I2RIhjl2yvvjyI2I2_IUXcyIocjyIM";

    //c="ABa";
    //afin afina_(c,18,731);

    //c="YxSfh-qphe..Qhf.hq8hWfh,..STh,zxQ.Qhq8huzxgy7pohezShxhGyxpo.hLpQhWh-,78h-zf.hVz7,hx9xThv9x,,z9.Qhez,,z9.QhM.x Thx6zqgh. .STgy7poh6qghfTh,z .hv9x,,z9.Qh-zSSz9.QhWfh97gyh. .STzp.hxpQhT.ghpzghWfh97gyh. .STzp.hxpQhT.ghpzghWfh97gyh. .STzp.hxpQhT.ghpzghaq-gh9xpg.Qhgzh6.hfT-.,ehM.ThTzqh-x7QhTzqh9zq,Qh,z .hgzhgSTh-zf.hM.ThTzqh-x7QhTzqh9zq,Qh,z .hgzhQ7.h-zf.hWphgy.hf7QQ,.hzehxh9zS,Qhzphxhe7-yyzzRhmzqS.hgy.h9x .hmzqS.hgy.h9x .hmzqS.hgy.h9x .hv9x,,z9.Qh6zSSz9.QhM.x Thx6zqgh. .STgy7poh6qghfTh,z .hv9x,,z9.Qhyz,,z9.QhvyxS8hx6zqgh. .STzp.h6qghTzqS-.,ehv9x,,z9.QhzyhpzhWfh97gyh. .STzp.hxpQhT.ghpzghWfh97gyh. .STzp.hxpQhT.ghpzghWfh97gyh. .STzp.hxpQhTzqBS.hpzghWBfh97gyh. .STzp.hxpQhT.ghX7--hzph-.,eh.-g..fh2zS9xSQh6q-g.QhRp..hv7GRhy.xQhV,xGR.p.Qh,qpo-hLpQhWfhxh-7f8,.h-.,e7-yh-zphv9x,,z9.Qhez,,z9.QhM.x Thx6zqgh. .STgy7poh6qghfTh,z .hv9x,,z9.QhzyhpzhWfh97gyh. .STzp.hxpQhT.ghpzghWfh97gyh. .STzp.hxpQhT.ghpzghWfh97gyh. .STzp.hxpQhT.ghpzghCzghgzho.ghx9xTheSzfhy.S.hCzghgzho.ghx9xTheSzfhy.S.hCzghgzho.ghx9xTheSzfhy.S.hCzghgzho.ghx9xTheSzfhy.S.hWhf7--hgy.hzp.hgyxghWh,z .hxh,zghWhf7--hgy.hzp.hgyxghWh,z .hxh,zghWhf7--hgy.hzp.hgyxghWh,z .hxh,zghWh,z .hXxgS7GRhcx 7.Sh3xSIq._h)yzIq.h0i0P0rPKsAUK";
    //c="316969313177331DpWpZipCpZoe8ZCbZl8vZpl.8WTPF8vZipliolbZblZFpBTF8Zi8FoeZCTITv8WZ_pWpZl8vZbePbW8vZkSrZaZrdy(WbplT4peC8ZoeZvb.oTFTbeP8ZeoFbWTi8ZFpeopl(ZTeCTipeC8ZlpZIpWTpiT8eZCbZlpvZIpWTpJlbvZ_pv8ZpZ_pv89JQZ3F_lbFbePbZipCpZoe8ZCbZl8vZpl.8WTPF8v9ZqobvPWbZ_8WZ_pePpllpZl8vZWbvolPpC8vZ_pv8";
    //c="ny8yQfy3yQEe2Q3SQx2XQyx928rqL2XQfyxfExSQSxQLyKrL2Qf2LEeQ3r_rX28QRy8yQx2XQSeqS82XQD7WQdQWvjAQ8Syxr1ye32QEeQXS9ErLrSeq2QeELS8rf2QLyeEyxAQre3rfye32QxyQ_y8ryfr2eQ3SQxyXQ_y8ryMxSXQRyX2QyQRyX2";


    //c="RpZbeiWT_PpiT0eZ8ZiT5WpC8ZCbZpWizTI8v(ZbvZoeZ_W8ibCTFTbeP8Z1obZIoblIbZi8F_lbPpFbePbZTlb.TJlbvZl8vZCpP8vZCbZoeZC8ioFbeP8Z8ZCbZiopl1oTbWZpWizTI89ZnbZbvPpZFpebWp(ZblZpWizTI8ZvbZIoblIbZ_W0iPTipFbePbZTevbWITJlbZ_pWpZoeZovopWT8Ze8ZpoP8WT4pC8ZpZlbbWl8(ZapZ1obZTeilov8ZvTZl8ZzpZTePbWib_PpC8Z8Zl8ZzpZi8_TpC8(ZvTZe8ZiobePpZi8eZblZ_pvvh8WCZi8WWbv_8eCTbePb(Ze8Z_8CW0ZlbbWl8Z8ZITvoplT4pWl89";
    //nuevo=afin_.descifrar(c,31,21);
    //cout<<"el descifrado es "<<a<<endl;





    return 0;
}

