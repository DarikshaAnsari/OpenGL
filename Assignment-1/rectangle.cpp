#include <GL/glut.h>
#include <cmath>

// Cube vertices
GLfloat vertices[] = {
    -0.5f, -0.5f, -0.5f, // Vertex 0
     0.5f, -0.5f, -0.5f, // Vertex 1
     0.5f,  0.5f, -0.5f, // Vertex 2
    -0.5f,  0.5f, -0.5f, // Vertex 3
    -0.5f, -0.5f,  0.5f, // Vertex 4
     0.5f, -0.5f,  0.5f, // Vertex 5
     0.5f,  0.5f,  0.5f, // Vertex 6
    -0.5f,  0.5f,  0.5f  // Vertex 7
};

// Indices to define cube faces
GLuint indices[] = {
    0, 1, 2, 3, // Front face
    4, 5, 6, 7, // Back face
    0, 3, 7, 4, // Left face
    1, 2, 6, 5, // Right face
    0, 1, 5, 4, // Bottom face
    2, 3, 7, 6  // Top face
};

// Translation and rotation parameters
GLfloat translation[] = { -1.0f, -1.0f, -1.0f };
GLfloat rotationAngle = 45.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Apply translation
    glTranslatef(translation[0], translation[1], translation[2]);

    // Apply rotation
    glRotatef(rotationAngle, 1.0f, 1.0f, 1.0f);

    // Render the cube
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, indices);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Cube");

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
