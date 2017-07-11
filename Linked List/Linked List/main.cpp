//
//  main.cpp
//  Linked List
//
//  Created by Adi Bangun on 23/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;

class Shape{
protected:
    double width;
    double height;
public:
    Shape():width(0),height(0){cout << "Base constructor is called" <<endl;}
    void setWidth(const double &_w);
    void setHeight(const double &_h);
    virtual double getArea()=0;
};
void Shape::setWidth(const double &_w){
    this->width = _w;
}

void Shape::setHeight(const double &_h){
    this->height = _h;
}
class Rectangle:public Shape{
public:
    Rectangle(){
        cout << "Rectangle constructor is called" << endl;
    }
    double getArea(){
        return width*height;
    }
};

class Triangle:public Shape{
public:
    Triangle(){
        cout << "Triangle constructor is called" << endl;
    }
    double getArea(){
        return (width*height)/2;
    }
};
int main(int argc, const char * argv[]) {
    Rectangle rect;
    Triangle triangle;
    Shape *s1 = &rect;
    s1->setWidth(5.0);
    s1->setHeight(4.0);
    
    cout << s1->getArea() << endl;
    return 0;
}
