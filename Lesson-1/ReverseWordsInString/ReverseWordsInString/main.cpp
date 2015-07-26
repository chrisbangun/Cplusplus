//
//  main.cpp
//  ReverseWordsInString
//
//  Created by Adi Bangun on 17/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;

void printLexio(int n,int k){
    for(int i=0;i<9;i++){
        if(k<=n){
            cout << k << endl;
            k*=10;
            printLexio(n,k);
            k/=10;
            k++;
        }
        else{
            return ;
        }
    }
}

int main(int argc, char ** argv){
    int n;
    cin >> n;
    printLexio(n,1);
    return 0;
}
