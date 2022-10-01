#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
long long n;
const int  maxn =1e6+10;
int cnt=0; //记录已知素数数量
vector<int> primes; //存放素数的不定长数组
bool judge[maxn]; //筛除标记
 
int main()
{
//	scanf("%lld",&n);
    int i,j;
    memset(judge,true,sizeof(judge));
    judge[0]=false;
    judge[1]=false;// 0和1都不是素数
    for(i=2;i<maxn;i++)
    {
        if(judge[i])
        {
            primes.push_back(i);
            cnt++;
        }
        for(j=0;j<cnt && i*primes[j]<=maxn;j++)
        {
            judge[i*primes[j]]=false; //筛除
            if(i%primes[j]==0) //关键代码
                break;
        }
    }
    vector<int>::iterator it;
    for(it=primes.begin();it!=primes.end();it++)//遍历
    {
        printf("%d\n",*it);
    }
    return 0;
}
