// Leetcode :      128. Longest Consecutive Sequence



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
