#include "3d_data.hpp"
#include "color_data.hpp"
#include "animation.hpp"

#include <GLUT/glut.h>

GLfloat light0pos[] = {0.0, 0.0, 5.0, 1.0};
GLfloat light1pos[] = {5.0, 0.0, 0.0, 1.0};
GLfloat light2pos[] = {0.0, 5.0, 0.0, 1.0};

void Shading(void)
{
    int v_i;
    int n_j;
    static double rotation = 0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(3.0, 3.0, 3.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    /// Set Lights
    glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
    glLightfv(GL_LIGHT1, GL_POSITION, light1pos);
//    glLightfv(GL_LIGHT2, GL_POSITION, light2pos);

    /// Rotate by Axis-Y
    glRotated(rotation, 1.0, 1.0, 1.0);

    /// Color of Object
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, WHITE);
    /// Draw image
    glBegin(GL_QUADS);
    for (n_j = 0; n_j < 6; ++n_j)
    {
        glNormal3dv(normal[n_j]);
        for (v_i = 0; v_i < 4; ++v_i)
        {
            glVertex3dv(vertex[face[n_j][v_i]]);
        }
    }
    glEnd();

    glutSwapBuffers();
    rotation += 1.5;
    if (rotation >= 360.0) rotation = 0.0;
}

void InitLighting()
{
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, BLUE);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, GREEN);
    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, RED);

}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Shading");
    glutDisplayFunc(Shading);
    glutReshapeFunc(Resize);
    glutKeyboardFunc(KeyInput);
    InitBackGroundColor();
    InitLighting();
    glutMainLoop();
    return 0;
}