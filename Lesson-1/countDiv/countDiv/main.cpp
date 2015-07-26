//
//  main.cpp
//  countDiv
//
//  Created by Adi Bangun on 27/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//
#include<iostream>
using namespace std;

#define max_n 5000000
int mod=100000;
int memo[max_n+5];

int fib(int n)
{
    if(n==1)return 0;
    if(n==2) return 1;
    if(memo[n]>0)return memo[n];
    memo[n]=(fib((n%mod)-1) + fib((n%mod)-2))%mod;
    return memo[n];
}
int main()
{
    int n,i;
    for(i=max_n;i>=1;i--)
    {
        fib(i);
    }
    
    cin>>n;
    cout<<memo[n]<<endl;
    return 0;
    
}

