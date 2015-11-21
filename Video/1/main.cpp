#include "videoframes.hpp"
#include "motiontools.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>


// 2.1 : Extraction de la séquence d'images d'une vidéo
//Terminé, les images de la séquence sont enregistrées dans le dossier Resultat.

int main( int argc, char* argv[] )
{
	// Lecture de la vidéo passée en paramètre
	// La création du vecteur se fait à la lecture
	VideoFrames vf(argv[1]);

	// Affichage de la première trame
	const cv::Mat& frame = vf.frame(1);
	if(! frame.data )                             
    {
        std::cout <<  "Impossible d'afficher l'image" << std::endl ;
        return -1;
    }
	cv::namedWindow( "Résultat", CV_WINDOW_AUTOSIZE);
    imshow( "Résultat", frame );

    cv::waitKey(0);                                          // Appuyer sur une touche pour pouvoir continuer

	// Sauvegarde de la séquence des trames
	vf.saveToPngSequence(argv[2]);

	return 0;
}/*

// 2.2 Affichage d’un champ de vecteurs
int main( int argc, char* argv[] )
{
	// Lecture de l'image passée en paramètre
    cv::Mat image = cv::imread(argv[1], 0);

	// Initialisation des vecteur de déplacement
    cv::Mat vectX(image.rows,0,CV_32FC2,0);
    cv::Mat vectY(image.cols,0,CV_32FC2,0);

    

	// Dessin des vecteurs de déplacment sur une image à afficher
	cv::Scalar& color(255,255,255);
 	MotionTools::drawVectorFlow( image, vectX, vectY, 15, color);

	// Affichage de l'image où ont été dessiné les vecteurs
	cv::namedWindow( "Résultat", CV_WINDOW_AUTOSIZE);
    imshow( "Résultat", image );

    cv::waitKey(0);                                          // Appuyer sur une touche pour pouvoir continuer

 	return 0;
}

/*
// 2.3, 2.4 et 2.5 Compensation de l'image, calcul de l'image d'erreurs et calcul de l'Erreur Quadratique Moyenne (EQM)
int main( int argc, char* argv[] )
{
	// Lecture de l'image passée en paramètres
	À compléter 

	// Création artificielle d'un champ de vecteur (3,3) sur l'ensemble de l'image
	 À compléter 

	// Calcul de l'image compensée à partir du champ de vecteurs (cela produit un décalage de (3,3))
	MotionTools::compenseFromVectorFlow(  À compléter  );

	// Calcul de l'image d'erreur entre l'image initiale et l'image compensée
	MotionTools::errorImage( À compléter  );

	// Calcul et affichage de l'Erreur Quadratique Moyenne
	std::cout << "EQM = " << MotionTools::computeEQM(  À compléter ) << std::endl;

	// Affichage des différentes images
	 À compléter 

	return 0;
}*/