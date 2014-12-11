/*Intentemos animar a Kepler 01 */

#include "LOpenGL.h"
#include <vector>
#include "Planeta01.hpp"

#include <fstream>


using namespace std;
vector<float> trazounox(1);
vector<float> trazounoy(1);

Planeta Tierra=Planeta();


#include "FondosyFiguras01.hpp"

void runMainLoop( int val )
{
//Si hacemos esto, val tiene el valor de frames, no de tiempo.
  val++;
  float time=(float)val/60.0;
  //Frame logic
  //  update();
  render();
  update(Tierra);    
  trazounox.push_back(Tierra.q(0));
  trazounoy.push_back(Tierra.q(1));

  glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, val );     
  
};



int main(int argc, char* args[]){

  Tierra.q(0)=0;
  Tierra.q(1)=50;

  Tierra.p(0)=3.0;
  Tierra.q(0)=0.00;

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
