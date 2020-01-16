// Sistema Solar (Principal)

#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define p 112
#define v 118

// Variáveis para controles de navegação
GLfloat eixoZ, fAspect=1;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
int x_ini, y_ini, bot;

int mov = 1 , tela = 1, show = 0;
int vista=1;
// Angulo de rotação para camera
float angulo = 0.1f;

char texto[30];
GLfloat win=150, r, g, b;
GLint view_w, view_h, primitiva=-1;

void DesenharEstrelas() {
	GLfloat luz_emissao[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);	
    glColor3f(1.0f, 1.0f, 1.0f); // Cor Branca
    glBegin(GL_POINTS);
    
    //Frente
	glVertex3f(0.0f, 0.0f, -150.0f);
	glVertex3f(10.0f, 10.0f, -150.0f);
	glVertex3f(50.0f, 9.0f, -150.0f);
	glVertex3f(70.0f, 55.0f, -150.0f);
	glVertex3f(20.0f, 100.0f, -150.0f);
	glVertex3f(-10.0f, 16.0f, -150.0f);
	glVertex3f(-9.0f, 60.0f, -150.0f);
	glVertex3f(-80.0f, 10.0f, -150.0f);
	glVertex3f(-13.0f, 6.0f, -150.0f);
	glVertex3f(-90.0f, 50.0f, -150.0f);
	glVertex3f(-10.0f, -10.0f, -150.0f);
	glVertex3f(9.0f, 50.0f, -150.0f);
	glVertex3f(55.0f, 70.0f, -150.0f);
	glVertex3f(100.0f, 20.0f, -150.0f);
	glVertex3f(16.0f, -10.0f, -150.0f);
	glVertex3f(-60.0f, 9.0f, -150.0f);
	glVertex3f(-10.0f, 80.0f, -150.0f);
	glVertex3f(6.0f, -13.0f, -150.0f);
	glVertex3f(-40.0f, 40.0f, -150.0f);
	glVertex3f(60.0f, 2.0f, -150.0f);
	glVertex3f(-50.0f, 3.0f, -150.0f);
	glVertex3f(-22.0f, 5.0f, -150.0f);
	glVertex3f(5.0f, 100.0f, -150.0f);
	glVertex3f(70.0f, 16.0f, -150.0f);
	glVertex3f(90.0f, -60.0f, -150.0f);
	glVertex3f(-75.0f, 10.0f, -150.0f);
	glVertex3f(-30.0f, 6.0f, -150.0f);
	glVertex3f(-90.0f, 25.0f, -150.0f);
	glVertex3f(120.0f, -10.0f, -150.0f);
	glVertex3f(-110.0f, 0.0f, -150.0f);
	glVertex3f(90.0f, -230.0f, -150.0f);
	glVertex3f(50.0f, -8.0f, -150.0f);
	glVertex3f(-90.0f, -1.0f, -150.0f);
	glVertex3f(45.0f, -4.0f, -150.0f);
	glVertex3f(20.0f, 90.0f, -150.0f);
	glVertex3f(-46.0f, 10.0f, -150.0f);
	glVertex3f(-30.0f, 50.0f, -150.0f);
	glVertex3f(10.0f, 100.0f, -150.0f);
	glVertex3f(-55.0f, 6.0f, -150.0f);
	glVertex3f(0.0f, 10.0f, -150.0f);
	glVertex3f(-90.0f, -5.0f, -150.0f);
	glVertex3f(10.0f, -16.0f, -150.0f);
	glVertex3f(-3.0f, -30.0f, -150.0f);
	glVertex3f(20.0f, -8.0f, -150.0f);
	glVertex3f(-12.0f, -1.0f, -150.0f);
	glVertex3f(6.0f, -4.0f, -150.0f);
	glVertex3f(30.0f, -20.0f, -150.0f);
	glVertex3f(-90.0f, -5.0f, -150.0f);
	glVertex3f(30.0f, -60.0f, -150.0f);
	glVertex3f(-60.0f, -65.0f, -150.0f);
	glVertex3f(120.0f, -80.0f, -150.0f);
	
	// Trás
	glVertex3f(0.0f, 0.0f, 150.0f);
	glVertex3f(10.0f, 10.0f, 150.0f);
	glVertex3f(50.0f, 9.0f, 150.0f);
	glVertex3f(70.0f, 55.0f, 150.0f);
	glVertex3f(20.0f, 100.0f, 150.0f);
	glVertex3f(-10.0f, 16.0f, 150.0f);
	glVertex3f(-9.0f, 60.0f, 150.0f);
	glVertex3f(-80.0f, 10.0f, 150.0f);
	glVertex3f(-13.0f, 6.0f, 150.0f);
	glVertex3f(-90.0f, 50.0f, 150.0f);
	glVertex3f(-10.0f, -10.0f, 150.0f);
	glVertex3f(9.0f, 50.0f, 150.0f);
	glVertex3f(55.0f, 70.0f, 150.0f);
	glVertex3f(100.0f, 20.0f, 150.0f);
	glVertex3f(16.0f, -10.0f, 150.0f);
	glVertex3f(-60.0f, 9.0f, 150.0f);
	glVertex3f(-10.0f, 80.0f, 150.0f);
	glVertex3f(6.0f, -13.0f, 150.0f);
	glVertex3f(-40.0f, 40.0f, 150.0f);
	glVertex3f(60.0f, 2.0f, 150.0f);
	glVertex3f(-50.0f, 3.0f, 150.0f);
	glVertex3f(-22.0f, 5.0f, 150.0f);
	glVertex3f(5.0f, 100.0f, 150.0f);
	glVertex3f(70.0f, 16.0f, 150.0f);
	glVertex3f(90.0f, -60.0f, 150.0f);
	glVertex3f(-75.0f, 10.0f, 150.0f);
	glVertex3f(-30.0f, 6.0f, 150.0f);
	glVertex3f(-90.0f, 25.0f, 150.0f);
	glVertex3f(120.0f, -10.0f, 150.0f);
	glVertex3f(-110.0f, 0.0f, 150.0f);
	glVertex3f(90.0f, -230.0f, 150.0f);
	glVertex3f(50.0f, -8.0f, 150.0f);
	glVertex3f(-90.0f, -1.0f, 150.0f);
	glVertex3f(45.0f, -4.0f, 150.0f);
	glVertex3f(20.0f, 90.0f, 150.0f);
	glVertex3f(-46.0f, 10.0f, 150.0f);
	glVertex3f(-30.0f, 50.0f, 150.0f);
	glVertex3f(10.0f, 100.0f, 150.0f);
	glVertex3f(-55.0f, 6.0f, 150.0f);
	glVertex3f(0.0f, 10.0f, 150.0f);
	glVertex3f(-90.0f, -5.0f, 150.0f);
	glVertex3f(10.0f, -16.0f, 150.0f);
	glVertex3f(-3.0f, -30.0f, 150.0f);
	glVertex3f(20.0f, -8.0f, 150.0f);
	glVertex3f(-12.0f, -1.0f, 150.0f);
	glVertex3f(6.0f, -4.0f, 150.0f);
	glVertex3f(30.0f, -20.0f, 150.0f);
	glVertex3f(-90.0f, -5.0f, 150.0f);
	glVertex3f(30.0f, -60.0f, 150.0f);
	glVertex3f(-60.0f, -65.0f, 150.0f);
	glVertex3f(120.0f, -80.0f, 150.0f);
	
	//Direita
	glVertex3f(150.0f, 0.0f, 0.0f);
	glVertex3f(150.0f, 10.0f, 10.0f);
	glVertex3f(150.0f, 9.0f, 50.0f);
	glVertex3f(150.0f, 55.0f, 70.0f);
	glVertex3f(150.0f, 100.0f, 20.0f);
	glVertex3f(150.0f, 16.0f, -10.0f);
	glVertex3f(150.0f, 60.0f, -90.0f);
	glVertex3f(150.0f, 10.0f, -80.0f);
	glVertex3f(150.0f, 6.0f, -13.0f);
	glVertex3f(150.0f, 50.0f, -90.0f);
	glVertex3f(150.0f, -10.0f, -10.0f);
	glVertex3f(150.0f, 50.0f, 9.0f);
	glVertex3f(150.0f, 70.0f, 55.0f);
	glVertex3f(150.0f, 20.0f, 100.0f);
	glVertex3f(150.0f, -10.0f, 16.0f);
	glVertex3f(150.0f, 9.0f, -60.0f);
	glVertex3f(150.0f, 80.0f, -10.0f);
	glVertex3f(150.0f, -13.0f, 6.0f);
	glVertex3f(150.0f, 40.0f, -40.0f);
	glVertex3f(150.0f, 2.0f, 60.0f);
	glVertex3f(150.0f, 3.0f, 50.0f);
	glVertex3f(150.0f, 5.0f, -22.0f);
	glVertex3f(150.0f, 100.0f, 5.0f);
	glVertex3f(150.0f, 16.0f, 70.0f);
	glVertex3f(150.0f, -60.0f, 90.0f);
	glVertex3f(150.0f, 10.0f, -75.0f);
	glVertex3f(150.0f, 6.0f, -30.0f);
	glVertex3f(150.0f, 25.0f, -90.0f);
	glVertex3f(150.0f, -10.0f, 120.0f);
	glVertex3f(150.0f, 0.0f, -110.0f);
	glVertex3f(150.0f, -230.0f, 90.0f);
	glVertex3f(150.0f, -8.0f, 50.0f);
	glVertex3f(150.0f, -1.0f, -90.0f);
	glVertex3f(150.0f, -4.0f, 45.0f);
	glVertex3f(150.0f, 90.0f, 20.0f);
	glVertex3f(150.0f, 10.0f, -46.0f);
	glVertex3f(150.0f, 50.0f, -30.0f);
	glVertex3f(150.0f, 100.0f, -10.0f);
	glVertex3f(150.0f, 6.0f, -55.0f);
	glVertex3f(150.0f, 10.0f, -0.0f);
	glVertex3f(150.0f, -5.0f, -90.0f);
	glVertex3f(150.0f, -16.0f, -10.0f);
	glVertex3f(150.0f, -30.0f, -3.0f);
	glVertex3f(150.0f, -8.0f, 20.0f);
	glVertex3f(150.0f, -1.0f, -12.0f);
	glVertex3f(150.0f, -4.0f, -6.0f);
	glVertex3f(150.0f, -20.0f, 30.0f);
	glVertex3f(150.0f, -5.0f, -90.0f);
	glVertex3f(150.0f, -60.0f, 30.0f);
	glVertex3f(150.0f, -65.0f, -60.0f);
	glVertex3f(150.0f, -80.0f, 120.0f);
	
	// Esquerda
	glVertex3f(-150.0f, 0.0f, 0.0f);
	glVertex3f(-150.0f, 10.0f, 10.0f);
	glVertex3f(-150.0f, 9.0f, 50.0f);
	glVertex3f(-150.0f, 55.0f, 70.0f);
	glVertex3f(-150.0f, 100.0f, 20.0f);
	glVertex3f(-150.0f, 16.0f, -10.0f);
	glVertex3f(-150.0f, 60.0f, -90.0f);
	glVertex3f(-150.0f, 10.0f, -80.0f);
	glVertex3f(-150.0f, 6.0f, -13.0f);
	glVertex3f(-150.0f, 50.0f, -90.0f);
	glVertex3f(-150.0f, -10.0f, -10.0f);
	glVertex3f(-150.0f, 50.0f, 9.0f);
	glVertex3f(-150.0f, 70.0f, 55.0f);
	glVertex3f(-150.0f, 20.0f, 100.0f);
	glVertex3f(-150.0f, -10.0f, 16.0f);
	glVertex3f(-150.0f, 9.0f, -60.0f);
	glVertex3f(-150.0f, 80.0f, -10.0f);
	glVertex3f(-150.0f, -13.0f, 6.0f);
	glVertex3f(-150.0f, 40.0f, -40.0f);
	glVertex3f(-150.0f, 2.0f, 60.0f);
	glVertex3f(-150.0f, 3.0f, 50.0f);
	glVertex3f(-150.0f, 5.0f, -22.0f);
	glVertex3f(-150.0f, 100.0f, 5.0f);
	glVertex3f(-150.0f, 16.0f, 70.0f);
	glVertex3f(-150.0f, -60.0f, 90.0f);
	glVertex3f(-150.0f, 10.0f, -75.0f);
	glVertex3f(-150.0f, 6.0f, -30.0f);
	glVertex3f(-150.0f, 25.0f, -90.0f);
	glVertex3f(-150.0f, -10.0f, 120.0f);
	glVertex3f(-150.0f, 0.0f, -110.0f);
	glVertex3f(-150.0f, -230.0f, 90.0f);
	glVertex3f(-150.0f, -8.0f, 50.0f);
	glVertex3f(-150.0f, -1.0f, -90.0f);
	glVertex3f(-150.0f, -4.0f, 45.0f);
	glVertex3f(-150.0f, 90.0f, 20.0f);
	glVertex3f(-150.0f, 10.0f, -46.0f);
	glVertex3f(-150.0f, 50.0f, -30.0f);
	glVertex3f(-150.0f, 100.0f, -10.0f);
	glVertex3f(-150.0f, 6.0f, -55.0f);
	glVertex3f(-150.0f, 10.0f, -0.0f);
	glVertex3f(-150.0f, -5.0f, -90.0f);
	glVertex3f(-150.0f, -16.0f, -10.0f);
	glVertex3f(-150.0f, -30.0f, -3.0f);
	glVertex3f(-150.0f, -8.0f, 20.0f);
	glVertex3f(-150.0f, -1.0f, -12.0f);
	glVertex3f(-150.0f, -4.0f, -6.0f);
	glVertex3f(-150.0f, -20.0f, 30.0f);
	glVertex3f(-150.0f, -5.0f, -90.0f);
	glVertex3f(-150.0f, -60.0f, 30.0f);
	glVertex3f(-150.0f, -65.0f, -60.0f);
	glVertex3f(-150.0f, -80.0f, 120.0f);
	
	// Cima
	glVertex3f(0.0f, 150.0f, 0.0f);
	glVertex3f(10.0f, 150.0f, 10.0f);
	glVertex3f(9.0f, 150.0f, 50.0f);
	glVertex3f(55.0f, 150.0f, 70.0f);
	glVertex3f(100.0f, 150.0f, 20.0f);
	glVertex3f(16.0f, 150.0f, -10.0f);
	glVertex3f(60.0f, 150.0f, -90.0f);
	glVertex3f(10.0f, 150.0f, -80.0f);
	glVertex3f(6.0f, 150.0f, -13.0f);
	glVertex3f(50.0f, 150.0f, -90.0f);
	glVertex3f(-10.0f, 150.0f, -10.0f);
	glVertex3f(50.0f, 150.0f, 9.0f);
	glVertex3f(70.0f, 150.0f, 55.0f);
	glVertex3f(20.0f, 150.0f, 100.0f);
	glVertex3f(-10.0f, 150.0f, 16.0f);
	glVertex3f(9.0f, 150.0f, -60.0f);
	glVertex3f(80.0f, 150.0f, -10.0f);
	glVertex3f(-13.0f, 150.0f, 6.0f);
	glVertex3f(40.0f, 150.0f, -40.0f);
	glVertex3f(2.0f, 150.0f, 60.0f);
	glVertex3f(2.0f, 150.0f, 50.0f);
	glVertex3f(5.0f, 150.0f, -22.0f);
	glVertex3f(100.0f, 150.0f, 5.0f);
	glVertex3f(16.0f, 150.0f, 70.0f);
	glVertex3f(-60.0f, 150.0f, 90.0f);
	glVertex3f(10.0f, 150.0f, -75.0f);
	glVertex3f(6.0f, 150.0f, -30.0f);
	glVertex3f(25.0f, 150.0f, -90.0f);
	glVertex3f(-10.0f, 150.0f, 120.0f);
	glVertex3f(0.0f, 150.0f, -110.0f);
	glVertex3f(-230.0f, 150.0f, 90.0f);
	glVertex3f(-8.0f, 150.0f, 50.0f);
	glVertex3f(-1.0f, 150.0f, -90.0f);
	glVertex3f(-4.0f, 150.0f, 45.0f);
	glVertex3f(90.0f, 150.0f, 20.0f);
	glVertex3f(-10.0f, 150.0f, -46.0f);
	glVertex3f(50.0f, 150.0f, -30.0f);
	glVertex3f(100.0f, 150.0f, -10.0f);
	glVertex3f(6.0f, 150.0f, -55.0f);
	glVertex3f(10.0f, 150.0f, -0.0f);
	glVertex3f(-5.0f, 150.0f, -90.0f);
	glVertex3f(-16.0f, 150.0f, -10.0f);
	glVertex3f(-30.0f, 150.0f, -3.0f);
	glVertex3f(-8.0f, 150.0f, 20.0f);
	glVertex3f(-1.0f, 150.0f, -12.0f);
	glVertex3f(-4.0f, 150.0f, -6.0f);
	glVertex3f(-20.0f, 150.0f, 30.0f);
	glVertex3f(-5.0f, 150.0f, -90.0f);
	glVertex3f(-60.0f, 150.0f, 30.0f);
	glVertex3f(-65.0f, 150.0f, -60.0f);
	glVertex3f(-80.0f, 150.0f, 120.0f);
	
	// Baixo
		glVertex3f(0.0f, -150.0f, 0.0f);
	glVertex3f(10.0f, -150.0f, 10.0f);
	glVertex3f(9.0f, -150.0f, 50.0f);
	glVertex3f(55.0f, -150.0f, 70.0f);
	glVertex3f(100.0f, -150.0f, 20.0f);
	glVertex3f(16.0f, -150.0f, -10.0f);
	glVertex3f(60.0f, -150.0f, -90.0f);
	glVertex3f(10.0f, -150.0f, -80.0f);
	glVertex3f(6.0f, -150.0f, -13.0f);
	glVertex3f(50.0f, -150.0f, -90.0f);
	glVertex3f(-10.0f, -150.0f, -10.0f);
	glVertex3f(50.0f, -150.0f, 9.0f);
	glVertex3f(70.0f, -150.0f, 55.0f);
	glVertex3f(20.0f, -150.0f, 100.0f);
	glVertex3f(-10.0f, -150.0f, 16.0f);
	glVertex3f(9.0f, -150.0f, -60.0f);
	glVertex3f(80.0f, -150.0f, -10.0f);
	glVertex3f(-13.0f, -150.0f, 6.0f);
	glVertex3f(40.0f, -150.0f, -40.0f);
	glVertex3f(2.0f, -150.0f, 60.0f);
	glVertex3f(2.0f, -150.0f, 50.0f);
	glVertex3f(5.0f, -150.0f, -22.0f);
	glVertex3f(100.0f, -150.0f, 5.0f);
	glVertex3f(16.0f, -150.0f, 70.0f);
	glVertex3f(-60.0f, -150.0f, 90.0f);
	glVertex3f(10.0f, -150.0f, -75.0f);
	glVertex3f(6.0f, -150.0f, -30.0f);
	glVertex3f(25.0f, -150.0f, -90.0f);
	glVertex3f(-10.0f, -150.0f, 120.0f);
	glVertex3f(0.0f, -150.0f, -110.0f);
	glVertex3f(-230.0f, -150.0f, 90.0f);
	glVertex3f(-8.0f, -150.0f, 50.0f);
	glVertex3f(-1.0f, -150.0f, -90.0f);
	glVertex3f(-4.0f, -150.0f, 45.0f);
	glVertex3f(90.0f, -150.0f, 20.0f);
	glVertex3f(-10.0f, -150.0f, -46.0f);
	glVertex3f(50.0f, -150.0f, -30.0f);
	glVertex3f(100.0f, -150.0f, -10.0f);
	glVertex3f(6.0f, -150.0f, -55.0f);
	glVertex3f(10.0f, -150.0f, -0.0f);
	glVertex3f(-5.0f, -150.0f, -90.0f);
	glVertex3f(-16.0f, -150.0f, -10.0f);
	glVertex3f(-30.0f, -150.0f, -3.0f);
	glVertex3f(-8.0f, -150.0f, 20.0f);
	glVertex3f(-1.0f, -150.0f, -12.0f);
	glVertex3f(-4.0f, -150.0f, -6.0f);
	glVertex3f(-20.0f, -150.0f, 30.0f);
	glVertex3f(-5.0f, -150.0f, -90.0f);
	glVertex3f(-60.0f, -150.0f, 30.0f);
	glVertex3f(-65.0f, -150.0f, -60.0f);
	glVertex3f(-80.0f, -150.0f, 120.0f);

glEnd();
}

