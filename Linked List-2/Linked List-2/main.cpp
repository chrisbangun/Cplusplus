//
//  main.cpp
//  Linked List-2
//
//  Created by Adi Bangun on 26/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>

class Node{
private:
    int data;
    Node *next;
public:
    Node(){}
    Node(const int& _data):data(_data),next(NULL){}
    int getData(){return this->data;}
    Node *getNext(){return this->next;}
    void setNext(Node *_next){this->next = _next;}
};

class LinkedList{
private:
    Node *head;
public:
    LinkedList();
    ~LinkedList();
    Node *getHead(){return this->head;}
    void InsertElementFront(int n);
    void InsertElementLast(int n);
    bool searchElement(int n);
    void deleteElement(int n);
    void printList()const;
    void printReverse(Node *head_ref);
    void reverseLLRecursive();
    void reverseLLRecursiveUtil(Node *cur,Node *prev);
};

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    Node *current = head;
    while(current!=NULL){
        Node *next = current->getNext();
        delete current;
        current = next;
    }
    head = 0;
}

void LinkedList::InsertElementFront(int n){
    Node *newNode = new Node(n);
    if(head==NULL)
        head = newNode;
    else{
        newNode->setNext(head);
        head = newNode;
    }
}

void LinkedList::InsertElementLast(int n){
    Node *newNode = new Node(n);
    if(head==NULL){
        head = newNode;
        return;
    }
    Node *tail = head;
    while(tail->getNext()!=NULL)
        tail = tail->getNext();
    tail->setNext(newNode);
    tail = newNode;
}

bool LinkedList::searchElement(int n){
    if(head==NULL){
        //throw std::invalid_argument ("Linked list is empty");
        return false;
    }
    Node *current = head;
    while(current!=NULL){
        if(current->getData() == n)
            return true;
        current = current->getNext();
    }
    return false;
}

void LinkedList::deleteElement(int n){
    if(head==NULL){
        throw std::invalid_argument ("Linked list is empy");
        return;
    }
    //case 1, if n is head
    if(head->getData()==n){
        if(head->getNext()!=NULL){
            Node *temp = head;
            head = head->getNext();
            delete temp;
        }else
            head = 0;
    }else{
        Node *current =  head->getNext();
        Node *prev = head;
        while(current!=NULL){
            if(current->getData()==n){
                prev->setNext(current->getNext());
                delete current;
                current = prev->getNext();
            }else{
                prev = current;
                current = current->getNext();
            }
        }
    }
}
void LinkedList::printList()const{
    if(head==NULL){
        throw std::invalid_argument("The list is empty");
        return;
    }
    Node *current = head;
    std::cout << "Data: " ;
    while(current!=NULL){
        std::cout << current->getData() << " " ;
        current = current->getNext();
    }
    std::cout << std::endl;
}

void LinkedList::printReverse(Node *head_ref){
    if(head_ref==NULL)
        return;
    printReverse(head_ref->getNext());
    std::cout << head_ref->getData() << " ";
}

void LinkedList::reverseLLRecursive(){
    if(head==NULL)
        return;
    reverseLLRecursiveUtil(head,NULL);
}
void LinkedList::reverseLLRecursiveUtil(Node *current, Node *prev){
    if(current->getNext()==NULL){
        head = current;
        current->setNext(prev);
        return;
    }
    Node *next = current->getNext();
    current->setNext(prev);
    reverseLLRecursiveUtil(next,current);
}
int main(int argc, const char * argv[]) {
    LinkedList LL;
    LL.InsertElementFront(4);
    LL.InsertElementFront(5);
    LL.InsertElementLast(6);
    LL.InsertElementLast(7);
    LL.InsertElementLast(8);
    //LL.deleteElement(8);
    if (LL.searchElement(7))
        std::cout << "FOUND" << std::endl;
    else
        std::cout << "NOT FOUND" << std::endl;
    
    LL.printList();
    std::cout << "Reversed: ";
    LL.printReverse(LL.getHead());
    std::cout << std::endl;
    LL.reverseLLRecursive();
    
    LL.printList();
    std::cout << "Reversed: ";
    LL.printReverse(LL.getHead());
    return 0;
}
