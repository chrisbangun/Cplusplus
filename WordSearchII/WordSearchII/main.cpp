//
//  main.cpp
//  WordSearchII
//
//  Created by Adi Bangun on 18/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution{
public:
    vector<string> findWords(vector<vector<char>>&board,vector<string>&words){
    
    }

};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<vector<char>> v;
    vector<string>words{"oath","pea","eat","rain"};
    
    //cout << words.at(2) << endl;
    vector<char> row;
    row.push_back('0');
    row.push_back('a');
    row.push_back('a');
    row.push_back('n');
    v.push_back(row);
    vector<char> rows;
    rows.push_back('e');
    rows.push_back('t');
    rows.push_back('a');
    rows.push_back('e');
    v.push_back(rows);
    vector<char> rowss;
    rowss.push_back('i');
    rowss.push_back('h');
    rowss.push_back('k');
    rowss.push_back('r');
    v.push_back(rowss);
    vector<char> ro;
    ro.push_back('i');
    ro.push_back('f');
    ro.push_back('l');
    ro.push_back('v');
    v.push_back(ro);
    
    //cout << v[3].at(3) << endl;
    vector<string>ans;
    
    ans = solution.findWords(v,words);
    
    return 0;
}
