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

void CreateTriangle(Triangle triangle, double *color, double alpha)
{
    glBegin(GL_TRIANGLES);
    glColor4d(color[0], color[1], color[2], alpha);
    for (auto & vertex : triangle.m_Vertex) {
        glVertex2dv(vertex);
    }
    glEnd();
}

void DrawTriangle(void)
{
    static double step = 0.05;
    static int state = 0;
    Triangle triangle0(SIZE, ORIGIN[0], ORIGIN[1]);
    Triangle triangle1(SIZE+0.05, ORIGIN[0] - DIRECTION[0], ORIGIN[1] - DIRECTION[1]);
    Triangle triangle2(SIZE+0.1, ORIGIN[0] - DIRECTION[0] * 2, ORIGIN[1] - DIRECTION[1] * 2);
    Triangle triangle3(SIZE+0.15, ORIGIN[0] - DIRECTION[0] * 3, ORIGIN[1] - DIRECTION[1] * 3);
    double* color = triangle0.GetColor(state);

    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    // Draw Blur Triangle
    glBlendFunc(GL_SRC_COLOR, GL_DST_COLOR);
    CreateTriangle(triangle3, color, 0.1);
    CreateTriangle(triangle2, color, 0.2);
    CreateTriangle(triangle1, color, 0.3);
    // Draw Original Triangle
    glBlendFunc(GL_ONE, GL_ZERO);
    CreateTriangle(triangle0, color, 1.0);
    glDisable(GL_BLEND);
    glutSwapBuffers();

    SIZE += step;
    if (SIZE > 0.5) step = triangle0.m_DecreaseStep;
    if (SIZE < 0.0){
        step = triangle0.m_IncreaseStep;
        if (state++ >= 3) state = 0;
    }

}

void Hover(int x, int y)
{
    double newOrigin[] = {  2.0 * ( x / (double) WIDTH)  - 1.0,
                          - 2.0 * ( y / (double) HEIGHT) + 1.0 };
    DIRECTION[0] = newOrigin[0] - ORIGIN[0];
    DIRECTION[1] = newOrigin[1] - ORIGIN[1];
    ORIGIN[0] = newOrigin[0];
    ORIGIN[1] = newOrigin[1];
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
