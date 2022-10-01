#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<opencv.hpp>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace cv;

int  f(int x,int  y,int n,int m,int c,int d) {
	double a;
	a = (2.0 - sqrt(2))* (2.0 - sqrt(2))/ 4.0 * (a)+0.5 * m + (sqrt(2) - 1.0) / 2.0 * (1.0*c + 1.0*d);
	return a;
}
void ff(Mat s, Mat ss,int x, int y) {

	if (s.at<uchar>(x - 1, y - 1) > s.at<uchar>(x, y))///1
	{
		ss.at<uchar>(x - 1, y - 1) = 1;
	}
	else {
		ss.at<uchar>(x - 1, y - 1) = 0;
	}

	if (s.at<uchar>(x , y - 1) > s.at<uchar>(x, y))//2
	{
		ss.at<uchar>(x, y - 1) = 1;
	}
	else {
		ss.at<uchar>(x, y - 1) = 0;
	}

	if (s.at<uchar>(x , y +1) > s.at<uchar>(x, y))//3
	{
		ss.at<uchar>(x , y + 1) = 1;
	}
	else {
		ss.at<uchar>(x, y + 1) = 0;
	}

	if (s.at<uchar>(x + 1, y +1) > s.at<uchar>(x, y))//4
	{
		ss.at<uchar>(x +1, y + 1) = 1;
	}
	else {
		ss.at<uchar>(x +1, y + 1) = 0;
	}

	if (s.at<uchar>(x - 1, y + 1) > s.at<uchar>(x, y))//5
	{
		ss.at<uchar>(x - 1, y +1) = 1;
	}
	else {
		ss.at<uchar>(x - 1, y + 1) = 0;
	}

	if (s.at<uchar>(x +1, y - 1) > s.at<uchar>(x, y))//6
	{
		ss.at<uchar>(x + 1, y - 1) = 1;
	}
	else {
		ss.at<uchar>(x + 1, y - 1) = 0;
	}

	if (s.at<uchar>(x - 1, y ) > s.at<uchar>(x, y))
	{
		ss.at<uchar>(x - 1, y ) = 1;
	}
	else {
		ss.at<uchar>(x - 1, y) = 0;
	}

	if (s.at<uchar>(x + 1, y ) > s.at<uchar>(x, y))
	{
		ss.at<uchar>(x + 1, y) = 1;
	}
	else {
		ss.at<uchar>(x + 1, y ) = 0;
	}
}

