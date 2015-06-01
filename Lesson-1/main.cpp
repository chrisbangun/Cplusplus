//
//  main.cpp
//  Lesson-1
//
//  Created by Adi Bangun on 01/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int data;
    int count;
    struct node *left, *right;
};
struct node* newNode(int item){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->count = 1;
    temp->left = temp->right = NULL;
    return temp;
};

void inorder(struct node *root,int &max,int &key){
    if(root!=NULL){
        if(root->count > max){
            max = root->count;
            key = root->data;
        }
        inorder(root->left,max,key);
      //  cout << root->data << " ";
        inorder(root->right,max,key);
        
    }
}

struct node* insert(struct node* node, int key){
    if(node==NULL)
        return newNode(key);
    if(key== node->data){
        (node->count)++;
        return node;
    }
    if(key < node->data){
        node->left = insert(node->left, key);
    }else{
        cout << "here\n";
        node->right = insert(node->right,key);}
    
    return node;
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    struct node *root = NULL;
    int N;
    int arr[N+1];
    cin >> N;
    int max = 0;
    int key = 0;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    int mid = N/2;
    root = insert(root,arr[mid]);
    for(int i=0;i<mid;i++)
        root = insert(root,arr[i]);
    cout << root->data << "\n";
    for(int i=mid+1;i<N;i++){
        cout << arr[i] << "\n";
        root = insert(root,arr[i]);
    }
    inorder(root,max,key);
   // cout << key << "\n";
    return 0;
}
