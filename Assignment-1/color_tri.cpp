#include <GL/glut.h>
void display()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);//red
    glVertex2f(0.2,0.2);
    glColor3f(0,1,0);//green
    glVertex2f(0.8,0.2);
    glColor3f(0,0,1);//blue
    glVertex2f(0.5,0.9);
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