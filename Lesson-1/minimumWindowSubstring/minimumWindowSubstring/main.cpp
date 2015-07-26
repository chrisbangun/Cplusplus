//
//  main.cpp
//  minimumWindowSubstring
//
//  Created by Adi Bangun on 23/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
class Solution{
public:
    string minWindow(string S,string T){
        if(S=="" || T=="")
            return "";
        map<char,vector<char>> myMap;
        int sizeS = (int)S.length();
        for(int i=0;i<sizeS;i++){
            if(i+1<sizeS){
                
            }
        }
        
    }

};
int main(int argc, const char * argv[]) {
    string S="ADOBECODEBANC";
    string T="ABC";
    Solution solution;
    string ans = solution.minWindow(S,T);
    return 0;
}
