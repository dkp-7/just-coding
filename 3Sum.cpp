// Leetcode :      15. 3Sum (distinct pairs)



// BRUTE Force Approach   (TLE)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set < vector < int >> pairs;    //using set to store distinct pairs

        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector < int > temp { nums[i] , nums[j] , nums[k] } ;
                        sort(temp.begin() , temp.end());    //sorting this vector, so it helps "pairs set" to identify similar pairs 
                        pairs.insert(temp);
                    }    
                }
            }
        }
        vector<vector<int>> ans{pairs.begin() , pairs.end()};
        return ans;
    }
};
