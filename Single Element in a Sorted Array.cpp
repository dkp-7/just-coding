// Leetcode :   540. Single Element in a Sorted Array

//Optimal method using (Binary Search + XOR)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0;
        int high = n-2;

        while(low <= high){
            int mid = (low + high)/2;
            /*
            even XOR 1  ==  NEXT ODD
            odd XOR 1  ==  previous even
            */

            //it will only be true, when mid is even
            if(nums[mid] == nums[mid^1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        //when low has crossed high, single element is at index 'low'
        return nums[low];
    }
};

---------------------------------------------------------------------------

//Optimal method using Binary Search

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0;
        int high = n-2;

        while(low <= high){
            int mid = (low + high)/2;

            //even index, assuming it to be 1st element in duplicate, check left half
            if(mid%2 == 0){    
                if(nums[mid] == nums[mid+1]){
                    //left half confirmed, shrink the left half search space
                    low = mid+1;
                }
                else{
                    // else, it is from right half, shrink the right half
                    high = mid-1;
                }
            }

            // mid is odd, it maybe index in right half then
            else{
                if(nums[mid] == nums[mid+1]){
                    //right half confirmed, shrink the right half search space
                    high = mid-1;
                }
                else{
                    // else, it is from left half, shrink the left half
                    low = mid+1;
                }
            }
        }
        //when low has crossed high, single element is at index 'low'
        return nums[low];
    }
};


-------------------------------------------------------------------------------------------------

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
