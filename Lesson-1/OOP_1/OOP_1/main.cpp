//
//  main.cpp
//  OOP_1
//
//  Created by Adi Bangun on 04/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution{
public:
    int sum(int a, int b){
        return a+b;
    }
};

int main(){
    Solution solution;
    cout << solution.sum(5, 10);
    return 0;
}
