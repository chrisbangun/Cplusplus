//
//  main.cpp
//  In Place conversion DLL to a balanced BST
//
//  Created by Adi Bangun on 25/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
class Node{
private:
    int data;
    Node *prev;
    Node *next;
public:
    Node():data(0),prev(NULL),next(NULL){}
    Node(int _data):data(_data),prev(NULL),next(NULL){}
    int getData(){return this->data;}
    Node *getPrev(){return this->prev;}
    Node *getNext(){return this->next;}
    void setPrev(Node *_prev){
        this->prev = _prev;
    }
    void setNext(Node *_next){
        this->next = _next;
    }
};

class DLL{
private:
    Node *root;
public:
    DLL():root(NULL){}
    ~DLL();
    Node *getRoot(){return this->root;}
    void add(Node **root,int _data);
    int countNodes(Node *root);
    Node *sortedListToBST(Node *root);
    Node *sortedListToBSTUtil(Node **root_ref,int n);
    void printList(Node *root) const;

};
DLL::~DLL(){
    Node * temp;
    while(root!=NULL){
        temp = root->getNext();
        delete root;
        root = temp;
    }
}
Node* DLL::sortedListToBST(Node *root){
    int n = countNodes(root);
    return DLL::sortedListToBSTUtil(&root, n);
}

Node* DLL::sortedListToBSTUtil(Node **root_ref, int n){
    if(n <=0) //base case
        return NULL;
    Node *left = sortedListToBSTUtil(root_ref,n/2);
    Node *root = *root_ref;
    root->setPrev(left);
    *root_ref = (*root_ref)->getNext();
    root->setNext(sortedListToBSTUtil(root_ref, n-n/2-1));
    return root;
}
void DLL::add(Node **root,int _data){
    Node *new_node = new Node(_data);
    new_node->setNext(*root);
    if((*root)!=NULL){
        (*root)->setPrev(new_node);
    }
    *root = new_node;
}

int DLL::countNodes(Node *root){
    if(root==0)
        return 0;
    Node *temp = root;
    int count = 1;
    while(temp->getNext()!=NULL)
        count++;
    return count;
}

void DLL::printList(Node *root)const{
    if(root==NULL){
        throw invalid_argument("The list is empty");
        return;
    }
    Node *temp = root;
    while(temp){
        cout << temp->getData() << endl;
        temp=temp->getNext();
    }
}
int main(int argc, const char * argv[]) {
    DLL dll = DLL();
    Node *head = dll.getRoot();
    dll.add(&head, 7);
    dll.add(&head, 6);
    dll.add(&head, 5);
    dll.add(&head, 4);
    dll.add(&head, 3);
    dll.add(&head, 2);
    dll.add(&head, 1);
    dll.printList(head);
    return 0;
}
