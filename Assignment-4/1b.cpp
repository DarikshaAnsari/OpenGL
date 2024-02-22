#include <bits/stdc++.h>

#include <GL/glut.h>
using namespace std;
void display() {
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);

 glPointSize(5);

glBegin(GL_POINTS);

 glColor3f(1.0f, 0.0f, 0.0f);

float pi = 3.14159;

int xc = 20, yc = 20;
int r = 50;
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
 gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
 glutMainLoop();
return 0;
}