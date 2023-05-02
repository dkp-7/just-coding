//LeetCode  :       42. Trapping Rain Water


// Most optimal approach (2 Pointer)        TC : O(N)          SC : O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        
        //Using 2 Pointer Approach
        int n = height.size();
        int ans = 0;
        int leftmax = INT_MIN;
        int rightmax = INT_MIN;

        int left=0, right=n-1;
        while(left < right){

            //this block will only execute if there is a bigger/equal element to the right of this element
            if(height[left] <= height[right]){
                if(height[left] >= leftmax){
                    leftmax = height[left];
                }
                else{
                    ans += leftmax-height[left];
                }
                left++;
            }

            ////this block will only execute if there is a bigger element to the left of this element

            else{          //if(height[right] < height[left])
                if(height[right] >= rightmax){
                    rightmax = height[right];
                }
                else{
                    ans += rightmax-height[right];
                }
                right--;
            }
        }
        return ans;
    }
};



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//Better Approach               TC : O(3N) i.e, similar to O(N)      SC : O(2N)

class Solution {
public:
    int trap(vector<int>& height) {
        
        // Take 2 array & precompute leftmax for each index in one array and rightmax for each index in another array
        int n = height.size();
        int ans = 0;

        vector<int> left(n,0);     //leftmax array for each index
        int lm = INT_MIN;
        for(int i=0; i<n; i++){
            lm = max(lm , height[i]);
            left[i] = lm;
        }

        vector<int> right(n,0);       //rightmax array for each index
        int rm = INT_MIN;
        for(int j=n-1; j>=0; j--){
            rm = max(rm , height[j]);
            right[j] = rm;
        }

        for(int k=0; k<n; k++){
            int small = min(left[k] , right[k]);
            ans += small - height[k];
        }
        return ans;
    }
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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
