#ifndef TRIANGLE_TRIANGLE_HPP
#define TRIANGLE_TRIANGLE_HPP

#include <cmath>
#include <iostream>
#include <GLUT/glut.h>

using namespace std;

static const double PI = 3.141592653589793;
const int m_Width = 500;
const int m_Height = 500;

class Triangle
{
public:
    Triangle();
    Triangle(double size);
    Triangle(double size, double posX, double posY);
    void SetSize(double size);
    double GetSize();
    void SetVertex(double posX, double posY);

    double m_Size;
    double m_Vertex[3][2] = {
            {cos(PI/2), sin(PI/2)},
            {cos(7 * PI/6), sin(7 * PI/6)},
            {cos(11 * PI/6), sin(11 * PI/6)}
    };
};
#endif //TRIANGLE_TRIANGLE_HPP

void Hover(int x, int y);
void Display(void);