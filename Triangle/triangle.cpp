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

void DrawBlur(double step)
{
    double blurSize = SIZE + step;
    Triangle triangle(blurSize, ORIGIN[0], ORIGIN[1]);

    glColor4dv(WHITE);
    for (auto & vertex : triangle.m_Vertex) {
        glVertex2dv(vertex);
    }
    glEnd();
    glutSwapBuffers();
}

void DrawTriangle(void)
{
    static double step = 0.05;
    static int state = 0;
    Triangle triangle(SIZE, ORIGIN[0], ORIGIN[1]);
    Triangle blur(SIZE+0.1, ORIGIN[0], ORIGIN[1]);
    Triangle blur2(SIZE+0.05, ORIGIN[0], ORIGIN[1]);
    double* color = triangle.GetColor(state);

    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4d(color[0], color[1], color[2], 0.2);
    for (auto & vertex : blur.m_Vertex) {
        glVertex2dv(vertex);
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor4d(color[0], color[1], color[2], 0.4);
    for (auto & vertex : blur2.m_Vertex) {
        glVertex2dv(vertex);
    }
    glEnd();

    glBlendFunc(GL_ONE, GL_ZERO);
    glBegin(GL_TRIANGLES);
    glColor4d(color[0], color[1], color[2], 1.0);
    for (auto & vertex : triangle.m_Vertex) {
        glVertex2dv(vertex);
    }
    glDisable(GL_BLEND);

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
