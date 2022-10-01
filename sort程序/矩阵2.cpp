#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<opencv.hpp>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace cv;
typedef struct NODE
{
 int row;
 int col;
 int date;
 struct NODE* next;
}node;
node* createList(char str[]);
void destroyList(node* head);
void suanfa(node* head1, node* head2);
char* my_itoa(char* str, int num)//局部变量，出了作用域释放
{
 int i = 0;
 while (num != 0)
 {
  str[i] = num % 10 + '0';//得到字符串“3 2 1”
  num = num / 10;//num == 0
  i++;//i == 3
 }
 str[i] = '\0';//str[3]
 i--;
 for (int j = 0; j < i; j++, i--)
 {
  char ch = str[j];//0号下标的元素赋给ch
  str[j] = str[i];//2号下标的元素赋给0号下标==》str【】==121
  str[i] = ch;//把3赋给2号下标
 }
 return str;
}
Mat image(Size(256, 256), CV_8UC3, Scalar(255, 255, 255));
int X[196608];
int a[196608];
int main()
{
 node* head1, * head2;
 char str1[] = "C:\\作业\\opencv\\A.txt";
 char str2[] = "C:\\作业\\opencv\\B.txt";
 head1 = createList(str1);
 head2 = createList(str2);
 suanfa(head1, head2);
 destroyList(head1);
 destroyList(head2);
 imwrite("X.jpg", image);
 return 0;
}
node* createList(char str[])//读文件
{
 FILE* fp;
 fp = fopen(str, "r");
 node* p, * q, * head;
 head = (node*)malloc(sizeof(node));
 q = head;
 int rows, cols, udate;
 printf("%c", fgetc(fp));
 while (!feof(fp))
 {
  fscanf(fp, "%d", &rows);
  fgetc(fp);
  fgetc(fp);
  fscanf(fp, "%d", &cols);
  fgetc(fp);
  fgetc(fp);
  fscanf(fp, "%d", &udate);
  fgetc(fp);
  fgetc(fp);
  fgetc(fp);
  p = (node*)malloc(sizeof(node));
  p->col = cols;
  p->row = rows;
  p->date = udate;
  q->next = p;
  q = p;
 }
 q->next = NULL;
 q = head;
 head = head->next;
 free(q);
 return head;
}
void destroyList(node* head)
{
 node* p, * q;
 for (p = head; p != NULL;)
 {
  q = p;
  p = p->next;
  free(q);
 }
}
void suanfa(node* head1, node* head2)
{
 FILE* fp;
 int i, j, flag;
 int sum;
 char s[8] = "";
 node* p, * q;
 memset(X, 0, sizeof(X));
 memset(a, 0, sizeof(a));
 for (i = 0; i < 4; i++)
 {
  p = head1;
  q = head2;
  for (j = 0; j < 196608; j++)
  {
   sum = 0;
   while (p->row == j + 1)
   {
    if (j + 1 == p->col)
    {
     flag = p->date;
     p = p->next;
    }
    else
    {
     sum += (-1) * p->date * X[p->col - 1];
     p = p->next;
    }
    if (p == NULL)
     break;
   }
   a[j] = X[j] = (sum + q->date) / flag;
   q = q->next;
  }
  fp = fopen("C:\\作业\\opencv\\X.txt", "w");
  if (fp == NULL)
  {
   printf("文件打开失败\n");
  }
  else
  {
   for (i = 0; i < 196608; i++)
   {
    fputs(my_itoa(s, a[i]), fp);
    fputs("\n", fp);
   }
  }
  fclose(fp);
  for (int i = 0; i < 256; i++)
  {
   for (int j = 0; j < 256; j++)
   {
    image.at<Vec3b>(i, j)[2] = X[i * 256 + j];
    image.at<Vec3b>(i, j)[1] = X[256 * 256 + i * 256 + j];
    image.at<Vec3b>(i, j)[0] = X[256 * 256 * 2 + i * 256 + j];
   }
  }
  imshow("a", image);
  waitKey(0);
 }
}
