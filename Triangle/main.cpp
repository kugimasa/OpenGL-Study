#include "triangle.hpp"

int main(int argc, char *argv[]) {
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("Triangle");
    glutDisplayFunc(Display);
    glutPassiveMotionFunc(Hover);
    glClearColor(BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, 1.0);
    glutIdleFunc(Idle);
    glutMainLoop();
    return 0;
}
