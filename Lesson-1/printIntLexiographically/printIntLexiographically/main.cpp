//
//  main.cpp
//  printIntLexiographically
//
//  Created by Adi Bangun on 09/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;

void printLexiograph(long long _number,int x){
    if(x>_number)
        return;
    for(int i=0;i<9;i++){
        if(x <= _number){
            cout << x << endl;  
            x = x * 10;
            printLexiograph(_number,x);
            x = x /10;
            x++;
            if(x%10==0)
                return;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    long long number;
    cout << "input a number: ";
    cin >> number; cout << endl;
    printLexiograph(number,1);
    return 0;
}

