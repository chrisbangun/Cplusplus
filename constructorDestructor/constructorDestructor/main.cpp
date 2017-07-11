//
//  main.cpp
//  constructorDestructor
//
//  Created by Adi Bangun on 24/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
class Simple{
private:
    int m_ID;
public:
    Simple(int ID){
        cout << "Constructing Simple " << ID << endl;
        m_ID = ID;
    }
    ~Simple(){
        cout << "Destructing Simple " << m_ID << endl;
    }
    int getID2()const {return m_ID;}
    int getID(){
        return m_ID;
    }
};
int main(int argc, const char * argv[]) {
    Simple cSimple(1);
    cout << cSimple.getID() << endl;
    Simple *pSimple = new Simple(2);
    cout << pSimple->getID() << endl;
    delete pSimple;
    const Simple simpleConst(9);
    cout << simpleConst.getID2() << endl;
    return 0;
}
