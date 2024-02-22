#include<GL/glut.h>

void display(){
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0f, 0.0f, 1.0f );

glBegin(GL_LINES);
glVertex2f(1.0, 0.0);
glVertex2f(-1.0, 0.0);
glVertex2f(0.0, 1.0);
glVertex2f(0.0, -1.0);
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