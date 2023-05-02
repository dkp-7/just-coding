//LeetCode  :       42. Trapping Rain Water





//Brute Force Approach        TC : O(N*N)           SC : O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int left = INT_MIN, right=INT_MIN;
            for(int j=0; j<=i; j++){
                //if(left < height[j])  left = height[j];
                left = max(left , height[j]); 
            }
            for(int k=i; k<n; k++){
                right = max(right , height[k]);
            }
            int small = min(left , right);
            ans += (small-height[i]);
        }
        return ans;
    }
};
