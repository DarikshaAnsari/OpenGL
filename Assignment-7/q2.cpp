// Set up an algorithm for converting a given cylinder to a
// polygon-mesh representation.
#include<iostream>
#include <GL/glut.h>
#include<stdlib.h>
// Additional GLU Quadric Functions:

    // // Activate the GLU quadric renderer for an object
    // GLUquadricObj *quadric = gluNewQuadric();

    // // Select a display mode for the predefined GLU object
    // gluQuadricDrawStyle(quadric, GLU_FILL);

    // // Display a GLU sphere
    // gluSphere(quadric, 2.0, 20, 20);

    // // Display a GLU cylinder
    // gluCylinder(quadric, 1.0, 1.0, 3.0, 15, 10);

    // // Display a GLU disk
    // gluDisk(quadric, 0.5, 1.5, 15, 5);

    // // Display a section of a GLU disk
    // gluPartialDisk(quadric, 0.5, 1.5, 15, 5, 45.0, 270.0);

    // // Eliminate the GLU quadric object
    // gluDeleteQuadric(quadric);

    // // Define inside and outside orientations for a GLU quadric object
    // gluQuadricOrientation(quadric, GLU_OUTSIDE);

    // // Specify how surface-normal vectors should be generated for a GLU quadric object
    // gluQuadricNormals(quadric, GLU_SMOOTH);

    // // Specify a callback error function for a GLU quadric object
    // gluQuadricCallback(quadric, GLU_ERROR, errorCallback);

GLsizei winWidth = 500, winHeight = 500;

void init(void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
}

void wireQuadSurfs(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 0.0, 1.0);
gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);


glutWireTeapot(1.0);
// GLUquadricObj *sphere;
// glPushMatrix();
// sphere = gluNewQuadric();

// gluQuadricDrawStyle(sphere, GLU_LINE);
//  gluDisk(sphere, 0.5, 1.5, 15, 5);
// glPopMatrix();
glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
glViewport(0, 0, newWidth, newHeight);
glMatrixMode(GL_PROJECTION);
glOrtho(-2.0, 2.0, -2.0, 2.0, 0.0, 5.0);
glMatrixMode(GL_MODELVIEW);
glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(100, 100);
glutInitWindowSize(winWidth, winHeight);
glutCreateWindow("Cylinder polygon mesh representation");
init();
glutDisplayFunc(wireQuadSurfs);
glutReshapeFunc(winReshapeFcn);
glutMainLoop();
}
// // Display wire-frame tetrahedron
//     glutWireTetrahedron();

//     // Display surface-shaded tetrahedron
//     glutSolidTetrahedron();

//     // Display wire-frame cube
//     glutWireCube(2.0);

//     // Display surface-shaded cube
//     glutSolidCube(2.0);

//     // Display wire-frame octahedron
//     glutWireOctahedron();

//     // Display surface-shaded octahedron
//     glutSolidOctahedron();

//     // Display wire-frame dodecahedron
//     glutWireDodecahedron();

//     // Display surface-shaded dodecahedron
//     glutSolidDodecahedron();

//     // Display wire-frame icosahedron
//     glutWireIcosahedron();

//     // Display surface-shaded icosahedron
//     glutSolidIcosahedron();

//     // Display wire-frame GLUT sphere
//     glutWireSphere(2.0, 20, 20);

//     // Display surface-shaded GLUT sphere
//     glutSolidSphere(2.0, 20, 20);

//     // Display wire-frame GLUT cone
//     glutWireCone(1.0, 3.0, 15, 10);

//     // Display surface-shaded GLUT cone
//     glutSolidCone(1.0, 3.0, 15, 10);

//     // Display wire-frame GLUT torus
//     glutWireTorus(0.5, 1.5, 15, 20);

//     // Display surface-shaded GLUT torus
//     glutSolidTorus(0.5, 1.5, 15, 20);

//     // Display wire-frame GLUT teapot
//     glutWireTeapot(2.0);

//     // Display surface-shaded GLUT teapot
//     glutSolidTeapot(2.0);