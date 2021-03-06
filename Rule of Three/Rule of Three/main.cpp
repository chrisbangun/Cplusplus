//
//  main.cpp
//  Rule of Three
//
//  Created by Adi Bangun on 23/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include "GCharacter.h"
using namespace std;
int main(int argc, const char * argv[]) {
    GCharacter gc1;
    gc1.insert("Poison");
    gc1.insert("Crossbow");
    gc1.insert("Candle");
    gc1.insert("Cloak");
    gc1.insert("Sword");
    gc1.insert("Axe");
    
    cout << gc1 << endl;
    
    GCharacter gc2("Chris",5);
    gc2.insert("Axe");
    gc2 = gc1;
    cout << gc2 << endl;
    
    GCharacter gc3 = gc2;
    cout << gc3 << endl;
    return 0;
}
