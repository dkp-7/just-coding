// Leetcode :   5. Longest Palindromic Substring


// Using Dynamic Programming      TC: O(n*n)       SC: O(N*N)

class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.length();
        string ans;
        ans += s[0];
        int longest = INT_MIN;

        vector<vector<int>> dp(n, vector<int>(n));

        for(int i=0; i<n-1; i++){
            dp[i][i] = 1;
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                longest = 2;
                ans = s.substr(i,2);
            }
        }
        dp[n-1][n-1] = 1;
        
        // we have marked string of length==1 as 1 in dp array bcoz they will always be palindrome
        // Also, we have marked string of length==2 as 1 IN DP array, if they are palindrome
        // Now, we will check for all substring between length 3 and n whether they are palindrome or not
        
        for(int len=3; len<=n; len++){
            for(int i=0; i<=n-len; i++){
                int j = i+len-1;

                if(s[i]==s[j]  &&  dp[i+1][j-1]==1){

                    dp[i][j] = 1;
                    if(longest < j-i+1){
                        longest = j-i+1;
                        ans = s.substr(i,len);
                    }
                }
            }
        }
        return ans;
    }
};


---------------------------------------------------------------------------------------------------------------------------

// Brute Force Approach        TC: O(n*n*n)   SC: O(1)      (TLE)

class Solution {
public:

    bool palindrome(string str){
        int n = str.length();
        for(int i=0; i<n/2; i++){
            if(str[i] != str[n-1-i]) return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        
        int n = s.length();
        string ans;
        int longest = INT_MIN;
        for(int i=0; i<n; i++){
            string a = s.substr(i,n-i);
            int newlen = n-i;
            while(newlen > 0){

                if(palindrome(a.substr(0,newlen)) ){
                    if(newlen > longest){
                        longest = newlen;
                        ans = a.substr(0,newlen);
                    }
                }
                newlen--;
            }
        }
        return ans;
    }
};
