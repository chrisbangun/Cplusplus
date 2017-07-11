//
//  main.cpp
//  mostSuccessiveElement
//
//  Created by Adi Bangun on 23/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    map<int,int>container;
    cin >> n;
    int number;
    while(n--){
        cin >> number;
        if(container.count(number)==1){
            container[number]++;
        }
        else
            container[number] = 1;
    }
    map<int,int>::iterator it;
    int successive = -1;
    for(it=container.begin();it!=container.end();it++){
        successive = MAX(successive,it->second);
    }
    cout << successive << endl;
    return 0;
}
