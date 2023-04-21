// Leetcode :      128. Longest Consecutive Sequence

// OPTIMAL APPROACH   TC: O(N)   {OR O(3N}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        
        unordered_set<int> hashset;      //set stores only unique elements
        
        for(int i=0; i<n; i++){
            hashset.insert(nums[i]);
        }
        int maxi = INT_MIN;
        
        for(auto it : hashset){           //one have to iterate through set / map elements like this
            
            if(hashset.find(it-1)  == hashset.end()){      //this means it is first element in consecutive order
                int k = it;
                int cnt=1; 
                
                while(hashset.find(k+1) != hashset.end()){
                    cnt++;
                    k = k+1;
                }
                maxi = max(maxi , cnt);
            }
            
        }
        return maxi;
    }
};


/*

// OPTIMAL APPROACH   TC: O(N)          {OR O(3N}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        
        unordered_set<int> hashset;      //set stores only unique elements
        
        for(int i=0; i<n; i++){
            hashset.insert(nums[i]);
        }
        int maxi = 1;
        
        for(auto it : hashset){           //one have to iterate through set / map elements like this
            
            if(hashset.find(it-1)  == hashset.end()){      //this means it is first element in consecutive order
                int k = it;
                int cnt=1; 
                
                while(hashset.find(k+1) != hashset.end()){
                    cnt++;
                    k = k+1;
                }
                maxi = max(maxi , cnt);
            }
            
        }
        return maxi;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////




//tc : O(n log n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0) return 0;
        
        sort(nums.begin() , nums.end());
        int c=1;
        int maxi = 0;
        
        for(int i=0; i<n-1; i++){
            
            if(nums[i] == nums[i+1]-1){
                c++;
            }
            else if(nums[i] == nums[i+1]){
                c=c;
            }
            else{
                maxi = max(maxi , c);
                c=1; 
            }
        }
        maxi = max(maxi , c);
        return maxi;
    }
};


/*

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


    void helper(vector<int> &nums, int k, int i, int n, int &c , int &maxi){
        
        if( i > n){
            return;
        }
        
        if(nums[i] == k+1){
            c++;
            maxi = max(maxi , c);
            helper(nums , nums[i] , i+1 , n , c , maxi);
        }
        else{
            c=1;
            helper(nums , nums[i] , i+1 , n , c , maxi);
        }
        return;
    }
    

    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int c = 1; int maxi = 0;
        int i = 1;
        int k = nums[0];   //or nums[i-1]
        helper(nums, k , i , n , c, maxi);
        return maxi;
    }


int main()
{
    vector<int> nums = {100,4,200,1,3,2};
    
    int c = longestConsecutive(nums);
    cout<<c;

    return 0;
}
*/
