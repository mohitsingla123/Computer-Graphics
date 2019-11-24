// To emulate the scan conversion of graphical primitive circle and ellipse
//1.Two points A and B are acquired through random mouse clicks on a window
// a. Considering a as center scan convert a circle having a radius of length AB(Use bresnhams algorithm)
// b. Manipulate the location of B using a key press event to generate varying size circles
// glutKeyboardFunc(keyFunc);
// void keyFunc(GLubyte key, GLint xMouse , GLint yMouse)

#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;


void init(void)
{
 glClearColor(1.0,1,1,1.0);
 glMatrixMode(GL_PROJECTION);
 glClear(GL_COLOR_BUFFER_BIT);
 gluOrtho2D(-250,250,-250,250);
}
int i=1;
float x1,yy;
float xval, yval;
int xarr[2];
int yarr[2];

//function to plot the point
void plotPoint(GLfloat x, GLfloat y){
  glPointSize(5);
  glBegin(GL_POINTS);
  glVertex2f(x,y);
  glEnd();
}

void calc(int x1, int y1 , int x2, int y2){
 double radius ;
 int xfinal = x2-x1;
 int yfinal = y2-y1;

 radius = sqrt(pow(xfinal,2)+ pow(yfinal,2));

 //midpoint algorithm
 GLint x=0,y=radius,p=1-radius;

 while(x<=y)
 {
  plotPoint(x,y);
  plotPoint(-x,-y);
  plotPoint(-x,y);
  plotPoint(x,-y);
  plotPoint(y,x);
  plotPoint(-y,x);
  plotPoint(y,-x);
  plotPoint(-y,-x);
  if(p<0)
    p+=2*x+3;
  else
  {
   p+=2*(x-y)+5;
   y--;
  }
  x++;
  glFlush();
 }

}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse){

  if(button == GLUT_LEFT_BUTTON && action==GLUT_DOWN)
  {
      x1=xMouse;
      yy=500-yMouse;

      xval = x1-250;
      yval = yy-250;

      glPointSize(5);
      glBegin(GL_POINTS);
      glColor3f(1,0,0);
      glVertex2i(xval,yval);
      glEnd();
      glFlush();

      xarr[i]=xval;
      yarr[i]=yval;
      i++;

      if(i%2!=0){
        calc(xarr[i-1],yarr[i-1], xarr[i-2],yarr[i-2]);
      }


  }
}


int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  glutCreateWindow("circleScanConversion");

  init();
  //glutDisplayFunc(display);
  glutMouseFunc(mousePtPlot);
  glutMainLoop();
  return 0;
}
