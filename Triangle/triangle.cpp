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
    glFlush();
}