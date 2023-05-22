// Leetcode :  40. Combination Sum II

//Optimal Approach with less time complexity & no extra space complexity

class Solution {
public:
    void helper(vector<int>& candidates, int target, int n , int ind , vector<int> pair , vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(pair);
            return;
        }
        for(int i = ind; i < n ; i++){

            if(i > ind   &&  candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;

            pair.push_back(candidates[i]);
            helper(candidates , target-candidates[i] , n , i+1 , pair , ans);    //here always give ind=i+1 and not ind+1, if we give it as ind+1, then it will repeat the loop for same value, which will result in wrong answer
            pair.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> pair;
        vector<vector<int>> ans;
        sort(candidates.begin() , candidates.end());
        int n = candidates.size();
        int ind = 0;
        helper(candidates , target , n , ind , pair, ans);
        return ans;
    }
};


---------------------------------------------------------------------------------------------------------------------------------------
    

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
