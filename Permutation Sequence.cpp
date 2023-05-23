// LEETCODE :   60. Permutation Sequence




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