void DesenhaMercurio(){
		glColor3f(1,0,0);
        	glRasterPos2f(-40, 20);         
        	char* a = (char*) "MERCURIO";
        	char* i1 = (char*) "Massa (kg) 3.303e+23";
        	char* i2 = (char*) "Densidade media (gm/cm^3) 5.42";
        	char* i5 = (char*) "Distancia media ao Sol (km) 57,910,000";
        	char* i4 = (char*) "Periodo de rotacao (dias) 58.6462";
        	char* p1 = (char*) "Periodo orbital (dias) 87.969 ";
        	char* p2 = (char*) "Velocidade orbital media (km/seg) 47.88";
           	char* p3 = (char*) "Gravidade a superficie no equador(m/seg^2) 3.7";
        while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *a++);
            }
            glRasterPos2f(-50, 9);
            while (*i1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i1++);
            }
            glRasterPos2f(-50, 5);
            while (*i2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i2++);
            }
            glRasterPos2f(-50, 1);
            while (*i5 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i5++);
            }
            glRasterPos2f(-50, -3);
            while (*i4 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i4++);
            }
            glRasterPos2f(-50, -7);
            while (*p1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p1++);
            }
            glRasterPos2f(-50, -11);
            while (*p2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p2++);
            }
            glRasterPos2f(-50, -15);
            while (*p3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p3++);
            }
            glRasterPos2f(-50, -19);
            char* i3 = (char*) "Temperatura media a superficie 179 C";
            while (*i3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i3++);
            }
           
            
}

