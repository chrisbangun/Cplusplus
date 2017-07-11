//
//  main.cpp
//  printRecurrsive
//
//  Created by Adi Bangun on 19/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string.h>
#define R 3
#define C 3
using namespace std;

void printUtil(string arr[R][C],string seen, int row){
    if(row==R ){
        //cout << seen << endl;
        return;
    }
    for(int i=0;i<C;i++){
        if(arr[row][i]!=" "){
            cout << "cek: " << row << endl;
            printUtil(arr,seen+" "+arr[row][i],row+1);}
    }
}


void print(string arr[R][C]){
    printUtil(arr,"",0);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string arr[R][C]={{"you","we"},{"have","are"},{"sleep","eat","drink"}};
    //cout << arr[1][0];
    print(arr);
    return 0;
}
