//
//  main.cpp
//  OOP1
//
//  Created by Adi Bangun on 05/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

class Employee{
private:
    string m_firstName;
    string m_lastName;
    int m_age;
    double m_salary;
public:
    void setFirstName(string firstName){
        m_firstName = firstName;
    }
    void setLastName(string lastName){
        m_lastName = lastName;
    }
    void setAge(int age){
        m_age = age;
    }
    void setSalary(double salary){
        m_salary = salary;
    }
    int getAge(){return m_age;}
    double getSalary(){return m_salary;}
    string getFirstName(){return m_firstName;}
    string getLastName(){return m_lastName;}
};

class Solution{
    int a; //by default all members of class are private members
    int b;
    int c;
};

int main(int argc,char *argv[]){
    Employee E;
    
    E.setFirstName("Adi Chris");
    E.setLastName("Bangun");
    E.setAge(23);
    E.setSalary(20.000);
    cout << E.getAge()<<endl;
    
    Solution solution;
    solution.a = 0;
    return 0;
}