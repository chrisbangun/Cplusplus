//
//  main.cpp
//  hasStatic
//
//  Created by Adi Bangun on 20/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>

int hasStatic(int n){
    static int x = 0;
    x+=n;
    return x;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int sum = 0;
    for(int i=1;i<=4;i++){
        std::cout << hasStatic(i) << std::endl;
        sum+= hasStatic(i);
    }
    std::cout << sum << std::endl;
    return 0;
}
