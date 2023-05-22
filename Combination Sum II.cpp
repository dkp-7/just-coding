// Leetcode :  40. Combination Sum II




//Brute Force Approach , its Time complexity is more & it will be using extra space for hashset

class Solution {
public:
    void helper(vector<int>& candidates, int target, int n, int i, vector<int> pair, set<vector<int>> &ans){
        if(target == 0){
            sort(pair.begin() , pair.end());
            ans.insert(pair);
            return;
        }
        if(i == n) return;

        pair.push_back(candidates[i]);
        helper(candidates, target-candidates[i] , n , i+1 , pair , ans);
        pair.pop_back();
        helper(candidates , target , n , i+1 , pair , ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        set<vector<int>> ans;
        vector<int> pair;
        int i=0;
        helper(candidates , target, n , i, pair, ans);
        vector<vector<int>> ans2{ans.begin(),ans.end()};
        return ans2;
    }
};
