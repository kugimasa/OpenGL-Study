#include <GLUT/glut.h>

void Display(void)
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

void Resize(int w, int h)
{
    const float basic_width = 200.0;
    const float basic_height = 200.0;
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho(-w / basic_width, w / basic_width, -h / basic_height , h / basic_height, -1.0, 1.0);
}

void InitBackGroundColor(void)
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
    glutDisplayFunc(Display);
    glutReshapeFunc(Resize);
    InitBackGroundColor();
    glutMainLoop();
    return 0;
}