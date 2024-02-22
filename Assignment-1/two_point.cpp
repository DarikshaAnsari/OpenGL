
#include<GL/glut.h>

void display(){
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(8);
glBegin(GL_POINTS);
glColor3f(0.0f, 0.0f, 1.0f );
glVertex2f(-0.3, -0.5);
glVertex2f(0.5, 0.7);
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