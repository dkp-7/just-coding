//Optimised code


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n = arr.size();
    unordered_map<int,int> um;
    int cnt = 0;
    int xr=0;
    
    for(int i=0; i<n; i++){
        
        xr = xr^arr[i];
        
        if(xr == x){
            cnt++;
        }
        int y = xr^x;
        if(um.find(y) != um.end()){
            cnt = cnt + um[y];
        }
        um[xr]++;
    }
    return cnt;
}


int main()
{
    //cout<<"Hello World";
    vector<int> arr{ 5, 6, 7, 8, 9};

    int totalCount= subarraysXor(arr,5);
    cout<<"The total number of subarrays having a given XOR k is "<<totalCount<<endl;

    return 0;
}



/*

#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int cnt = 0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int k = 0;
        for(int j=i; j<n; j++){
            k = k^arr[j];
            if(k == x){
                cnt++;
            }
        }
    }
    return cnt;
    
}

*/
