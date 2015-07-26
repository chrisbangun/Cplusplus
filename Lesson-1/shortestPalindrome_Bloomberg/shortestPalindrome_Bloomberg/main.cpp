//
//  main.cpp
//  shortestPalindrome_Bloomberg
//
//  Created by Adi Bangun on 23/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
string shortestPalindrome(string input){
    if(input.length()<2)
        return input;
    int longest = 1;
    int l,r;
    for(int i=0;i<=input.length()/2;){
        l = r = i;
        while(r < input.length()-1 && input.at(r+1)==input.at(r))
            ++r;
        i = r + 1;
        while(r < input.length()-1 && l > 0 && input.at(r+1)==input.at(l-1)){
            --l;
            ++r;
        }
        if(l==0 && longest < r-l+1)
            longest = r-l+1;
    }
    string remaining = input.substr(longest,input.length()-longest);
    reverse(remaining.begin(),remaining.end());
    return remaining + input;
}

int main(int argc, const char * argv[]) {
    // find the largest palindrome prefix substring
    // if the length of s is len, and the length of the longest palindrome prefix substring is longest
    // the remaining substring will be s.substr(longest, len-longest), than we should reverse the remaining
    // substring and adding it in front of s
    string input;
    cin >> input;
    string palindrome = shortestPalindrome(input);
    cout << palindrome.length() << endl;
    return 0;
}
