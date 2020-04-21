#include "triangle.hpp"

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("Triangle");
    glutDisplayFunc(Display);
    glutPassiveMotionFunc(Hover);
    InitBackGroundColor();
    glutMainLoop();
    return 0;
}
