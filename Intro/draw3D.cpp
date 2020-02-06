#include <iostream>
#include <GLUT/glut.h>

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    /// Rotate 45(deg) in axis-Y
    glRotated(45.0, 0.0, 1.0, 0.0);

    glBegin(GL_POLYGON);
    glColor3d(1.0, 0.0, 0.0);
    glVertex2d(-0.9, -0.9);
    glColor3d(0.0, 1,0.0);
    glVertex2d(0.9, -0.9);
    glColor3d(0.0, 0.0, 1.0);
    glVertex2d(0.9, 0.9);
    glColor3d(1.0, 1.0, 0.0);
    glVertex2d(-0.9, 0.9);
    glEnd();
    glFlush();
}

void InitBackGroundColor(void)
{
    ///The color I like
    glClearColor((double)120/255, (double)240/255, (double)80/255,1.0);
}

void Exit(unsigned char key, int x, int y)
{
    if(key == 'q' || key == 'Q' || key == 27)
    {
        std::cout << "Close Project 👋" << std::endl;
        exit(0);
    }
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("Draw-in-3D");
    glutDisplayFunc(Display);
    glutKeyboardFunc(Exit);
    InitBackGroundColor();
    glutMainLoop();
    return 0;
}