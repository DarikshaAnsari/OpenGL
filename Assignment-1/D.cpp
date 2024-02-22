#include <GL/glut.h>

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glPointSize(10);
    glClear(GL_COLOR_BUFFER_BIT);
     
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0f, 0.0f);

    glVertex2f(-0.45f, -0.5f);
    glVertex2f(-0.45f, -0.3f);

    glVertex2f(-0.45f, -0.3f);
    glVertex2f(-0.3f, -0.3f);

    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.25f, -0.35f);

    glVertex2f(-0.25f, -0.35f);
    glVertex2f(-0.25f, -0.45f);

    glVertex2f(-0.25f, -0.45f);
    glVertex2f(-0.3f, -0.5f);

    glVertex2f(-0.3f, -0.5f);
    glVertex2f(-0.45f, -0.5f);

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,900);
    glutInitWindowPosition(500, 500);
    glutCreateWindow("OpenGL Letter D");
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
