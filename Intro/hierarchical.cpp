#include "3d_data.hpp"
#include "color_data.hpp"
#include "animation.hpp"

#include <GLUT/glut.h>

GLfloat light0pos[] = {0.0, 3.0, 5.0, 1.0};
GLfloat light1pos[] = {5.0, 3.0, 0.0, 1.0};

void InitLighting()
{
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, WHITE);
}

void DisplayCube(void)
{
    static double rotation = 0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /// Set Lights
    glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
    glLightfv(GL_LIGHT1, GL_POSITION, light1pos);

    /// Cube1 ///
    /// Push ModelView-Matrix
    glPushMatrix();
    glRotated(rotation, 0.0, 1.0, 0.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, KUGI_COLOR);
    Cube();

    /// Cube2 ///
    /// Push ModelView-Matrix
    glPushMatrix();
    glTranslated(1.0, 1.0, 1.0);
    glRotated(2 * rotation, 0.0, 1.0, 0.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, RED);
    Cube();
    /// Pop ModelView-Matrix
    glPopMatrix();

    /// Pop ModelView-Matrix
    glPopMatrix();

    glutSwapBuffers();
    /// Reset Rotate-Angle
    if (++rotation >= 360) rotation = 0;
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Hierarchical");
    glutDisplayFunc(DisplayCube);
    glutReshapeFunc(Resize);
    glutKeyboardFunc(KeyInput);
    InitBackGroundColor();
    InitLighting();
    glutMainLoop();
    return 0;
}