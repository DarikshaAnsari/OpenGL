// Q3. Draw the shape given below using
// line-strip and line-loop.
#include<GL/glut.h>
void drawHouse() {
// Draw the base of the house
glColor3f(1.0, 1.0, 1.0); // white color
glBegin(GL_LINE_STRIP);
glVertex2f(40, 80);
glVertex2f(40, 40);
glVertex2f(100, 40);
glVertex2f(100, 80);
glEnd();
// Draw the roof
glColor3f(1.0, 1.0, 1.0); // white color
glBegin(GL_LINE_STRIP);
glVertex2f(40, 80);
glVertex2f(70, 120);
glVertex2f(100, 80);
glEnd();
// Draw the door
glColor3f(1.0, 1.0, 1.0); // white color
glBegin(GL_LINE_LOOP);
glVertex2f(50, 40);
glVertex2f(50, 70);
glVertex2f(70, 70);
glVertex2f(70, 40);
glEnd();

// Draw the window
glColor3f(1.0, 1.0, 1.0); // white color
glBegin(GL_LINE_LOOP);
glVertex2f(80,60);
glVertex2f(80, 70);
glVertex2f(90, 70);
glVertex2f(90, 60);
glEnd();
// Draw the chimney
glColor3f(1.0, 1.0, 1.0); // white color

glBegin(GL_LINE_LOOP);
glVertex2f(50,93);
glVertex2f(50, 120);
glVertex2f(60, 120);
glVertex2f(60, 107);
glEnd();
}
void display() {
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(1.0, 1.0, 1.0, 0);
glOrtho(0, 200, 0, 200, -1, 1);
drawHouse();
glFlush();
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutCreateWindow("House");
glutInitWindowSize(100, 120);
glutInitWindowPosition(50, 50);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}