#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

void init(void)
{
 glClearColor(1,1,1,1);
 glMatrixMode(GL_PROJECTION);
 glClear(GL_COLOR_BUFFER_BIT);
 gluOrtho2D(-100,100,-100,100);
 glFlush();
}
void display(){
  glColor3f(1,0,0);
  glBegin(GL_LINES);
  glVertex2i(-30,10);
  glVertex2i(20,10);

  glVertex2i(20,10);
  glVertex2i(20,60);

  glVertex2i(20,60);
  glVertex2i(-30,60);

  glVertex2i(-30,60);
  glVertex2i(-30,10);
  glEnd();
  glFlush();
}

int i=1;
float x1,yy;
float xval, yval;
int xarr[2];
int yarr[2];

void setPixel(float x, float y){
  glPointSize(1);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

const int x_max = 20;
const int y_max = 60;
const int x_min = -30;
const int y_min = 10;

int computeCode(double x, double y)
{
    int rcode = INSIDE;

    if (x < x_min){
        rcode |= LEFT;
        cout<<"xmin rcode="<<rcode<<endl;
      }
    else if (x > x_max){
        rcode |= RIGHT;
        cout<<"xmax rcode="<<rcode<<endl;
      }
    if (y < y_min){
        rcode |= BOTTOM;
        cout<<"ymin rcode="<<rcode<<endl;
      }
    else if (y > y_max){
        rcode |= TOP;
        cout<<"ymax rcode="<<rcode<<endl;
      }
    return rcode;
}

void cohenSutherlandClip(double x1, double y1, double x2, double y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            double x, y;

            // At least one endpoint is outside the
            // rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & TOP)
            {
                x = x1 + (x2 - x1) * double(y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                x = x1 + (x2 - x1) * double(y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {

                y = y1 + (y2 - y1) * double(x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                y = y1 + (y2 - y1) * double(x_min - x1) / (x2 - x1);
                x = x_min;
            }
            cout<<"x="<<x;
            cout<<", y="<<y<<"\n";

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        cout <<"Line accepted from " << x1 << ", "
             << y1 << " to "<< x2 << ", " << y2 << endl;
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glEnd();
        glFlush();
    }
    else
        cout << "Line rejected" << endl;
}

void dline(int x1, int y1, int x2, int y2){
  glColor3f(0,0,1);
  cout<<"original point:"<<x1<<","<<x2<<" & "<<y1<<","<<y2<<"\n";
  glBegin(GL_LINES);
  glVertex2i(x1,y1);
  glVertex2i(x2,y2);
  glEnd();
  cohenSutherlandClip(x1, y1, x2, y2);
  glFlush();
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse){

  if(button == GLUT_LEFT_BUTTON && action==GLUT_DOWN)
  {
      x1=xMouse;
      yy=400-yMouse;

      xval = ((x1*200)/400)-100;
      yval = ((yy*200)/400)-100;
      // cout<<"x="<<xval<<" & y="<<yval<<"\n";

      xarr[i]=xval;
      yarr[i]=yval;
      i++;

      if(i%2!=0){
        glClear(GL_COLOR_BUFFER_BIT);
        display();
        dline(xarr[i-2],yarr[i-2],xarr[i-1],yarr[i-1]);
      }
  }
  glFlush();
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(400,400);
  glutCreateWindow("Clipping window");

  init();
  glutDisplayFunc(display);
  glutMouseFunc(mousePtPlot);
  // glutSpecialFunc(keyFunc);
  glutMainLoop();
  return 0;
}
