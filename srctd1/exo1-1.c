#include <GL/glut.h>    // GLUT Library 
#include <GL/gl.h>	// OpenGL32 Library
#include <GL/glu.h>	// GLu32 Library
#include <stdio.h> 
int window; 

/* angle de rotation pour notre carre */
float rcx = 0.0f;
float rcy = 0.0f;




void mouse(int button,int state,int x,int y) ; //détecte qu'un bouton est appuyé

void mousemotion(int x,int y) ; //calcul et applique le déplacement (x et y sont les positions de la souris dans la fenêtre au moment de l'appel de la fonction.)
void keyboard(unsigned char touche,int x,int y) ;

/* fonction d'initialisation */
void InitGL(int Width, int Height)
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// Fond noir
  glClearDepth(1.0);				// on vide le z-buffer 
  glDepthFunc(GL_LESS);				// on définit le type de test
  glEnable(GL_DEPTH_TEST);			// on permet les tests en question
  glShadeModel(GL_SMOOTH);			// Smooth Color Shading

  glMatrixMode(GL_PROJECTION);                  // mode 'projection'
  glLoadIdentity();				// on initialise avec la matrice identité
  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// calcul de l'aspect ratio de la fenêtre 

  glMatrixMode(GL_MODELVIEW); // on passe en mode 'vue'
}

/* en cas de redimensionnement */
void ReSizeGLScene(int Width, int Height)
{
  if (Height==0)				// au cas où
    Height=1;

  glViewport(0, 0, Width, Height);		// on utilise toute la fenêtre

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f); // aspect ratio
  glMatrixMode(GL_MODELVIEW); 
}
/* fonction d'initialisation en cas de caméra */
void InitGL_camera(int Width, int Height)
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// Fond noir
  glClearDepth(1.0);				// on vide le z-buffer 
  glDepthFunc(GL_LESS);				// on définit le type de test
  glEnable(GL_DEPTH_TEST);			// on permet les tests en question
  glShadeModel(GL_SMOOTH);			// Smooth Color Shading
  glMatrixMode(GL_MODELVIEW); // on passe en mode 'vue'                 // mode 'projection'
  glLoadIdentity();				// on initialise avec la matrice identité
  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// calcul de l'aspect ratio de la fenêtre 

 
  gluLookAt(0.0,0.0,10.0,0.0,0.0,0.0,1.0,1.0,0.0);
}

/* en cas de redimensionnement */
void ReSizeGLScene_camera(int Width, int Height)
{
  if (Height==0)				// au cas où
    Height=1;

  glViewport(0, 0, Width, Height);		// on utilise toute la fenêtre

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f); // aspect ratio
  glMatrixMode(GL_MODELVIEW); 
  gluLookAt(0.0,0.0,10.0,0.0,0.0,0.0,1.0,1.0,0.0);
}

