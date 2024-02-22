#include<GL/glut.h>

void display(){
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(5);
glBegin(GL_POINTS);
glColor3f(0.0f, 0.0f, 1.0f );
glVertex2f(-0.2,-0.2);
glVertex2f(-0.2,-0.1);
glVertex2f(-0.2,0.0);
glVertex2f(-0.2,0.1);
glVertex2f(-0.2,0.2);
glVertex2f(-0.05, 0.25);
glVertex2f(0.03, 0.2);
glVertex2f(0.1, 0.15);
glVertex2f(0.12, 0.08);
glVertex2f(-0.08, 0.05);
glVertex2f(0.02, 0.02);

glVertex2f(0.04, -0.06);
glVertex2f(0.1, -0.15);
glVertex2f(0.15, -0.25);
glEnd();
glFlush();
}
int main(int argc,char** argv){
glutInit(&argc,argv);
glutCreateWindow("OpenGL Setup Test2");
glutInitWindowSize(500,500);
glutInitWindowPosition(50,50);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}