#include "triangle.hpp"

void InitBackGroundColor()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Hover(int x, int y)
{
    cout << "(" << x << "," << y <<  ")" << endl;
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3d(1.0, 1.0, 1.0);
    glVertex2d(-0.5, 0.0);
    glVertex2d( 0.5, 0.0);
    glVertex2d( 0.0, 0.5);
    glEnd();

    glFlush();
}