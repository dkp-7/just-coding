// Leetcode :  300. Longest Increasing Subsequence



//Time Limit Exceeding for large size inputs

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
