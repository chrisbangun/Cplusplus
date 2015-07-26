//
//  main.cpp
//  OOP
//
//  Created by Adi Bangun on 21/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string.h>
class Circle{
private:
    double radius;
    std::string color;
public:
    //Circle():radius(0.0),color("reds"){} default constructor
    Circle(double radius=0.0, std::string color="red"){ //this constructors serves both default and non
        //default constructor
        this->radius = radius;
        this->color = color;
    }
    //copy constructor is a special constructor that initializes a new object from an existing object
    Circle(const Circle &circleSource):radius(circleSource.radius),color(circleSource.color){    }
    //the  parameter MUST be passed by reference to the copy constructor unless it will lead to
    //infinite recursion, stack overflow
    
    //asignment operator overload
    Circle& operator=(const Circle& circleSource);
    double getRadius(){return radius;}
    void setRadius(double mRadius){this->radius = mRadius;}
    std::string getColor(){return color;}
    void setColor(std::string mColor){this->color = mColor;}

};

Circle& Circle::operator=(const Circle& circleSource){
    if(this!=&circleSource){
        radius = circleSource.radius;
        color = circleSource.color;
    }
    return *this;
}
void cek(int *arr){
    int size = (int) sizeof(*arr);
    std::cout << size << std::endl;
}
void cek2(char *c){
    int size = (int)sizeof(c);
    std::cout << "string " << size << std::endl;
}
int main(int argc, char **argv){
    Circle circle(1.5);
    Circle circle2 = circle;
    std::cout << circle2.getColor() << std::endl;
    std::cout << circle.getRadius() << std::endl;
    int arr[]={1,2,3,4,5};
    cek(arr);
    int size = (int) sizeof(arr)/sizeof(*arr);
    std::cout << size << std::endl;
    std::string s = "asd";
    char c[] = {'a','b','c'};
    cek2(c);
    return 0;
}
