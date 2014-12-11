#include "LOpenGL.h"
#include "circuloopengl.hpp"

#include <iostream>

/*Me gusta todo mas en un solo archivo
//hpp que en uno h y otro cpp.  
//se me hace mucha mamada.
//Por supuesto que con tu convencion la documentacion queda menos clara.
// Pero para tus propositos es suficiente */

//Screen Constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int SCREEN_FPS = 60;
const float TimeStep=0.5f/SCREEN_FPS;


//Color modes
//Trazar la cola del disco.
bool trazo=false;
bool cuadrados=false;

//Centros y velocidades de los discos

float r1;
float border=10/2.0;


bool initGL()
{

  glutSetWindow(1);
  //Initialize Projection Matrix
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();

  double auxborder=110;
  
  glOrtho( -auxborder-0.5, auxborder, -auxborder-0.5, auxborder, 1.0, -1.0 );
  
  
  //Initialize Modelview Matrix
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  //Initialize clear color
  glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
  // rojo, verde, azul y alfa. 
  //Valore entre 0 y 1 punto flotante.

  

  //Check for error
  GLenum error = glGetError();
  if( error != GL_NO_ERROR )
    {
      printf( "Muere, no pude inicializar OpenGL!! %s\n", gluErrorString( error ) );
      return false;
    };
  
  return true;
};



void update( Planeta & Uno, Planeta & Dos, Planeta &Tres )
{
  
  vec patada(2),desplazamiento(2);
  int pasos=240;
  
  double dt=0.0005;
  
  //menos llamadas a las subrutinas
  vec fuerzita1(2),fuerzita2(2),fuerzita3(2);

  for (int k=0; k<pasos;k++){

    
    fuerzita1=Fuerza(Uno,Dos);
    fuerzita2=Fuerza(Uno,Tres);
    fuerzita2=Fuerza(Dos,Tres);
    
    patada=dt*(fuerzita1+fuerzita2);
    Uno.p+=patada;

    patada=dt*(-fuerzita1+fuerzita3);
    Dos.p+=patada;
        
    patada=dt*(-fuerzita2-fuerzita3);
    Tres.p+=patada;

    desplazamiento=dt*Uno.p/Uno.masa;
    Uno.q+=desplazamiento;

    desplazamiento=dt*Dos.p/Dos.masa;
    Dos.q+=desplazamiento;
    
    desplazamiento=dt*Tres.p/Tres.masa;
    Tres.q+=desplazamiento;
  
 
  }

};


void render()
{ 
  glutSetWindow(1);
  //Clear color buffer
  glClear( GL_COLOR_BUFFER_BIT );

  //Reset modelview matrix
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  

  glLineWidth(1.0) ; 
  
  /*dibujamos tres planetas*/

  float r2=5;

  glColor3f( 0.98f, 0.81f, 0.2f );
  DrawDisk(Sol.q(0), Sol.q(1), r2, 50);
  

  glColor3f( 0.89f, 0.12f, 0.2f );
  DrawDisk(Jovis.q(0), Jovis.q(1), r2, 50);
  
  
  glColor3f( 0.3f, 0.12f, 0.9f );
  DrawDisk(Luna.q(0), Luna.q(1), 1, 50);
  
  
 
  if( trazo ){
    glColor4f( 0.98f, 0.90f, 0.05f, 0.4f );
    glLineWidth(2.0) ;
    glBegin(GL_LINES);    
    for(int i=1; i<trazosolx.size();i++){
      glVertex2f(trazosolx[i-1], trazosoly[i-1]);//output vertex           
      glVertex2f(trazosolx[i], trazosoly[i]);//output vertex           
    };
    glEnd();
    
    glColor4f( 0.87f, 0.1f, 0.021f, 0.4f );
    glLineWidth(2.0) ;
    glBegin(GL_LINES);    
    for(int i=1; i<trazosolx.size();i++){
      glVertex2f(trazojovisx[i-1], trazojovisy[i-1]);//output vertex           
      glVertex2f(trazojovisx[i], trazojovisy[i]);//output vertex           
    };
    glEnd();


    glColor4f( 0.7f, 0.7f, 0.9f, 0.4f );
    glLineWidth(2.0) ;
    glBegin(GL_LINES);    
    for(int i=1; i<trazosolx.size();i++){
      glVertex2f(trazolunax[i-1], trazolunay[i-1]);//output vertex           
      glVertex2f(trazolunax[i], trazolunay[i]);//output vertex           
    };
    glEnd();
    


  };


  
  //Update screen 1
  glutSwapBuffers();
  
};


void handleKeys( unsigned char key, int x, int y ){
  //If the user presses q
  
  //  if( key == 'x' )glutLeaveMainLoop();
  
  // if(GLUT_ACTION_ON_WINDOW_CLOSE)glutLeaveMainLoop();
  
  
  if( key == 't' ){
    trazo=!trazo;   
    };
  
  
  if( key == 'p' ){
    //stop;
    };
 

};  
  

