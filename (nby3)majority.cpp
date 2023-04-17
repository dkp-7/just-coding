// Leetcode : 229. Majority Element II



/////////////////////////////////////////////////////////////////


/*

vector<int> majorityElement(vector<int>& nums) {
        
        int prev = INT_MAX;
        unordered_map<int,int> um;
        vector<int> ans ;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i=0; i<n; i++){
            um[nums[i]]++;
            
            if((um[nums[i]] > n/3)  &&  (nums[i] != prev) ){
                ans.push_back(nums[i]);
                prev = nums[i];
            }
        }
        return ans;
    }
    
    
    */
