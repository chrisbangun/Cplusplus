//
//  main.cpp
//  Trie
//
//  Created by Adi Bangun on 23/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node{
private:
    bool is_end; // acts like a flag to show the end of the word
    char mValue;
    int prefix_count; //number of words with the given prefix
    vector<Node*> child;

public:
    Node():prefix_count(0),is_end(false){} //default constructor
    ~Node();
    bool getIsEnd(){
        return is_end;
    }
    void setIsEnd(){
        is_end = true;
    }
    char getValue(){
        return mValue;
    }
    void setValue(char c){
        mValue = c;
    }
    int getPrefixCount(){
        return prefix_count;
    }
    void setPrefix(int n){prefix_count = n;}
    Node* findChild(char c);
    void appendChild(Node *_child){
        child.push_back(_child);
    }
    vector<Node*> getChild(){
        return child;
    }
    int getChildSize(){
        return (int)child.size();
    }
};

class Trie{
private:
    Node* root;
public:
    Trie();
    ~Trie();
    void insertWord(string word);
    bool searchWord(string word);
    int words_prefix(string prefix);
    bool searchWordWithSuffix(string suffix);
    Node* getRoot(){
        return root;
    }
};

Trie::Trie(){
    root = new Node();
}

Node* Node::findChild(char c){
    for(int i=0;i<getChildSize();i++){
        Node* temp = child.at(i);
        if(temp->getValue()==c)
            return temp;
    }
    return NULL;
}

void Trie::insertWord(string word){
    Node* current = root;
    if(word.length()==0){
        current->setIsEnd(); //set the marker to be true means it is the end of the word
        return;
    }
    int prefix = current->getPrefixCount();
    prefix++;
    current->setPrefix(prefix);
    for(int i=0;i<word.length();i++){
        //each time we want to add a new char, check whether it is already exist in the trie
        Node* temp = current->findChild(word.at(i));
        if(temp!=NULL){ //means the char is exist in the trie
            current = temp;
        }else{
            Node* newChild = new Node;
            newChild->setValue(word.at(i));
            current->appendChild(newChild);
            current = newChild;
        }
        prefix = current->getPrefixCount();
        prefix++;
        current->setPrefix(prefix);
        //we check if we are now at the end of the word
        if(i==word.length()-1)
            current->setIsEnd();
    }
}

bool Trie::searchWord(string word){
    Node* current = root;
    if(word.length()==0){
        current->setIsEnd();
        return false;
    }
    if(current!=NULL){
        for(int i=0;i<word.length();i++){
            Node* temp = current->findChild(word.at(i));
            if(temp==NULL)
                return false;
            current = temp;
        }
        if(current->getIsEnd())
            return true;
        return false;
    }
    return false;
}

bool Trie::searchWordWithSuffix(string suffix){
    if(suffix.length()==0)
        return false;
    Node* current = root;
    if(current!=NULL){
        for(int i=0;i<suffix.length();i++){
            Node* temp = current->findChild(suffix.at(i));
            if(temp==NULL)
                return false;
            current = temp;
        }
        if(current->getIsEnd())
            return true;
        return false;
    }
    return false;
}

int Trie::words_prefix(string prefix){
    if(prefix.length()==0)
        return -1;
    Node* current = root;
    if(current!=NULL){
        for(int i=0;i<prefix.length();i++){
            Node* temp = current->findChild(prefix.at(i));
            if(temp==NULL)
                return 0;
            current = temp;
        }
        return current->getPrefixCount();
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    
    Trie* trie = new Trie();
    trie->insertWord("Bloomberg");
    trie->insertWord("London");
    trie->insertWord("Bloomberg.L.P");
    if(trie->searchWord("Blomberg"))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    int ans = trie->words_prefix("Lon");
    cout << ans << endl;
    return 0;
}
