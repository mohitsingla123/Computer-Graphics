#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
double X1, Y1, X2, Y2;
float round_value(float v)
{
return (v + 0.5);
}
void DDAline()
{
double dx=(X2-X1);
double dy=(Y2-Y1);
double slope=dy/dx;
double c=Y1-slope*X1;
/* Clears buffers to preset values */
glClear(GL_COLOR_BUFFER_BIT);
/* Plot the points */
glBegin(GL_POINTS);
/* Plot the first point */
glVertex2d(X1,Y1);
int k;
/* For every step, find an intermediate vertex */
for(int x=X1;x<X2;x++)
{
int y=slope*x+c;
y=round_value(y);
glVertex2d(round_value(x), round_value(y));
 }
glEnd();
glFlush();
}
void Init()
{
/* Set clear color to white */
glClearColor(1.0,1.0,1.0,0);
/* Set fill color to black */
glColor3f(0.0,0.0,0.0);

/* glViewport(0 , 0 , 640 , 480); */
/* glMatrixMode(GL_PROJECTION); */
/* glLoadIdentity(); */
gluOrtho2D(0 , 640 , 0 , 480);
}
void main(int argc, char **argv)
{
printf("Enter two end points of the line to be drawn:\n");
printf("\n************************************");
printf("\nEnter Point1( X1 , Y1):\n");
scanf("%lf%lf",&X1,&Y1);
printf("\n************************************");
printf("\nEnter Point1( X2 , Y2):\n");
scanf("%lf%lf",&X2,&Y2);
/* Initialise GLUT library */
glutInit(&argc,argv);
/* Set the initial display mode */
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
/* Set the initial window position and size */
glutInitWindowPosition(0,0);
glutInitWindowSize(640,480);
/* Create the window with title "DDA_Line" */
glutCreateWindow("Draw a line using DDA algorithm");
/* Initialize drawing colors */
Init();
/* Call the displaying function */
glutDisplayFunc(DDAline);
/* Keep displaying untill the program is closed */
glutMainLoop();
}
