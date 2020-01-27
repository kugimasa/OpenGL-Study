#include <iostream>
#include <GLUT/glut.h>

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void Resize(int w, int h)
{
//    const float basic_width = 200.0;
//    const float basic_height = 200.0;
    const float basic_width = 1.0;
    const float basic_height = 1.0;
    /// The origin of viewport(mouse) in world coordinate
    const float origin_x = -0.5;
    const float origin_y = -0.5;
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho(origin_x / basic_width , (w + origin_x) / basic_width, h + origin_y / basic_height , origin_y / basic_height, -1.0, 1.0);
}

void Mouse(int button, int state, int x, int y)
{
    static int point_x, point_y;
    std::string direction;
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_UP)
        {
            /// Stroke Color (White)
            glColor3d(0.0, 0.0, 0.0);
            glBegin(GL_LINES);
            glVertex2i(point_x, point_y);
            glVertex2i(x, y);
            glEnd();
            glFlush();
        } else {
            /// Remember point clicked
            point_x = x;
            point_y = y;
        }
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