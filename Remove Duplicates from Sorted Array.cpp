// Leetcode :    26. Remove Duplicates from Sorted Array

//TC : O(n)       SC : O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n =nums.size();
        int k=0;
        nums[k++] = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i-1]==nums[i]){
                continue;
            }
            nums[k++] = nums[i];
        }
        return k;
    }
};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////


// This approach uses SET to store only unique elements and then orderly replacing elements of vector by 1
//TC : O(2N)       SC : O(K), K<=N

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        set<int> s; 
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        int k=0;
        for(int it : s){
            nums[k++] = it;
        }
        return k;
    }
};
