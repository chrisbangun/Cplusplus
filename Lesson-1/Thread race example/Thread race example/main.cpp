//
//  main.cpp
//  Thread race example
//
//  Created by Adi Bangun on 20/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//
/*
    A race condition is a condition where the outcome of program depends on the relative execution order of one or more threads. One way to solve race condition is to use mutex to synchronize the access of the common resources
 
 */
#include <iostream>
#include <thread>
#include <mutex>
std::mutex _mutex;

void shared_print(std::string msg, int id){
    _mutex.lock(); //other thread won't able to access the resource
    std::cout << msg << id << std::endl; //how if this line of code throws exception? the mutex will lock forever :(
    _mutex.unlock();
}
void f_1(){
    for(int i=0; i>-100; --i){
        //std::cout << "From t1: " << i << std::endl; //thread t1 using the common resources (std::cout)
        shared_print(std::string("From t1: "),i);
    }
}


int main(int argc, const char * argv[]) {
    std::thread t1(f_1);
    for(int i=0; i<100; ++i){
        //std::cout << "from main: " << i << std::endl; //the main thread using the common resources (std::cout)
        shared_print(std::string("From main: "),i);
    }
    t1.join();
    return 0;
}
