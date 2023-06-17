// Leetcode :  152. Maximum Product Subarray


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int prefix=1, suffix=1, maxi=INT_MIN;

        for(int i=0; i<n; i++){

            if(prefix == 0) prefix=1;
            if(suffix == 0) suffix=1;

            prefix = prefix*nums[i];
            suffix = suffix*nums[n-1-i];

            maxi = max(maxi, max(prefix,suffix));
        }
        return maxi;
    }
};
