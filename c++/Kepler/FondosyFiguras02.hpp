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

  double auxborder=70;
  
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



void update( Planeta & Uno, Planeta *Varios)
{
  
  vec patada(2),desplazamiento(2);
  int pasos=30;
  double dt=4.0/(pasos*SCREEN_FPS);



  for (int k=0; k<pasos;k++){
  patada=dt*FuerzaSol(Uno);
  Uno.p+=patada;
  
  desplazamiento=dt*Uno.p;
  Uno.q+=desplazamiento;
  
  for (int j=0; j<numsom;j++){
      
      patada=dt*FuerzaSol(Varios[j]);
      Varios[j].p+=patada;
  
      desplazamiento=dt*Varios[j].p;
      Varios[j].q+=desplazamiento;
    
  }

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


  //dibujamos el SOL
  glLineWidth(1.0) ;
  glColor3f( 0.99f, 0.90f, 0.02f );
  DrawDisk(0, 0, 6.66, 50);

  float r2=1;

  glColor3f( 0.3f, 0.12f, 0.9f );
  DrawDisk(Tierra.q(0), Tierra.q(1), r2, 50);
  float aux1;
  float aux2;

  for(int j=0; j<numsom; j++){
    aux1=0.99*j/numsom;  
    aux2=sin((6.28*j)/numsom);
    aux2=aux2*aux2;
 
    glColor3f(aux2, 0.4, aux1 );
    DrawDisk(Sombra[j].q(0), Sombra[j].q(1), r2/2, 50);    
  }


 
  if( trazo ){
    glColor4f( 0.7f, 0.2f, 0.3f, 0.4f );
    glLineWidth(2.0) ;
    glBegin(GL_LINES);    
    for(int i=1; i<trazounox.size();i++){
      glVertex2f(trazounox[i-1], trazounoy[i-1]);//output vertex           
      glVertex2f(trazounox[i], trazounoy[i]);//output vertex           
    };
    glEnd();


    for(int j=0; j<numsom;j++){
       
      aux1=0.99*j/numsom;  
      aux2=sin((6.28*j)/numsom);
      aux2=aux2*aux2;
 

      glColor4f( aux2, 0.2f, aux1, 0.4f );
      glLineWidth(1.0) ;
      glBegin(GL_LINES);    
    
      for(int i=1; i<trazosx[0].size(); i++){
	glVertex2f(trazosx[j][i-1], trazosy[j][i-1]);//output vertex           
	glVertex2f(trazosx[j][i], trazosy[j][i]);//output vertex           
      };
      glEnd();
    }
    
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
  

