#include "animation.hpp"
#include <GLUT/glut.h>

const float fovy = 30.0;
bool animationPlay = false;

void Idle(void)
{
    glutPostRedisplay();
}

void InitBackGroundColor()
{
    /// Black
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Display(void)
{
    static double rotation = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    /// Rotate by Axis-Y
    glRotated(rotation, 0.0, 1.0, 0.0);

    /// The Color I Like
    glColor3d((double)120/255, (double)240/255, (double)80/255);
    glutWireTeapot(1.0);
    glEnd();

    glutSwapBuffers();
    if (++rotation >= 360.0) rotation = 0.0;
}

void Resize(int w, int h)
{

    glViewport(0, 0, w, h);

    /// Perspective Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovy, (double)w/ (double)h, 1.0, 100.0);

    /// Set Camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(6.0, 8.0, 10.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
}

void KeyInput(unsigned char key, int x, int y)
{
    /// Animation Play/Pause
    if (key == ' ')
    {
        animationPlay = !animationPlay;
        string state;
        if (animationPlay)
        {
            state = "Play 👍";
            glutIdleFunc(Idle);
        }
        else
        {
            state = "Pause ✋";
            glutIdleFunc(0);
        }

        cout << "Animation " + state << endl;
    }
    /// Exit
    if (key == 'q' || key == 'Q' || key == 27)
    {
        cout << "Close Project 👋" << endl;
        exit(0);
    }
}

