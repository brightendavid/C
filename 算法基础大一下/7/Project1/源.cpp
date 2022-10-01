
#include <iostream>   
#include <fstream>  
#include <opencv2/opencv.hpp>  
#include <math.h>  
using namespace cv;
using namespace std;
int main()
{
	//载入原始图，且必须以二值图模式载入  
	Mat M = imread("1.png", 0);
	imshow("原始图", M);

	//初始化结果图  
	Mat dstImage = Mat::zeros(M.rows, M.cols, CV_8UC3);
	int ElementShape = MORPH_RECT;

	Mat element = getStructuringElement(ElementShape, Size(2 * 2 + 1,
		2 * 2 + 1), Point(2, 2));

	morphologyEx(M, dstImage, MORPH_OPEN, element, Point(-1, -1), 4);


	imshow("【开运算】", dstImage);
	//定义轮廓和层次结构  
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(dstImage, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);
	//迭代器输出  
	/*for (vector<vector<Point>>::iterator it=contours.begin();it!=contours.end();++it)
	{
	for (vector<Point>::iterator inner_it=it->begin();inner_it!=it->end();++inner_it)
	{
	cout<<*inner_it<<endl;
	}
	}
	*/
	//下标输出  
	for (int i = 0; i < contours.size(); i++)
	{
		for (int j = 0; j < contours[i].size(); j++)
		{
			cout << contours[i][j].x << "   " << contours[i][j].y << endl;
			/*ofstream f;
			f.open("E:/坐标轮廓线.txt", ios::out | ios::app);
			f << contours[i][j].x << "  " << contours[i][j].y << endl;*/
		}
	}

	//遍历顶层轮廓，以随机颜色绘制出每个连接组件颜色  
	int index = 0;
	for (; index >= 0; index = hierarchy[index][0])
	{
		Scalar color(rand() % 255, rand() % 255, rand() % 255);
		drawContours(dstImage, contours, index, color, 1, 8, hierarchy);
	}

	imshow("轮廓图", dstImage);
	waitKey(5000); //等待5000ms后窗口自动关闭  
	getchar();
}
