#include "triangle.hpp"

void Hover(int x, int y)
{
    double posX =   2.0 * ( x / (double) m_Width)  - 1.0;
    double posY = - 2.0 * ( y / (double) m_Height) + 1.0;

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glBegin(GL_TRIANGLES);
    glColor3d(1.0, 1.0, 1.0);
    glVertex2d( cos(PI/2) + posX, sin(PI/2) + posY);
    glVertex2d( cos(7 * PI/6) + posX,  sin(7 * PI/6) + posY);
    glVertex2d( cos(11 * PI/6) + posX, sin(11 * PI/6) + posY);
    glEnd();

    glFlush();
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}