#include<iostream>
#include <GL/glut.h>
#include<stdlib.h>

GLsizei winWidth = 500, winHeight = 500;

void init(void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
}

void wireQuadSurfs(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 0.0, 1.0);
gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);


glColor3f(0.0f, 1.0f, 1.0f);  // Cyan color
glScalef(-5.5f, -5.5f,-5.5f);
glutSolidCube(0.5);

glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
glViewport(0, 0, newWidth, newHeight);
glMatrixMode(GL_PROJECTION);
glOrtho(-2.0, 2.0, -2.0, 2.0, 0.0, 5.0);
glMatrixMode(GL_MODELVIEW);
glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(100, 100);
glutInitWindowSize(winWidth, winHeight);
glutCreateWindow("Cylinder polygon mesh representation");
init();
glutDisplayFunc(wireQuadSurfs);
glutReshapeFunc(winReshapeFcn);
glutMainLoop();
}
