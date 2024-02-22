#include <GL/glut.h>
void display()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.25,0.25,0.0);
    glVertex3f(0.75,0.25,0.0);
    glVertex3f(0.75,0.75,0.0);
    glVertex3f(0.25,0.75,0.0);
    glEnd();
    glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(500,500);
    glutInitWindowPosition(50,50);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}