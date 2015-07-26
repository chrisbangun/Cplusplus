//
//  main.cpp
//  MaxDepth
//
//  Created by Adi Bangun on 17/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
struct node{
    node *left;
    node *right;
    int data;
};


int maxDepth(node head){
    return 0;
}
void insertNode(node **head,int _data){
    if(*head==NULL){
        (*head)->data = _data;
        (*head)->left = NULL;
        (*head)->right = NULL;
    }
}
int main(int argc,char **argv){
    node *head = NULL;
    int input;
    cin >> input;
    while(input!=0){
        insertNode(&head,input);
        
        cin >> input;
    }
    head->left = NULL;
    return 0;
}

