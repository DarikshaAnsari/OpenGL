// Q3. Draw a circle using Mid-point circle algorithm:

// using points (a) r=1, center=(0,0)

// (b) r=50, center=(-20,-30)

#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>

void myInit()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-5.0, 5.0, -5.0, 5.0,-1,1);
    glClearColor(0.0, 0.0, 0.0, 1.0);//background color black
}

void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    printf(", %d, %d, ", x, y);
    glEnd();
}

void circleDraw(int xc, int yc, int r)
{
    int x =r, y =0;

    draw_pixel(x,y);

    if (r>0)
    {
        draw_pixel(x + xc, -y + yc);
        draw_pixel(y + xc, x + yc);
        draw_pixel(-y + xc, x + yc);
    }

    int P = 1 - r;

    while (x > y)
    {
        y++;

        if (P <= 0)
            P = P + 2 * y  + 1;
        else{
            x--;
            P = P + 2*y - 2*x + 1;
        }
        if (x < y){
            break;
        }

        draw_pixel(x + xc, y + yc);
        draw_pixel(-x+xc, y + yc);
        draw_pixel(x + xc, -y + yc);
        draw_pixel(-x + xc, -y + yc);

        if (x!=y)
        {
            draw_pixel(y+xc, x + yc);
            draw_pixel(-y + xc, x + yc);
            draw_pixel(y + xc, -x + yc);
            draw_pixel(-y + xc, -x + yc);
        }
    }

}

void myDisplay()
{
    circleDraw(0,0, 1);
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle using mid Point Algorithm");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
