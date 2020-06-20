// Mid point circle code in CG(Computer Graphics) In C 
#include<GL/glut.h>
#include <stdio.h>
#include <math.h>
double r;
void Circle(void)
{
 int pko,pk;
 int x,y,xk1,yk1;
 pko=(1-r);
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_POINTS);
 pk=pko;
 x=0;
 y=r;
 while(x<=y)
 {
if(pk>=0)
{
xk1=x+1;
yk1=y-1;
}
else
{
xk1=x+1;
yk1=y;
}
glVertex2d(x,y);
glVertex2d(-x,y);
glVertex2d(x,-y);
glVertex2d(-x,-y);
glVertex2d(y,x);
glVertex2d(-y,x);
glVertex2d(y,-x);
glVertex2d(-y,-x);
printf("(%d %d) ",x,y);
pko=pk;
pk = pko+2*(x+1)+(yk1*yk1-y*y)-(yk1-y)+1;
x=xk1;
y=yk1;
 }
 glEnd();
 glFlush();
}
void Init()
{
 glClearColor(1.0,1.0,1.0,0);
 glColor3f(1.0,0.0,0.0);
 gluOrtho2D(-100 , 100 , -100 , 100);
}
void main(int argc, char **argv)
{
 printf("Enter radius of circle to be drawn:\n");
 printf("\nEnter radius:\n");
 scanf("%lf",&r);
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowPosition(0,0);
 glutInitWindowSize(640,640);
 glutCreateWindow("Mid Point Circle");
 Init();
 glutDisplayFunc(Circle);
 glutMainLoop();
}
