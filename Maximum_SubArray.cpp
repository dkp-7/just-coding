Leetcode (Question 53)


class Solution {
public:

    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        int c=0;
        for(int i=0; i<n; i++){
            if(nums[i] >= 0){
                c++;
            }
        }
        if(c==0){
            sort(nums.begin() , nums.end());
            return nums[n-1];
        }

        int ans = 0, sum=0;
        for(int i=0; i<n; i++){

            if((sum + nums[i]) <= 0){
                sum=0;
            }
            else{
                sum = sum + nums[i];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
