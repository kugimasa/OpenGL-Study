#include <GLUT/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3d(1.0, 0.0, 0.0);
    glVertex2d(-0.9,-0.9);
    glColor3d(0.0, 1.0, 0.0);
    glVertex2d(0.9,-0.9);
    glColor3d(0.0, 0.0, 1.0);
    glVertex2d(0.9,0.9);
    glColor3d(1.0, 1.0, 0.0);
    glVertex2d(-0.9,0.9);
    glEnd();
    glFlush();
}

void resize(int w, int h)
{
    const float width = 200.0;
    const float height = 200.0;
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho(-w / width, w / width, -h / height , h / height, -1.0, 1.0);
}

void initBackGroundColor(void)
{
    ///The color I like
    glClearColor((double)120/255, (double)240/255, (double)80/255,1.0);
}


int main(int argc, char *argv[])
{
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 240);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("Viewport");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    initBackGroundColor();
    glutMainLoop();
    return 0;
}