/* dessin de la scène vertex par vertex */
void DrawGLScene_VertexParVertex()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// on vide les buffers 
  glLoadIdentity();				// on initialise avec la matrice identité

  glTranslatef(0.0f,0.0f,-10.0f);		// on translate la scène vers le fond
	
  glRotatef(rcy,0.0f,1.0f,0.0f);		// on fait tourner la scène sur l'axe des Y
  glRotatef(rcx,1.0f,0.0f,0.0f);		// on fait tourner la scène sur l'axe des X

  //Début d'un cube vertex par vertex
  // on dessine un carre 
  glBegin(GL_QUADS);		// début du dessin
  glColor3f(1.0f,0.0f,0.0f);	// couleur du premier vertex
  glVertex3f(-1.0f, 1.0f, 0.0f);// coordonnées du 1e vertex 		
  glColor3f(0.0f,1.0f,0.0f); // couleur du deuxieme vertex
  glVertex3f( 1.0f, 1.0f, 0.0f);// coordonnées du 2eme vertex 		
  glColor3f(0.0f,0.0f,1.0f);
  glVertex3f( 1.0f,-1.0f, 0.0f);
  glColor3f(1.0f,1.0f,1.0f);
  glVertex3f(-1.0f,-1.0f, 0.0f);		
  glEnd();
 
  // on dessine un deuxieme carre 
  glBegin(GL_QUADS);		// début du dessin
  glColor3f(1.0f,0.0f,0.0f);	// couleur du premier vertex
  glVertex3f(-1.0f, 1.0f, 2.0f);// coordonnées du 1e vertex 		
  glColor3f(0.0f,1.0f,0.0f); // couleur du deuxieme vertex
  glVertex3f( 1.0f, 1.0f, 2.0f);// coordonnées du 2eme vertex 		
  glColor3f(0.0f,0.0f,1.0f);
  glVertex3f( 1.0f,-1.0f, 2.0f);
  glColor3f(1.0f,1.0f,1.0f);
  glVertex3f(-1.0f,-1.0f, 2.0f);		
  glEnd();

  // on dessine un 3ème carre 
  glBegin(GL_QUADS);		// début du dessin
  glColor3f(1.0f,0.0f,0.0f);	// couleur du premier vertex
  glVertex3f(-1.0f, 1.0f, 0.0f);// coordonnées du 1e vertex 		
  glColor3f(0.0f,1.0f,0.0f); // couleur du deuxieme vertex
  glVertex3f( 1.0f, 1.0f, 0.0f);// coordonnées du 2eme vertex 		
  glColor3f(0.0f,0.0f,1.0f);
  glVertex3f(1.0f,1.0f, 2.0f);
  glColor3f(1.0f,1.0f,1.0f);
  glVertex3f(-1.0f,1.0f, 2.0f);		
  glEnd();

  // on dessine un 4ème carre 
  glBegin(GL_QUADS);		// début du dessin
  glColor3f(1.0f,0.0f,0.0f);	// couleur du premier vertex
  glVertex3f(1.0f, -1.0f, 0.0f);// coordonnées du 1e vertex 		
  glColor3f(0.0f,1.0f,0.0f); // couleur du deuxieme vertex
  glVertex3f( -1.0f, -1.0f, 0.0f);// coordonnées du 2eme vertex 		
  glColor3f(0.0f,0.0f,1.0f);
  glVertex3f(-1.0f,-1.0f, 2.0f);
  glColor3f(1.0f,1.0f,1.0f);
  glVertex3f(1.0f,-1.0f, 2.0f);		
  glEnd();

  // on dessine un 5eme carre 
  glBegin(GL_QUADS);		// début du dessin
  glColor3f(1.0f,0.0f,0.0f);	// couleur du premier vertex
  glVertex3f(-1.0f, 1.0f, 0.0f);// coordonnées du 1e vertex 		
  glColor3f(0.0f,1.0f,0.0f); // couleur du deuxieme vertex
  glVertex3f( -1.0f, 1.0f, 2.0f);// coordonnées du 2eme vertex 		
  glColor3f(0.0f,0.0f,1.0f);
  glVertex3f(-1.0f,-1.0f, 2.0f);
  glColor3f(1.0f,1.0f,1.0f);
  glVertex3f(-1.0f,-1.0f, 0.0f);		
  glEnd();

  // on dessine un 6eme carre 
  glBegin(GL_QUADS);		// début du dessin
  glColor3f(1.0f,0.0f,0.0f);	// couleur du premier vertex
  glVertex3f(1.0f, 1.0f, 0.0f);// coordonnées du 1e vertex 		
  glColor3f(0.0f,1.0f,0.0f); // couleur du deuxieme vertex
  glVertex3f( 1.0f, 1.0f, 2.0f);// coordonnées du 2eme vertex 		
  glColor3f(0.0f,0.0f,1.0f);
  glVertex3f(1.0f,-1.0f, 2.0f);
  glColor3f(1.0f,1.0f,1.0f);
  glVertex3f(1.0f,-1.0f, 0.0f);		

  glEnd();

  // Fin d'un cube vertex par vertex

  glLoadIdentity();				// on ré initialise le point de vue de la scène
	
  rcx += 0.1f;					// Augmente la variable pour la rotation du carre sur l'axe des x
  rcy += 0.05f;					// Augmente la variable pour la rotation du carre sur l'axe des y

  // on échange les buffers (double buffering)
  glutSwapBuffers();
}

