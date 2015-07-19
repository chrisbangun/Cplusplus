//
//  main.cpp
//  Stack using Linked List
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
    Node():next(NULL){}
    Node(int _data):data(_data),next(NULL){}
    int getData(){
        return this->data;
    }
    void setNext(Node *_next){
        this->next = _next;
    }
    Node *getNext(){
        return this->next;
    }
};

class Stack{
private:
    Node* top;
public:
    Stack(){}
    ~Stack();
    int getTop();
    void Push(int data);
    void Pop();
    bool isEmpty() const;
    void Print()const;
};

Stack::~Stack(){
    Node* current = top;
    while(current!=NULL){
        Node *next = current->getNext();
        delete current;
        current = next;
    }
    top = NULL;
}
bool Stack::isEmpty()const{
    return (top==NULL) ? true:false;
}

int Stack::getTop(){
    if(top==NULL)
        throw invalid_argument("NULL");
    return top->getData();
}

void Stack::Push(int data){
    Node *temp = new Node(data);
    if(isEmpty())
        top = temp;
    else{
        temp->setNext(top);
        top = temp;
    }
    //delete temp;
}
void Stack::Pop(){
    if(isEmpty())
        throw invalid_argument("The Stack is empty");
    Node *temp = top;
    if(top->getNext()!=NULL)
        top = top->getNext();
    else
        top = NULL;
    delete temp;
}
void Stack::Print()const{
    if(isEmpty())
        throw invalid_argument("The Stack is empty");
    Node *temp = top;
    while(temp!= NULL){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}
int main(int argc, const char * argv[]) {
    Stack stack;
    try{
        stack.Push(3);
        //cout << stack.getTop() << endl;
        stack.Push(2);
        stack.Push(1);
        cout << stack.getTop() << endl;
        stack.Print();
        stack.Pop();
        stack.Pop();
        stack.Pop();
        //cout << stack.getTop() << endl;
        stack.Print();
    
    }catch(const invalid_argument& e){
        cout << e.what() << endl;
    }
    return 0;
}
