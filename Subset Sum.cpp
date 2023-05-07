Question :  Subset Sum

Link 1 : https://practice.geeksforgeeks.org/problems/subset-sums2234/1
Link 2 : https://www.codingninjas.com/codestudio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0




// Since, total no. of subsets created for n elements will (2 power n), therefore
//  TC :  O(2 power n)             SC :  O(2 power n)


#include <bits/stdc++.h> 

void helper(vector<int> &num , int i, int n, int sum , vector<int> &ans){
    
    if(i==n){
        ans.push_back(sum);
        return;
    }
    helper(num,i+1,n,sum+num[i],ans);
    helper(num,i+1,n,sum+0,ans);
    return;
}

vector<int> subsetSum(vector<int> &num)
{
    int n = num.size();
    int i=0;
    int sum = 0;
    vector<int> ans;
    helper(num , i , n , sum , ans);
    sort(ans.begin() , ans.end());
    return ans;
}
