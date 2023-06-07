//    Leetcode :  151. Reverse Words in a String


// Optimal method using 2 pointer Approach

class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        int i = n-1;
        int j = n-1;
        string ans;

        while(i>=0){

            while(i >= 0   &&   s[i] != ' '){
                i--;
            } 

            if(ans == ""){
                ans =  s.substr(i+1 , j-i);
            }

            else if(ans != ""){
                ans += " " + s.substr(i+1 , j-i);
            }
            while(i>=0  &&  s[i]==' '){       //note :  i>=0 should always come first
                i--;
                j = i;
            }
        }
        return ans;
    }
};


-------------------------------------------------------------------------------------

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