/* dessin de la scène par un tableau de vertex */
void DrawGLScene_TabVertex()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// on vide les buffers 
  glLoadIdentity();				// on initialise avec la matrice identité

  glTranslatef(0.0f,0.0f,-10.0f);		// on translate la scène vers le fond
	
  glRotatef(rcy,0.0f,1.0f,0.0f);		// on fait tourner la scène sur l'axe des Y
  glRotatef(rcx,1.0f,0.0f,0.0f);		// on fait tourner la scène sur l'axe des X

  //Début d'un cube par un tableau de vertex
  //8 vertex sous la forme de 8*3 floats
  GLfloat vertices[] = {-1.0f,1.0f,0.0f,
  						1.0f,1.0f,0.0f,
  						1.0f,-1.0f,0.0f,
  						-1.0f,-1.0f,0.0f,
  						-1.0f,1.0f,2.0f,
  						1.0f,1.0f,2.0f,
  						1.0f,-1.0f,2.0f,
  						-1.0f,-1.0f,2.0f};

  //24 indices sous la forme de 6 faces * 4 indices
  GLubyte indices[] = {0,1,2,3,
  					   4,5,6,7,
  					   4,0,3,7,
  					   1,5,6,2,
  					   4,5,1,0,
  					   7,6,2,3};
  //Les couleurs
  GLfloat colors [] = {1.0f,0.0f,0.0f,
  					   0.0f,1.0f,0.0f,
  					   0.0f,0.0f,1.0f,
  					   1.0f,1.0f,1.0f,
  					   1.0f,0.0f,0.0f,
  					   0.0f,1.0f,0.0f,
  					   0.0f,0.0f,1.0f,
  					   1.0f,1.0f,1.0f};
  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glColorPointer(3,GL_FLOAT,0,colors);
  glVertexPointer(3,GL_FLOAT,0,vertices);
  glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,indices);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
  
  // Fin d'un cube par un tableau de vertex

  glLoadIdentity();				// on ré initialise le point de vue de la scène
	
  rcx += 0.1f;					// Augmente la variable pour la rotation du carre sur l'axe des x
  rcy += 0.05f;					// Augmente la variable pour la rotation du carre sur l'axe des y

  // on échange les buffers (double buffering)
  glutSwapBuffers();
}

