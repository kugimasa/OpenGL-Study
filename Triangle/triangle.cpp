#include "triangle.hpp"

Triangle::Triangle()
{
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

double* Triangle::GetColor(int state)
{
    switch(state){
        case 0:
            return CANDY_PINK;
        case 1:
            return QUEEN_BLUE;
        case 2:
            return MEDIUM_AQUAMARINE;
        case 3:
            return SUNRAY;
        default:
            return BLACK;
    }
}

void DrawTriangle(void)
{
    static double step = 0.05;
    static int state = 0;
    Triangle triangle(SIZE, ORIGIN[0], ORIGIN[1]);

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    double* color = triangle.GetColor(state);
    glColor3d(color[0], color[1], color[2]);
    for (auto & vertex : triangle.m_Vertex) {
        glVertex2dv(vertex);
    }
    glEnd();
    glutSwapBuffers();

    SIZE += step;
    if (SIZE > 1.0) step = triangle.m_DecreaseStep;
    if (SIZE < 0.0){
        step = triangle.m_IncreaseStep;
        if (state++ >= 3) state = 0;
    }
}

void Hover(int x, int y)
{
    ORIGIN[0] =   2.0 * ( x / (double) WIDTH)  - 1.0;
    ORIGIN[1] = - 2.0 * ( y / (double) HEIGHT) + 1.0;
    DrawTriangle();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, 1.0);
    glutSwapBuffers();
}

void Idle()
{
    DrawTriangle();
}
