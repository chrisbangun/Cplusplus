//
//  main.cpp
//  arrayPermutation
//
//  Created by Adi Bangun on 04/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;

void permutate(int *a, int i, int n){
    if(i==n){
        cout << "disini " << i << n << endl;
        for(int x=0;x<=n;x++)
            cout << *(a+x) << " " ;
        cout << "\n";
    }else{
        for(int j=i;j<=n;j++){
            cout <<"increment " << j <<" i "<<i<< endl;
            int temp =a[i];
            a[i] = a[j];
            a[j] = temp;
            permutate(a,i+1,n);
            cout << "setelah " << i <<"dan " <<j<< endl;
            temp =a[i];
            a[i] = a[j];
            a[j] = temp;
            
        }
    }
}

int main(int argc, char *argv[]){
    int a[] = {1,2,3};
    permutate(a,0,2);
    return 0;
}