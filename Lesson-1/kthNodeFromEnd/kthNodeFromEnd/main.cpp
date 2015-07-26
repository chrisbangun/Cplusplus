//
//  main.cpp
//  kthNodeFromEnd
//
//  Created by Adi Bangun on 20/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node* addNode(Node *head,int _data){
    Node *temp = new Node;
    temp->data = _data;
    if(head==NULL){
        head = temp;
        temp->next = NULL;
    }
    else{
        Node *tail = head;
        while(tail->next!=NULL)
            tail = tail->next;
        
        tail->next = temp;
        tail = temp;
    }
    return head;
}

void printNode(Node *head){
    if(head==NULL)
        return;
    Node *tail = head;
    while(tail){
        cout << tail->data << endl;
        tail = tail->next;
    }
}

Node *findKthfromTail(Node *head, unsigned int _k){
    if(head==NULL || _k==0) //base-case
        return NULL;
    Node *pAhead = head;
    Node *pBehind = NULL;
    for(int i=0;i<_k-1;++i){
        if(pAhead->next!=NULL){ //make sure that k is not more than the size of list
            pAhead = pAhead ->next;
        }else
            return NULL;
    }
    pBehind = head;
    while(pAhead->next!=NULL){
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }
    return pBehind;
}
Node *deleteKthfromTail(Node *head,unsigned int _k){
    if(head==NULL || _k==0)
        return NULL;
    Node *pAhead = head;
    for(int i=0;i<_k-1;i++){
        if(pAhead->next!=NULL)
            pAhead = pAhead->next;
        else
            return NULL;
    }
    
    Node *pBehind = head;
    Node *priorNode = pBehind;
    while(pAhead->next!=NULL){
        pAhead = pAhead->next;
        if(priorNode!=pBehind)
            priorNode = priorNode->next;
        pBehind = pBehind->next;
    }
    if(pBehind==head){ //check if there is only one element in the list
        if(pBehind->next==NULL){
            head = NULL;
            delete pBehind;
        }else{
            head = pBehind->next;
            delete pBehind;
        }
        
    }else{
        priorNode->next = pBehind->next;
        delete pBehind;
    }
    return head;
}

Node *reverseList(Node *head){
    if(head==NULL)
        return NULL;
    Node *pNewHead=NULL;
    Node *pNode = head;
    Node *prev,*next;
    prev = NULL;
    next = NULL;
    while(pNode!=NULL){
        next = pNode->next;
        if(next==NULL)
            pNewHead = pNode;
        pNode->next = prev;
        prev = pNode;
        pNode = next;
    }
    return pNewHead;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Node *head = NULL;
    head=addNode(head,1);
    head=addNode(head,2);
    head=addNode(head,3);
    head=addNode(head,4);
    head=addNode(head,5);
    unsigned int k;
    cout << "input k:"; cin >> k;
    Node *ans = findKthfromTail(head,k);
    if(ans==NULL)
        cout<<"Not found or it does not exist"<<endl;
    else cout << ans->data << endl;
    int kD;
    cout << "input k to delete:"; cin >> kD;
    head = deleteKthfromTail(head,kD);
    printNode(head);
    cout << "=============================" << endl;
    head = reverseList(head);
    printNode(head);
    return 0;
}
