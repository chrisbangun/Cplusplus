//
//  main.cpp
//  squareRootNumber
//
//  Created by Adi Bangun on 08/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int number,int l,int r){
    if(r < l || number <=0)
        return -1;
    if(number==1)
        return 1;
    int mid = (l+r)/2;
    if(mid*mid==number)
        return mid;
    if(mid*mid < number){
        if(number - (mid*mid) <= r)
            return mid;
        return binarySearch(number,mid+1,r);
    }
    else{
        return binarySearch(number,l,mid);}
}

int main(int argc, const char * argv[]) {
    // insert code here...
    // finding the square root of a given number
    // without using the math.sqrt function
    int number;
    std::cin >> number;
    int n = 1;
    bool flag = false;
    
    // O(n)
    while(n*n <= number){
        if(n*n==number){
            flag = true;
            break;
        }
        n++;
    }
    std:: cout << binarySearch(number,0,number/2) << std::endl;
    (flag) ? std::cout << n << std::endl:std::cout<< n-1 << std::endl;
    return 0;
}
