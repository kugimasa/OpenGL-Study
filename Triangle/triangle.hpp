#ifndef TRIANGLE_TRIANGLE_HPP
#define TRIANGLE_TRIANGLE_HPP

#include <cmath>
#include <iostream>
#include <GLUT/glut.h>

#include "color_data.hpp"

using namespace std;

static const double PI = 3.141592653589793;
const int WIDTH = 500;
const int HEIGHT = 500;

static double SIZE = 0.0;
static double ORIGIN[] = {0.0, 0.0};

class Triangle
{
public:
    Triangle();
    Triangle(double size, double posX, double posY);
    void SetVertex(double posX, double posY);
    double* GetColor(int state);

    double m_Size = 1.0;
    double m_Vertex[3][2] = {
            {cos(PI/2), sin(PI/2)},
            {cos(7 * PI/6), sin(7 * PI/6)},
            {cos(11 * PI/6), sin(11 * PI/6)}
    };
    double m_DecreaseStep = - 0.03;
    double m_IncreaseStep = 0.1;
};

void CreateTriangle(Triangle triangle, double* color, double alpha);
void DrawTriangle(void);
void Hover(int x, int y);
void Display(void);
void Idle(void);

#endif //TRIANGLE_TRIANGLE_HPP