// Leetcode : 485. Max Consecutive Ones


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int cnt = 0; int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                cnt=0;
            }
            ans = max(ans , cnt);
        }
        
        return ans;
    }
};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int k = 0; int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 1){
                ans = max(ans , k);
                k=0;
                continue;
            }
            k = k+1;
        }
        ans = max(ans , k);
        return ans;
    }
};
