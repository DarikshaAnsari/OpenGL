#include <GL/glut.h>
#include <cmath>

float translationX = 6.0f;  // Translation in the x-direction
float rotationAngle = 30.0f;  // Rotation angle in degrees

void drawSquare(float x, float y, float size) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);
    glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawHouse() {
    // Draw the base (square)
    glColor3f(0.5f, 0.5f, 0.5f);  // Grey color
    drawSquare(100 + translationX, 100, 200);

    // Draw the roof (triangle)
    glColor3f(0.8f, 0.2f, 0.2f);  // Red color
    drawTriangle(100 + translationX, 300, 200 + translationX, 400, 300 + translationX, 300);

    // Draw the door (rectangle)
    glColor3f(0.2f, 0.2f, 0.8f);  // Blue color
    drawSquare(175 + translationX, 100, 50);

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Apply translation in the x-direction
    // glTranslatef(translationX, 0.0f, 0.0f);

    // Apply rotation about the center of the house
    // glTranslatef(200 + translationX, 200, 0); // Translate to the center of the house
    // glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f); // Rotate about the z-axis
    // glTranslatef(-(200 + translationX), -200, 0); // Translate back

    glScalef(2.0f,2.0f,2.0f);
    drawHouse();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D House");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set clear color to white

    glutMainLoop();

    return 0;
}
