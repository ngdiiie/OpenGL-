#include <GL/glut.h>
#define _USE_MATH_DFINES
#include <cmath>
#include <array>
#include <ctime>
struct Position{
    GLfloat x, y;
};
struct Figure{
    Position pos;
    bool isRight;
    GLfloat health;
};

struct Point{
    float x,y;
};

const int n = 100;
std::array <Point, n> graph;

Figure rocket = {{0, 0},false, 100};
Figure moon = {{1, 1}, false, 100};
clock_t time_appStart;
clock_t time_anima1;

void initGraph();
void plotGraph();
void plotAxes();

void renderScene(void);
void drawTreug(GLubyte r,GLubyte g,GLubyte b);
void drawRocket(Figure &f);
void drawMoon(Figure &f);
void processKeys(unsigned char key, int x, int y);
void animate(int value);
void drawAnima();
// блок реализации функций

int main(int argc, char* argv[])
{
    initGraph();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("Space");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(processKeys);
    glutTimerFunc(1000/60, animate, 1);
    time_appStart=clock();
    time_anima1=clock();
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
    plotGraph();
    //Ракета
    Figure f = {0.5, 0, false, 100};
    drawRocket(f);
    f.pos.x = -0.5;
    f.pos.y = 0.3;
    drawRocket(f);
    drawRocket(rocket);
/*
    //луна
    drawMoon(f);
    f.pos.x = -0.5;
    f.pos.y = 0.3;
    drawMoon(f);
    drawMoon(moon);
*/

    glutSwapBuffers();
}

void plotAxes(){
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(0,0);
    glVertex2f(3,0);
    glColor3f(0,0,1);
    glVertex2f(0,0);
    glVertex2f(0,3);
    glEnd();
}

void plotGraph(){
    glPushMatrix();
    glScalef(0.1, 0.1, 1);
    glTranslatef(-3, 0, 0);

    plotAxes();

    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);
    for(int i=0; i< graph.size(); i++)
        glVertex2f(graph[i].x, graph[i].y);

    glEnd();
    glPopMatrix();
}

void initGraph(){
    Point p;

    float x = 0.0;
    float xf = 2*3.14;
    float h = (xf - x)/n;
    int i = 0;
    while(x<xf){

        //астроида
        //p.x = 2*(pow(sin(x),3));
        //p.y = 2*(pow(cos(x),3));

        //сердце
        //p.x = 16*pow(sin(x), 3);
        //p.y = 13*cos(x)-5*cos(2*x)-2*cos(3*x)-cos(4*x);

        //pz
        //p.x = 3.0*cos(2.0*x); //x
        //p.y = 2.0*sinf(3.0*x)+1;
        graph[i]=p;
        x = x+h;
        i++;
    }

}
/*void drawMoon(Figure &f){
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
}
*/

void drawRocket(Figure &f){
    glPushMatrix();
    glTranslatef(f.pos.x, f.pos.y, 0);
    if(f.isRight)
        glRotatef(180, 0, 1, 0);
    glScalef(0.5, 0.5, 1);
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
    glPopMatrix();
}

void processKeys(unsigned char key, int x, int y){
    if(key == 'w'){
        rocket.pos.y += 0.01;
        rocket.isRight = true;
    }
    if(key == 's'){
        rocket.pos.y -= 0.01;
        rocket.isRight = false;
    }
    if(key == 'a'){
        rocket.pos.x -= 0.01;
        rocket.isRight = true;
    }
    if(key == 'd'){
        rocket.pos.x += 0.01;
        rocket.isRight = true;
    }
    glutPostRedisplay();

}

void animate(int value){
    glutPostRedisplay();
    glutTimerFunc(1000/60, animate, 1);
}

void drawAnima(){
    clock_t cT=clock()-time_appStart-time_anima1;
    float x,y;
    if(cT<1000.0){
        y = 0.0;
        x = 0.0+(1.0-0.0)/(1000.0-0.0)*cT;
    }else{
        if(cT<3000.0){
            x = 0.0+(1.0-0.0)/(1000.0-0.0)*1000.0;
            y = 0.0+(1.0-0.0)/(3000.0-1000.0)*cT;
        }else{
            time_anima1 = clock();
        }
    }
    glTranslatef(x,y,0);
}

