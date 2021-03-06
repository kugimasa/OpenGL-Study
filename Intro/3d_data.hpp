#ifndef INTRO_3D_DATA_HPP
#define INTRO_3D_DATA_HPP

#include <GLUT/glut.h>

static GLdouble vertex[][3] = {
        {0.0, 0.0, 0.0}, /* A */
        {1.0, 0.0, 0.0}, /* B */
        {1.0, 1.0, 0.0}, /* C */
        {0.0, 1.0, 0.0}, /* D */
        {0.0, 0.0, 1.0}, /* E */
        {1.0, 0.0, 1.0}, /* F */
        {1.0, 1.0, 1.0}, /* G */
        {0.0, 1.0, 1.0}  /* H */
};

static int face[][4] = {
        {0, 1, 2, 3}, /* A - B - C - D */
        {1, 5, 6, 2}, /* B - F - G - C */
        {5, 4, 7, 6}, /* F - E - H - G */
        {4, 0, 3, 7}, /* E - A - D - H */
        {4, 5, 1, 0}, /* E - F - B - A */
        {3, 2, 6, 7}, /* D - C - G - H */
};

static GLdouble normal[][3] = {
        { 0.0,  0.0, -1.0},
        { 1.0,  0.0,  0.0},
        { 0.0,  0.0,  1.0},
        {-1.0,  0.0,  0.0},
        { 0.0, -1.0,  0.0},
        { 0.0,  1.0,  0.0}
};

void Cube(void);

#endif //INTRO_3D_DATA_HPP
