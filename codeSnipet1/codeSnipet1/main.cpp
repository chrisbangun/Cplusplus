//
//  main.cpp
//  codeSnipet1
//
//  Created by Adi Bangun on 19/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
void extend( char *p ) {
    char *tmp = (char *)malloc( 20*sizeof(char) );
    int a = 41;
    a = a++;
    printf("%d\n",a);
    if( tmp ){
        printf("here\n");
        free(p);
        p = tmp;
    }
}

int main() {
    int i;
    
    char *p = (char *)malloc( 10*sizeof(char) );
    if( p ){
        extend( p );
    }
    
    for( i=0; i<20; i++ ){
        p[i] = 'q';
     //   printf("%c %d\n",p[i],i);
    }
    printf("%c\n",p[19]);
    return 0;
}