void DesenhaVenus(){
		glColor3f(1,0,0);
        	glRasterPos2f(-40, 20);         
        	char* a = (char*) "VENUS";
        	char* i1 = (char*) "Raio equatorial (km) 6,051.8 ";
        	char* i2 = (char*) "Densidade media (gm/cm^3) 5.25" ;
        	char* i5 = (char*) "Distancia media do Sol (km) 108,200,000  \n";
        	char* i4 = (char*) "Periodo de rotacao (dias) 116.8  \n";
        	char* p1 = (char*) "Velocidade orbital media(km/s) 35.02  \n";
        	char* p2 = (char*) "Temperatura media na superficie 460°C";
           	char* p3 = (char*) "Massa (kg) 4,867e+24  \n";
        while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *a++);
            }
            glRasterPos2f(-50, 9);
            while (*i1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i1++);
            }
            glRasterPos2f(-50, 5);
            while (*i2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i2++);
            }
            glRasterPos2f(-50, 1);
            while (*i5 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i5++);
            }
            glRasterPos2f(-50, -3);
            while (*i4 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i4++);
            }
            glRasterPos2f(-50, -7);
            while (*p1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p1++);
            }
            glRasterPos2f(-50, -11);
            while (*p2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p2++);
            }
            glRasterPos2f(-50, -15);
            while (*p3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p3++);
            }
            glRasterPos2f(-50, -19);
            char* i3 = (char*) "Gravidade equatorial na superficie (m/seg^2) 8.87  \n";
            while (*i3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i3++);
            }
	
}

