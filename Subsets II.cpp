// Leetcode :    90. Subsets II


//Without using set data structure        SC : O(1)

class Solution {
public:

    void helper(vector<int>& nums , int n, vector<vector<int>> &ans, vector<int> pair, int ind){
        
        ans.push_back(pair);
        for(int j=ind; j<n; j++){

            if(j != ind  &&  nums[j]==nums[j-1]) continue;

            pair.push_back(nums[j]);
            helper(nums, n, ans, pair, j+1); 
            pair.pop_back();
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> pair;
        int ind=0;
        sort(nums.begin(), nums.end());
        helper(nums , n , ans, pair, ind);
        return ans;
    }
};



---------------------------------------------------------------------------------------------------------------------
    //using set data structure  SC : O(N)

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
