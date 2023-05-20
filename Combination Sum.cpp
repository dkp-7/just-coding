// Leetcode:    39. Combination Sum



class Solution {
public:

    void helper(vector<int>& candidates, int target , int n , int i, vector<int> pair,vector<vector<int>> &ans){

        if(i==n  ||  target==0){
            return;
        }

        if(target >= candidates[i]){
            pair.push_back(candidates[i]);
            
            if(target-candidates[i]  == 0){
                ans.push_back(pair);
            }
            helper(candidates , target-candidates[i] , n , i, pair , ans);
            pair.pop_back();
        }
        
        helper(candidates , target , n , i+1, pair , ans);
        
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates , int target) {
        
        vector<vector<int>> ans;
        
        //sort(candidates.begin() , candidates.end());
        int n = candidates.size();
        int i = 0;
        vector<int> pair;
        helper(candidates , target , n , i , pair , ans);
        
        return ans;
        
    }
};
