//
//  main.cpp
//  firstCharAppearOnce
//
//  Created by Adi Bangun on 21/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <map>
using namespace std;
/*
 Implement a function to find the first character in a string that only appears once. For e.g. 
 the output is the character 'l' when the input is Bloomberg
 */

/*
 1. Does the input contain alphabets only? How about special characters or symbols?
 2.
 
 */

char firstNotRepeatingChar(char *pString){
    //cout << *pString+0  << endl;
    if(pString==NULL)
        return '\0';
    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for(unsigned int i=0;i<tableSize;i++)
        hashTable[i]=0;
    char *pHashKey = pString;
    //cout << *++pHashKey << endl;
    while(*(pHashKey)!='\0')
        hashTable[*(pHashKey++)]++;
    pHashKey = pString;
    while(*(pHashKey)!='\0'){
        if(hashTable[*pHashKey]==1)
            return *pHashKey;
        pHashKey++;
    }
    return '\0';
}

int findFirstUniqueInt(int *arr,int size){
    if(size==0)
        return INT_MIN;
    map<int,int> mapNumber;
    for(int i=0;i<size;i++){
        if(mapNumber.count(*(arr+i))==1)
            mapNumber[*(arr+i)]++;
        else
            mapNumber[*(arr+i)] = 1;
    }
    map<int,int>::iterator it;
    for(it=mapNumber.begin();it!=mapNumber.end();it++){
        if(it->second==1)
            return it->first;
    }
    return INT_MIN;
}
int main(int argc, const char * argv[]) {
    string input;
    cin >> input;
    char *pString = &input[0];
    char c = firstNotRepeatingChar(pString);
    //char c = findChar(input);
    if(c!='\0')
        cout << c << endl;
    else
        cout << "------" << endl;
    cout << "+++++++++++++++++++++++" << endl;
    
    int arr[]={1,2,3,4,3,2,1,5};
    int sizeArray = sizeof(arr)/sizeof(*arr);
    int ans = findFirstUniqueInt(arr,sizeArray);
    if(ans!=INT_MIN)
        cout << ans << endl;
    else
        cout << "There is no Unique element in the Array" << endl;
    return 0;
}
