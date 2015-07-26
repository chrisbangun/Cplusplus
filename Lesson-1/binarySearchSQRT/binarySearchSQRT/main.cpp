//
//  main.cpp
//  binarySearchSQRT
//
//  Created by Adi Bangun on 19/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>

int mySqrt(int x){
    if(x==0)
        return -1;
    if(x<=3)
        return 1;
    int l = 1;
    int r = x;
    while(r-l > 1){
        int mid = (l+r)/2;
        if(mid*mid==x)
            return mid;
        if(mid*mid > x)
            r = mid;
        else
            l = mid;
    }
    if(r*r==x)
        return r;
    return l;
}

int mySqrtUtil(long long int _x, long long int l,long long int r){
    if(_x < 0)
        return -1; // imaginer
    if(_x==1)
        return 1;
    if(r-l>1){
        long long int mid = (l+r)/2;
        if(mid*mid == _x)
            return (int)mid;
        if(mid*mid > _x)
            return mySqrtUtil(_x,l,mid);
        else
            return mySqrtUtil(_x,mid,r);
    }
    else{
        if(r*r==_x)
            return (int)r;
        return (int)l;
    }
}
int mySqrt2(int x){
    return mySqrtUtil(x,1,x);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int number;
    std::cin >> number;
    //std::cout<<mySqrt(number)<<std::endl;
    std::cout<<mySqrt2(number)<<std::endl;
    return 0;
}