/* dessin de la scène qui contient un cube (c), un triangle (t) et les objets c' et t' symétriques selon le plan (yOz)*/
void DrawGLScene_EnDeux()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// on vide les buffers 
  glLoadIdentity();				// on initialise avec la matrice identité

  glTranslatef(0.0f,0.0f,-10.0f);		// on translate la scène vers le fond
	
  //glRotatef(rcy,0.0f,1.0f,0.0f);		// on fait tourner la scène sur l'axe des Y
  //glRotatef(rcx,1.0f,0.0f,0.0f);		// on fait tourner la scène sur l'axe des X

  //Début d'un cube par un tableau de vertex
  //8 vertex sous la forme de 8*3 floats
  GLfloat vertices[] = {-3.0f,1.0f,0.0f,
  						-2.0f,1.0f,0.0f,
  						-2.0f,0.0f,0.0f,
  						-3.0f,0.0f,0.0f,
  						-3.0f,1.0f,1.0f,
  						-2.0f,1.0f,1.0f,
  						-2.0f,0.0f,1.0f,
  						-3.0f,0.0f,1.0f};

  //24 indices sous la forme de 6 faces * 4 indices
  GLubyte indices[] = {0,1,2,3,
  					   4,5,6,7,
  					   4,0,3,7,
  					   1,5,6,2,
  					   4,5,1,0,
  					   7,6,2,3};
  //Les couleurs
  GLfloat colors [] = {1.0f,0.0f,0.0f,
  					   0.0f,1.0f,0.0f,
  					   0.0f,0.0f,1.0f,
  					   1.0f,1.0f,1.0f,
  					   1.0f,0.0f,0.0f,
  					   0.0f,1.0f,0.0f,
  					   0.0f,0.0f,1.0f,
  					   1.0f,1.0f,1.0f};
  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glColorPointer(3,GL_FLOAT,0,colors);
  glVertexPointer(3,GL_FLOAT,0,vertices);
  glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,indices);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
  
  // Fin d'un cube par un tableau de vertex

  //Début d'un triangle
  glBegin(GL_TRIANGLES);		// début du dessin
  glColor3f(1.0f,0.0f,0.0f);	// couleur du premier vertex
  glVertex3f(-2.0f, 0.0f, -5.0f);// coordonnées du 1e vertex 		
  glColor3f(0.0f,1.0f,0.0f); // couleur du deuxieme vertex
  glVertex3f(-1.0f, 0.0f, -5.0f);// coordonnées du 2eme vertex 		
  glColor3f(0.0f,0.0f,1.0f);
  glVertex3f(-1.0f,1.0f, -5.0f);	
  glEnd();
  //Fin d'un triangle
  //Début de la symétrique de cube
