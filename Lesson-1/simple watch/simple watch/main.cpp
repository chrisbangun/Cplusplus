//
//  main.cpp
//  simple watch
//
//  Created by Adi Bangun on 21/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>

class Watch{
private:
    int hour;
    int minute;
    int second;
public:
    Watch():hour(0),minute(0),second(0){}
    int getHour(){return this->hour;}
    int getMinute(){return this->minute;}
    int getSecond(){return this->second;}
    void setHour(int _h){this->hour = _h;}
    void setMinute(int _m){this->minute = _m;}
    void setSecond(int _s){this->second = _s;}
    void convert_from_second(int _second);
};

void Watch::convert_from_second(int _second){
    int _h;
    int _m;
    if(_second >=3600){
        _h = _second/3600;
        setHour(_h);
        _second = _second - (_h*3600);
    }if(_second >=60){
        _m = _second/60;
        setMinute(_m);
        _second = _second - (_m*60);
    }
    setSecond(_second);
        
}

int main(int argc, const char * argv[]) {
    Watch watch = Watch();
    int second;
    do{
        if(!(std::cin >> second) || second < 0){
            std::cout << "You've entered an invalid value.Exiting.." << std::endl;
            break;
        }
        watch.convert_from_second(second);
        std::cout << "Hours: "<<watch.getHour() << std::endl;
        std::cout << "Minutes: "<<watch.getMinute() << std::endl;
        std::cout << "Seconds: "<<watch.getSecond() << std::endl;
    }while(second>=0);
    return 0;
}
