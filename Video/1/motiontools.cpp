#include "motiontools.hpp"

namespace MotionTools
{
	void drawVectorFlow( cv::Mat& im, const cv::Mat& vecFlowX, const cv::Mat& vecFlowY, int step, const cv::Scalar& color ){
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
	

	/*void compenseFromVectorFlow( cv::Mat& imComp, const cv::Mat& imRef, const cv::Mat& vecFlowX, const cv::Mat& vecFlowY ){}
	void errorImage( cv::Mat& imErr, const cv::Mat& imCurr, const cv::Mat& imComp ){}
	float computeEQM( const cv::Mat& imCurr, const cv::Mat& imComp ){}*/
}

