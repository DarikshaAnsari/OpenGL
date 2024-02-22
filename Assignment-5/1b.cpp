#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>

void myInit()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-100.0, 100.0, -100.0, 100.0,-1,1);
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    printf(", %d, %d, ", x, y);
    glEnd();
}

float centerX = -20.0f;
float centerY = -30.0f;
float majorAxis = 40.0f;
float minorAxis = 50.0f;

void drawEllipse() {
    glBegin(GL_POINTS);

    // Set the number of points to plot along the ellipse
    int numPoints = 100;

    for (int i = 0; i < numPoints; ++i) {
        float angle = 2.0f * M_PI * i / numPoints;
        float x = centerX + majorAxis * cos(angle);
        float y = centerY + minorAxis * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    glPointSize(2.0); // Adjust point size as needed
    drawEllipse();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ellipse Algorithm using center and major-minor axis");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
