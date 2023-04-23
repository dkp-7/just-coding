// Leetcode :    560. Subarray Sum Equals K



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int c=0;
        int sum = 0;
        unordered_map<int,int> um;   //to store sum at all indexes(till that index) : and how many times that sum has occured in that array
        um[0] = 1;
        
        for(int i=0; i<n; i++){
            
            sum += nums[i];
            int f = sum-k;
            
            if(um.find(f) != um.end()){
                c = c+um[f];     //um[f] will give us in how many ways that sum of array could be created
            }
            um[sum]++;
            
        }
        return c;
    }
};
