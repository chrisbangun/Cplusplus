//
//  main.cpp
//  strstr
//
//  Created by Adi Bangun on 06/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <string>
int main(){
    char haystack[100];
    char needle[100];
    fgets(haystack,sizeof(haystack),stdin);
    fgets(needle,sizeof(needle),stdin);
    int haySize = (int)strlen(haystack)-1;
    int needleSize = (int)strlen(needle)-1;
    if(needleSize > haySize)
        printf("-1");
    if(is
       return 0;
}