void DesenhaTerra(){
	glColor3f(1,0,0);
        	glRasterPos2f(-40, 20);         
        	char* a = (char*) "TERRA";
        	char* i1 = (char*) "Massa (Kg) 5,976e+24 \n";
        	char* i2 = (char*) "Raio equatorial (Km) 6.378,14 \n";
        	char* i5 = (char*) "Distancia media do Sol (Km) 149.600.000 \n";
        	char* i4 = (char*) "Periodo de rotacao (dias) 0,99727 \n";
        	char* p1 = (char*) "Periodo Orbital (dias) 365,265 \n";
        	char* p2 = (char*) "Velocidade orbital media (km/s) 29,79 \n";
        	char* p3 = (char*) "Temperatura media a superficie 15C \n";
		char* p4 = (char*) "Gravidade a superficie no euador (m/s^2) 9,78";
 	    	while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *a++);
            }
            glRasterPos2f(-50, 9);
            while (*i1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i1++);
            }
            glRasterPos2f(-50, 5);
            while (*i2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i2++);
            }
            glRasterPos2f(-50, 1);
            while (*i5 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i5++);
            }
            glRasterPos2f(-50, -3);
            while (*i4 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i4++);
            }
            glRasterPos2f(-50, -7);
            while (*p1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p1++);
            }
            glRasterPos2f(-50, -11);
            while (*p2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p2++);
            }
            glRasterPos2f(-50, -15);
            while (*p3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p3++);
            }
	    glRasterPos2f(-50, -19);
	    while (*p4 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p4++);
}
}

