//
//  main.cpp
//  buyAndSellStock
//
//  Created by Adi Bangun on 23/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

int maxProfit(vector<int>nums){
    int size = (int)nums.size();
    int maxProf = 0;
    int currentBuy = INT_MAX;
    int currentSell = INT_MIN;
    for(int i=0;i<size;i++){
        currentBuy = MIN(currentBuy,nums[i]);
        currentSell = MAX(currentSell,nums[i]-currentBuy);
        cout << "cb: " << currentBuy << " cs: " << currentSell <<endl;
        maxProf = currentSell;
    }
    return maxProf;
}

int main(int argc, const char * argv[]) {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(4);
    nums.push_back(6);
    int ans = maxProfit(nums);
    cout << ans << endl;
    return 0;
}
