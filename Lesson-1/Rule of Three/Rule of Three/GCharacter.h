//
//  GCharacter.h
//  Rule of Three
//
//  Created by Adi Bangun on 23/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#ifndef Rule_of_Three_GCharacter_h
#define Rule_of_Three_GCharacter_h

#include <iostream>
#include <string.h>
class GCharacter{
    friend std::ostream& operator<<(std::ostream& os, const GCharacter& gc);
public:
    static const int Default_Capacity = 5;
    //Constructor
    GCharacter(std::string name="Adi",int capacity=Default_Capacity);
    
    //Copy constructor
    GCharacter(const GCharacter& source);
    
    //Overloaded Assignment operator
    GCharacter& operator=(const GCharacter& source);
    
    //Destructor
    ~GCharacter();
    
    //insert a new to into the tool holder
    void insert(const std::string& toolName);
private:
    std::string name;
    int capacity;
    int used;
    std::string* toolHolder;
};
#endif