void DesenhaMarte(){
		glColor3f(1,0,0);
        	glRasterPos2f(-40, 20);         
        	char* a = (char*) "MARTE";
        	char* i1 = (char*) "Massa (kg) 6,39e+23 ";
        	char* i2 = (char*) "Raio equatorial (km) 3,389.5" ;
        	char* i5 = (char*) "Densidade media (gm/cm^3) 3,93";
        	char* i4 = (char*) "Inclinacao do Eixo (graus) 25";
        	char* p1 = (char*) "Gravidade a superficie no equador (m/s^2) 3,711";
        	char* p2 = (char*) "Distancia media ao Sol (km) 227.940.000 ";
           	char* p3 = (char*) "Excentricidade orbital 0,093";
        while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *a++);
            }
            glRasterPos2f(-50, 9);
            while (*i1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i1++);
            }
            glRasterPos2f(-50, 5);
            while (*i2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i2++);
            }
            glRasterPos2f(-50, 1);
            while (*i5 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i5++);
            }
            glRasterPos2f(-50, -3);
            while (*i4 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i4++);
            }
            glRasterPos2f(-50, -7);
            while (*p1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p1++);
            }
            glRasterPos2f(-50, -11);
            while (*p2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p2++);
            }
            glRasterPos2f(-50, -15);
            while (*p3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p3++);
            }
            glRasterPos2f(-50, -19);
            char* i3 = (char*) "Periodo de rotacao (horas) 24.6229 ";
            while (*i3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i3++);
            }
	
}

void DesenhaJupiter(){
		glColor3f(1,0,0);
        	glRasterPos2f(-40, 20);         
        	char* a = (char*) "JUPITER";
        	char* i1 = (char*) "";
        	char* i2 = (char*) "Raio Equatorial (km) 69,911" ;
        	char* i5 = (char*) "Densidade Media (gm/cm^3) 0.69";
        	char* i4 = (char*) "Distancia media do Sol (km)	1,429,400,000";
        	char* p1 = (char*) "Temperatura minima a superficie -140 °C";
        	char* p2 = (char*) "Temperatura media a superficie -63°C";
           	char* p3 = (char*) "Gravidade a superficie no equador (m/seg^2) 3.72";
        while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *a++);
            }
            glRasterPos2f(-50, 9);
            while (*i1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i1++);
            }
            glRasterPos2f(-50, 5);
            while (*i2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i2++);
            }
            glRasterPos2f(-50, 1);
            while (*i5 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i5++);
            }
            glRasterPos2f(-50, -3);
            while (*i4 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i4++);
            }
            glRasterPos2f(-50, -7);
            while (*p1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p1++);
            }
            glRasterPos2f(-50, -11);
            while (*p2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p2++);
            }
            glRasterPos2f(-50, -15);
            while (*p3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p3++);
            }
            glRasterPos2f(-50, -19);
            char* i3 = (char*) "Inclinacao do Eixo (graus) 23,45";
            while (*i3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i3++);
            }
	
}

void DesenhaSaturno(){
		glColor3f(1,0,0);
        	glRasterPos2f(-40, 20);         
        	char* a = (char*) "SATURNO";
        	char* i1 = (char*) "Massa (kg) 5.688e+26";
        	char* i2 = (char*) "Raio equatorial (km) 58.232" ;
        	char* i5 = (char*) "Velocidade media orbital (km/seg) 9.67";
        	char* i4 = (char*) "Distancia media ao Sol (km) 1.429.400.000";
        	char* p1 = (char*) "Inclinacao do Eixo (graus) 27";
        	char* p2 = (char*) "Temperatura minima a superficie -139°C";
           	char* p3 = (char*) "Area da superficie (km^2) 4,27e+10";
        while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *a++);
            }
            glRasterPos2f(-50, 9);
            while (*i1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i1++);
            }
            glRasterPos2f(-50, 5);
            while (*i2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i2++);
            }
            glRasterPos2f(-50, 1);
            while (*i5 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i5++);
            }
            glRasterPos2f(-50, -3);
            while (*i4 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i4++);
            }
            glRasterPos2f(-50, -7);
            while (*p1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p1++);
            }
            glRasterPos2f(-50, -11);
            while (*p2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p2++);
            }
            glRasterPos2f(-50, -15);
            while (*p3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p3++);
            }
            glRasterPos2f(-50, -19);
            char* i3 = (char*) "Gravidade (m/s^2) 10,44";
            while (*i3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i3++);
            }
	
}

void DesenhaUrano(){
		glColor3f(1,0,0);
        	glRasterPos2f(-40, 20);         
        	char* a = (char*) "URANO";
        	char* i1 = (char*) "Massa (kg) 8.681e+25";
        	char* i2 = (char*) "Raio equatorial (km) 25,362" ;
        	char* i5 = (char*) "Raio equatorial (Terra = 1) 4.0074";
        	char* i4 = (char*) "Densidade media (gm/cm^3) 1.27";
        	char* p1 = (char*) "Distancia media ao Sol (km) 2,870,990,000";
        	char* p2 = (char*) "Periodo orbital (anos) 84.01";
           	char* p3 = (char*) "Periodo de rotacao (horas) 17.9";
        while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *a++);
            }
            glRasterPos2f(-50, 9);
            while (*i1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i1++);
            }
            glRasterPos2f(-50, 5);
            while (*i2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i2++);
            }
            glRasterPos2f(-50, 1);
            while (*i5 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i5++);
            }
            glRasterPos2f(-50, -3);
            while (*i4 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i4++);
            }
            glRasterPos2f(-50, -7);
            while (*p1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p1++);
            }
            glRasterPos2f(-50, -11);
            while (*p2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p2++);
            }
            glRasterPos2f(-50, -15);
            while (*p3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p3++);
            }
            glRasterPos2f(-50, -19);
            char* i3 = (char*) "Temperatura media da superficie -224°C";
            while (*i3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i3++);
            }
	
}

