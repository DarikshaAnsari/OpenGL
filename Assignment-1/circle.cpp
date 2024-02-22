#include <GL/glut.h>
#include <cmath> 

const int screenWidth = 640;
const int screenHeight = 480;

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set clear color to white
    glColor3f(0.0, 0.0, 0.0); // Set drawing color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0); // Define the world coordinates
}

void drawCircle(float radius, int numSegments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCircle(1.0, 100); // Draw circle with radius 1 and 100 segments
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Circle Drawing");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}