#include <GL/glut.h>
#include <vector>

struct Point {
    float x, y;
};

void drawCubicBezier(Point p0, Point p1, Point p2, Point p3, int segments) {
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float t = static_cast<float>(i) / static_cast<float>(segments);
        float one_minus_t = 1.0f - t;

        float x = one_minus_t * one_minus_t * one_minus_t * p0.x +
                  3.0f * one_minus_t * one_minus_t * t * p1.x +
                  3.0f * one_minus_t * t * t * p2.x +
                  t * t * t * p3.x;

        float y = one_minus_t * one_minus_t * one_minus_t * p0.y +
                  3.0f * one_minus_t * one_minus_t * t * p1.y +
                  3.0f * one_minus_t * t * t * p2.y +
                  t * t * t * p3.y;

        glVertex2f(x, y);
    }
    glEnd();
}

void drawRaceTrack() {
    std::vector<Point> controlPoints1 = {
        {100, 300},
        {150, 400},
        {400, 500},
        {650, 400}
    };

    std::vector<Point> controlPoints2 = {
        {100, 250},
        {150, 350},
        {400, 450},
        {650, 350}
    };

    int segments = 100;

    glColor3f(1.0f, 1.0f, 1.0f);

    for (size_t i = 0; i < controlPoints1.size() - 3; i += 3) {
        drawCubicBezier(controlPoints1[i], controlPoints1[i + 1], controlPoints1[i + 2], controlPoints1[i + 3], segments);
    }

    for (size_t i = 0; i < controlPoints2.size() - 3; i += 3) {
        drawCubicBezier(controlPoints2[i], controlPoints2[i + 1], controlPoints2[i + 2], controlPoints2[i + 3], segments);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawRaceTrack();

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
    glutCreateWindow("Parallel Race Track");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 

    glutMainLoop();

    return 0;
}