void DesenhaNetuno(){
		glColor3f(1,0,0);
        	glRasterPos2f(-40, 20);         
        	char* a = (char*) "NETUNO";
        	char* i1 = (char*) "Massa (kg) 1.024e+26 ";
        	char* i2 = (char*) "Raio equatorial (km) 24,622" ;
        	char* i5 = (char*) "Densidade media (gm/cm^3) 1.64";
        	char* i4 = (char*) "Distancia media do Sol (km) 4,504,300,000 ";
        	char* p1 = (char*) "Periodo rotacional (horas) 16.11 ";
        	char* p2 = (char*) "Gravidade equatorial a superficie (m/seg^2) 11.15";
           	char* p3 = (char*) "Periodo orbital (anos) 165";
        while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *a++);
            }
            glRasterPos2f(-50, 9);
            while (*i1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i1++);
            }
            glRasterPos2f(-50, 5);
            while (*i2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i2++);
            }
            glRasterPos2f(-50, 1);
            while (*i5 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i5++);
            }
            glRasterPos2f(-50, -3);
            while (*i4 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i4++);
            }
            glRasterPos2f(-50, -7);
            while (*p1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p1++);
            }
            glRasterPos2f(-50, -11);
            while (*p2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p2++);
            }
            glRasterPos2f(-50, -15);
            while (*p3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p3++);
            }
            glRasterPos2f(-50, -19);
            char* i3 = (char*) "Temperatura media das nuvens -210 C ";
            while (*i3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i3++);
            }
	
}

void MenuVista(int op)
{
   switch(op) {
            case 0:
                    
                    vista=0;
                     break;
            case 1:
                   
                   vista=1;
                     break;
    }
    glutPostRedisplay();
}           

// Gerenciamento do menu com as opções de cores           
void MenuPlaneta(int op)
{
   switch(op) {
            case 0:
                     primitiva = 0;
                     break;
            case 1:
                     primitiva = 1;
                     break;
            case 2:
                     primitiva = 2;
                     break;
            case 3:
                     primitiva = 3;
                     break;
            case 4:
                     primitiva = 4;
                     break;
            case 5:
                     primitiva = 5;
                     break;
            case 6:
                     primitiva = 6;
                     break;
            case 7:
                     primitiva = 7;
                     break;
            case 8:
                     primitiva = 8;
                     break;
    }
    glutPostRedisplay();
}   
        
// Gerenciamento do menu principal           
void MenuPrincipal(int op)
{
	if(op==12)
		exit(1);
}
              
// Criacao do Menu
void CriaMenu() 
{
    int menu,submenu1,submenu2;

	submenu1 = glutCreateMenu(MenuPlaneta);
	glutAddMenuEntry("Mercurio",0);
	glutAddMenuEntry("Vênus",1);
	glutAddMenuEntry("Terra",2);
	glutAddMenuEntry("Marte",3);
	glutAddMenuEntry("Jupiter",4);
	glutAddMenuEntry("Saturno",5);
	glutAddMenuEntry("Urano",6);
	glutAddMenuEntry("Netuno",7);
	glutAddMenuEntry("Voltar a tela inicial",8);
    submenu2 = glutCreateMenu(MenuVista);
	glutAddMenuEntry("Sim",0);
	glutAddMenuEntry("Não",1);
	

    menu = glutCreateMenu(MenuPrincipal);
	glutAddSubMenu("Planeta",submenu1);
    glutAddSubMenu("Visao de cima",submenu2);
    glutAddMenuEntry("Sair",12);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void tela1(){
		glColor3f(1,0,0);
        	glRasterPos2f(-40, 20);         
        	char* a = (char*) "INSTRUCOES DO PROGRAMA:";
        	char* i1 = (char*) "1-> Acesse o menu com o botao direito do mouse;";
        	char* i2 = (char*) "2-> A tecla P pausa a rotacao e eh possivel arrastar o sistema segurando o botao esquerdo do mouse;";
        	char* i5 = (char*) "3-> Para voltar a rotacao pressione V e pressione uma das setas;";
        	char* i4 = (char*) "4-> Para dar zoom aperte as teclas PAGE UP e PAGE DOWN;";
        	char* p1 = (char*) "5-> Para sair/fechar pressione a tecla END ou selecione a opcao Sair no menu;";
        	char* p2 = (char*) "6-> Para ver os nomes dos planetas pressione 1 e para ocultar eles pressione 2;";
           	char* p3 = (char*) "OBS: Instrucao 6 somente eh possivel com os planetas em movimento.";
        while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *a++);
            }
            glRasterPos2f(-50, 9);
            while (*i1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i1++);
            }
            glRasterPos2f(-50, 5);
            while (*i2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i2++);
            }
            glRasterPos2f(-50, 1);
            while (*i5 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i5++);
            }
            glRasterPos2f(-50, -3);
            while (*i4 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i4++);
            }
            glRasterPos2f(-50, -7);
            while (*p1 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p1++);
            }
            glRasterPos2f(-50, -11);
            while (*p2 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p2++);
            }
            glRasterPos2f(-50, -15);
            while (*p3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p3++);
            }
            glRasterPos2f(-45, -23);
            char* i3 = (char*) "* PRESSIONE ENTER PARA INICIAR";
            while (*i3 != '\0'){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i3++);
            }
	
}

void DefineIluminacao (void){
	GLfloat luz_ambiente[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat luz_difusa[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat luz_especular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat luz_posicao[] = { 0.0f ,0.0f, 100.0f, 1.0f };

	// Capacidade de brilho do material
	GLint especMaterial = 90;

	// Define a refletância do material 

	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// LUZ
	glEnable(GL_LIGHT0);
	
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT,  luz_ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  luz_difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular);
    glLightfv(GL_LIGHT0, GL_POSITION, luz_posicao);
}

void Trajetoria_Planetas(float cx, float cy, float r, int num_segmentos){
	glColor3f(1,1,1);
 	glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segmentos; ii++){
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segmentos);
        float x = r * cosf(theta);//	calcula x
        float y = r * sinf(theta);//	calcula y 
    	glVertex3f(x + cx, 0, y + cy);
    }
    glEnd();
}

