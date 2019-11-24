#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double dx, dy, d1, d2, x, y;
double rx, ry, xc=50, yc=50;

float round_value(float v)
{
  return floor(v + 0.5);
}

void midptellipse() 
{   
  
    x = 0; 
    y = ry; 
  
    // Initial decision parameter of region 1 
    d1 = (ry * ry) 
         - (rx * rx * ry) 
         + (0.25 * rx * rx); 
    dx = 2 * ry * ry * x; 
    dy = 2 * rx * rx * y; 

   glClear(GL_COLOR_BUFFER_BIT);
    
   glBegin(GL_POINTS);
    while (dx <= dy) { 
  
         
       glVertex2d(x + xc, y + yc); 
       glVertex2d(-x + xc, y + yc); 
       glVertex2d(x + xc, -y + yc); 
       glVertex2d(-x + xc, -y + yc); 
  
        
        if (d1 < 0) { 
            x++; 
            dx = dx + (2 * ry * ry); 
            d1 = d1 + dx + (ry * ry); //pk+1
        } 
        else { 
            x++; 
            y--; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d1 = d1 + dx - dy + (ry * ry); //pk+1
        } 
    } 
  
  
    // Decision parameter of region 2 
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) 
         + ((rx * rx) * ((y - 1) * (y - 1))) 
         - (rx * rx * ry * ry); 
  
    
    while (y >= 0) { 
  
        
        glVertex2d(x + xc, y + yc); 
        glVertex2d(-x + xc, y + yc); 
        glVertex2d(x + xc, -y + yc); 
        glVertex2d(-x + xc, -y + yc); 
  
        
        if (d2 > 0) { 
            y--; 
            dy = dy - (2 * rx * rx); 
            d2 = d2 + (rx * rx) - dy; 
        } 
        else { 
            y--; 
            x++; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d2 = d2 + dx - dy + (rx * rx); 
        } 
    }
   glEnd(); 
   glFlush();

} 



void Init()

{

  /* Set clear color to white */

  glClearColor(0.0,0.8,0.4,0);

  /* Set fill color to black */

  glColor3f(0.0,0.0,0.0);

  /* glViewport(0 , 0 , 640 , 480); */

  /* glMatrixMode(GL_PROJECTION); */

  /* glLoadIdentity(); */

  gluOrtho2D(-640 , 640 , -640 , 640);

}

int main(int argc, char **argv)

{

 printf("\nEnter minor radius( X1 , Y1):\n");
 scanf("%lf",&rx);

 printf("\nEnter major radius( X1 , Y1):\n");
 scanf("%lf",&ry);

// printf("\nEnter Point1( X1 , Y1):\n");
 //scanf("%lf",&xc);

 //printf("\nEnter Point1( X2 , Y2):\n");
 //scanf("%lf",&yc);

  

  /* Initialise GLUT library */

  glutInit(&argc,argv);

  /* Set the initial display mode */

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  /* Set the initial window position and size */

  glutInitWindowPosition(0,0);

  glutInitWindowSize(640,480);

  /* Create the window with title "DDA_Line" */

  glutCreateWindow("Ellipse");

  /* Initialize drawing colors */

  Init();

  /* Call the displaying function */

  glutDisplayFunc(midptellipse);

  /* Keep displaying untill the program is closed */

  glutMainLoop();

}
