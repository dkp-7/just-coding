//Leetcode :  46. Permutations



class Solution {
public:

    void helper(vector<int> &nums, int n, int ind, vector<vector<int>> &ans){

        if(ind == n){
            ans.push_back(nums);
            return;
        }
        for(int i=ind; i<n; i++){
            swap(nums[ind] , nums[i]);
            helper(nums , n , ind+1 , ans);
            swap(nums[ind] , nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

     vector<vector<int>> ans;
     int ind = 0;
     int n = nums.size();
     helper(nums , n , ind , ans);
     return ans;   
    }
};
