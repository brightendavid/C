#include<opencv2/opencv.hpp>
#include<iostream>


using namespace cv;

int main(int arge, char** argv)
{
	Mat src = imread("1.jpg" ,1);
	//Mat src(600, 500, CV_8UC3, Scalar(0, 0, 0));
	//Mat src(100, 100, CV_8UC3, Scalar(0, 0, 255));
	int i,j;
	int b, g, r;
	/*int n, m;
	scanf_s("%d%d", &n, &m);*/
	if(src.empty())
	{
		printf("could not load image.......\n");
		return -2;
	}
	/*src.data[9] = 0;
	src.data[10] = 0;
	src.data[11] = 255;     */
	int cols = src.cols;
	int rows = src.rows;
	//printf("%d	%d", cols, rows);//图像的像素
	
	Mat test2;
	test2.create(src.size(),src.type());

	//Mat b;
	//namedWindow("test22", CV_WINDOW_AUTOSIZE);//CV_WINDOW_NORMAL
	//cvtColor(src,test2,CV_BayerRG2GRAY);
	int nc = src.channels();
	float al = 1.2;
	float beta = 10;
	//cvDrawCircle(src, 500, 500, 250);
	//filter2D(src, test2, -1, b);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			/*if ((i - 500) * (i - 500) + (j - 500) * (j - 500) <= 10000)
			{
				src.at<uchar>(i,j)= 0;
			}*/
			if (nc == 1)
			{
				int gray = test2.at<uchar>(i, j);
				test2.at<uchar>(i, j) = 255 - gray;
			}
			else if (nc == 3 )
			{
				b = src.at<Vec3b>(i, j)[0];
				g = src.at<Vec3b>(i, j)[1];
				r = src.at<Vec3b>(i, j)[2];
				test2.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(b*al+beta);
				test2.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(g *al + beta);;
				test2.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(r * al + beta);;
				
				//waitKey(1);

			}
		}
	}
	
	//bitwise_not(src, test2);
	imshow("text", src);
	imshow("1", test2);
//	imwrite("E:\\LJWJ\\551.bmp", src);
	waitKey(0);
	return 0;
}