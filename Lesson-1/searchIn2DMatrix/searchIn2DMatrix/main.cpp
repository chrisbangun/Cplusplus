//
//  main.cpp
//  searchIn2DMatrix
//
//  Created by Adi Bangun on 22/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#define ROWS 3
#define COLS 3
bool find(int *number,int target){
    int rows = (int)sizeof(number)/sizeof(number[0]);
    int cols = (int)sizeof(number[0])/sizeof(number[0][);
    std::cout << rows <<" "<< cols << std::endl;
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m,target;
    std::cin >> n >> m >> target;
    int number[n+1][m+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            std:: cin >> number[i][j];
    }
    bool flag = find((int*)number, target);
    return 0;
}
