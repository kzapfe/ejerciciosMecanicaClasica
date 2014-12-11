

#include "Planeta01.hpp"
#include <fstream>


int main() {

  
  vec pos(2), mom(2);
  ofstream orbitas;
  orbitas.open("Orbitas.dat");

  pos(0)=0.0;
  pos(1)=100.0;

  
  mom(0)=3.0;
  mom(1)=0.0;


  Planeta Tierra=Planeta(pos, mom);
  
  
  cout<<"RungeLenz Vector"<<Tierra.RungeLenz()<<endl;
  
  cout<<"Energia="<<Hamiltoniana(Tierra)<<endl;

  int tmax=350000;
  double dt=0.0025;
  vec patada(2), desplazamiento(2);
  
  for(int t=0; t<tmax; t++){

    patada=dt*FuerzaSol(Tierra);
    Tierra.p+=patada;

    desplazamiento=dt*Tierra.p;
    Tierra.q+=desplazamiento;

    if(t%25==0){
    orbitas<<Tierra.q(0)<<"\t"<<Tierra.q(1)<<
      "\t"<<Tierra.p(0)<<"\t"<<Tierra.p(1)<<"\t"
	   <<Tierra.MomRadial()<<endl;}

  }

  
  cout<<"RungeLenz Vector"<<Tierra.RungeLenz()<<endl;
  cout<<"Energia="<<Hamiltoniana(Tierra)<<endl;
    

  return 0;

}

