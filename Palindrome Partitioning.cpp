//Leetcode :   131. Palindrome Partitioning



class Solution {
public:

    bool isPalindrome(string s , int start , int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++; end--;
        }
        return true;
    }

    void helper(string s , int n , int ind , vector<string> pairs , vector<vector<string>> &ans){

        if(ind == n){
            ans.push_back(pairs);
            return;
        }

        for(int i = ind; i<n; i++){

            if(isPalindrome(s , ind , i) ){
                pairs.push_back(s.substr(ind , i-ind+1));
                helper(s, n, i+1, pairs , ans);
                pairs.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> pairs;
        int ind = 0;
        int n = s.size();
        helper(s , n , ind , pairs , ans);
        return ans;
    }
};