/*

    GLfloat vertices_sym[] = {3.0f,1.0f,0.0f,
  						2.0f,1.0f,0.0f,
  						2.0f,0.0f,0.0f,
  						3.0f,0.0f,0.0f,
  						3.0f,1.0f,1.0f,
  						2.0f,1.0f,1.0f,
  						2.0f,0.0f,1.0f,
  						3.0f,0.0f,1.0f};
  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glColorPointer(3,GL_FLOAT,0,colors);
  glVertexPointer(3,GL_FLOAT,0,vertices_sym);
  glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,indices);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
  //Fin de la symétrique de cube 
  
  //Début de la symétrique de triangle
  glBegin(GL_TRIANGLES);		// début du dessin
  glColor3f(1.0f,0.0f,0.0f);	// couleur du premier vertex
  glVertex3f(2.0f, 0.0f, -5.0f);// coordonnées du 1e vertex 		
  glColor3f(0.0f,1.0f,0.0f); // couleur du deuxieme vertex
  glVertex3f(1.0f, 0.0f, -5.0f);// coordonnées du 2eme vertex 		
  glColor3f(0.0f,0.0f,1.0f);
  glVertex3f(1.0f,1.0f, -5.0f);	
  glEnd();
  //Fin de la symétrique de triangle
  glLoadIdentity();				// on ré initialise le point de vue de la scène
	
  //rcx += 0.1f;					// Augmente la variable pour la rotation du carre sur l'axe des x
  //rcy += 0.05f;					// Augmente la variable pour la rotation du carre sur l'axe des y

  // on échange les buffers (double buffering)
  glutSwapBuffers();
}
// dessin de la scène qui contient un cube effectuant une marche aléatoire dans un espace à trois dimensions
void DrawGLScene_MarcheAleatoire(){
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// on vide les buffers 
  glLoadIdentity();				// on initialise avec la matrice identité

  glTranslatef(0.0f,0.0f,-10.0f);		// on translate la scène vers le fond
	
  //glRotatef(rcy,0.0f,1.0f,0.0f);		// on fait tourner la scène sur l'axe des Y
  //glRotatef(rcx,1.0f,0.0f,0.0f);		// on fait tourner la scène sur l'axe des X

  //Début d'un cube par un tableau de vertex
  //8 vertex sous la forme de 8*3 floats
  GLfloat vertices[] = {-3.0f,1.0f,0.0f,
  						-2.0f,1.0f,0.0f,
  						-2.0f,0.0f,0.0f,
  						-3.0f,0.0f,0.0f,
  						-3.0f,1.0f,1.0f,
  						-2.0f,1.0f,1.0f,
  						-2.0f,0.0f,1.0f,
  						-3.0f,0.0f,1.0f};

  //24 indices sous la forme de 6 faces * 4 indices
  GLubyte indices[] = {0,1,2,3,
  					   4,5,6,7,
  					   4,0,3,7,
  					   1,5,6,2,
  					   4,5,1,0,
  					   7,6,2,3};
  //Les couleurs
  GLfloat colors [] = {1.0f,0.0f,0.0f,
  					   0.0f,1.0f,0.0f,
  					   0.0f,0.0f,1.0f,
  					   1.0f,1.0f,1.0f,
  					   1.0f,0.0f,0.0f,
  					   0.0f,1.0f,0.0f,
  					   0.0f,0.0f,1.0f,
  					   1.0f,1.0f,1.0f};
  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glColorPointer(3,GL_FLOAT,0,colors);
  glVertexPointer(3,GL_FLOAT,0,vertices);
  glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,indices);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
  
  // Fin d'un cube par un tableau de vertex
  */

	const GLfloat M [] = {-1.0f,0.0f,0.0f,0.0f,
		       0.0f,1.0f,0.0f,0.0f,
		       0.0f,0.0f,1.0f,0.0f,
		       0.0f,0.0f,0.0f,1.0f};
	glMultMatrixf(M);

	 glEnableClientState(GL_COLOR_ARRAY);
  	glEnableClientState(GL_VERTEX_ARRAY);
  	glColorPointer(3,GL_FLOAT,0,colors);
  	glVertexPointer(3,GL_FLOAT,0,vertices);
  	glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,indices);
  	glDisableClientState(GL_COLOR_ARRAY);
  	glDisableClientState(GL_VERTEX_ARRAY);

	//Début d'un triangle
	  glBegin(GL_TRIANGLES);		// début du dessin
	  glColor3f(1.0f,0.0f,0.0f);	// couleur du premier vertex
	  glVertex3f(-2.0f, 0.0f, -5.0f);// coordonnées du 1e vertex 		
	  glColor3f(0.0f,1.0f,0.0f); // couleur du deuxieme vertex
	  glVertex3f(-1.0f, 0.0f, -5.0f);// coordonnées du 2eme vertex 		
	  glColor3f(0.0f,0.0f,1.0f);
	  glVertex3f(-1.0f,1.0f, -5.0f);	
	  glEnd();
	  //Fin d'un triangle
	//glutPostRedisplay();  
//glLoadIdentity();				// on ré initialise le point de vue de la scène
	
  //rcx += 0.1f;					// Augmente la variable pour la rotation du carre sur l'axe des x
  //rcy += 0.05f;					// Augmente la variable pour la rotation du carre sur l'axe des y

  // on échange les buffers (double buffering)
  glutSwapBuffers();
}
//Fonction qui détecte la touche de clavier
void clavier (unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'q':  printf("Au revoir!\n");
				   exit(1);
				   break;
		default : printf("Touche appuyé est %c\n",key);
	}
}

//Fonction qui détecte les touches de la souris
void MouseButton (int button,int state,int x,int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		printf ("Left mouse button pressed position (%d,%d)\n",x,y);
		gluLookAt(10,10,-10.0,0.0,0.0,0.0,0.0,1.0,0.0);
		glutPostRedisplay();
	}
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP))
	{
		printf ("Left mouse button released position (%d,%d)\n",x,y);
	} 
	if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN))
	{
		printf ("Right mouse button pressed position (%d,%d)\n",x,y);
	}
	if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_UP))
	{
		printf ("Right mouse button released position (%d,%d)\n",x,y);
	}
	if (button == 3)
	{
		printf ("Mouse wheel scroll up position (%d,%d)\n",x,y);
		glScalef(1,1,10);

	}
	if (button == 4)
	{
		printf ("Mouse wheel scroll down position (%d,%d)\n",x,y);
	}
 }


