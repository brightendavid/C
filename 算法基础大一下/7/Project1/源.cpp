
#include <iostream>   
#include <fstream>  
#include <opencv2/opencv.hpp>  
#include <math.h>  
using namespace cv;
using namespace std;
int main()
{
	//����ԭʼͼ���ұ����Զ�ֵͼģʽ����  
	Mat M = imread("1.png", 0);
	imshow("ԭʼͼ", M);

	//��ʼ�����ͼ  
	Mat dstImage = Mat::zeros(M.rows, M.cols, CV_8UC3);
	int ElementShape = MORPH_RECT;

	Mat element = getStructuringElement(ElementShape, Size(2 * 2 + 1,
		2 * 2 + 1), Point(2, 2));

	morphologyEx(M, dstImage, MORPH_OPEN, element, Point(-1, -1), 4);


	imshow("�������㡿", dstImage);
	//���������Ͳ�νṹ  
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(dstImage, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);
	//���������  
	/*for (vector<vector<Point>>::iterator it=contours.begin();it!=contours.end();++it)
	{
	for (vector<Point>::iterator inner_it=it->begin();inner_it!=it->end();++inner_it)
	{
	cout<<*inner_it<<endl;
	}
	}
	*/
	//�±����  
	for (int i = 0; i < contours.size(); i++)
	{
		for (int j = 0; j < contours[i].size(); j++)
		{
			cout << contours[i][j].x << "   " << contours[i][j].y << endl;
			/*ofstream f;
			f.open("E:/����������.txt", ios::out | ios::app);
			f << contours[i][j].x << "  " << contours[i][j].y << endl;*/
		}
	}

	//���������������������ɫ���Ƴ�ÿ�����������ɫ  
	int index = 0;
	for (; index >= 0; index = hierarchy[index][0])
	{
		Scalar color(rand() % 255, rand() % 255, rand() % 255);
		drawContours(dstImage, contours, index, color, 1, 8, hierarchy);
	}

	imshow("����ͼ", dstImage);
	waitKey(5000); //�ȴ�5000ms�󴰿��Զ��ر�  
	getchar();
}
