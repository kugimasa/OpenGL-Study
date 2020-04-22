#include "triangle.hpp"

Triangle::Triangle()
{
    m_Size = 1.0;
}

Triangle::Triangle(double size)
{
    m_Size = size;
}

Triangle::Triangle(double size, double posX, double posY)
{
    m_Size = size;
    SetVertex(posX, posY);
}

void Triangle::SetVertex(double posX, double posY)
{
    for (auto & index : m_Vertex) {
        index[0] = m_Size * index[0] + posX;
        index[1] = m_Size * index[1] + posY;
    }
}

void Hover(int x, int y)
{

    double posX =   2.0 * ( x / (double) m_Width)  - 1.0;
    double posY = - 2.0 * ( y / (double) m_Height) + 1.0;
    static double size = 0.0;
    static double step = 0.05;
    Triangle triangle(size, posX, posY);

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glBegin(GL_TRIANGLES);
    glColor3d(1.0, 1.0, 1.0);
    for (auto & vertex : triangle.m_Vertex) {
        glVertex2dv(vertex);
    }
    glEnd();
    glutSwapBuffers();

    size += step;
    if (size > 1.0) step = - 0.025;
    if (size < 0.0) step =   0.1;
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}