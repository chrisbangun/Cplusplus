//
//  main.cpp
//  BJSS1
//
//  Created by ; Bangun on 02/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class A{
public:
    virtual int foo() = 0;
//    int weight;
//    void print(){
//        cout << "Base non-virtual print" << endl;
//    }
//    virtual void vPrint(){
//        cout << "Base virtual print" << endl;
//    }
};

class B{
public:
    virtual int foo(){return 1;};
    
//    void print(){
//        cout << "Derived non-virtual print" << endl;
//    }
//    
//    virtual void vPrint(){
//        cout << "Derived virtual print" << endl;
//    }
};
class C{
public:
    int foo(){return -10;}
};

class Child: public B{
public:
    int foo(){return -1;}

};

void f(int *p, int *q){
    p = q;
    *p = 2;
    
}

void test(int arr[]){
    int size= (int)sizeof(arr)/sizeof(arr[0]);
    cout << size << endl;
    cout << sizeof(arr) << " and " << sizeof(arr[0]) << endl;
    cout << *arr << endl;
}
int i=0;
int j=1;
int main(){
    Child child;
    cout << child.foo() << endl;
    
    int arr[] = {10,20,30,40,50,60};
    int *ptr1 = arr;
    ++*ptr1;
    int *ptr2 = arr+5;
    cout << "--> "<<*ptr1 << endl;
    cout << "--> "<<(char*)ptr2  - (char*)ptr1 << endl;

    f(&i,&j);
    cout << i <<" "<< j << endl;
    test(arr);
    int size= (int)sizeof(arr)/sizeof(arr[0]);
    cout << "Size here: " << sizeof(arr[0]) << endl;
    //x = (char *)a;
    ///cout <<"here " << x << endl;
//    Tiger tiger;
//    Animal animal;
//    animal.print();
//    animal.vPrint();
//    tiger.print();
//    tiger.vPrint();
//    Animal *a = &animal;
//    a->print();
//    a->vPrint();
//    a = &tiger;
//    a->print();
//    a->vPrint();
    return 0;
}
/*int solution(vector<int> &A) {
    // write your code in C++11
    vector<int>_A;
    int newi = A[0];
    while(find(_A.begin(),_A.end(),A[newi])==_A.end()){
        _A.push_back(A[newi]);
        newi = A[newi];
    }
    for(int i=0;i<_A.size();i++){
        if(_A[i]==A[newi])
            return (int)_A.size()-i;
    }
    return 0;
}
int globalA = 2;
int globalB = 1;
void fun(int x, int y){
    globalB = x + y;
    x =globalA + y;
    y = globalB + x ;
}
int main(int argc, const char * argv[]) {
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
   
    cout<<solution(a) << endl;
    fun(globalB,globalB);
    cout << globalA << " " << globalB << endl;
    return 0;
}
*/