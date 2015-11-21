#include "videoframes.hpp"
#include "motiontools.hpp"


// 2.1 : Extraction de la séquece d'images d'une vidéo

int main( int argc, char* argv[] )
{
	// Lecture de la vidéo passée en paramètre
	// La création du vecteur se fait à la lecture
	VideoFrames vf(argv[1]);
		
	
	

	// Affichage de la première trame
	const cv::Mat& frame = vf.frame(1);
	
	
	
	// Sauvegarde de la séquence des trames
	vf.saveToPngSequence( argv[2] );
	
	return 0;
}

// 2.2 Affichage d’un champ de vecteurs
//int main( int argc, char* argv[] )
//{
	// Lecture de l'image passée en paramètre
	/* À compléter */

	// Initialisation des vecteur de déplacement
	/* À compléter */

	// Dessin des vecteurs de déplacment sur une image à afficher
 //	MotionTools::drawVectorFlow( /* À compléter */ );

	// Affichage de l'image où ont été dessiné les vecteurs
	/* À compléter */

 //	return 0;
//}

// 2.3, 2.4 et 2.5 Compensation de l'image, calcul de l'image d'erreurs et calcul de l'Erreur Quadratique Moyenne (EQM)
//int main( int argc, char* argv[] )
//{
	// Lecture de l'image passée en paramètres
	 //À compléter 

	// Création artificielle d'un champ de vecteur (3,3) sur l'ensemble de l'image
	//À compléter 

	// Calcul de l'image compensée à partir du champ de vecteurs (cela produit un décalage de (3,3))
//	MotionTools::compenseFromVectorFlow( /* À compléter */ );

	// Calcul de l'image d'erreur entre l'image initiale et l'image compensée
//	MotionTools::errorImage( /* À compléter */ );

	// Calcul et affichage de l'Erreur Quadratique Moyenne
//	std::cout << "EQM = " << MotionTools::computeEQM( /* À compléter */ ) << std::endl;

	// Affichage des différentes images
	/* À compléter */

//	return 0;
//}
