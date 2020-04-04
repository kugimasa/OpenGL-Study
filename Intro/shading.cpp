#include "3d_data.hpp"
#include "animation.hpp"

#include <GLUT/glut.h>

void Shading(void)
{
    int v_i;
    int n_j;
    static double rotation = 0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(3.0, 4.0, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    /// Rotate by Axis-Y
    glRotated(rotation, 1.0, 1.0, 1.0);

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
    if (++rotation >= 360.0) rotation = 0.0;
}

void InitLighting()
{
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
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