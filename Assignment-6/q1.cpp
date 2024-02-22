// Q1. Create a display window with resolution of 600x600 on your
// computer screen. On that display window, draw the Indian flag with
// the flag post.
#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
const int numSpokes = 24;

const float radius = 0.1;
// Function to draw a rectangle
void drawRectangle(float x, float y, float width, float height, float
colorR, float colorG, float colorB) {
glColor3f(colorR, colorG, colorB);
glBegin(GL_POLYGON);
glVertex2f(x, y);
glVertex2f(x + width, y);
glVertex2f(x + width, y + height);
glVertex2f(x, y + height);
glEnd();
}

void drawAshokaChakra() {
glColor3f(0.0, 0.2, 0.6); // Blue color for the Ashoka Chakra
// Draw the outer circle
glBegin(GL_LINE_LOOP);
for (int i = 0; i<numSpokes; ++i) {
float theta = 2.0 * M_PI * float(i) / float(numSpokes);
float x = radius * cos(theta);
float y = radius * sin(theta);
glVertex2f(x, y);
}
glEnd();
// Draw the 24 spokes
for (int i = 0; i<numSpokes; ++i) {
float theta = 2.0 * M_PI * float(i) / float(numSpokes);
float x1 = 0.0;
float y1 = 0.0;
float x2 = radius * cos(theta);
float y2 = radius * sin(theta);
glBegin(GL_LINES);
glVertex2f(x1, y1);
glVertex2f(x2, y2);
glEnd();
}
}
void display() {
glClear(GL_COLOR_BUFFER_BIT);
// Green Rectangle (Bottom)
drawRectangle(-1.0f, -0.3f, 2.0f, 0.2f, 0.0f, 0.4f, 0.0f);

// White Rectangle (Middle)
drawRectangle(-1.0f, -0.1f, 2.0f, 0.2f, 1.0f, 1.0f, 1.0f);
// Orange Rectangle (Top)
drawRectangle(-1.0f, 0.1f, 2.0f, 0.2f, 1.0f, 0.42f, 0.0f);
// Flag post
drawRectangle(-1.0f, -1.0f, 0.05f, 1.3f, 1.0f, 1.0f, 1.0f);
drawAshokaChakra();
glFlush();
}
int main(int argc, char**argv){
glutInit(&argc,argv);
glutCreateWindow("circle with line loop&quot");
glutInitWindowSize(600,600);
glutInitWindowPosition(50,50);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}