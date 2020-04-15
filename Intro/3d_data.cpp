#include "3d_data.hpp"
#include <GLUT/glut.h>

void Cube(void)
{
    int v_i, n_j;
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
}