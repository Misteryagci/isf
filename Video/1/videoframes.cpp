
#include "opencv2/opencv.hpp"
#include "videoframes.hpp"
#include <cstdio> 
#include <stdio.h>
#include <vector>
#include <sstream>

using namespace cv;
using namespace std;

	VideoFrames::VideoFrames(){
    _frames.reserve(0);

	}
    //Constructeur avec paramètre
	VideoFrames::VideoFrames( const std::string& filename ){
        open(filename);
	}

	VideoFrames::~VideoFrames(){
    _frames.reserve(0);

	}

    //ouvre la vidéo passée en paramètre
	void VideoFrames::open( const std::string& filename ){
    VideoCapture cap(filename);
    if(!cap.isOpened())
    	printf("Erreur lors de l'ouverture de la vidéo");
    int x = cap.get(CV_CAP_PROP_FRAME_COUNT);

	_frames.resize(x);	

	for(int i=0; i<x; i++)
	{
		cap >> _frames[i];
	}
	}

    //On sauvegarde les frames en png
	void VideoFrames::saveToPngSequence( const std::string& folderName ) const{
    int x = nbFrames();
    std::stringstream file;
    int i;

    //On utilise un stringstream afin de pouvoir incrémenter le numéro de nom de chaque frame (afin qu'elles ne s'écrasent pas)
    for (int i = 0; i < x; ++i)
    {
        file <<folderName << "/image" << i << ".png";
        cv::imwrite(file.str(), frame(i));
        file.str("");
    }

	}
   
    //getter
	const cv::Mat& VideoFrames::frame( unsigned int index ) const{
    return _frames[index];

	}

	int VideoFrames::nbFrames() const{
    return _frames.size();

	}
