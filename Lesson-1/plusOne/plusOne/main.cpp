//
//  main.cpp
//  plusOne
//
//  Created by Adi Bangun on 22/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<int>plusOneUtil(vector<int>digits, int k){
        if(k!=0){
            digits.push_back(k);
            return digits;
        }else{
            int temp;
            for(int i=0;i<digits.size();i++){
                temp = digits[i] + 1;
            }
        }
        
    }
    vector<int>plusOne(vector<int>& digits){
        return plusOneUtil(digits,0);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;
    vector<int>digit;
    digit.push_back(9);
    digit.push_back(9);
    digit.push_back(9);
    digit.push_back(9);
    digit = solution.plusOne(digit);
    return 0;
}
