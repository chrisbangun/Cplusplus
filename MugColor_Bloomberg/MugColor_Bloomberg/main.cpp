//
//  main.cpp
//  MugColor_Bloomberg
//
//  Created by Adi Bangun on 23/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    map<string,int> mugColor;
    string s[5];
    s[0] = "Bloomberg";
    s[1] = "Adi";
    cout << s[1] << " works in " << s[0] << endl;
    mugColor["White"] = 0;
    mugColor["Black"] = 0;
    mugColor["Blue"] = 0;
    mugColor["Red"] = 0;
    mugColor["Yellow"]= 0;
    int N;
    string color;
    cin >> N;
    while(N--){
        cin >> color;
        mugColor[color]++;
    }
    map<string,int>::iterator it;
    for(it=mugColor.begin();it!=mugColor.end();++it){
        if(it->second==0){
            cout << it->first << endl;
            break;
        }
    }
    return 0;
}
