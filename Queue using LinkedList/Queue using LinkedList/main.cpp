//
//  main.cpp
//  Queue using LinkedList
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
    int getData(){return this->data;}
    Node* getNext(){return this->next;}
    void setNext(Node *_next){
        this->next = _next;
    }
        
};

class Queue{
private:
    Node *front;
    Node *rear;
public:
    Queue():front(NULL),rear(NULL){}
    void enqueue(int data);
    void dequeue();
    void print();

};

void Queue::enqueue(int data){
    Node *temp = new Node(data);
    if(front==NULL){
        front = temp;
        rear = temp;
    }else{
        rear->setNext(temp);
        rear = rear->getNext();
    }
}

void Queue::dequeue(){
    if(front==NULL && rear==NULL)
        throw invalid_argument("The Queue is empty");
    if(front!=rear){
        Node *temp = front;
        if(front->getNext()!=NULL)
            front = front->getNext();
        delete temp;
    }else{
        front = NULL;
        rear = NULL;
    }
}

void Queue::print(){
    if(front==NULL && rear==NULL)
        throw invalid_argument ("No data to be printed");
    Node *temp = front;
    while(temp!=rear){
        cout << temp->getData()<<" ";
        temp = temp->getNext();
    }
    cout << rear->getData() << endl;
}


int main(int argc, const char * argv[]) {
    Queue queue;
    try
    {
        queue.enqueue(1);
        queue.enqueue(2);
        queue.print();
//        queue.dequeue();
//        queue.dequeue();
//        queue.dequeue();
//        queue.print();
    }catch(const invalid_argument& e){
        cout << e.what() << endl;
    }
    return 0;
}
