//
//  main.cpp
//  ValidPalindrome
//
//  Created by Adi Bangun on 06/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool checkAlphabets(char c){
    if(!isspace(c) && ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))){
        printf("%c\n",c);
        return true;}
    return false;
}

int main(int argc, char *argv[]){
    char _string[1001];
    if(fgets(_string,sizeof(_string),stdin)){
        int y = (int)strlen(_string)-1;
        int l = 0;
        int r = y-1;
       
        bool valid = false;
        while(l<r){
            while(l<r && !checkAlphabets(_string[l]))l++;
            while(l<r && !checkAlphabets(_string[r]))r--;
            printf("%d %d\n",l,r);
            if(tolower(_string[l])!=tolower(_string[r])){
                valid = false;
                break;
            }
            valid = true;
            l++;
            r--;
        }
        if (valid)
            printf("Valid\n");
        else printf("Invalid");
    }
    return 0;
}
