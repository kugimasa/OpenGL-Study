#include "triangle.hpp"

int main(int argc, char *argv[]) {
    glutInitWindowSize(m_Width, m_Height);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("Triangle");
    glutDisplayFunc(Display);
    glutPassiveMotionFunc(Hover);
    glutMainLoop();
    return 0;
}
