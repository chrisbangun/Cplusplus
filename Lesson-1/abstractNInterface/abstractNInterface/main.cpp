//
//  main.cpp
//  abstractNInterface
//
//  Created by Adi Bangun on 09/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
class Shape{
protected:
    int width;
    int height;
public:
    void setWidth(int _width){
        width = _width;
    }
    void setHeight(int _height){
        height = _height;
    }
    virtual int getArea()=0; // define a pure virtual function
    //virtual int getSquare()=0; // all the pure virtual function have to be implemented on the derived class

};

//The derived class
class Rectangle: public Shape{
public:
    int getArea(){
        return (width*height);
    }
};

class Triangle: public Shape{
public:
    int getArea(){
        return (width*height)/2;
    }

};
int main(int argc, const char * argv[]) {
    // Shape shape; // an abstrac class can be used to instantiate objects
                 // and serves only as an interface
    Rectangle rectangle;
    Triangle triangle;
    
    rectangle.setWidth(10);
    rectangle.setHeight(5);
    cout << "total area of the Reactangle: " << rectangle.getArea() << endl;
    
    triangle.setWidth(18);
    triangle.setHeight(10);
    cout << "total area of the Triangle: " << triangle.getArea() << endl;
    return 0;
}
