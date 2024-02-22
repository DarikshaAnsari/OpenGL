// Q1: Use a straight-line algorithm to draw a line of the given points with the window
// size 512x512:

// (a). Point – (85.67,78.96) and (25.92,39.23)
#include <GL/glut.h>

int windowWidth = 512;
int windowHeight = 512;

void plotPoint(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1;
    int y = y1;
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    
    while (true) {
        plotPoint(x, y);
        
        if (x == x2 && y == y2) {
            break;
        }
        
        int e2 = 2 * err;
        
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    
    int x1 = static_cast<int>(85.67 * windowWidth / 100);
    int y1 = static_cast<int>(78.96 * windowHeight / 100);
    int x2 = static_cast<int>(25.92 * windowWidth / 100);
    int y2 = static_cast<int>(39.23 * windowHeight / 100);
    
    drawLineBresenham(x1, y1, x2, y2);
    
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
    glutCreateWindow("Line Drawing Algorithm");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    
    return 0;
}
