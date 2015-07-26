//
//  main.cpp
//  leetcode_MaxSubArray
//
//  Created by Adi Bangun on 21/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#define MAX(a,b) ((a)>(b)? (a):(b))
#define MAX3(a,b,c) (MAX((a),MAX((b),(c))))

int maxSubArrayUtil(int *nums,int low,int high){
    if(low > high)
        return INT_MIN;
    int mid = low+(high-low)/2;
    int leftHalves = maxSubArrayUtil(nums, low, mid-1);
    int rightHalves = maxSubArrayUtil(nums,mid+1,high);
    int lMax,sum;
    lMax = 0; sum = 0;
    for(int i=mid-1;i>=low;i--){
        sum+=*(nums+i);
        lMax = MAX(sum,lMax);
    }
    int rMax = 0;
    sum = 0;
    for(int i=mid+1;i<=high;i++){
        sum+=*(nums+i);
        rMax = MAX(sum,rMax);
    }
    return MAX3(lMax+nums[mid]+rMax,leftHalves,rightHalves);
}
int maxSubArray(int *nums,int size){
    return maxSubArrayUtil(nums,0,size-1);
}

int maxSubArrayDP(int *nums,int size){
    int globalMax = *nums;
    //std::cout << *(nums+size) << std::endl;
    int localMax = globalMax;
    for(int i=1;i<size;i++){
        localMax = MAX(localMax+*(nums+i),*(nums+i));
        globalMax = MAX(localMax, globalMax);
    }
    return globalMax;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[]={-2,1,-3,4,-1,2,1-5,4};
    int size = sizeof(arr)/sizeof(*arr);
    std::cout << maxSubArray(arr,size) << std::endl;
    std::cout << maxSubArrayDP(arr,size) << std::endl;
    return 0;
}
