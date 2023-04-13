//Best optimal method
//T.C. : O(n)     S.C.: O(1) 


int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        //to find 1st collision in the cycle
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);

        //to get 2nd collision, to find the element from where the cycle starts (i.e. duplicate no.)

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
