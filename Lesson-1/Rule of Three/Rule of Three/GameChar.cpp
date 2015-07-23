//
//  GameChar.cpp
//  Rule of Three
//
//  Created by Adi Bangun on 23/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//
#include "GCharacter.h"
using namespace std;

//start writing the definition from GCharacter.h

//constructor
GCharacter::GCharacter(string n, int cap){
    name = n;
    capacity = cap;
    used = 0;
    toolHolder = new string[cap];
}

//copy constructor
GCharacter::GCharacter(const GCharacter& source){
    // simply cout to show whether this is invoked
    cout << "Copy constuctor called" << endl;
    this->name = source.name;
    this->capacity = source.capacity;
    this->used = source.used;
    this->toolHolder = new string[source.capacity];
    
    copy(source.toolHolder,source.toolHolder + used, toolHolder);
    
//    for(int i=0;i<this->used;++i)
//        this->toolHolder[i] = source.toolHolder[i];
}

//Overloaded Assignment Operator
//This will be invoked for the existing objects
GCharacter& GCharacter::operator=(const GCharacter& source){
    cout << "Overloaded Assignment Operator is called" << endl;
    //check for self assignment [FIRTS THING TO DO]
    // GC1 = GC1
    if(this==&source)
        return *this; //we have to run the object not the pointer it self (need dereferencing)
    this->name = source.name;
    this->capacity = source.capacity;
    this->used = source.used;
    copy(source.toolHolder,source.toolHolder + used, toolHolder);
    return *this;
}


//Destructor
GCharacter::~GCharacter(){
    cout <<"Destructor called for " << this->name << "@ this memory location: " << this << endl;
    delete[] toolHolder;
}


//Inserting a new tool to the tool holder
void GCharacter::insert(const string& toolName){
    if(this->used==this->capacity)
        cout << "Tool holder is full, cannot add any additional tools" << endl;
    else{
        this->toolHolder[used] = toolName;
        this->used++;
    }
}

std::ostream& operator<< (std::ostream& os, const GCharacter& gc){
    os << "Game Character " << gc.name << "\nhas the following tools: " <<std::endl <<"| ";
    for(int i=0;i<gc.used;i++)
        os << gc.toolHolder[i]+" | ";
    return os << std::endl;
}