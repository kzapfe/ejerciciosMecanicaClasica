/*Intentemos animar a Kepler 02_
 Pongamos una marejada de Planetas ahora*/

#include "LOpenGL.h"
#include <vector>
#include "Planeta01.hpp"

#include <fstream>


using namespace std;

//numero de sombras
//const int numsom=20;
vector<float> trazosolx(1);
vector<float> trazosoly(1);

vector<float> trazojovisx(1);
vector<float> trazojovisy(1);

vector<float> trazolunax(1);
vector<float> trazolunay(1);


//vector<float> trazosx[numsom];
//vector<float> trazosy[numsom];


Planeta Sol,Jovis,Luna;


#include "FondosyFiguras03.hpp"

void runMainLoop( int val )
{
//Si hacemos esto, val tiene el valor de frames, no de tiempo.
  val++;
  float time=(float)val/60.0;
  //Frame logic
  //  update();
  render();
  update(Sol,Jovis,Luna);    
  trazosolx.push_back(Sol.q(0));
  trazosoly.push_back(Sol.q(1));
  
  trazojovisx.push_back(Jovis.q(0));
  trazojovisy.push_back(Jovis.q(1));
  
  trazolunax.push_back(Luna.q(0));
  trazolunay.push_back(Luna.q(1));
 


  glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, val );     
  
};



int main(int argc, char* args[]){

  vec pos(2), mom(2);
  ofstream orbitasol, orbitajupiter,orbitaeuro;
  double masa;
  /*orbitasol.open("OrbitaSol.dat");
  orbitajupiter.open("OrbitaJupiter.dat");
  orbitaeuro.open("OrbitaEuropa.dat");
  */
  //iniciamos tres planetas.

  pos(0)=0.0;
  pos(1)=-80.0;  
  mom(0)=-700.0;
  mom(1)=0.0;
  masa=1000; //
  Sol=Planeta(pos, mom,masa);
  
  
  pos(0)=0.0;
  pos(1)=50.0;
  mom(0)=700.0;
  mom(1)=0.0;
  masa=1000; //

  Jovis=Planeta(pos, mom,masa);
  
  pos(0)=100;
  pos(1)=0.0;
  mom(0)=-0.0;
  mom(1)=+2.0;
  masa=1; //

  Luna=Planeta(pos, mom,masa);
  

  //Argumentos posibles para iniciar freeglut
  glutInit( &argc, args );

  // Create OpenGL 2.1 context
  glutInitContextVersion( 2, 1 );

  //Create Double Buffered Window
  glutInitDisplayMode( GLUT_DOUBLE );
  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutCreateWindow( "Planetas 3 Cuerpos" );
  glutPositionWindow(701,0);
  
    //Do post window/context creation initialization
    if( !initGL() )
    {
      printf( "Tienes panchos con GLUT!\n" );
      return 1;
    };

 
  ofstream orbitas;
  
  orbitas.open("Test01.dat");
  
  trazosolx[0]=Sol.q(0);
  trazosoly[0]=Sol.q(1);

  
  trazojovisx[0]=Jovis.q(0);
  trazojovisy[0]=Jovis.q(1);

  
  trazolunax[0]=Luna.q(0);
  trazolunay[0]=Luna.q(1);

  

  //Inicializar las cosas que va hacer freeglut.
  //Set keyboard handler 
  glutKeyboardFunc( handleKeys );  
  //Set rendering function
  glutDisplayFunc( render );
 
  //Set main loop
  glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, 0 );
  //Start GLUT main loop
  glutMainLoop();
   


  return 0;

}
