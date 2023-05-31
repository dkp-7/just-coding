// Leetcode :   540. Single Element in a Sorted Array


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int ans = -1;
        int i = 0;
        while(i <= n-1){
            if(nums[i] != nums[i+1]){
                ans = nums[i];
                break;
            }
            i = i+2;
        }
        return ans;
    }
};
