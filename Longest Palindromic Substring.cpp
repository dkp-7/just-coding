// Leetcode :   5. Longest Palindromic Substring


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
