//
//  main.cpp
//  Trie_C++
//
//  Created by Adi Bangun on 18/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Node{
private:
    bool mMarker; //markers are used to indicate end of words
    char mContent; // to save the content
    vector<Node*> mChildren; //the vector is the collection of the children
    
public:
    ~Node(){}
    char getContent(){
        return mContent;
    }
    void setContent(char c){
        mContent = c;
    }
    bool getMarker(){
        return mMarker;
    }
    void setMarker(){
        mMarker = true;
    }
    Node* findChild(char c);
    void appendChild(Node *child){
        mChildren.push_back(child);
    }
    vector<Node*> getChild(){
        return mChildren;
    }
    int getVectorSize(){
        return (int)mChildren.size();
    }
};

class Trie{
private:
    Node *root;
public:
    Trie();
    ~Trie();
    void addWord(string s);
    bool searchWord(string s);
    void deleteWord(string s);
    Node* getRoot(){return root;}
};

Node* Node::findChild(char c){
    for(int i=0; i<mChildren.size();i++){
        Node* temp = mChildren.at(i);
        cout << mChildren.size() <<" " <<temp->getContent() << endl;
        if(temp->getContent()==c){
            return temp;
        }
    }
    return NULL;
}

Trie::Trie(){
    root = new Node();
}
void Trie::addWord(string s){
    Node* current = root;
    if(s.length()==0){
        current->setMarker();
        return;
    }
    for(int i=0; i<s.length();i++){
        Node* child = current->findChild(s.at(i));
        if(child!=NULL)
            current = child;
        else{
            Node *temp=new Node();
            temp->setContent(s.at(i));
            current->appendChild(temp);
            current = temp;
        }
        if(i==s.length()-1)
            current->setMarker(); // marking the end of char on a word
    }
}

bool Trie::searchWord(string s){
    Node* current = root;
    while(current!=NULL){
        for(int i=0;i<s.length();i++){
            Node *tmp = current->findChild(s.at(i));
            if(tmp==NULL)
                return false;
            current = tmp;
        }
        if(current->getMarker())
            return true;
        else
            return false;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    Trie* trie= new Trie();
    trie->addWord("oath");
    trie->addWord("pea");
    //trie->addWord("eat");
    //trie->addWord("rain");
    
//    if(trie->searchWord("pea"))
//        cout << "found oath" << endl;
//    else cout << "not found :("<<endl;
    
    Node* node = trie->getRoot();
    cout << node->getVectorSize() << endl;
    return 0;
}
