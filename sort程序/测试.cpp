#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
struct gen                //����Ⱦɫ��ṹX
{
	int  info;        		//Ⱦɫ��ṹ //��ʾlength ��(0,255)������
	int  suitability;		//��Ⱦɫ������Ӧ����Ӧ�Ⱥ���ֵ���ڱ�����Ϊf(x)=|AX-B|������� ����״̬Ӧ����1 ѡ��ʱ����  ���ǰ������ó���������f(x)��ֵ
};
struct gen	new1[2]={{1,2},{2,2}};
main()
{
 
  struct gen *s;
  s=(struct gen*)malloc(sizeof(gen));
  *s=new1[0];
  new1[0]=new1[1];
  new1[1]=*s;
  free(s);
  printf("%d %d",new1[0].info,new1[1].info);
}
