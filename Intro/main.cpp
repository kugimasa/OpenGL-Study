#include <iostream>
#include <GLUT/glut.h>

#define MAXPOINTS 100
GLint points[MAXPOINTS][2];
int point_num = 0;


void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    /// Draw all the lines
    if (point_num > 1)
    {
        /// Stroke Color (White)
        glColor3d(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        for (int i = 0; i < point_num; ++i)
        {
            glVertex2iv(points[i]);
        }
        glEnd();
    }

    glFlush();
}

void Resize(int w, int h)
{
    /// The origin of viewport(mouse) in world coordinate
    const float origin_x = -0.5;
    const float origin_y = -0.5;
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho(origin_x, w + origin_x, h + origin_y, origin_y, -1.0, 1.0);
}

void Mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        points[point_num][0] = x;
        points[point_num][1] = y;
        if (state == GLUT_UP)
        {
            /// Stroke Color (White)
            glColor3d(0.0, 0.0, 0.0);
            glBegin(GL_LINES);
            glVertex2iv(points[point_num - 1]);
            glVertex2iv(points[point_num]);
            glEnd();
            glFlush();
        }
        if (point_num < MAXPOINTS - 1) ++point_num;
    }
}

void InitBackGroundColor(void)
{
    ///The color I like
    glClearColor((double)120/255, (double)240/255, (double)80/255,1.0);
}


int main(int argc, char *argv[])
{
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(320, 240);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("Canvas");
    glutDisplayFunc(Display);
    glutReshapeFunc(Resize);
    glutMouseFunc(Mouse);
    InitBackGroundColor();
    glutMainLoop();
    return 0;
}