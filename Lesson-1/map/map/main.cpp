//
//  main.cpp
//  map
//
//  Created by Adi Bangun on 07/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <map>
#include <string.h>
using namespace std;


void insertData(std::map<char,char*>&_map){
    map<char,char*>::iterator it;
    char id;
    char name[100];
    cout << "insert the id: "; cin >> id; cout<<endl;
    cout << "insert the name: "; cin >> name; cout << endl;
    if(_map.find(id)!=_map.end()){
        cout << "Name with id: "<<id<< "is already exist" << endl;
    }else{
        _map.insert(pair<char,char*>(id,name));
    }
}

void findData(map<char,char*>_map){
    char name[100];
    cout << "insert the name: "; cin >> name; cout << endl;
    map<char,char*>::iterator it;
    int check = 0;
    for(it=_map.begin();it!=_map.end();it++){
        if(strcmp(it->second, name)==0)
        {
            //cout << it->second << endl;
            cout << "found!! with id: " << it->first << endl;
            check++;
            break;
        }
    }
    if(check==0)
        cout << "data not found!" << endl;
}


void deleteData(std::map<char,char*>&_map){
    char c;
    cout << "insert the id that need to be deleted: "; cin >> c; cout << endl;
    if(_map.find(c)!=_map.end()){
        _map.erase(c);
    }else
        cout << "no such the data to be deleted" << endl;
}
void printData(map<char,char*>_map){
    map<char,char*>::iterator it;
    for(it=_map.begin();it!=_map.end();it++){
        cout << it->first << it->second << endl;
    }
}

int main(int argc, char *argv[]){
    map<char,char*> myMap;
    cout << "Simple Database" << endl;
    cout << "1. Insert Data" << endl;
    cout << "2. Find data" << endl;
    cout << "3 Delete Data" << endl;
    cout << "4. Print Data" << endl;
    int choice;
    cin >> choice;
    while(choice!=0){
    switch(choice){
        case 1: insertData(myMap);
            break;
        case 2: findData(myMap);
            break;
        case 3: deleteData(myMap);
            break;
        case 4: printData(myMap);
            break;
    }
        cin >> choice;
    }
    return 0;
}