//��Ե���
int main()
{
	int i, j;

	Mat img = imread("2.jpg");
	imshow("ԭͼ��", img);
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(15, 15));
	Mat DstPic, edge, grayImage, fushi, src, out2;
	//namedWindow("1");
	//������srcͬ���ͺ�ͬ��С�ľ���
	DstPic.create(img.size(), img.type());

	//��ԭʼͼת��Ϊ�Ҷ�ͼ
	cvtColor(img, grayImage, COLOR_BGR2GRAY);
	Mat img2;
	cvtColor(img,img2, COLOR_BGR2GRAY);

	imshow("�Ҷ�", grayImage);
	//��ʹ��3*3�ں�������
	{
		blur(grayImage, edge, Size(3, 3));
		imshow("����", edge);	
	}

	//����
	{
		
		Mat pengzhang;
		dilate(edge, pengzhang, element);
		imshow("����",pengzhang);
	}


	//��ʴ
	{
		erode(edge, fushi,element);
		imshow("��ʴ", fushi);
	}


	

	//new
	{
		/*cvtColor(img, src, COLOR_BGR2GRAY);
		for (i = 0;i < src.rows;i++) {
			for (j = 0;j < src.cols;j++) {
					src.at<uchar>(i, j) = (i+j)%255;
			}
		}*/
		//imshow("new",src);
	}
	Mat out;
	cvtColor(edge,edge, COLOR_GRAY2RGB);
	//˫���˲�
	{
		
		bilateralFilter(edge, out, 25, 25 * 2, 25 / 2);
		imshow("˫���˲�", out);
		imwrite("˫���˲�.jpg", out);
	}
	//cvtColor(out, out, COLOR_GRAY2RGB);
	cvtColor(out, out, COLOR_BGR2GRAY);
	
		//����canny����
		{
				Canny(out,out, 3, 9, 3);
				imshow("Canny�㷨������ȡЧ��",out);
				imwrite("����.jpg",out);
		}
		for (i = 0;i < out.rows;i++) {
			for (j = 0;j < out.cols;j++) {
				out.at<uchar> (i, j)= 255 - out.at<uchar>(i, j);
			}
		}
		imshow("��ɫ", out);
		imwrite("����2.jpg", out);
		//��һ��ͼ��,������Сʹ��ͼ��ɱȽ�
		int xmin = 0, xmax = 3 * img.rows / 4, ymin = 0, ymax = 3 * img.cols / 4;
		printf("%d %d\n", img.rows, img.cols);
		float a = 200.0 / (xmax - xmin);
		float b = 300.0 / (ymax - ymin);
		printf("%f %f", a, b);
		for (i = 0;i < img.rows;i++) {
			for (j = 0;j < img.cols;j++) {
				if (out.at<uchar>(i, j) <= 100)
				{
					out.at<uchar>(i, j) = 0;
				}
				img2.at<uchar>(i, j) = 255;
			}
		}
		for (i = 0;i < out.rows;i++) {
			for (j = 0;j < out.cols;j++) {
				if (out.at<uchar>(i, j) == 0) {
					img2.at<uchar>(int(a * i), int(b * j)) = 0;
				}

			}
		}
		imshow("��һ��ͼ��δʹ�ã�", img2);
		imwrite("��һ��.jpg", img2);
		Mat src3;
		cvtColor(img2, src3, COLOR_BGR2GRAY);
		//new ����LBP����
		for (i = 0;i < img2.rows;i++) {
			for (j = 0;j < img2.cols;j++) {
				src3.at<uchar>(i, j) = 255;
				if (img2.at<uchar>(i, j) == 0) {
					ff(img2,src3,i, j);
				}
			}
		}
		//�Შ�ݲ�
		int max;
		if (out.cols > out.rows) {
			max = out.cols;
		}
		else {
			max = out.rows;
		}

		Mat coor1 = Mat(max, max, CV_8UC3);
		cvtColor(coor1,coor1, COLOR_BGR2GRAY);
		coor1.setTo(255);
		int num = 0;
		/*Img = cv::Mat(cDepthHeight, cDepthWidth, CV_8UC3, cvScalar(255, 255, 255, 255));
		Img.setTo(255);*/
		for (i = 0;i < out.rows;i++) {
			for (j = 0;j < out.cols;j++) {
				if (out.at<uchar>(i, j) == 0) {
					num++;
				}
			}
			for (int k = max - num - 1;k < max;k++) {
					coor1.at<uchar>(k,i) = 0;
			}
			
			num = 0;
		}
		imshow("��",coor1);
		imwrite("�Შ.jpg", coor1);

		Mat coor2 = Mat(max,max, CV_8UC3);
		cvtColor(coor2, coor2, COLOR_BGR2GRAY);
		coor2.setTo(255);
		num = 0;
		for (j = 0;j < out.cols;j++) {
			for (i = 0;i < out.rows;i++) {
				if (out.at<uchar>(i, j) == 0) {
					num++;
				}
			}
			for (int k = max - num - 1;k < max;k++) {
					coor2.at<uchar>(k,j) = 0;
			}
		
			num = 0;
		}
		imshow("��",coor2);
		imwrite("�ݲ�.jpg", coor2);
	//��Բ
	/*{
			Mat ff;
			cvtColor(img, ff, COLOR_BGR2GRAY);
			int x, y;
			x = grayImage.rows/2;
			y = grayImage.cols/2;
			for (i = 0;i < grayImage.rows;i++) {
				for (j = 0;j < grayImage.cols;j++) {
					if ((i - x)*(i - x) + (j - y)*(j - y) <= 100) {
						ff.at<uchar>(i, j) = 255;
					}
					else {
						ff.at<uchar>(i, j) = 0;
					}
				}
			}
			Canny(ff,ff, 3, 9, 3);
			imshow("Բ",ff);
	}*/
	/*Mat src1,src2,x;
	//open����
	{
	
		erode(grayImage, src1, element);
		dilate(src1,src1,element);
		imshow("��", src1);
		imwrite("kai.jpg", src1);
	}

	//close
	{
		dilate(grayImage, src1, element);
		erode(src1, src1, element);
		imshow("��", src1);
		imwrite("bi.jpg", src1);
	}
			cvtColor(img, src1, COLOR_BGR2GRAY);
			cvtColor(img, src2, COLOR_BGR2GRAY);
			cvtColor(img, x, COLOR_BGR2GRAY);
	//��̬ѧ�ݶ�
	{
		
		dilate(grayImage, src1, element);
		erode(grayImage, src2, element);
		for (i = 0;i < grayImage.rows;i++) {
			for (j = 0;j < grayImage.cols;j++) {
				x.at<uchar>(i, j) = src1.at<uchar>(i, j) - src2.at<uchar>(i, j);
			}
		}
		imshow("��̬ѧ�ݶ�",x);
		imwrite("��̬ѧ�ݶ�.jpg", x);
	}
	//��ñ
	{
		erode(grayImage, src1, element);
		dilate(src1, src1, element);
		for (i = 0;i < grayImage.rows;i++) {
			for (j = 0;j < grayImage.cols;j++) {
				x.at<uchar>(i, j) = grayImage.at<uchar>(i, j) - src2.at<uchar>(i, j);
			}
		}
		imshow("��ñ", x);
		imwrite("��ñ.jpg",x);
	}
	//��ñ
	{
		dilate(grayImage, src1, element);
		erode(src1, src1, element);
		for (i = 0;i < grayImage.rows;i++) {
			for (j = 0;j < grayImage.cols;j++) {
				x.at<uchar>(i, j) = grayImage.at<uchar>(i, j) - src2.at<uchar>(i, j);
			}
		}
		imshow("��ñ", x);
		imwrite("��ñ.jpg", x);
	}*/
	waitKey(0);
}
