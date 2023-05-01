// Leetcode :      15. 3Sum (distinct pairs , here tArget is 0)


// OPtimised Approach usin 2 pointer 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n= nums.size();
        sort(nums.begin() , nums.end());
        for(int i=0; i<n; i++){
            if(i>0  &&  nums[i] == nums[i-1]) continue;

            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    vector<int> pair = {nums[i] , nums[l] , nums[r]};
                    ans.push_back(pair);
                    l++; r--;
                    while(nums[l] == nums[l-1]  &&  l<r) l++;
                    while(nums[r] == nums[r+1]  &&  l<r) r--;
                }
                if(sum < 0) l++;
                else if(sum > 0) r--;
            }
        }
        return ans;
    }
};



//////////////////////////////////////////////////////////////////////////////////////////////////


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
