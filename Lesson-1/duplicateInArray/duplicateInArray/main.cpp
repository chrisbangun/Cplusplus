//
//  main.cpp
//  duplicateInArray
//
//  Created by Adi Bangun on 22/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
int duplicate(int *arr,int size){
    for(int i=0;i<size;i++){
        if(arr[i] > size-1 || arr[i] < 0)
            return INT_MIN;
        while(arr[i]!=i){
            if(arr[i]==arr[arr[i]])
                return arr[i];
            int temp = arr[i];
            arr[i] = arr[temp];
            arr[temp] = temp;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    std::cin >> n;
    int arr[n+1];
    for(int i=0;i<n;i++)
        std::cin >> arr[i];
    int ans = duplicate(arr,n);
    if(ans==INT_MIN)
        std::cout << "Error" << std::endl;
    else if(ans==-1)
        std::cout << "No duplications found" << std::endl;
    else
        std::cout << ans << std::endl;
    return 0;
}
