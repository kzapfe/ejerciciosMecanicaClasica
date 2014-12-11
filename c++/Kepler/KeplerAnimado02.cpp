/*Intentemos animar a Kepler 02_
 Pongamos una marejada de Planetas ahora*/

#include "LOpenGL.h"
#include <vector>
#include "Planeta01.hpp"

#include <fstream>


using namespace std;

//numero de sombras
const int numsom=20;
vector<float> trazounox(1);
vector<float> trazounoy(1);

vector<float> trazosx[numsom];
vector<float> trazosy[numsom];



Planeta Tierra=Planeta();

Planeta *Sombra;

#include "FondosyFiguras02.hpp"

void runMainLoop( int val )
{
//Si hacemos esto, val tiene el valor de frames, no de tiempo.
  val++;
  float time=(float)val/60.0;
  //Frame logic
  //  update();
  render();
  update(Tierra, Sombra);    
  trazounox.push_back(Tierra.q(0));
  trazounoy.push_back(Tierra.q(1));
  for(int j=0; j<numsom; j++){
    trazosx[j].push_back(Sombra[j].q(0));
    trazosy[j].push_back(Sombra[j].q(1));
  }

  glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, val );     
  
};



int main(int argc, char* args[]){

  

  Tierra.q(0)=0;
  Tierra.q(1)=60;

  Tierra.p(0)=3.5;
  Tierra.q(0)=0.00;


  double MomentoInicial=norm(Tierra.p);
  double VariacionAngular=datum::pi/5.0;
  cout<<VariacionAngular<<endl;
  double angulito=0.0;
  Sombra=new Planeta[numsom];

  for(int j=0; j<numsom; j++){
    Sombra[j].q(0)=Tierra.q(0);
    Sombra[j].q(1)=Tierra.q(1);
    angulito=-VariacionAngular+(2.0*j)*VariacionAngular/numsom;
    Sombra[j].p(0)=MomentoInicial*cos(angulito);
    Sombra[j].p(1)=MomentoInicial*sin(angulito);
    //  cout<<"Test\t"<<Sombra[j].q<<endl;

  }
    

  

  //Argumentos posibles para iniciar freeglut
  glutInit( &argc, args );

  // Create OpenGL 2.1 context
  glutInitContextVersion( 2, 1 );

  //Create Double Buffered Window
  glutInitDisplayMode( GLUT_DOUBLE );
  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutCreateWindow( "Animales en su territorio" );
  glutPositionWindow(701,0);
  
    //Do post window/context creation initialization
    if( !initGL() )
    {
      printf( "Tienes panchos con GLUT!\n" );
      return 1;
    };

 
  ofstream orbitas;
  
  orbitas.open("Test01.dat");
  
  trazounox[0]=Tierra.q(0);
  trazounoy[0]=Tierra.q(1);
  for(int j=0; j<numsom; j++){
    trazosx[j].push_back(Sombra[j].q(0));
    trazosy[j].push_back(Sombra[j].q(1));
  }

  

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
