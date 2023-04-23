#include <bits/stdc++.h>

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here

    int n= a.size();
    long long sum = 0;
    int len = 0;
    unordered_map<long long, int> um; //for sum & index
    for(int i=0; i<n; i++){
        sum = sum + (long long)a[i];
        long long f = sum - k;
        if(sum == k){
            len = max(len , i+1);
        }
        if(um.find(f) != um.end()){
            len = max(len , i-um[f]);
        }
        if(um.find(sum) == um.end()){
            um[sum] = i;
        }
        
    }
    return len;
}



/*
// most optimal approach if array does not have any -ve number

#include <bits/stdc++.h>

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here

    int n= a.size();
    long long sum = a[0];
    int len = 0;
    int left = 0, right=0;

    //unordered_map<long long, int> um; //for sum & index
    
    while(right < n){
        
        while(left<=right  &&  sum>k){
            sum = sum-a[left];
            left++;
        }

        if(sum == k){
            len = max(len , right-left+1);
        }
        
        right++;
        if(right<n)  sum = sum+a[right];
    }

    return len;
}


*/
