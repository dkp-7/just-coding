class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i=0; i<n; i++){
            if(i>0  &&  nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if(j>i+1  &&  nums[j]==nums[j-1])  continue;
                
                int l = j+1;
                int r = n-1;
                while(l<r){
                    long long sum = (long long)nums[i];
                    sum += (long long)nums[j];
                    sum += (long long)nums[l];
                    sum += (long long)nums[r];
                    
                    if(target == sum){
                        vector<int> a = {nums[i] , nums[j] , nums[l] , nums[r]};
                        ans.push_back(a);
                        l++; r--;
                        while(nums[l]==nums[l-1]  &&  l<r) l++;
                        while(nums[r]==nums[r+1]  &&  l<r) r--;
                    }
                    
                    else if(sum < target){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
                
            }
            
        }
        return ans;
    }
};
