// Leetcode :  300. Longest Increasing Subsequence



//Time Limit Exceeding for large size inputs

class Solution {
public:

    int f(vector<int>& nums, int n, int ind, int prev){
        if(ind == n) return 0;

        //for not pick
        int len = 0 + f(nums, n, ind+1, prev);
        //for pick
        if(prev==INT_MIN  ||  prev<nums[ind]){
            len = max(len , 1 + f(nums, n, ind+1, nums[ind]));
        }
        return len;
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        int prev =  INT_MIN;
        return f(nums , n , 0 , prev);   
    }
};
---------------------------------------------------------------------------------------------
class Solution {
public:

    int f(vector<int>& nums , int n , int ind , int cnt , int prev){
        if(ind == n) return cnt;

        int np = f(nums , n , ind+1 , cnt , prev);

        if(prev < nums[ind]){
            cnt++;
            prev = nums[ind];
        }
        int pick = f(nums , n , ind+1 , cnt , prev);

        return max(np, pick);
    }

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;
        int prev = INT_MIN;
        int ind = 0;
        int ans = f(nums , n , ind , cnt , prev);
        return ans;
    }
};