void sol(){
	
	Trajetoria_Planetas(0,0,5,360); // Mercurio 00
	Trajetoria_Planetas(0,0,10.8,360); // Venus 00
	Trajetoria_Planetas(0,0,15.8,360); // Terra 00
	Trajetoria_Planetas(0,0,20,360); // Marte 00
	Trajetoria_Planetas(0,0,28,360); // Jupiter
	Trajetoria_Planetas(0,0,35.5,360); // Saturno
	Trajetoria_Planetas(0,0,43,360); // Urano
	Trajetoria_Planetas(0,0,55,360); // Netuno
	
	DesenharEstrelas();	
	//if(show==1){		
	GLfloat luz_emissao[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	//}	
	glColor3f(1,1,0);
	glTranslatef(0.0f ,0.0f, 0.0f);
	glutSolidSphere(3.0f, 100, 100000);
	
    glEnd();
}

 void mercurio(){
 	GLfloat luz_emissao[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	
 	glRotatef(angulo, 0.0f, 1.0f, 0.0f); //  Velocidade de rotação
 	if(show==1 && mov==1){
 		GLfloat luz_emissao[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	 char* a = (char*) "MERCURIO";
 	glColor3f(1,1,0);
		glRasterPos2f(-4, 0);
		while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *a++);
            }
        }
        luz_emissao[0]=luz_emissao[1]=luz_emissao[2]=luz_emissao[3]=0;  
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	GLfloat luz_posicao[] = { 0.0f ,0.0f, 1.0f, 1.0f };
	 glLightfv(GL_LIGHT0, GL_POSITION, luz_posicao);
// Desennhar Mercurio : Cinza
    glColor3f(0.4f, 0.4f, 0.4f);

		glTranslatef(-5.0f, 0.0f, 0.0f);
	glutSolidSphere(0.4f, 100.0f, 100.0f);
 }
 
 void venus(){
 	
// Desennhar Venus : Laranja

 	glColor3f(0.9f, 0.6f, 0.0f);
 	
	glTranslatef(15.0f, 0.0f, 4.0f);
	glutSolidSphere(1.1f, 100.0f, 100.0f);
	if(show==1 && mov==1){
		GLfloat luz_emissao[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	char* a = (char*) "VENUS";
 	glColor3f(1,1,0);
glRasterPos2f(-3, 0);
while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *a++);
            }
        }
        GLfloat luz_emissao[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
 }
 
 void terra(){
 	
// Desennhar Terra : Azul

    glColor3f(0.0f, 0.5f, 1.0f);
	glTranslatef(-20.0f, 0.0f, 8.0f);
	glutSolidSphere(1.0f, 100.0f, 100.0f);
	if(show==1 && mov==1){
	char* a = (char*) "TERRA";
 	glColor3f(1,1,0);
glRasterPos2f(-4, 0);
while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *a++);
            }
        }
 }
 
 void marte(){

// Desennhar Marte : vermelho
          
   glColor3f(1.0f, 0.1f, 0.0f);
	glTranslatef(10.0f, 0.0f, 8.0f);
	glutSolidSphere(0.5f, 100.0f, 100.0f);
	if(show==1 && mov==1){
	char* a = (char*) "MARTE";
 	glColor3f(1,1,0);
glRasterPos2f(-4, 0);
while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *a++);}
}
 }
 
 void jupiter(){
 	
// Desennhar Jupiter: Amarelado

	glColor3f(1.0f, 1.0f, 0.4f);
	
	glTranslatef(20.0f, 0.0f, 0.0f);
	glutSolidSphere(2.0f, 100.0f, 100.0f);
	if(show==1 && mov==1){
	char* a = (char*) "JUPITER";
 	glColor3f(1,1,0);
glRasterPos2f(-4, 0);
while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *a++);
            }
        }
}
 
 void AnelSaturno(float cx, float cz, float r, int num_segmentos){
 	glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segmentos; ii++){
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segmentos);
        float x = r * cosf(theta);//	calcula x
        float z = r * sinf(theta);//	calcula y 

    	glVertex3f(x + cx, 0, z + cz);
    }
    glEnd();
}
 
 void saturno(){
 	
// Desennhar saturno: Marrom

	glColor3f(0.7f, 0.5f, 0.1f);

	glTranslatef(-25.0f, 0.0f, 15.0f);
	AnelSaturno(0.0, 0.0, 2.2, 360);
	glutSolidSphere(1.8f, 100.0f, 100.0f);
	if(show==1 && mov==1){
	char* a = (char*) "SATURNO";
 	glColor3f(1,1,0);
glRasterPos2f(-4, 0);
while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *a++);
            }
        }
 }
 
 void urano(){

// Desennhar Urano: Branco

	glColor3f(1.0f, 1.0f, 1.0f);

	glTranslatef(0.0f, 0.0f, -78.0f);
	glutSolidSphere(1.5f, 100.0f, 100.0f);
	if(show==1 && mov==1){
		GLfloat luz_emissao[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	char* a = (char*) "URANO";
 	glColor3f(1,1,0);
glRasterPos2f(-4, 0);
while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *a++);
            }
        }
}
 
 void netuno(){

// Desennhar Netuno: Azulado

	glColor3f(0.2f, 0.0f, 1.0f);

	glTranslatef(20.0f, 0.0f, -10.0f);
	glutSolidSphere(1.4f, 100.0f, 100000.0f);
	if(show==1 && mov==1){
		GLfloat luz_emissao[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	char* a = (char*) "NETUNO";
 	glColor3f(1,1,0);
glRasterPos2f(-4, 0);
while (*a != '\0'){ glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *a++);
            }
        }
        glEnd();
}

void DesenharSistemaSolar() {
	DefineIluminacao();
	
	sol();
	mercurio();
	venus();
	terra();
	marte();
	jupiter();
	saturno();
	urano();
		GLfloat luz_emissao[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	netuno();
		 luz_emissao[0]=luz_emissao[1]=luz_emissao[2]=luz_emissao[3]=0;  
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
glEnd();
	
	
	if(mov==1){
		angulo+=0.1f;
		glutSwapBuffers();
	}	

}

// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	if(mov!=0)
	rotX=rotY=0;
	// Posiciona e orienta o observador
	glTranslatef(-obsX,-obsY,-obsZ);
	glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);

}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void){
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(eixoZ, fAspect, 0.5, 1000);
	printf("%f",fAspect);
	PosicionaObservador();
}

