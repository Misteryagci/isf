#include "motiontools.hpp"

namespace MotionTools;

	void MotionTools::drawVectorFlow( cv::Mat& im, const cv::Mat& vecFlowX, const cv::Mat& vecFlowY, int step, const cv::Scalar& color ){
        cv::Point pt1;
        cv::Point pt2;
        int lignes = im.rows;
        int colonnes = im.cols;
        for (int i = 0; i < lignes; i+step)
        {
        	for (int j = 0; j < colonnes; j+step)
        	{
        		pt1.x = i;
        	    pt1.y = j;
        	    pt2.x << vecFlowX.at<int>(0,i);
        	    pt2.y << vecFlowY.at<int>(0,j);
                line(im, pt1, pt2, color, 1, 8, 0);	
            }
        }
	}	
	

	void MotionTools::compenseFromVectorFlow( cv::Mat& imComp, const cv::Mat& imRef, const cv::Mat& vecFlowX, const cv::Mat& vecFlowY )
    {
        int i = 0;
        int j = 0;
        cv::Size tailleRef = imRef.size(); //La taille de la matrice réfécrence
        cv::Size tailleX = vecFlowX.size();
        cv::Size tailleY = vecFlowY.size();
        imComp = imRef.clone();
        //Parcours de l'image référence
        for (i=0;i<tailleRef.width;i++)
        {
            //Parcours de la line
            for (j=0;j<tailleRef.height;j++)
            {
                imComp.at<int>(i,j) = imRef.at<int>(i+vecFlowX.at<int>(0,i),j+vecFlowY.at<int>(j,0));
            }
        }

    }
	void errorImage( cv::Mat& imErr, const cv::Mat& imCurr, const cv::Mat& imComp ){
        imErr = imComp.clone();
        int i=0,j=0;
        for (i=0;i<imCurr.size().width;i++)
        {
            for (j=0;j<imCurr.size().height;j++)
            {
                imErr.at<int>(i,j) = min(255,max(0,imCurr.at<int>(i,j)-imComp.at<int>(i,j)+128));
            }
        }
    }
	float computeEQM( const cv::Mat& imCurr, const cv::Mat& imComp ){
        float res = 0;
        int w = (imCurr.size().width), h = (imCurr.size().height));
        int i = 0;
        for (i=0;i<w;i++)
        {
            for (j=0;j<h;j++)
            {
                res+=imCurr.at<float>(i,j)+imComp.at<float>(i,j);
            }
        }
        return (1.0/() * res;
    }

