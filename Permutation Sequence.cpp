// LEETCODE :   60. Permutation Sequence




// optimised approach

class Solution {
public:
    int factorial(int m){
        if(m == 0) return 1;
        int f = 1;
        for(int i=1; i<=m; i++){
            f = f*i;
        }
        return f;
    }

    void helper(vector<int> nums , int k, int size , string &ans){

        if(size == 0){
            return;
        }
        int ind = k/factorial(size-1);
        ans += to_string(nums[ind]);
        nums.erase(nums.begin() + ind);
        k = k % factorial(size-1);

        helper(nums , k , size-1 , ans);
    }

    string getPermutation(int n, int k) {
        
        vector<int> nums(n,0);
        for(int i=0; i<n; i++){
            nums[i] = i+1;
        }
        string ans;
        int size = n;
        k = k-1;
        helper(nums , k , size , ans);
        return ans;
    }
};



-----------------------------------------------------------------------------------------------------------------------------

//Brute Force Approach (Time Limit is Exceeding)

class Solution {
public:

    void helper(vector<int> &arr, int n, int ind, vector<vector<int>> &ans){

        if(ind == n){
            ans.push_back(arr);
            return;
        }
        for(int i=ind; i<n; i++){
            swap(arr[ind] , arr[i]);
            helper(arr, n , ind+1 , ans);
            swap(arr[ind] , arr[i]);
        }
    }

    string getPermutation(int n, int k) {

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = i+1;
        }
        vector<vector<int>> ans;
        int ind = 0;
        helper(arr , n ,ind , ans);

        sort(ans.begin() , ans.end());
        vector<int> ans1;
        for(int i=0; i<k; i++){
            ans1 = ans[i];
        }
        int pair = ans1[0];
        for(int m=1; m < ans1.size(); m++){
            pair = (pair*10)+ans1[m];
        }
        
        return to_string(pair);;
    }
};
