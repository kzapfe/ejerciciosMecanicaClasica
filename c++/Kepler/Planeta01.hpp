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
  vec q;
  vec p;
  double thetaini;
  double rhoini;
  double masa;
  
  Planeta(){
    this->qini=zeros<vec>(2);
    this->pini=zeros<vec>(2);  
    this->q=zeros<vec>(2);
    this->p=zeros<vec>(2);
    this->thetaini=0.00;
    this->rhoini=0.000;
   
    this->masa=1.0;

  }

  Planeta(vec qi, vec pi){
    this->qini=qi;
    this->q=qi;
    this->pini=pi;
    this->p=pi;
    this->rhoini=sqrt(qi(0)*qi(0)+qi(1)*qi(1));
    this->thetaini=atan2(qi(1), qi(0));
    this->masa=1.0;
  }


  Planeta(double qx, double qy, double px, double py,  double m){
    this->qini(0)=qx;
    this->qini(1)=qy;
    this->q=qini;
    this->pini(0)=px;
    this->pini(1)=py;
    this->p=pini;
    this->rhoini=norm(qini);
    this->thetaini=atan2(qy, qx);
    this->masa=m;
  }

  
  Planeta(vec qi, vec pi, double m){
    this->qini=qi;
    this->q=qi;
    this->pini=pi;
    this->p=pi;
    this->rhoini=sqrt(qi(0)*qi(0)+qi(1)*qi(1));
    this->thetaini=atan2(qi(1), qi(0));
    this->masa=m;
  }


  double Kinetica(){
    double result=norm(p)*norm(p)/(2*masa);
    return result;

  }

 
  double MomAngular(){
    //momento angular respecto al origen (Sol)
    double l=q(0)*p(1)-q(1)*p(0);
    return l;
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

  double theta(){
    double t=atan2(q(1),q(0));
    return t;
  }

  double distancia(Planeta &Dos){
    /*la distancia a otro punto en el espacio bidimensional */
    vec aux=(q-Dos.q);
    double result=norm(aux);
    return result;

  }

  /*Estas Tres funciones solo funcionan si el el Sol esta en el origen */
  vec RungeLenz(){
    vec result(2);
    vec aux(2);
    result(0)=p(1)*MomAngular();
    result(1)=-p(0)*MomAngular();
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
  vec Fuerza(2);
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
  vec Fuerza(2);
  double r=Uno.distancia(Dos);
  vec posicionrelativa;
  posicionrelativa=Uno.q-Dos.q;
  //q cout<<r<<endl;
  Fuerza=((-Dos.masa*Uno.masa)/(r*r*r))*posicionrelativa;
  return Fuerza;
  
}


#endif
