#include <bits/stdc++.h>
#include <GL/glut.h>

/*Create a display window of resolution of 512x512 on your
computer screen. On that display window, draw the following circle:

using points (a) r=1, center=(0,0)

(b) r=50, center=(20,20)

using line loop*/
using namespace std;
void display() {
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);

glPointSize(5);

glBegin(GL_POINTS);

glColor3f(1.0f, 0.0f, 0.0f);

float pi = 3.14159;

 int xc = 0, yc = 0;
 int r = 1;

int steps = 1000;
 int cnt = 0;
 while (cnt <= steps) {
 glVertex2f(r * cos(2 * pi * cnt / 1000.0) + xc, r * sin(2 * pi * cnt / 1000.0) + yc);
cnt++;
 }

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
 gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
 glutMainLoop();
 return 0;
}