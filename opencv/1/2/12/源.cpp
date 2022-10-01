#include<opencv2/opencv.hpp>
#include<iostream>
#include <opencv2/highgui/highgui_c.h>
using namespace cv;
int main(int arge, char** argv)
{
	Mat a = imread("1.jpg",1);
	if (a.empty())
	{
		printf("NOooooo\n");
		return -2;
	}
	Mat b;
	cvtColor(a, b, CV_GRAY2BGR);
	namedWindow("tt", CV_WINDOW_AUTOSIZE);
	imshow("tt", a);
	imshow("ttt", b);
	imwrite("E:\\LJWJ\\1.jpg",a);
	waitKey(0);
	return 0;
}