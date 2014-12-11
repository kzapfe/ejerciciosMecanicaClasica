//#include "LOpenGL.h"
//Supon que seguro necesitas esos headers. 
//#include <math.h>

void DrawCircle(float cx, float cy, float r, int num_segments)
{ 
  float theta = 2 * 3.1415926 / float(num_segments); 
  float tangetial_factor = tan(theta);//calculate the tangential factor 

	float radial_factor = cos(theta);//calculate the radial factor 
	
	float x = r;//we start at angle = 0 

	float y = 0; 
    
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		glVertex2f(x + cx, y + cy);//output vertex 
        
		//calculate the tangential vector 
		//remember, the radial vector is (x, y) 
		//to get the tangential vector we flip 
		//those coordinates and negate one of them 

		float tx = -y; 
		float ty = x; 
        
		//add the tangential vector 

		x += tx * tangetial_factor; 
		y += ty * tangetial_factor; 
        
		//correct using the radial factor 

		x *= radial_factor; 
		y *= radial_factor; 
       }; 
      glEnd(); 
};

void DrawDisk(float cx, float cy, float r, int num_segments) 
{ 
         float theta = 2 * 3.1415926 / float(num_segments); 
float tangetial_factor = tan(theta);//calculate the tangential factor 
 
	float radial_factor = cos(theta);//calculate the radial factor 
	
	float x = r;//we start at angle = 0 

	float y = 0; 
    
	glBegin(GL_TRIANGLE_FAN); 
for(int ii = 0; ii < num_segments; ii++) 
	  { 

		glVertex2f(x + cx, y + cy);//output vertex 

        
		//calculate the tangential vector 
		//remember, the radial vector is (x, y) 
		//to get the tangential vector we flip 
		//those coordinates and negate one of them 

		float tx = -y; 
		float ty = x; 
        
		//add the tangential vector 

		x += tx * tangetial_factor; 
		y += ty * tangetial_factor; 
        
		//correct using the radial factor 

		x *= radial_factor; 
		y *= radial_factor; 
	} 
	glEnd(); 
};
