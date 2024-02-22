// Q2. Draw a line and shapes using Mid-point line algorithm , following line
// segments and note dawn the time taken by each of the algorithms.

#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>

void myInit()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-50.0, 50.0, -50.0, 50.0,-1.0,1.0);
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    printf("%d, %d", x, y);
    glEnd();
}

void drawLine(int x1, int y1, int x2, int y2){

    int dy = y2 - y1;
    int dx = x2 - x1;
    int d;
    int x,y;
    if (dy<=dx){
        d = dy - (dx/2);
        x = x1;
        y = y1;

        draw_pixel(x,y);

        while (x < x2){
            x++;

            if (d < 0)
                d = d + dy;

            else{
                d += (dy - dx);
                y++;
            }
            draw_pixel(x,y);
        }
    }
    else if (dx < dy)
    {
        d = dx - (dy/2);
        x = x1;
        y = y1;

        draw_pixel(x,y);

        while (y < y2){

            y++;

            if (d < 0){
                d = d + dx;
            }
            else{
                d += (dx - dy);
                x++;
            }
            draw_pixel(x,y);

        }
    }
}
void myDisplay()
{
    drawLine(1,1, 15,15);
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Straight line using Mid Point Algorithm");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;}
