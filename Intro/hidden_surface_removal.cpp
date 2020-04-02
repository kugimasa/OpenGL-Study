#include <GLUT/glut.h>
#include "animation.hpp"

const float fovy = 30.0;

void TeaPots(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    gluLookAt(3.0, 4.0, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    /*
    glTranslated(0.5, 0.0, 0.0);
    glColor3d(0, 1, 0);
    glutWireTeapot(1.0);

    glTranslated(-1.0, 0.0, 0.0);
    glColor3d(1, 0, 0);
    glutWireTeapot(1.0);
    */

    glColor3d(0, 0, 1);
    glutSolidTeapot(1.0);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("HiddenSurfaceRemoval");
    glutDisplayFunc(TeaPots);
    glutReshapeFunc(Resize);
    glutKeyboardFunc(KeyInput);
    InitBackGroundColor();
    //    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glutMainLoop();
    return 0;
}
