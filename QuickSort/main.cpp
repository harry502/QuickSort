//
//  main.cpp
//  QuickSort
//
//  Created by shana on 2016/11/8.
//  Copyright © 2016年 shana. All rights reserved.
//

#include<cstdio>
#include<iostream>

using namespace std;

int a[100005];

void sway(int n,int m)
{
    int temp=a[n];
    a[n]=a[m];
    a[m]=temp;
}

int partition(int p,int q)
{
    int n=q,s=1;
    while(p!=q)
    {
        if( s && a[n]<a[p])
        {
            s=!s;
            sway(n,p);
            n=++p;
        }
        else if( s && a[n]>=a[p])
        {
            n=--q;
        }
        else if( !s && a[n]>a[q])
        {
            s=!s;
            sway(n,q);
            n=--q;
        }
        else if( !s && a[n]<=a[q])
        {
            n=++p;
        }
    }
    return n;
}

void qsort(int p,int q)
{
    int j=partition(p,q);
    if(p!=j) qsort(p,j-1);
    if(q!=j) qsort(j+1,q);
}

int main()
{
    freopen("/Users/shana/Desktop/实验课/算法实验课/1/Data.txt","r",stdin);
    freopen("/Users/shana/Desktop/实验课/算法实验课/1/out2.txt","w",stdout);
    
    //	----start time-----  设置计时开始
    double duration;
    clock_t  finish, start;
    start = clock();

    
    int t;
    scanf("%d",&t);
    int i=0;
    for(i=0;i<t;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(0,t-1);
    /*
    for(i=0;i<t;i++)
    {
        printf("%d ",a[i]);
    }
    */
    
    
    //	----finish time-----设置计时结束
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;  // 统计时间duration
    printf( "\nThe CPU time is %2.6f seconds:\n", duration );
    
    return 0;
}
