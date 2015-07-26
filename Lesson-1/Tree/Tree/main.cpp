//
//  main.cpp
//  Tree
//
//  Created by Adi Bangun on 19/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node *left;
    Node *right;
    Node *parent;
public:
    Node();
    Node(int _data):data(_data),left(NULL),right(NULL),parent(NULL){}
    int getData(){return this->data;}
    Node *getLeft(){return this->left;}
    Node *getRight(){return this->right;}
    Node *getParent(){return this->parent;}
    void setLeft(Node *_left){this->left = _left;}
    void setRight(Node *_right){this->right = _right;}
    void setParent(Node *_parent){this->parent = _parent;}
    
};

class BSTree{
private:
    Node *root;
public:
    BSTree();
    ~BSTree();
    void insertElement(int n);
    void insertElementUtil(Node* node,int n);
    void traverse(Node *root);
    void deleteElement(int n);
    bool isBST(Node *root);
    void destructNode(Node *node);
    Node* searchTree(Node *node,int data);
};

BSTree::BSTree(){
    root = NULL;
}

BSTree::~BSTree(){
    destructNode(root);
    delete root;
}

void BSTree::destructNode(Node *node){

    if(node->getLeft()!=NULL)
        destructNode(node->getLeft());
    if(node->getRight()!=NULL)
        destructNode(node->getRight());
    delete node;
}

void BSTree::insertElement(int n){
    if(root==NULL){
        Node *newNode = new Node(n);
        root = newNode;
    }
    else
        insertElementUtil(root,n);
}

void BSTree::insertElementUtil(Node *node,int n){
    if(n < node->getData()){
        if(node->getLeft()==NULL){
            Node *newNode = new Node(n);
            newNode->setParent(node);
            node->setLeft(newNode);
        }else
            insertElementUtil(node->getLeft(),n);
    }else if( n > node->getData()){
        if(node->getRight()==NULL){
            Node *newNode = new Node(n);
            newNode->setParent(node);
            node->setRight(newNode);
        }
    }else
        throw invalid_argument("The given data already exist");
}

Node* BSTree::searchTree(Node *node,int data){
    if(node==NULL)
        return NULL;
    if(data == node->getData())
        return node;
    if(data < node->getData())
        return searchTree(node->getLeft(),data);
    if(data > node->getData())
        return searchTree(node->getRight(), data);
    return NULL;
}

bool BSTree::isBST(Node *root){
    static Node* prev = NULL;
    if(root){
        if(!isBST(root->getLeft()))
            return false;
        if(prev!=NULL && root->getData() <= prev->getData())
            return false;
        prev = root;
        return isBST(root->getRight());
    }
    return false;
}

void BSTree::deleteElement(int n){
    if(root==NULL)
        return;
    Node *thisKey = searchTree(root,n);
    // case 1
    if(thisKey->getLeft()==NULL && thisKey->getRight()==NULL){
        if(thisKey->getData() > thisKey->getParent()->getData())
            thisKey->setRight(NULL);
        else
            thisKey->setLeft(NULL);
        delete thisKey;
    }
    
    //case 2
    if(thisKey->getLeft()==NULL && thisKey->getRight()!=NULL){
        if(thisKey->getData() > thisKey->getParent()->getData())
            thisKey->getParent()->setRight(thisKey->getRight());
        else
            thisKey->getParent()->setLeft(thisKey->getRight());
        delete thisKey;
    }
    if(thisKey->getLeft()!=NULL && thisKey->getRight()==NULL){
        if(thisKey->getData() > thisKey->getParent()->getData())
            thisKey->getParent()->setRight(thisKey->getLeft());
        else
            thisKey->getParent()->setLeft(thisKey->getLeft());
    }
    
    //case 3
    if(thisKey->getLeft()!=NULL && thisKey->getRight()!=NULL){
        
    }
    
}



int main(int argc, char **argv){
    return 0;
}