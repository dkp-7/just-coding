//    Leetcode :  151. Reverse Words in a String


class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> a;
        int n = s.length();
        int ind = 0;
        int cnt = 0;
        int start = ind;
        while(ind <= n){
            cnt++;
            if(s[ind] == ' '  ||  ind == n){
                string word = s.substr(start , cnt-1);
                if(word != "") a.push_back(word);  
                cnt = 0;
                start = ind + 1; 
            }
            ind++;    
        }
        string ans;
        for(int i = a.size()-1; i>0; i--){
            ans = ans + a[i] + ' ';
        }
        ans = ans + a[0];
        return ans;
    }
};
