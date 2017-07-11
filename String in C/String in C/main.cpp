//
//  main.cpp
//  String in C
//
//  Created by Adi Bangun on 19/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node* next;
public:
    Node():next(NULL){cout << "test" << endl;}
    Node(int value):data(value),next(NULL){}
    void setData(int _data){
        this->data = _data;
    }
    void setNext(Node *_next){
        this->next = _next;
    }
    int getData(){
        return this->data;
    }
    Node *getNext(){
        return this->next;
    }

};

class LinkedList{
private:
    Node *head;
public:
    LinkedList():head(NULL){}
    void Print();
    void Append(int data);
    void Delete(int data);

};

void LinkedList::Print(){
    if(head==NULL){
        throw invalid_argument("No data in the list");}
    Node* temp = head;
    do{
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    while(temp!=NULL);
    cout << endl;
}

void LinkedList::Append(int data){
    Node *temp = new Node(data);
    Node *tail = head;
    if(tail!=NULL){
        while(tail->getNext()!=NULL)
            tail = tail->getNext();
        tail->setNext(temp);
    }else
        head = temp;
}

void LinkedList::Delete(int data){
    int isDataExist = 0;
    if(head==NULL)
        throw invalid_argument("No data in the List");
    if(head->getData()==data){
        Node *temp = head;
        delete temp;
        if(head->getNext()!=NULL)
            head = head->getNext();
        else{
            head = NULL;
        }
        isDataExist = 1;
    }else{
        Node *preceding = head;
        Node *current = head->getNext();
        while(current!=NULL){
            if(current->getData()== data){
                preceding->setNext(current->getNext());
                current = current->getNext();
                isDataExist = 1;
            }else{
                preceding = current;
                current = current->getNext();
            }
        }
    }
    
    if(isDataExist==0)
        cout << "The given data doesn't exist" << endl;
    else
        cout << data << " is deleted" << endl;
}
int main(int argc, const char * argv[]) {
    LinkedList list;
    try
    {
        list.Append(100);
        list.Print();
        list.Append(200);
        list.Print();
        list.Append(300);
        list.Print();
        list.Append(400);
        list.Print();
        
        //delete nodes from the list
        list.Delete(400);
        list.Print();
        list.Delete(100);
        list.Print();
        list.Delete(300);
        list.Print();
        list.Delete(500);
        list.Print();
    }catch(const invalid_argument& e){
        e.what();
    }
    return 0;
}
