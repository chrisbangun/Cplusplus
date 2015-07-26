//
//  main.cpp
//  Sansa and Xor
//
//  Created by Adi Bangun on 23/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void printContigousArray(vector<int>& numbers,int l,int r){
    if(l==r){
        int size = (int)numbers.size();
        for(int i=0;i<size;i++)
            cout << numbers[i] << " " ;
        cout << endl;
    }
    else{
        for(int i=l;i<=r;i++){
            swap(numbers[l],numbers[i]);
            printContigousArray(numbers,l+1,r);
            swap(numbers[l],numbers[i]);
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int T, N,n;
    cin >> T;
    vector<int> numbers;
    while(T--){
        cin >> N;
        for(int i=0;i<N;i++){
            cin >> n;
            numbers.push_back(n);
        }
        printContigousArray(numbers,0,N-1);
    }
    return 0;
}
