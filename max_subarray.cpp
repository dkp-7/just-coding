int maxSubArray(vector<int>& nums) {

/*       (TC : O(n2)
        int ans=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                ans = max(sum, ans); 
            }
        }
        return ans;
*/

  //TC : O(N)
        int n = nums.size();
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
