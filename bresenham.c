#include <GL/glut.h>
#include <stdio.h>
int a1, a2, b1, b2;
void Init() {
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(1.0,1.0,1.0,1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,500,0,500); }
void draw_pixel(int x, int y) {
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd(); }
void draw_line(int a1, int a2, int b1, int b2) {
int dx, dy, i, pk;
int xInc, yInc, Inc1, Inc2;
int x, y;
dx = a2-a1;
dy = b2-b1;
if(dx<0)
dx=-dx;
if(dy<0)
dy=-dy;
xInc=1;
yInc=1;
x=a1;
y=b1;
if(dx>dy) {
draw_pixel(x,y);
pk = 2*dy-dx;
Inc1 = 2*(dy-dx);
Inc2 = 2*dy;
for(i=0; i<dx; i++) {
if(pk>=0) {
y += yInc;
pk += Inc1; }
else
pk += Inc2;
x += xInc;
draw_pixel(x,y);
}
}
else
{
draw_pixel(x, y);
pk = 2*dx-dy;
Inc1 = 2*(dx-dy);
Inc2 = 2*dx;
 for(i=0; i<dy; i++)
{
if (pk >= 0)
{
x += xInc;
pk += Inc1;
}
else
 pk += Inc2;
y += yInc;
draw_pixel(x, y);
}
}
}
void myDisplay()
{
draw_line(a1, a2, b1, b2);
glFlush();
}
int main(int argc, char** argv)
{
printf("Enter two end points of the line to be drawn:\n");
 printf("\nEnter Point1( a1 , b1):\n");
 scanf("%d%d",&a1,&b1);
 printf("\nEnter Point1( a2 , b2):\n");
 scanf("%d%d",&a2,&b2);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(600, 600);
glutInitWindowPosition(0, 0);
glutCreateWindow("Bresenham's Line Drawing");
Init();
glutDisplayFunc(myDisplay);
glutMainLoop();
return 0;
}