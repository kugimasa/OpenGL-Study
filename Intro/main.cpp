#include <GLUT/glut.h>

void display(void)
{
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("Intro");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}