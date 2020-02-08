#include <iostream>
#include <GLUT/glut.h>

const float width = 200.0;
const float height = 200.0;

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    /// The Color I Like
    glColor3d((double)120/255, (double)240/255, (double)80/255);
    glRotated(25.0,0.0 ,1.0 , 0.0);
    glRotated(25.0,1.0 ,0.0 , 0.0);
    glutWireCube(1.0);
    glEnd();
    glFlush();
}

void Resize(int w, int h)
{
    glViewport(0,0, w, h);
    glLoadIdentity();
    /// The Cube is scaled depending on the window size
//    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    /// The Cube size doesn't change
    glOrtho(-w / width, w / width, -h / height, h / height, -2.0, 2.0);
}


void InitBackGroundColor(void)
{
    /// Black
    glClearColor(0.0, 0.0, 0.0,1.0);
}

void Exit(unsigned char key, int x, int y)
{
    if(key == 'q' || key == 'Q' || key == 27)
    {
        std::cout << "Close Project 👋" << std::endl;
        exit(0);
    }
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("CUBE");
    glutDisplayFunc(Display);
    glutReshapeFunc(Resize);
    glutKeyboardFunc(Exit);
    InitBackGroundColor();
    glutMainLoop();
    return 0;
}