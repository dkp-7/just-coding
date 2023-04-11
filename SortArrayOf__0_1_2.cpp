// Sort an Array of 0,1,2
//Dutch National Flag (DNF) Algorithm
//Leetcode (Question 75)

void sortColors(vector<int>& nums) {
  
        int n = nums.size();
        int low=0;
        int mid=0;
        int high=n;

        while(mid < high){
            if(nums[mid] == 0){
                swap(nums[low] , nums[mid]);
                low++; mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                high--;
                swap(nums[high] , nums[mid]);
            }
        }
}
