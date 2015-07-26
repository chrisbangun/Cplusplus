//
//  main.cpp
//  linkedList
//
//  Created by Adi Bangun on 08/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *insert_data(node *head){
    int _data;
    cout << "insert the data: ";
    cin >> _data;
    cout << endl;
    node *temp = new node;
    temp->data = _data;
    if(head==NULL){
        head = temp;
    }else{
        node *tail = head;
        while(tail->next!=NULL)
            tail = tail->next;
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
    }
    return head;
}
node *delete_data(node *head){
    cout << "insert the data to delete: ";
    int _data;
    cin >> _data;
    cout << endl;
    if(head==NULL)
        cout << "no data in the list" << endl;
    else{
        if(head->data==_data){
            node *temp = head;
            if(temp->next!=NULL){
                head = temp->next;
            }
            delete temp;
            head = NULL;
        }else{
            node *tail = head;
            while(tail){
                if(tail->data==_data){
                        node *preceding = head;
                        while(preceding->next!=tail)
                            preceding = preceding->next;
                        preceding->next = tail->next;
                        delete tail;
                        tail = preceding->next;
                }else
                    tail = tail->next;
            }
        }
    }
    return head;
}

void print_list(node *head){
    if(head==NULL)
        cout << "No data in the list" << endl;
    else{
        node *tail = head;
        while(tail){
            cout << tail->data << endl;
            tail = tail->next;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    node *head = NULL;
    cout << "1. Insert Data" << endl;
    cout << "2. Delete Data" << endl;
    cout << "3. Print List" << endl;
    int choice;
    cin >> choice;
    while(choice!=0){
        switch(choice){
            case 1: head = insert_data(head);
                break;
            case 2: try{
                head=delete_data(head);
            }catch(exception e){
                cout << "List now is empty" << endl;
            }
                break;
            case 3: print_list(head);
                break;
        }
        cin >> choice;
    }
    return 0;
}
