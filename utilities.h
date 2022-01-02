#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#include <gl/glext.h>
#include <jpeglib.h>
#include <jerror.h>
#endif


//initial conditions
int sol = 10.0f;
int windowW = 640;
int windowH = 480;
float focale = 65.0f;
float nearp = 0.1f;
float farp = 100.0f;
float xr = 0; float zr = 0;
GLfloat angleX = 0;
GLfloat angleY = 0;
GLfloat yr = 0;
GLint etat = 1;

// structures to create a parallelogramm in OpenGL

typedef struct {
	float x;
	float y;
	float z;
	float r;
	float g;
	float b;
	//float a;
}
vertex;
vertex para[8] = {
   {-0.5f,-0.5f, 2.5f},
   {-0.5f, -0.25f, 2.5f},
   { 2.5f, -0.25f, 2.5f},
   { 2.5f,-0.5f, 2.5f},
   {-0.5f,-0.5f,-0.5f},
   {-0.5f, -0.25f,-0.5f},
   { 2.5f, -0.25f,-0.5f},
   { 2.5f,-0.5f,-0.5f}
};
vertex objet[8] = {
	{-0.5f,-0.25f, 2.5f},
   {-0.5f, 5.75f, 2.5f},
   { 2.5f, 5.75f, 2.5f},
   { 2.5f, -0.25f, 2.5f},
   {-0.5f,-0.25f,-0.5f},
   {-0.5f, 5.75f,-0.5f},
   { 2.5f, 5.75f,-0.5f},
   { 2.5f,-0.25f,-0.5f}
};
int face[6][4] = {
   {0,1,2,3},
   {3,2,6,7},
   {4,5,6,7},
   {0,1,5,4},
   {1,5,6,2},
   {0,4,7,3}
};

GLvoid affichage();
GLvoid objetcon();
GLvoid paral(float m);
GLvoid specialkey(int key, int x, int y);
GLvoid redimensionner(int w, int h);
GLvoid plateforme(void);
GLvoid Displaymenu(void);
GLvoid MenuHandler(void);


// Creates the plateform of the game 
GLvoid plateforme(void) {
	float cas = 1;
	for (int i = 0; i < 3; i++) {
		for (int m = 0; m < 3; m++) {
			paral(cas);
			glTranslatef(0.0f, 0.0f, 3.0f);
			cas = cas * (-1);

		} glTranslatef(3.0f, 0.0f, 0.0f);
		cas = 1;
	}
	glTranslatef(-12.0f, 0.0f, -27.0f);
	cas = -1;

	for (int i = 0; i < 3; i++) {
		for (int m = 0; m < 3; m++) {
			paral(cas);
			glTranslatef(0.0f, 0.0f, 3.0f);
			cas = cas * (-1);

		} glTranslatef(3.0f, 0.0f, 0.0f);
		cas = -1;

	}
	glTranslatef(-12.0f, 0.0f, -27.0f);
	cas = 1;

	for (int i = 0; i < 3; i++) {
		for (int m = 0; m < 3; m++) {
			paral(cas);
			glTranslatef(0.0f, 0.0f, 3.0f);
			cas = cas * (-1);

		} glTranslatef(3.0f, 0.0f, 0.0f);
		cas = 1;
	}
	glTranslatef(-6.0f, 0.0f, -6.0f);
	paral(1);
	glTranslatef(-3.0f, 0.0f, -3.0f);
	paral(-1);
	glTranslatef(-0.0f, 0.0f, -3.0f);
	paral(1);
	glTranslatef(0.0f, 0.0f, 6.0f);
	paral(1);

}

//Creates the object of the game
GLvoid paral(float m) {
	for (int i = 0; i < 6; i++) {
		if (m == 1) {
			glBegin(GL_QUADS);
			for (int j = 0; j < 4; j++) {
				//glColor3f(cube[face[i][j]].r, cube[face[i][j]].g, cube[face[i][j]].b);
				glColor3f(0.2f, 0.0f, 0.8f);
				glVertex3f(para[face[i][j]].x, para[face[i][j]].y, para[face[i][j]].z);
			}
			glEnd();
		}
		else
			glBegin(GL_QUADS);
		for (int j = 0; j < 4; j++) {
			//glColor3f(cube[face[i][j]].r, cube[face[i][j]].g, cube[face[i][j]].b);
			glColor3f(0.9f, 0.9f, 0.9f);
			glVertex3f(para[face[i][j]].x, para[face[i][j]].y, para[face[i][j]].z);
		}
		glEnd();
	}
}

//Change the dimensions of the App window
GLvoid redimensionner(int w, int h) {
	// Garde les valeurs
	windowW = w;
	windowH = h;
	// eviter une division par 0
	if (windowH == 0)
		windowH = 1;
	glMatrixMode(GL_PROJECTION);

	// Resetting matrix
	glLoadIdentity();

	// Viewport
	// // TODO Essayez de modifier l'appel à glViewport
	// en changeant les parametre d'appel a la fonction mais
	// tout en obtenant le meme resultat
	glViewport(0, 0, windowW, windowH);

	// Mise en place de la perspective
	// TODO : peut-on changerle ratio ici pour un meilleur resultat ?
	gluPerspective(focale, 4 / 3.0, nearp, farp);

	// Retourne a la pile modelview
	glMatrixMode(GL_MODELVIEW);
}


GLvoid objetcon() {
	for (int i = 0; i < 6; i++) {
		glBegin(GL_QUADS);
		for (int j = 0; j < 4; j++) {
			//glColor3f(cube[face[i][j]].r, cube[face[i][j]].g, cube[face[i][j]].b);
			glColor3f(0.8, 0.0, 0.2);
			glVertex3f(objet[face[i][j]].x + yr, objet[face[i][j]].y, objet[face[i][j]].z);

		}
	}
	glEnd();

}

//Moving the object along the plateform
GLvoid specialkey(int key, int x, int y) {
	cout << etat << endl;
	if (etat == 1) {
		switch (key) {
		case GLUT_KEY_UP:
			angleY += 90;

			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:

			angleY += -90;


			glutPostRedisplay();
			break;

		case GLUT_KEY_RIGHT:
			angleX += 90;


			glutPostRedisplay();
			break;

		case GLUT_KEY_LEFT:
			angleX += -90;


			glutPostRedisplay();
			break;

		}
		etat = -1;
	}
	cout << etat << endl;

	if (etat == -1) {
		switch (key) {
		case GLUT_KEY_UP:
			angleY += -180;

			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:

			angleY += 180;



			glutPostRedisplay();
			break;

		case GLUT_KEY_RIGHT:
			angleX += -90;
			etat = 1;


			glutPostRedisplay();
			break;

		case GLUT_KEY_LEFT:
			angleX += 90;
			etat = 1;

			glutPostRedisplay();
			break;
		default:
			break;
		}

	}

}
// Display
GLvoid affichage() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, windowW, windowH);
	gluPerspective(focale, 4 / 3.0, nearp, farp);
	gluLookAt(20, 20, 10, 0, 0, 10, 0, 1, 0);
	glColor3f(0.2f, 0.2f, 0.2f);
	plateforme();
	glTranslatef(3.0f, 0.0f, -21.0f);
	glRotatef(angleY, 0.0f, 0.0f, 1.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	objetcon();

	glutSwapBuffers();
}
