//
//  main.cpp
//  stamp duty
//
//  Created by Adi Bangun on 15/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
class Stamp{
private:
    double housePrice;
    double stampResult;
public:
    Stamp():stampResult(0.0){}
    double calculateStamp();
    void setHousePrice(double housePrice);
    double utilCalculateStamp();
};

void Stamp::setHousePrice(double housePrice){
    this->housePrice = housePrice;
}
double Stamp::calculateStamp(){
    if(housePrice <= 125000)
        return stampResult;
    return utilCalculateStamp();
}
double Stamp::utilCalculateStamp(){
    int lower[] = {125000,675000,575000,575001};
    double rate[] = {0.02,0.05,0.1,0.12};
    double tempPrice = housePrice - lower[0];
    double result = lower[0] * rate[0];
    for(int i=1;i<4;i++){
        if(tempPrice > 0 && tempPrice <=lower[i]){
            result+=lower[
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
