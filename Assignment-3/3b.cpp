//pentagon
#include <GL/glut.h>
#include <cmath>

int windowWidth = 800;
int windowHeight = 600;

void plotPoint(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = std::max(abs(dx), abs(dy));
    
    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;
    
    float x = x1;
    float y = y1;
    
    for (int i = 0; i <= steps; ++i) {
        plotPoint(static_cast<int>(x + 0.5), static_cast<int>(y + 0.5));
        
        x += xIncrement;
        y += yIncrement;
    }
}

void drawRegularPentagonDDA(int centerX, int centerY, int radius) {
    const int sides = 5;
    const float angleIncrement = 2 * M_PI / sides;
    
    int x1, y1, x2, y2;
    
    for (int i = 0; i < sides; ++i) {
        float angle1 = i * angleIncrement;
        float angle2 = (i + 1) * angleIncrement;
        
        x1 = centerX + static_cast<int>(radius * cos(angle1));
        y1 = centerY + static_cast<int>(radius * sin(angle1));
        x2 = centerX + static_cast<int>(radius * cos(angle2));
        y2 = centerY + static_cast<int>(radius * sin(angle2));
        
        drawLineDDA(x1, y1, x2, y2);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    
    int centerX = windowWidth / 2;
    int centerY = windowHeight / 2;
    int radius = 100;
    
    drawRegularPentagonDDA(centerX, centerY, radius);
    
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
    glutCreateWindow("DDA Regular Pentagon Drawing Algorithm");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    
    return 0;
}
