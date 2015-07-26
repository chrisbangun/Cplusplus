//
//  main.cpp
//  error handling-2
//
//  Created by Adi Bangun on 14/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int t=0;
    try{
        throw t;
    }catch(...){
    }
    return 0;
}
