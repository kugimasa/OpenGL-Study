#include "triangle.hpp"

void InitBackGroundColor()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Hover(int x, int y)
{
    double posX =   2.0 * ( x / (double) m_Width)  - 1.0;
    double posY = - 2.0 * ( y / (double) m_Height) + 1.0;

    cout << "(" << posX << "," << posY <<  ")" << endl;
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3d(1.0, 1.0, 1.0);
    glVertex2d( cos(PI/2),      sin(PI/2));
    glVertex2d( cos(7 * PI/6),  sin(7 * PI/6));
    glVertex2d( cos(11 * PI/6), sin(11 * PI/6));
    glEnd();

    glFlush();
}