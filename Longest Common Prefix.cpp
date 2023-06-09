// Leetcode :   14. Longest Common Prefix

// TC :  O(n1*n)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        if(n==1)  return strs[0];
        int n1 = strs[0].length();
        bool flag = false;
        int ind=0;

        while(ind <= n1-1){
            char ch = strs[0][ind];
            for(int i=1; i<n; i++){
                if(ch != strs[i][ind]){
                    flag = true;
                    break;
                }
            }
            if(flag == true) break;
            ind++;
        }
        string ans = strs[0];
        
        return ans.substr(0,ind);
    }
};
