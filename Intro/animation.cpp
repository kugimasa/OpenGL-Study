#include <iostream>
#include <GLUT/glut.h>

using namespace std;

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
    glLoadIdentity();

    gluLookAt(3.0, 4.0, 5.0,
               0.0, 0.0, 0.0,
               0.0, 1.0, 0.0);
    /// Rotate by Axis-Y
    glRotated(rotation, 0.0, 1.0, 0.0);

    /// The Color I Like
    glColor3d((double)120/255, (double)240/255, (double)80/255);
    glutSolidTeapot(1.0);
    glEnd();

    glFlush();

    if (++rotation >= 360.0) rotation = 0.0;
}

void Resize(int w, int h)
{
    /// Perspective Projection
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovy, (double)w/ (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
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

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("Animation");
    glutDisplayFunc(Display);
    glutReshapeFunc(Resize);
    glutKeyboardFunc(KeyInput);
    InitBackGroundColor();
    glutMainLoop();
    return 0;
}

