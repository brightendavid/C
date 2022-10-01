#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
long long n;
const int  maxn =1e6+10;
int cnt=0; //��¼��֪��������
vector<int> primes; //��������Ĳ���������
bool judge[maxn]; //ɸ�����
 
int main()
{
//	scanf("%lld",&n);
    int i,j;
    memset(judge,true,sizeof(judge));
    judge[0]=false;
    judge[1]=false;// 0��1����������
    for(i=2;i<maxn;i++)
    {
        if(judge[i])
        {
            primes.push_back(i);
            cnt++;
        }
        for(j=0;j<cnt && i*primes[j]<=maxn;j++)
        {
            judge[i*primes[j]]=false; //ɸ��
            if(i%primes[j]==0) //�ؼ�����
                break;
        }
    }
    vector<int>::iterator it;
    for(it=primes.begin();it!=primes.end();it++)//����
    {
        printf("%d\n",*it);
    }
    return 0;
}
