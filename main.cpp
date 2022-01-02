#include "utilities.h"
int main(int argc, char* argv[])
{

	// Initialisation de GLUT
	glutInit(&argc, argv);
	// Choix du mode d'affichage (ici RVB)
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	// Position initiale de la fenetre GLUT
	glutInitWindowPosition(200, 200);
	// Taille initiale de la fenetre GLUT
	glutInitWindowSize(windowW, windowH);
	// Creation de la fenetre GLUT
	glutCreateWindow("Cube3D");
	glEnable(GL_DEPTH_TEST);
	// Définition de la couleur d'effacement du framebuffer
	glClearColor(0.0f, 0.1f, 0.1f, 0.0f);
	// Définition des fonctions de callbacks
	glutDisplayFunc(affichage);
	glutSpecialFunc(specialkey);
	glutReshapeFunc(redimensionner);
	// Lancement de la boucle infinie GLUT
	glutMainLoop();

	return 0;
}