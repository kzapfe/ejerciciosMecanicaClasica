/*Problema Sol Tierra Luna  Planar*/
#include "Planeta01.hpp"
#include <fstream>



int main() {

  
  vec pos(2), mom(2);
  ofstream orbitasol, orbitajupiter,orbitaeuro;
  double masa;
  orbitasol.open("OrbitaSol.dat");
  orbitajupiter.open("OrbitaJupiter.dat");
  orbitaeuro.open("OrbitaEuropa.dat");

  //iniciamos tres planetas.

  pos(0)=0.0;
  pos(1)=-80.0;  
  mom(0)=-600.0;
  mom(1)=0.0;
  masa=1000; //
  Planeta Sol=Planeta(pos, mom,masa);
    
  pos(0)=0.0;
  pos(1)=50.0;
  mom(0)=600.0;
  mom(1)=0.0;
  masa=1000; //

  Planeta Jupiter=Planeta(pos, mom,masa);
  
  pos(0)=100;
  pos(1)=0.0;
  mom(0)=0.0;
  mom(1)=+2.0;
  masa=1; //

  Planeta Europa=Planeta(pos, mom,masa);

  
  cout<<"Energia Inicial="<<Hamiltoniana(Sol, Jupiter, Europa)<<endl;

  int tmax=1000000;
  double dt=0.00025;
  vec patada(2), desplazamiento(2);
  //menos llamadas a las subrutinas
  vec fuerzita1(2),fuerzita2(2),fuerzita3(2);

  
  for(int t=0; t<tmax; t++){

    fuerzita1=Fuerza(Sol,Jupiter);
    fuerzita2=Fuerza(Sol,Europa);
    fuerzita2=Fuerza(Jupiter,Europa);
    
    patada=dt*(fuerzita1+fuerzita2);
    Sol.p+=patada;

    patada=dt*(-fuerzita1+fuerzita3);
    Jupiter.p+=patada;
        
    patada=dt*(-fuerzita2-fuerzita3);
    Europa.p+=patada;

    desplazamiento=dt*Sol.p/Sol.masa;
    Sol.q+=desplazamiento;

    desplazamiento=dt*Jupiter.p/Jupiter.masa;
    Jupiter.q+=desplazamiento;
    
    desplazamiento=dt*Europa.p/Europa.masa;
    Europa.q+=desplazamiento;



    if(t%250==0){
    orbitasol<<Sol.q(0)<<"\t"<<Sol.q(1)<<
      "\t"<<Sol.p(0)<<"\t"<<Sol.p(1)<<"\t"
	   <<Sol.MomRadial()<<endl;
    
    orbitajupiter<<Jupiter.q(0)<<"\t"<<Jupiter.q(1)<<
      "\t"<<Jupiter.p(0)<<"\t"<<Jupiter.p(1)<<"\t"
	   <<Jupiter.MomRadial()<<endl;

    orbitaeuro<<Europa.q(0)<<"\t"<<Europa.q(1)<<
      "\t"<<Europa.p(0)<<"\t"<<Europa.p(1)<<"\t"
	   <<Europa.MomRadial()<<endl;

    }

  }

  
  cout<<"Energia Final="<<Hamiltoniana(Sol, Jupiter, Europa)<<endl;
  
    

  return 0;

}

