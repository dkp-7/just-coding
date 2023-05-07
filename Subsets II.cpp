// Leetcode :    90. Subsets II



class Solution {
public:

    void helper(vector<int> nums, int n, int i, vector<int> pairs, set<vector<int>> &ans){

        if(i == n){
            sort(pairs.begin() , pairs.end());
            ans.insert(pairs);
            return;
        }
        pairs.push_back(nums[i]);
        helper(nums , n , i+1 , pairs , ans);
        pairs.pop_back();
        helper(nums , n , i+1 , pairs , ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        int i=0;
        vector<int> pairs;
        set<vector<int>> ans;
        helper(nums , n, i , pairs , ans);

        vector<vector<int>> ans1 {ans.begin() , ans.end()};
        return ans1;
    }
};
