//circle

#include <GL/glut.h>
#include <cmath>

int windowWidth = 800;
int windowHeight = 600;

void plotPoint(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawCircleDDA(int centerX, int centerY, int radius) {
    float x = radius;
    float y = 0;
    float theta = 0;
    float stepSize = 1.0 / radius;
    
    while (theta <= 45.0) {
        plotPoint(centerX + static_cast<int>(x + 0.5), centerY + static_cast<int>(y + 0.5));
        
        float newX = x * cos(stepSize) - y * sin(stepSize);
        float newY = x * sin(stepSize) + y * cos(stepSize);
        
        x = newX;
        y = newY;
        theta += stepSize;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    
    int centerX = windowWidth / 2;
    int centerY = windowHeight / 2;
    int circleRadius = 100;
    
    drawCircleDDA(centerX, centerY, circleRadius);
    
    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
    
    windowWidth = width;
    windowHeight = height;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("DDA Circle Drawing Algorithm");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    
    return 0;
}
