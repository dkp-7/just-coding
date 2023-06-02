// Question :  Allocate Books
// Question link (Coding Ninja) : https://www.codingninjas.com/codestudio/problems/ayush-gives-ninjatest_1097574?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isPossible1(vector<int> times, int m, int maxDays, int limit){
     
    int day = 1;
    int sum = 0;
    for(int i=0; i<m; i++){
        if(times[i] > limit) return false;
         
        if((sum + times[i]) <= limit){
            sum += times[i];
        }
        else{
            sum=times[i];
            day++;
        }
    }
    if(day > maxDays) return false;
    return true;
}


int ayushGivesNinjatest(int n, int m, vector<int> times){
    
    int low = INT_MAX;
    int high = 0;
    
    for(int i=0; i<m; i++){
        high += times[i];
        low = min(low , times[i]);
    }
	
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;       
        if(isPossible1(times, m, n, mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}


int main()
{
    int n = 4;
    vector<int> times = {2, 2, 3, 3, 4, 4, 1};
    int m  = 7;
    int ans = ayushGivesNinjatest(n, m, times);
    cout<<ans;

    return 0;
}
