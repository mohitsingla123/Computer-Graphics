#include<GL/glut.h>
#include<iostream>
using namespace std;

void init(void)
{
 glClearColor(1,1,1,1);
 glMatrixMode(GL_PROJECTION);
 glClear(GL_COLOR_BUFFER_BIT);
 gluOrtho2D(-200,200,-200,200);
 glFlush();
}
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 cout<<"Press t to translate"<<"\n"<<"Press r to rotate"<<"\n"<<"Press s to scale"<<"\n"<<"Press x for reflection in x-axis"<<"\n"<<"Press y for reflection in y-axis"<<"\n";
 glColor3f(0,0,1);
 glBegin(GL_LINES);
 glVertex2i(-200,0);
 glVertex2i(200,0);

 glVertex2i(0,-200);
 glVertex2i(0,200);
 glEnd();
 glFlush();
}

int i=0;
float xx,yy;
float xval, yval;
int xarr[7];
int yarr[7];
int xsend, ysend;

void translate(int x1, int y1,int x2, int y2,int x3, int y3){
  x1=x1+50;
  x2=x2+50;
  x3=x3+50;
  glColor3f(0,1,0);
  glBegin(GL_LINES);
  glVertex2i(x1,y1);
  glVertex2i(x2,y2);
  glVertex2i(x2,y2);
  glVertex2i(x3,y3);
  glVertex2i(x3,y3);
  glVertex2i(x1,y1);
  glEnd();
  glFlush();
}
void rotate(int x1, int y1,int x2, int y2,int x3, int y3){
  int xx1=x1*(0.5)-y1*(0.86602540378);
  int yy1=x1*(0.86602540378)+y1*(0.5);
  int xx2=x2*(0.5)-y2*(0.86602540378);
  int yy2=x2*(0.86602540378)+y2*(0.5);
  int xx3=x3*(0.5)-y3*(0.86602540378);
  int yy3=x3*(0.86602540378)+y3*(0.5);
  glColor3f(0,0,1);
  glBegin(GL_LINES);
  glVertex2i(xx1,yy1);
  glVertex2i(xx2,yy2);
  glVertex2i(xx2,yy2);
  glVertex2i(xx3,yy3);
  glVertex2i(xx3,yy3);
  glVertex2i(xx1,yy1);
  glEnd();
  glFlush();
}
void scale(int x1, int y1,int x2, int y2,int x3, int y3){
  glColor3f(0,1,1);
  glBegin(GL_LINES);
  glVertex2i(2*x1,2*y1);
  glVertex2i(2*x2,2*y2);
  glVertex2i(2*x2,2*y2);
  glVertex2i(2*x3,2*y3);
  glVertex2i(2*x3,2*y3);
  glVertex2i(2*x1,2*y1);
  glEnd();
  glFlush();
}
void xrefl(int x1, int y1,int x2, int y2,int x3, int y3){
  glColor3f(0.7,1,0.3);
  glBegin(GL_LINES);
  glVertex2i(x1,-y1);
  glVertex2i(x2,-y2);
  glVertex2i(x2,-y2);
  glVertex2i(x3,-y3);
  glVertex2i(x3,-y3);
  glVertex2i(x1,-y1);
  glEnd();
  glFlush();
}
void yrefl(int x1, int y1,int x2, int y2,int x3, int y3){
  glColor3f(0.5,0.2,0.8);
  glBegin(GL_LINES);
  glVertex2i(-x1,y1);
  glVertex2i(-x2,y2);
  glVertex2i(-x2,y2);
  glVertex2i(-x3,y3);
  glVertex2i(-x3,y3);
  glVertex2i(-x1,y1);
  glEnd();
  glFlush();
}
void tri(int x1, int y1,int x2, int y2,int x3, int y3){
  glColor3f(1,0,0);
  glBegin(GL_LINES);
  glVertex2i(x1,y1);
  glVertex2i(x2,y2);
  glVertex2i(x2,y2);
  glVertex2i(x3,y3);
  glVertex2i(x3,y3);
  glVertex2i(x1,y1);
  glEnd();
  glFlush();
  // translate(x1,y1,x2,y2,x3,y3);
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse){

  if(button == GLUT_LEFT_BUTTON && action==GLUT_DOWN)
  {
      xx=xMouse;
      yy=400-yMouse;

      xval = xx-200;
      yval = yy-200;
      // xval = xx;
      // yval = yy;

      glPointSize(5);
      glBegin(GL_POINTS);
      glColor3f(1,0,0);
      glVertex2i(xval,yval);
      glEnd();

      i++;
      xarr[i]=xval;
      yarr[i]=yval;

      // cout<<"count="<<i<<"\n";

      if(i%3==0){

        tri(xarr[i-2],yarr[i-2], xarr[i-1],yarr[i-1],xarr[i],yarr[i]);
      }
  }
  glFlush();
}

void keyy(unsigned char key, GLint xMouse, GLint yMouse){
  if(key=='t' || key=='T'){
    translate(xarr[i-2],yarr[i-2], xarr[i-1],yarr[i-1],xarr[i],yarr[i]);
  }
  if(key=='r' || key=='R'){
    rotate(xarr[i-2],yarr[i-2], xarr[i-1],yarr[i-1],xarr[i],yarr[i]);
  }
  if(key=='s' || key=='S'){
    scale(xarr[i-2],yarr[i-2], xarr[i-1],yarr[i-1],xarr[i],yarr[i]);
  }
  if(key=='x' || key=='X'){
    xrefl(xarr[i-2],yarr[i-2], xarr[i-1],yarr[i-1],xarr[i],yarr[i]);
  }
  if(key=='y' || key=='Y'){
    yrefl(xarr[i-2],yarr[i-2], xarr[i-1],yarr[i-1],xarr[i],yarr[i]);
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(400,400);
  glutCreateWindow("2-D transformation");

  init();
  glutDisplayFunc(display);
  glutMouseFunc(mousePtPlot);
  glutKeyboardFunc(keyy);
  glutMainLoop();
  return 0;
}
