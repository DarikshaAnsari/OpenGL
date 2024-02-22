// Draw any living or non-living shape with curves. (Don’t simply make
// triangle, rectangle, circles, etc.)
#include <GL/glut.h>
#include <cmath>
void drawPencil() {
// Draw the body of the pencil
glColor3f(0.8, 0.6, 0.4); // Brown color for the pencil body
glBegin(GL_POLYGON);
glVertex2f(20, 100);
glVertex2f(40, 150);
glVertex2f(50, 150);
glVertex2f(30, 100);
glEnd();
// Draw the lead of pencil
glColor3f(0.9, 0.9, 0.9); // Light gray color for the eraser

glBegin(GL_POLYGON);
glVertex2f(40, 150);
glVertex2f(50, 150);
glVertex2f(50, 160);
glVertex2f(40, 160);
glEnd();
// Draw the lead
glColor3f(0.2, 0.2, 0.2); // Dark gray color for the lead
glBegin(GL_POLYGON);
glVertex2f(30, 100);
glVertex2f(50, 100);
glVertex2f(50, 150);
glVertex2f(40, 150);
glEnd();
//handle of the pencil
glColor3f(0.4, 0.2, 0.1); // Brown color for the pencil handle
glBegin(GL_POLYGON);
glVertex2f(20, 100);
glVertex2f(50, 100);
glVertex2f(50, -50);
glVertex2f(20, -50);
glEnd();
}
void drawPen() {
// Draw the body of the pen
glColor3f(0.2, 0.2, 0.2); // Black color for the pen body
glBegin(GL_POLYGON);
glVertex2f(60, 100);
glVertex2f(80, 100);
glVertex2f(80, 150);
glVertex2f(60, 150);
glEnd();
// Draw the cap
glColor3f(1.0, 1.0, 1.0); // Dark gray color for the cap
glBegin(GL_POLYGON);
glVertex2f(60, 150);
glVertex2f(80, 150);
glVertex2f(80, 160);
glVertex2f(60, 160);
glEnd();
//handle of the pen
glColor3f(0.4, 0.2, 0.1); // Brown color for the pencil handle

glBegin(GL_POLYGON);
glVertex2f(60, 100);
glVertex2f(80, 100);
glVertex2f(80, -50);
glVertex2f(60, -50);
glEnd();
}

void drawEraser() {
// Draw the body of the eraser
glColor3f(0.9, 0.9, 0.9); // Light gray color for the eraser body
glBegin(GL_POLYGON);
glVertex2f(110, 100);
glVertex2f(120, 100);
glVertex2f(120, 120);
glVertex2f(110, 120);
glEnd();
// Draw the top of the eraser
glColor3f(1.0, 1.0, 1.0); // White color for the top
glBegin(GL_POLYGON);
glVertex2f(110, 120);
glVertex2f(120, 120);
glVertex2f(120, 130);
glVertex2f(110, 130);
glEnd();
}

void display() {
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(1.0, 1.0, 1.0, 0);
glOrtho(-100, 400, -100, 400, -1, 1);
drawPencil();
drawEraser();
drawPen();

glFlush();
}
int main(int argc, char** argv) {
glutInit(&argc, argv);

glutCreateWindow("Pencil,Pen,Eraser");
glutInitWindowSize(500, 500);
glutInitWindowPosition(50, 50);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}