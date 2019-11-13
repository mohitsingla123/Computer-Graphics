
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display(){
	glClearColor(0.0,0.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);	
   	glColor3f(1.0f, 1.0f, 1.0f); 
  	glRectf(-0.50f, 0.75f, 0.50f, -0.75f);
  	glFlush();
  	glutSwapBuffers();
	glBegin(GL_LINE_STRIP);
	 glClear(GL_COLOR_BUFFER_BIT);
 	glColor3f(1.0,0.0,0.0);
 	glPointSize(2.0);


	glVertex2f(-.50,.75);
	glVertex2f(-.50,.75);


	glVertex2f(-.50,.60);
	glVertex2f(-.40,.75);

	glVertex2f(-.50,.45);
	glVertex2f(-.30,.75);

	glVertex2f(-.50,.30);
	glVertex2f(-.20,.75);

	glVertex2f(-.50,.15);
	glVertex2f(-10,.75);

	glVertex2f(-.50,.00);
	glVertex2f(-.00,.75);

	glVertex2f(-.50,-.00);
	glVertex2f(.00,.75);

	glVertex2f(-.50,-.15);
	glVertex2f(.10,.75);

	glVertex2f(-.50,-.30);
	glVertex2f(.20,.75);

	glVertex2f(-.50,-.45);
	glVertex2f(.30,.75);

	glVertex2f(-.50,-.60);
	glVertex2f(.40,.75);

	glVertex2f(-.50,-.75);
	glVertex2f(.50,.75);

	glVertex2f(-.40,-.75);
	glVertex2f(.50,.65);
 
	glVertex2f(-.30,-.75);
	glVertex2f(.50,.50);

	glVertex2f(-.20,-.75);
	glVertex2f(.50,.25);

	glVertex2f(-.10,-.75);
	glVertex2f(.50,.15);

	glVertex2f(-.00,-.75);
	glVertex2f(.50,.0);

	glVertex2f(.10,-.75);
	glVertex2f(.50,-.15);

	glVertex2f(.20,-.75);
	glVertex2f(.50,-.30);

	glVertex2f(.30,-.75);
	glVertex2f(.50,-.45);

	glVertex2f(.40,-.75);
	glVertex2f(.50,-.60);

	glVertex2f(.50,-.75);
	glVertex2f(.50,-.75);
glEnd();
glFlush();
}

int main(int argc, char *argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(800, 800);   
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Lab Test");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
