#include <iostream>
#include <GLUT/glut.h>

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
    glutKeyboardFunc(Exit);
    InitBackGroundColor();
    glutMainLoop();
    return 0;
}