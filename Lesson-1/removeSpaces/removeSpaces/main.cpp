//
//  main.cpp
//  removeSpaces
//
//  Created by Adi Bangun on 24/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution{
public:
    string removeSpace(string input);
};
string Solution::removeSpace(string input){
    if(input.length()==0)
        return "";
    int spaceCount = 0;
    for(int i=0;i<input.length();i++){
        if(input.at(i)!=' ')
            input.at(spaceCount++) = input.at(i);
    }
    for(int i=spaceCount; i<input.length();i++)
        input.at(i)=NULL;
    return input;
}
int main(int argc, const char * argv[]) {
    string input;
    getline(cin,input);
    Solution solution;
    input = solution.removeSpace(input);
    cout << input << endl;
    return 0;
}
