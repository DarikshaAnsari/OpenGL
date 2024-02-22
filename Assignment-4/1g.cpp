#include <bits/stdc++.h>

#include <GL/glut.h>
using namespace std;
/*Draw a circle using Bresenham's circle algorithm and two
concentric circles.*/
void draw(int xc, int yc, int x, int y) {
 glVertex2f(xc+x, yc+y);
 glVertex2f(xc-x, yc+y);
 glVertex2f(xc+x, yc-y);
 glVertex2f(xc-x, yc-y);
 glVertex2f(xc+y, yc+x);
 glVertex2f(xc-y, yc+x);
 glVertex2f(xc+y, yc-x);
glVertex2f(xc-y, yc-x);
}
 void bresenham(int xc, int yc, int r) {
 int x = 0, y = r;
 int d = 3 - 2 * r;
 draw(xc, yc, x, y);
 while (y >= x) {
 x++;
 if (d > 0) {
 y--;
 d += 4 * (x - y) + 10;
 }
 else {
 d += 4 * x + 6;
 }
 draw(xc, yc, x, y);
}
}
void display() {
 glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
 glClear(GL_COLOR_BUFFER_BIT);

 glPointSize(5);

 glBegin(GL_POINTS);

 glColor3f(1.0f, 0.0f, 0.0f);

 bresenham(0, 0, 50);
 bresenham(0, 0, 25);

 glEnd();

 glFlush();
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(512, 512);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Output using OpenGL");
 glClearColor(0.0, 0.0, 0.0, 1.0);
 glutDisplayFunc(display);
 gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
 glutMainLoop();
return 0;
}