// Função callback de redesenho da janela de visualização
void Desenha(){
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 CriaMenu();
	 if(primitiva==0){//Mercurio
	 	tela=2;
	 	GLfloat luz_emissao[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	 	DesenhaMercurio();
	 	glutSwapBuffers();
	 }
	 if(primitiva==1){//Venus
	 	tela=2;
	 	GLfloat luz_emissao[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	 	DesenhaVenus();
	 	glutSwapBuffers();
	 }
	 if(primitiva==2){//Terra
	 	tela=2;
	 	GLfloat luz_emissao[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	 	DesenhaTerra();
	 	glutSwapBuffers();
	 }
	 if(primitiva==3){//Marte
	 	tela=2;
	 	GLfloat luz_emissao[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	 	DesenhaMarte();
	 	glutSwapBuffers();
	 }
	 if(primitiva==4){//Jupiter
	 	tela=2;
	 	GLfloat luz_emissao[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	 	DesenhaJupiter();
	 	glutSwapBuffers();
	 }
	 if(primitiva==5){//Saturno
	 	tela=2;
	 	GLfloat luz_emissao[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	 	DesenhaSaturno();
	 	glutSwapBuffers();
	 }
	 if(primitiva==6){//Urano
	 	tela=2;
	 	GLfloat luz_emissao[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	 	DesenhaUrano();
	 	glutSwapBuffers();
	 }
	 if(primitiva==7){//Netuno
	 	tela=2;
	 	GLfloat luz_emissao[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	 	DesenhaNetuno();
	 	glutSwapBuffers();
	 }
	 if(primitiva==8){
	 	tela=1;
	 	GLfloat luz_emissao[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, luz_emissao);
	 	glutSwapBuffers();
	 }
	 if(tela==1){
	 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 	tela1();
	 	
	 	glutSwapBuffers();
	 }
	 
	if(mov==1 && tela ==0 && primitiva == -1){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	// Camera
	if(vista==1)
		gluLookAt( 0.0f, 20.0f, 120.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	if(vista==0)
		gluLookAt( 0.0f, 250.0f, 120.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);	
		DesenharSistemaSolar();
		glutPostRedisplay();
	}
	 if(mov==0 && tela==0 && primitiva == -1){
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//	glTranslatef(15.0f, 0.0f, -53.0f);
		DesenharSistemaSolar();
		//glutPostRedisplay();
		glutSwapBuffers();
	}	
}

// Função callback chamada para gerenciar eventos de teclas normais (ESC)
void Teclado (unsigned char key, int x, int y){

	//FALTA IF PARA ABRIR MENU COM A LETRA 'M'
	if(key== 49 && mov==1){//key 49 = 1
		show=1;
		Desenha();
	}
	if(key==50 && mov==1){//key 50 = 2
		show=0;
		Desenha();
	}
	if(key == v){
		mov = 1;
		Desenha();	
	}
	if((key == 13 && tela == 1) || tela ==2){
		tela=0;
		primitiva=-1;
		Desenha();
	}
	if(key == p){	
		mov = 0;
		Desenha();
	}
}

// Função callback para tratar eventos de teclas especiais
void TeclasEspeciais (int tecla, int x, int y)  
{
	switch (tecla)
	{
		case GLUT_KEY_PAGE_UP:	if(eixoZ>=10) eixoZ -=5;
							break;
		case GLUT_KEY_PAGE_DOWN:	if(eixoZ<=60) eixoZ +=5;
							break;
		case GLUT_KEY_END: exit(0);
	}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Função callback para eventos de botões do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if(state==GLUT_DOWN)
	{
		// Salva os parâmetros atuais
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
}

// Função callback para eventos de movimento do mouse
#define SENS_ROT	5.0
#define SENS_OBS	10.0
#define SENS_TRANSL	10.0
void GerenciaMovim(int x, int y)
{
	// Botão esquerdo ?
	if(bot==GLUT_LEFT_BUTTON)
	{
		// Calcula diferenças
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica ângulos
		rotY = rotY_ini - deltax/SENS_ROT;
		rotX = rotX_ini - deltay/SENS_ROT;
	}
	// Botão direito ?
	else if(bot==GLUT_RIGHT_BUTTON)
	{
		// Calcula diferença
		int deltaz = y_ini - y;
		// E modifica distância do observador
		obsZ = obsZ_ini + deltaz/SENS_OBS;
	}
	// Botão do meio ?
	else if(bot==GLUT_MIDDLE_BUTTON)
	{
		// Calcula diferenças
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica posições
		obsX = obsX_ini + deltax/SENS_TRANSL;
		obsY = obsY_ini - deltay/SENS_TRANSL;
	}
	PosicionaObservador();
	glutPostRedisplay();
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica as dimensões da viewport
	glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função responsável por inicializar parâmetros e variáveis
void Inicializa (void)
{   
	// Define a cor de fundo da janela de visualização como branca
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
         
	// Inicializa a variável que especifica o ângulo da projeção
	// perspectiva
	eixoZ = 30;
    
	// Inicializa as variáveis usadas para alterar a posição do 
	// observador virtual
	rotX = 0;
	rotY = 0;
	obsX = obsY = 0;
	obsZ = 150;    
}

// Programa Principal 
int main(void)
{
	// Define o modo de operação da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); 
 
	// Especifica a posição inicial da janela GLUT
	glutInitWindowPosition(5,5); 
    
	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(1350, 650); 
 
	// Cria a janela passando como argumento o título da mesma
	glutCreateWindow("Sistema Solar TOP");
 
	// Registra a função callback de redesenho da janela de visualização
	glutDisplayFunc(Desenha);
  
	// Registra a função callback de redimensionamento da janela de visualização
	glutReshapeFunc(AlteraTamanhoJanela);

	// Chama a função responsável por fazer as inicializações 
	Inicializa();
	
	// Registra a função callback para tratamento das teclas normais 
	glutKeyboardFunc (Teclado);

	// Registra a função callback para tratamento das teclas especiais
	glutSpecialFunc (TeclasEspeciais);
     
	// Registra a função callback para eventos de botões do mouse	
	glutMouseFunc(GerenciaMouse);
	 
	// Registra a função callback para eventos de movimento do mouse	
	glutMotionFunc(GerenciaMovim);

	 
 	glEnable(GL_DEPTH_TEST);
 	
	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();
 
	return 0;
}
