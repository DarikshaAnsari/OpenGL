#include<GL/glut.h>

void display(){
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(12);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 1.0f );
glBegin(GL_LINES);
glVertex2f(-0.4f,-0.2f);
glVertex2f(0.6f,-0.2f);
glVertex2f(0.6f,-0.2f);
glVertex2f(0.4f,0.2f);
glVertex2f(-0.2f,0.2f);
glVertex2f(0.4f,0.2f);
glVertex2f(-0.2f,0.2f);
glVertex2f(-0.4f,-0.2f);

glEnd();
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