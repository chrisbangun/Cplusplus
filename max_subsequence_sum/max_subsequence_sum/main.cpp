//
//  main.cpp
//  max_subsequence_sum
//
//  Created by Adi Bangun on 02/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#define max(a,b) ((a) > (b) ? (a):(b))
#define max3(a,b,c) (max((a),max((b),(c))))
using namespace std;

int max_subsequence_On2(int arr[],int n){
    int max_sum = 0;
    int sum;
    int best_i=-1;
    int best_j=-1;
    for(int i =0;i<n;i++){
        sum = 0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum > max_sum){
                max_sum = sum;
                best_i = i;
                best_j = j;
            }
        }
    }
    return max_sum;
}



int max_sub_sum(int a[],int l,int r){
    if(l==r){
        if(a[l] > 0)
            return a[l];
        return 0;
    }
    int mid = (l+r)/2;
    int max_left_sum = max_sub_sum(a,l,mid);
    int max_right_sum = max_sub_sum(a,mid+1,r);
    int max_left_border_sum = 0;
    int left_border_sum = 0;
    for(int i = mid ; i>=l ; i--){
        left_border_sum += a[i];
        if(left_border_sum > max_left_border_sum){
            max_left_border_sum = left_border_sum;
        }
    }
    int max_right_border_sum = 0;
    int right_border_sum = 0;
    for(int i=mid+1; i<=r ; i++){
        right_border_sum += a[i];
        if(right_border_sum > max_right_border_sum){
            max_right_border_sum = right_border_sum;
        }
    }
    return max3(max_left_sum, max_right_sum, max_left_border_sum + max_right_border_sum);
}

int max_subsequence_sum_On(int arr[],int n){
    return max_sub_sum(arr,0,n-1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    int arr[N+1];
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> arr[i];
    cout << max_subsequence_On2(arr,N) << "\n";
    cout << max_subsequence_sum_On(arr,N) << "\n";
    return 0;
}
