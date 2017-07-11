//
//  main.cpp
//  primeNumber
//
//  Created by Adi Bangun on 25/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
typedef long long ll;
void sieve(ll upperBound,bitset<100007>&_bitset,vector<int>& primes){
    ll sieveSize = upperBound + 1;
    _bitset.reset();
    _bitset.flip(); //set all numbers to 1
    _bitset.set(0,false);
    _bitset.set(1,false);
    for(ll i=2;i<=sieveSize;i++){
        if(_bitset.test((size_t)i)){
            for(ll j=i*i;j<=sieveSize;j+=i)
                _bitset.set((size_t)j,false);
            primes.push_back((int)i);
        }
        
    }
}
bool isPrimeUtil(ll N,bitset<100007>&_bitset,vector<int>&primes){
    if(N < (int)_bitset.size())
        return _bitset.test(N);
    for(ll i=0; i<primes.size();i++)
        if(N%primes[i]==0)
            return false;
    return true;
}
bool isPrime(ll N){
    bitset<100007>_bitset;
    vector<int>primes;
    sieve(100000,_bitset, primes);
    return isPrimeUtil(N,_bitset,primes);
}
int main(int argc, const char * argv[]) {
    if(isPrime(100007))
        cout << "Prime" << endl;
    else
        cout << "Not Prime" << endl;
    return 0;
}