int main(int argc, char **argv) 
{  
  int choice = 0;
  printf("1. Dessiner un cube vertex par vertex (Exercice 1)\n2. Dessiner un cube en utilisant de tableaux de vertex(Exercice 1)\n3. En deux (Exercice 2)\n4. Marche aléatoire (Exercice 3)\nVeuillez faire votre choix : ");
  scanf("%d",&choice);
  /* initialisation de glut */
  glutInit(&argc, argv);  

  /* Mode d'affichage
     RGBA color
     Double buffer      
     Alpha components supported 
     z-buffer */  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  

  /* taille de la fenêtre 640 x 480 */
  glutInitWindowSize(640, 480);  

  /* la fenêtre se positionne en haut à gauche */
  glutInitWindowPosition(0, 0);  

    


  if (choice == 1)
  {
  	/* on crée la fenêtre */  
  	window = glutCreateWindow("Cube vertex par vertex- exo1");
  	/* On 'register' la fonction de dessin */
  	glutDisplayFunc(&DrawGLScene_VertexParVertex);  

  	/* fullscreen */
  	/* glutFullScreen(); */

  	/* même sans événements, on va re dessiné la scène */
  	glutIdleFunc(&DrawGLScene_VertexParVertex);
  	 /* en cas de redimensionnement */
 	 glutReshapeFunc(&ReSizeGLScene);
  

  	/* on initialise la scène */
 	 InitGL(640, 480);
  
 	 /* On lance la boucle de la gestion d'événements */  
  	glutMainLoop();  

  	}
   	if (choice == 2)
  	{
	  	/* on crée la fenêtre */  
	  	window = glutCreateWindow("Cube par le tableau de vertex- exo1");
	  	/* On 'register' la fonction de dessin */
	  	glutDisplayFunc(&DrawGLScene_TabVertex);  

	  	/* fullscreen */
	  	/* glutFullScreen(); */

	  	/* même sans événements, on va re dessiné la scène */
	  	glutIdleFunc(&DrawGLScene_TabVertex);
		/* en cas de redimensionnement */
		glutReshapeFunc(&ReSizeGLScene);
		  
		/* on initialise la scène */
		InitGL(640, 480);
		  
		/* On lance la boucle de la gestion d'événements */  
		glutMainLoop();  

	  }
	  if (choice == 3)
	  {
	  	/* on crée la fenêtre */  
	  	window = glutCreateWindow("En deux- exo2");
	  	/* On 'register' la fonction de dessin */
	  	glutDisplayFunc(&DrawGLScene_EnDeux);  

	  	/* fullscreen */
	  	/* glutFullScreen(); */

	  	/* même sans événements, on va re dessiné la scène */
	  	glutIdleFunc(&DrawGLScene_EnDeux);
		/* en cas de redimensionnement */
		glutReshapeFunc(&ReSizeGLScene_camera);
		// en cas d'appuie sur le clavier
		glutKeyboardFunc(&clavier); 
		//en cas d'appuie sur la souris
		glutMouseFunc(&MouseButton);
		/* on initialise la scène */
		InitGL_camera(1024, 780);
		
		/* On lance la boucle de la gestion d'événements */  
		glutMainLoop();  

	  }
	  if ((choice != 1)&&(choice != 2)&&(choice != 3)&&(choice != 4))
	  {
	  	printf ("Choix invalid\n");
	  }
	  /* les autres fonctions, gérant les événements :
	     claviers => glutKeyboardFunc(void (*func)(unsigned char key, int x, int y));
	     souris => glutMouseFunc(void (*func)(int button, int state, int x, int y)); 
	     mouvement de la sourie => void glutMotionFunc(void (*fonct)(int x,int y));
	  */

	 
	  return 1;
}
