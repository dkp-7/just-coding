//Leetcode :  1. Two Sum 
/*
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n= nums.size();
        vector<int> ans(2,0);
        unordered_map<int,int> um;
        for(int i=0; i<n; i++){
            
            if(um.find(target-nums[i]) != um.end()){
                ans[0] = um[target-nums[i]];
                ans[1] = i;
            }
            um[nums[i]] = i;
        }
        return ans;
    }
};


/*

// 2 pointer approach (this is good, if indexes are not asked)

string Sum(vector<int> &arr, int target){
   
   int left = 0;
   int right = arr.size()-1;
   while(left < right){
      int sum = arr[left] + arr[right];
      if(sum == target){
         return "TRUE"
      }
      else if(sum < target){
         left++;
      }
      else{
         right--;
      }
   }
   return "FALSE";
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n= nums.size();
        vector<int> ans(2,0);
        unordered_map<int,int> um;
        for(int i=0; i<n; i++){
            um[nums[i]] = i;
        }
        for(int i=0; i<n; i++){
            if( um.find(target-nums[i]) != um.end()  &&  (um[target-nums[i]] != i)){
                ans[0] = i;
                ans[1] = um[target-nums[i]];
            }
        }
        return ans;
    }
};


*/
