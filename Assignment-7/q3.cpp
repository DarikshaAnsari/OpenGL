// Write a program that displays a torus in the display window and
// allows the user to switch between solid and wire-frame views of
// the torus, translate the torus along any dimension, rotate the torus
// around its center in any direction, and change the sizes of the torus’
// defining properties (i.e., the radius of its cross section ellipse and its
// axial radius).
#include<iostream>
#include <GL/glut.h>
#include<stdlib.h>

using namespace std;

void display()
{

glClear(GL_COLOR_BUFFER_BIT);
GLdouble iRadius = 0.5;
GLdouble oRadius = 2;
GLint sides = 15;
GLint rings = 30;

char view;
glColor3f(1.0, 1.0, 1.0);
cout<<"Enter the torus view (wireframe(w) / solid(s)):"<<endl;
cin>>view;

glPushMatrix();
glTranslatef(-2.0, 1, 0);
// glRotatef(45,1,0,0);
glScalef(0.8,0.8,1);

if (view == 's')
glutSolidTorus(iRadius,oRadius,sides,rings);
else
glutWireTorus(iRadius,oRadius,sides,rings);

glPopMatrix();

glBegin(GL_LINES);
//X
glColor3f(1, 0, 0);
glVertex3f(0, 0, 0);
glVertex3f(10, 0, 0);
//Y
glColor3f(0, 1, 0);
glVertex3f(0, 0, 0);
glVertex3f(0, 10, 0);
//Z
glColor3f(0, 0, 1);
glVertex3f(0, 0, 0);
glVertex3f(0, 0, 10);
glEnd();
glFlush();
}

void init()
{

glClearColor(0.0, 0.0, 0.0, 1.0);
glColor3f(1.0, 1.0, 1.0);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60.0, 4.0 / 3.0, 1, 40);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(4, 6, 5, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(80, 80);
glutInitWindowSize(800, 600);
glutCreateWindow("Normal Torus");
glutDisplayFunc(display);
init();
glutMainLoop();
}