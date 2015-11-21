#include "opencv2/opencv.hpp"
#include "videoframes.hpp"
#include <cstdio> 
#include <stdio.h>
#include <vector>

using namespace cv;
using namespace std;

VideoFrames::VideoFrames()
{
	_frames.reserve(0);
}

VideoFrames::~VideoFrames()
{
	_frames.reserve(0);
}

VideoFrames::VideoFrames( const std::string& filename )
{
	VideoCapture cap(filename);

	int nb_frame = cap.get(CV_CAP_PROP_FRAME_COUNT);
	
	//initialiser et allocation tableau
	_frames.resize(nb_frame);	

	for(int i=0; i<nb_frame; i++)
	{
		cap >> _frames[i];
	}
}

void VideoFrames::open( const std::string& filename )
{
	VideoCapture cap(filename);

	int nb_frame = cap.get(CV_CAP_PROP_FRAME_COUNT);
	
	//initialiser et allocation tableau
	_frames.reserve(nb_frame);	

	for(int i=0; i<nb_frame; i++)
	{
		cap >> _frames[i];
	}
}


int VideoFrames::nbFrames() const
{

return _frames.size(); 

}


const cv::Mat& VideoFrames::frame( unsigned int index ) const
{
	return _frames[index];
}




void VideoFrames::saveToPngSequence( const std::string& folderName ) const
{
	int nb = nbFrames();
	char s[20];
	int i;

	for(i=0; i<nb; i++)	
	{
	sprintf(s,"folderName/frame%d.jpg",i);
	imwrite(s, _frames[i]);
	}	

}
