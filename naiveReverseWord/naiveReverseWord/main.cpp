//
//  main.cpp
//  naiveReverseWord
//
//  Created by Adi Bangun on 18/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

//reverse using string.reverse() and two iterators
void reverseWord(string &s){
    reverse(s.begin(),s.end());
    string::iterator i=s.begin(),j=s.begin();
    while(i!=s.end()){
        while(i!=s.end()&&(*i)==' ')
            i++;
        j = i;
        while(i!=s.end()&&(*i)!=' ')
            i++;
        reverse(j,i);
    }
    //cout << s << endl;
}


void reverseUsingStack(string &s){
    stack<string> myStack;
    string substring = " ";
    for(int i=0;i<s.length();i++){
        if(s.at(i)==' '){
            myStack.push(substring);
            substring.clear();
            continue;
        }else if(s.at(i)=='\0'){
            myStack.push(substring);
            substring.clear();
            break;
        }
        substring+=s.at(i);
    }
    if(substring!=" ")
        myStack.push(substring);
    
    while(!myStack.empty()){
        substring = myStack.top();
        myStack.pop();
        cout << substring << "";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s;
    getline(cin,s);
    reverseUsingStack(s);
    //reverseWord(s);
    //cout << s << endl;
    
    cout << endl;
    return 0;
}
