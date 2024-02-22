// Create a display window of resolution of 600x600 on your
// computer screen. On that display window, draw the following Ellipse:

// using points (a) a=10,b=15, center=(0,0)

// (b) a=40,b=50, center=(-20,-30)

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

float centerX = 0.0f;
float centerY = 0.0f;
//here we are considering a as major axis no matter it is small or big
float majorAxis = 10.0f;
float minorAxis = 15.0f;

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
    glColor3f(0.0, 1.0, 0.0); // Set color to green
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
