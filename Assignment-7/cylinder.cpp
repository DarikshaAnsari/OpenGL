#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

float sphereRadius = 1.0;
bool isWireframe = false;
GLfloat rotationX = 0.0, rotationY = 0.0;
GLfloat translationX = 0.0, translationY = 0.0, translationZ = 0.0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(translationX, translationY, translationZ);
    glRotatef(rotationX, 1, 0, 0);
    glRotatef(rotationY, 0, 1, 0);

    char view;
    glColor3f(1.0, 1.0, 1.0);
    cout << "Enter the sphere view (wireframe(w) / solid(s)): ";
    cin >> view;

    if (view == 's')
    {
        if (isWireframe)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            isWireframe = false;
        }
        glutSolidSphere(sphereRadius, 30, 30);
    }
    else
    {
        if (!isWireframe)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            isWireframe = true;
        }
        glutWireSphere(sphereRadius, 30, 30);
    }

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        rotationX -= 5;
        break;
    case GLUT_KEY_DOWN:
        rotationX += 5;
        break;
    case GLUT_KEY_LEFT:
        rotationY -= 5;
        break;
    case GLUT_KEY_RIGHT:
        rotationY += 5;
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        translationZ += 0.1;
        break;
    case 's':
        translationZ -= 0.1;
        break;
    case 'a':
        translationX -= 0.1;
        break;
    case 'd':
        translationX += 0.1;
        break;
    case '+':
        sphereRadius += 0.1;
        break;
    case '-':
        if (sphereRadius > 0.1)
            sphereRadius -= 0.1;
        break;
    case 27: // Escape key
        exit(0);
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 4.0 / 3.0, 1, 40);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Interactive Sphere");
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();

    return 0;
}