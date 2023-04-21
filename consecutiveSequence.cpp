// Leetcode :      128. Longest Consecutive Sequence


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0) return 0;
        
        sort(nums.begin() , nums.end());
        int c=1;
        int maxi = 0;
        
        for(int i=0; i<n-1; i++){
            
            if(nums[i] == nums[i+1]-1){
                c++;
            }
            else if(nums[i] == nums[i+1]){
                c=c;
            }
            else{
                maxi = max(maxi , c);
                c=1; 
            }
        }
        maxi = max(maxi , c);
        return maxi;
    }
};


/*

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


    void helper(vector<int> &nums, int k, int i, int n, int &c , int &maxi){
        
        if( i > n){
            return;
        }
        
        if(nums[i] == k+1){
            c++;
            maxi = max(maxi , c);
            helper(nums , nums[i] , i+1 , n , c , maxi);
        }
        else{
            c=1;
            helper(nums , nums[i] , i+1 , n , c , maxi);
        }
        return;
    }
    

    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int c = 1; int maxi = 0;
        int i = 1;
        int k = nums[0];   //or nums[i-1]
        helper(nums, k , i , n , c, maxi);
        return maxi;
    }


int main()
{
    vector<int> nums = {100,4,200,1,3,2};
    
    int c = longestConsecutive(nums);
    cout<<c;

    return 0;
}
*/
