//
//  main.cpp
//  singleElement
//
//  Created by Adi Bangun on 09/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    set<int> containers;
    int arr[] = {1,2,1,2,3,4,3,5,5};
    int arr_size = sizeof(arr)/sizeof(*arr);
    int singleNumber = 0;
    
    //using XOR
    for(int i=0;i< arr_size;i++){
        singleNumber^=arr[i];
       // cout << "here: " << singleNumber << endl;
    }
    cout << "using XOR: " << singleNumber << endl;
    //using set
    set<int>::iterator it;
    for(int i=0;i<arr_size;i++){
        if(containers.find(arr[i])!=containers.end()){
            containers.insert(arr[i]);
        }
        else
            containers.erase(arr[i]);
    }
    for (it=containers.begin();it!=containers.end();++it)
            cout << *it<< endl;
    return 0;
}
