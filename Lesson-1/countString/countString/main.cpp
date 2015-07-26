#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct Alphabets{
    char c;
    int counter;
};

bool compare(Alphabets a, Alphabets b){
    return a.counter > b.counter;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    
    int n;
    int k;
    scanf("%d",&T);
    char c;
   // char sentence[50001];
    while(T--){
        struct Alphabets alphabets[26];
        for(int i=0;i<26;i++){
            alphabets[i].counter = 0;
        }
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++){
            cin >> c;
            int index = c-'0';
            alphabets[index-49].c = c;
            alphabets[index-49].counter++;
            
        }
        sort(alphabets, alphabets+26,compare);
        bool flag = false;
        for(int i=0;i<26;i++){
            if(alphabets[i].counter > k){
                flag = true;
                printf("%c",alphabets[i].c);
            }
        }
        printf("\n");
        if(!flag)
            printf("NONE\n");
        
    }
    return 0;
}


