/*Clase Planeta */

#ifndef __planeta__
#define __planeta__

#include<cmath>
#include<armadillo>

using namespace std;
using namespace arma;

//Si usamos Un Sol muy grande, necesitamos Momentos muy grandes,
//Si no. caemos en pedos
const double MasaSol=1000; //Una masa Jupiter aprox=1
//G=1. (constante de Newton)


class Planeta{
private:

public:

  vec qini;
  vec pini;  
  vec lini;  
  vec q;
  vec p;
  vec l; //momento angular 
  double rhoini;
  double masa;
  
  Planeta(){
    this->qini=zeros<vec>(3);
    this->pini=zeros<vec>(3);  
    this->q=zeros<vec>(3);
    this->p=zeros<vec>(3);
    this->l=zeros<vec>(3);
    this->rhoini=0.000;   
    this->masa=1.0;

  }

  Planeta(vec qi, vec pi){
    this->qini=qi;
    this->q=qi;
    this->pini=pi;
    this->p=pi;
    this->rhoini=norm(qi);
    this->lini=cross(qi,pi);
    this->l=lini;
    this->masa=1.0;
  }


  Planeta(double qx, double qy, double qz, 
	  double px, double py,  double pz, 
	  double m){
    this->qini(0)=qx;
    this->qini(1)=qy;
    this->qini(2)=qz;
    this->q=qini;
    this->pini(0)=px;
    this->pini(1)=py;
    this->pini(2)=pz;
    this->p=pini;
    this->rhoini=norm(qini);
    this->masa=m;
  }

  
  Planeta(vec qi, vec pi, double m){
    this->qini=qi;
    this->q=qi;
    this->pini=pi;
    this->p=pi;
    this->rhoini=norm(qi);
    this->lini=cross(qi,pi);
    this->l=lini;
 
    this->masa=m;
  }


  double Kinetica(){
    double result=norm(p)*norm(p)/(2*masa);
    return result;

  }

  
  double MomRadial(){
    double pr;
    pr=dot(q,p)/norm(q);
    return pr;   
    
    }

  double rho(){
    // variable radial respetco al origen
    double r=norm(q);
    return r;
  }


  double distancia(Planeta &Dos){
    /*la distancia a otro punto en el espacio bidimensional */
    vec aux=(q-Dos.q);
    double result=norm(aux);
    return result;

  }

  /*Estas Tres funciones solo funcionan si el el Sol esta en el origen */
  vec RungeLenz(){
    vec result(3);
    vec aux(3);
    result=cross(l,p);
    aux=MasaSol/rho()*q;
    result=result-aux;
    return result;

  }

};

/*Estas Tres funciones solo funcionan si el el Sol esta en el origen */
double Hamiltoniana(Planeta & Uno){
  //energia total respecto al campo del Sol Fijo
  double result;
  result=dot(Uno.p,Uno.p)/(2*Uno.masa)-MasaSol*Uno.masa/Uno.rho();
  return result;

};

vec FuerzaSol(Planeta & Uno){
  //La fuerza debida al Sol
  vec Fuerza(3);
  double r=Uno.rho();
  //q cout<<r<<endl;
  Fuerza=((-MasaSol*Uno.masa)/(r*r*r))*Uno.q;
  return Fuerza;
  

}

/**Funciones mas generales **/
  double Potencial(Planeta &Uno, Planeta &Dos){
  double rr=Uno.distancia(Dos);  
  double result=Uno.masa*Dos.masa/rr;
  return result;
  
}
  
double Hamiltoniana(Planeta &Uno, Planeta &Dos, Planeta &Tres){
  double result;
  result=Uno.Kinetica()+Dos.Kinetica()+Tres.Kinetica()-
    (Potencial(Uno,Dos)+Potencial(Dos,Tres)+Potencial(Tres,Uno));
  return result;

}

vec Fuerza(Planeta &Uno, Planeta &Dos){
  //La fuerza experimentada por uno debida a Dos. 
  //para la otra, basta el negativo de la primera.
  vec Fuerza(3);
  double r=Uno.distancia(Dos);
  vec posicionrelativa;
  posicionrelativa=Uno.q-Dos.q;
  //q cout<<r<<endl;
  Fuerza=((-Dos.masa*Uno.masa)/(r*r*r))*posicionrelativa;
  return Fuerza;
  
}


#endif
