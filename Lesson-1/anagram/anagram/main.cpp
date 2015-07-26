//
//  main.cpp
//  anagram
//
//  Created by Adi Bangun on 02/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;
class AreAnagrams
{
    public:
    static bool areStringsAnagrams(std::string a, std::string b)
    {
        if(a.length()!=b.length())
            return false;
        map<char,int> myMap;
        for(int i=0;i<a.length();i++){
            if(myMap.count(a.at(i))>0)
                myMap[a.at(i)]++;
            else
                myMap[a.at(i)]=1;
        }
        for(int i=0;i<b.length();i++){
            if(myMap.count(a.at(i))>0)
                myMap[a.at(i)]--;
            else
                return false;
        }
        map<char,int>::iterator it;
        for(it=myMap.begin();it!=myMap.end();++it){
            if(it->second > 0)
                return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a;
    std::cout << AreAnagrams::areStringsAnagrams("momdad", "dadmem");
    return 0;
}
