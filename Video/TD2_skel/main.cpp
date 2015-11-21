#include "../../TD1/src/videoframes.hpp"
#include "../../TD1/src/motiontools.hpp"

#include <opencv2/legacy/legacy.hpp>

/*
 * Utilisation : ./blockMatching imRef imCurr blockSize vectordFlowStep
 *
 * imRef			fichier de l'image précédente
 * imCurr			fichier de l'image courante (que l'on souhaite également obtenir par compensation)
 * blockSize		taille des blocs
 * vectordFlowStep	pas pour l'affichage des vecteurs
 */
int main( int argc, char **argv )
{
	// Lecture des 2 image en entrée
	/* À compléter */

	// Lecture de la taille des blocks
	/* À compléter */

	// Conversion des 2 images en images Intel (IplImage)
	/* À compléter */

	// Définition des 2 matrices de déplacements en x et en y
	/* À compléter */

	// Définition des sous-matrices pour répondre aux contraintes de l'appel à cvCalcOpticalFlowBM
	/* À compléter */

	// Conversion des sous-matrices en images IPL
	/* À compléter */

	// Exécution de l'algorithme de block matching
	cvCalcOpticalFlowBM( /* À compléter */ );

	// Dessin de l'image de déplacements
	MotionTools::drawVectorFlow( /* À compléter */ );

	// Calcul de l'image compensée à partir des vecteurs de déplacement
	MotionTools::compenseFromVectorFlow( /* À compléter */ );

	// Calcul de l'image d'erreur entre l'image courante et l'image compensée
	MotionTools::errorImage( /* À compléter */ );

	// Calcul et affichage de l'Erreur Quadratique Moyenne
	std::cout << "EQM = " << MotionTools::computeEQM( /* À compléter */ ) << std::endl;

	// Affichage des deux images passées en paramètre
	/* À compléter */

	// Affichage de l'image de mouvements
	/* À compléter */

	// Affichage de l'image compensée
	/* À compléter */

	// Affichage de l'image d'erreur
	/* À compléter */

	return 0;
}

/*
 * Utilisation : ./blockMatching video blockSize vectordFlowStep
 *
 * video			fichier vidéo dont on souhaite calculer les frames par compensation
 * blockSize		taille des blocs
 * vectordFlowStep	pas pour l'affichage des vecteurs
 */
int main( int argc, char **argv )
{
	// Lecture de la video en entrée
	VideoFrames vf(/* À compléter */);

	// Lecture de la taille des blocks
	/* À compléter */

	// Initialisation de l'affichage de l'image courante, de l'image compensée et l'image de déplacement
	/* À compléter */

	// Définition des 2 matrices des déplacements en x et en y
	/* À compléter */
	// Définition des sous-matrices pour répondre aux contraintes de l'appel à cvCalcOpticalFlowBM
	/* À compléter */
	// Conversion des sous-matrices en images IPL
	/* À compléter */

	for ( int i=1 ; i<vf.nbFrames() ; ++i )
	{		
		std::cout << "Frame " << i << "/" << vf.nbFrames() << std::endl;

		// Initialisation de l'image de référence et de l'image courante
		const cv::Mat& imRef = /* À compléter */
		const cv::Mat& imCurr = /* À compléter */

		// Conversion des 2 images ci-dessus en images Intel
		/* À compléter */

		// Exécution de l'algorithme de block matching
		cvCalcOpticalFlowBM( /* À compléter */ );

		// Calcul de l'image compensée à partir des vecteurs de déplacement
		MotionTools::compenseFromVectorFlow( /* À compléter */ );

		// Dessin de l'image de déplacements
		MotionTools::drawVectorFlow( /* À compléter */ );

		// Mise à jour de l'affichage des 3 images
		/* À compléter */
	}

	return 0;
}