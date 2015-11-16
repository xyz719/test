/*#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main()
{
    Mat img = imread("F:\\LES.jpg");
    if(img.empty())
	{
       cout<<"error";
         return -1;
     }
     imshow("my",img);
	      waitKey();

     return 0;
}
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;

using namespace cv;
using namespace std;
void drawDetectLines(Mat& image,const vector<Vec4i>& lines,Scalar & color)
{
    // 将检测到的直线在图上画出来
    vector<Vec4i>::const_iterator it=lines.begin();
    while(it!=lines.end())
    {
        Point pt1((*it)[0],(*it)[1]);
        Point pt2((*it)[2],(*it)[3]);
        line(image,pt1,pt2,color,2); //  线条宽度设置为2
        ++it;
    }
}
int main()
{
     Mat img = imread("f:\\beauty.jpg");
	 Mat dst;
	 Sobel(img,dst,img.depth(),1,1);
     imwrite("sobel.jpg",dst);
     if(img.empty())
     {
         cout<<"error";
         return -1;
     }
	 Mat contours;
	 Canny(img,dst,200,200,3);  
	 //threshold(contours,contours,128,255,THRESH_BINARY);
	 //vector<Vec4i> lines;
	// HoughLinesP(contours,lines,1,CV_PI/18,8,5,1);
    // drawDetectLines(img,lines,Scalar(0,255,0));
     imwrite("canny.jpg",dst);
     imshow("20131105808",dst);
	 imshow("123",img);
     waitKey();
     return 0;
}*/
//#include "stdafx.h"
#include <opencv2/opencv.hpp>  
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>  
//using namespace std;  
using namespace cv; 

int main( int argc, char** argv )  
{  
    Mat src, edge,color_edge;  
    src=imread("f:\\beauty.jpg");  
    if( !src.data )    
        return -1;    
  
    Canny(src,edge,50,200,3);  
    cvtColor( edge, color_edge, CV_GRAY2BGR );  
    vector<Vec4i> lines;  
    HoughLinesP(edge, lines, 1, CV_PI/180, 80, 30, 10 );  
    for( size_t i = 0; i < lines.size(); i++ )  
    {  
        Vec4i l = lines[i];  
        line( color_edge, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 2);  
    }    
    namedWindow( "lines", CV_WINDOW_AUTOSIZE );  
    imshow( "lines", color_edge );  
    waitKey(0);  
    return 0;  
}
