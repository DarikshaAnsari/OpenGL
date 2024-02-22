#include <bits/stdc++.h>

#include <GL/glut.h>
using namespace std;
/*Draw a line using Bresenham's line algorithm , following line segments
and note dawn the time taken by each of the algorithms.
1.line
2.A
3.Star
*/
void bresenham(int sx, int sy, int fx, int fy) {
 int m_new = 2 * (fy - sy);
 int m_error = m_new - (fx - sx);
 int y = sy;
 for (int x = sx;x <= fx;x++) {
 glVertex2f(x, y);
m_error += m_new;
if (m_error >= 0) {
 y++;
 m_error -= 2 * (fx - sx);
}
 }
}
void display() {
 glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
 glClear(GL_COLOR_BUFFER_BIT);

 glPointSize(5);

 glBegin(GL_POINTS);

 glColor3f(1.0f, 0.0f, 0.0f);

 bresenham(-500, -500, 500, 500);

 glEnd();

 glFlush();
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(512, 512);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Output using OpenGL");
 glClearColor(0.0, 0.0, 0.0, 1.0);
 glutDisplayFunc(display);
 gluOrtho2D(-1000.0, 1000.0, -1000.0, 1000.0);
 glutMainLoop();
return 0;
}
