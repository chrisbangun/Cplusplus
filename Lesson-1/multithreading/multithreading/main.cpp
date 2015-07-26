#include <iostream>
using namespace std;

class Singleton{
private:
    Singleton(){};
    static bool instanceFlag;
    static Singleton* single;
public:
    static Singleton* getInstance();
    void method();
    ~Singleton(){
        instanceFlag = false;
    }
};

bool Singleton::instanceFlag = false;
Singleton* Singleton::single = NULL;
Singleton* Singleton::getInstance(){
    if(!instanceFlag){
        single = new Singleton();
        instanceFlag = true;
        return single;
    }
    return single;
}

void Singleton::method(){
    cout << "this is the Singleton method" << endl;
}

int main(int argc, char **args){
    Singleton *sc1,*sc2;
    sc1 = Singleton::getInstance();
    sc1->method();
    sc2 = Singleton::getInstance();
    sc2->method();


    return 0;
}