#include<cmath>
#include<GL/glut.h>
#include<stdlib.h>
// B-spline curve,
// Define control points for a 4x4 Bezier surface
GLfloat controlPoints[4][4][3] = {
{{-1.0, -1.0, 0.0}, {-0.5, -1.0, 1.0}, {0.5, -1.0, -1.0}, {1.0, -1.0, 0.0}},
{{-1.0, -0.5, 1.0}, {-0.5, -0.5, 0.0}, {0.5, -0.5, 0.0}, {1.0, -0.5, -1.0}},
{{-1.0, 0.5, -1.0}, {-0.5, 0.5, 0.0}, {0.5, 0.5, 0.0}, {1.0, 0.5, 1.0}},
{{-1.0, 1.0, 0.0}, {-0.5, 1.0, -1.0}, {0.5, 1.0, 1.0}, {1.0, 1.0, 0.0}}};

void drawBezierSurface()
{
int i, j;
int numDivisions = 20; // Number of divisions for tessellation

glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4,
&controlPoints[0][0][0]);
glEnable(GL_MAP2_VERTEX_3);
glEnable(GL_AUTO_NORMAL);

glMapGrid2f(numDivisions, 0.0, 1.0, numDivisions, 0.0, 1.0);
glEvalMesh2(GL_LINE, 0, numDivisions, 0, numDivisions);

glFlush();
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT |
GL_DEPTH_BUFFER_BIT);
glPushMatrix();

//glRotatef(30.0, 0, 1, 0); // Rotate for a better view
//glRotatef(50.0, 0, 0, 1);
glRotatef(90.0, 1, 0, 1);
drawBezierSurface();
glPopMatrix();
glutSwapBuffers();
}

void init()
{
glEnable(GL_DEPTH_TEST);
glClearColor(0.0, 0.0, 0.0, 1.0);
glColor3f(0.0,0.0,1.0);
glOrtho(-1.5,1.5,-1.5,1.5,-1.5,1.5);
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |
GLUT_DEPTH);
glutInitWindowSize(800, 800);
glutCreateWindow("Bezier Surface");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}