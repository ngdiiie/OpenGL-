#include "GL/freeglut.h"
#define _USE_MATH_DFINES
#include <cmath>

void renderScene(void);
void drawTreug(GLubyte r,GLubyte g,GLubyte b);

// блок реализации функций

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);
    glutMainLoop();
    return 0;
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна быть первой в renderScene

    glBegin(GL_QUAD_STRIP);
    //Фон
    glColor3ub(255, 255, 0); 
    glVertex2f(1, -1);
    glColor3ub(0, 0, 0);
    glVertex2f(-1, -1);
    glColor3ub(0, 0, 0);
    glVertex2f(1, 1);
    glColor3ub(0, 0, 54);
    glVertex2f(-1, 1);
    glEnd();
    //Ракета
    /*
    glBegin(GL_QUAD_STRIP);
    glColor3ub(176, 196, 222);
    glVertex2f(0.03, -0.13);
    glVertex2f(-0.03, -0.13);
    glVertex2f(0.025, -0.18);
    glVertex2f(-0.025, -0.18);
    glEnd();
    
    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(255, 250, 250);
    glVertex2f(-0.027, -0.13);
    glColor3ub(255, 235, 215);
    glVertex2f(0.07, -0.44);
    glColor3ub(112, 128, 144);
    glVertex2f(0.06, -0.24);
    glEnd();
    
    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(255, 250, 250);
    glVertex2f(0.027, -0.13);
    glColor3ub(255, 235, 215);
    glVertex2f(-0.07, -0.44);
    glColor3ub(112, 128, 144);
    glVertex2f(-0.06, -0.24);
    glEnd();
   
    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(112, 128, 144);
    glVertex2f(0.037, -0.2);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.037, -0.2);
    glColor3ub(0, 0, 0);
    glVertex2f(0, -0.25);
    glEnd();
    
    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.037, 0.07);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.037, -0.18);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.055, 0);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(0, 0, 0);
    glVertex2f(0.037, 0.07);
    glColor3ub(0, 0, 0);
    glVertex2f(0.037, -0.18);
    glColor3ub(0, 0, 0);
    glVertex2f(0.055, 0);
    glEnd();
    
    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 255, 255);
    glVertex2f(0.037, -0.2);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.037, -0.2);
    glColor3ub(255, 255, 255);
    glVertex2f(0.037, 0.2);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.037, 0.2);
    glEnd();
    
    glBegin(GL_QUAD_STRIP);
    glColor3ub(112, 128, 144);
    glVertex2f(0.037, 0.2);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.037, 0.2);
    glColor3ub(0, 0, 0);
    glVertex2f(0.03, 0.24);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.03, 0.24);
    glEnd();
    
    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 255, 255);
    glVertex2f(0.048, 0.24);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.048, 0.24);
    glColor3ub(255, 255, 255);
    glVertex2f(0.048, 0.4);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.048, 0.4);
    glEnd();
    
    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 255, 255);
    glVertex2f(0.035, 0.44);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.035, 0.44);
    glColor3ub(255, 255, 255);
    glVertex2f(0.048, 0.4);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.048, 0.4);
    glEnd();
    
    glBegin(GL_QUAD_STRIP);
    glColor3ub(71, 74, 81);
    glVertex2f(0.02, 0.47);
    glColor3ub(71, 74, 81);
    glVertex2f(-0.02, 0.47);
    glColor3ub(255, 255, 255);
    glVertex2f(0.035, 0.44);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.035, 0.44);
    glEnd();
    
    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 0, 0);
    glVertex2f(0.02, 0.47);
    glVertex2f(-0.02, 0.47);
    glVertex2f(0, 0.5);
    glVertex2f(0, 0.5);
    glEnd();
    */

    glColor3ub(92, 92, 92); 
    glBegin(GL_POLYGON);
    int num_segments = 100; 
    float radius = 0.5; 
    float center_x = 0.0; 
    float center_y = 0.0;
    for (int i = 0; i < num_segments; i++) {
    float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); 
    float x = radius * cosf(theta) + center_x; 
    float y = radius * sinf(theta) + center_y;
    glVertex2f(x, y); 
}
    glEnd();

    glColor3ub(41, 49, 51); // устанавливаем цвет для кратеров
    float crater_radius = 0.05; // радиус кратеров
    float num_craters = 3; // количество кратеров
    float angle = 12 / num_craters; // угол между кратерами
    float offset = 0.3; // смещение кратеров от центра луны
    for (int i = 0; i < num_craters; i++) {
        float crater_center_x = offset * cosf(i * angle) + center_x; // вычисляем координаты центра кратера
        float crater_center_y = offset * sinf(i * angle) + center_y;
        glBegin(GL_POLYGON);
        for (int j = 0; j < num_segments; j++) {
            float theta = 2.0f * 3.1415926f * float(j) / float(num_segments); // угол следующей вершины
            float x = crater_radius * cosf(theta) + crater_center_x; // вычисляем координаты следующей вершины
            float y = crater_radius * sinf(theta) + crater_center_y;
            glVertex2f(x, y); // добавляем вершину в многоугольник
        }
        glEnd();
    }
    glutSwapBuffers();
}