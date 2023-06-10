// Leetcode :   38. Count and Say


class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1) return "1";
        if(n == 2) return "11";
        
        string ans = "11";
        for(int i=3; i<=n; i++){
            ans = ans+"$";
            string ans1 = "";
            for(int j=1; j<ans.length(); j++){
                int cnt = 1;
                while(ans[j]==ans[j-1]   &&   j<ans.length()){
                    cnt++;
                    j++;
                }
                ans1 += to_string(cnt) + ans[j-1];
            }
            ans = ans1;
        }
        return ans;
    }
};



--------------------------------------------------------------------------------------------------------------

// in below code "cout" statements helped in debugging the code which helped in finding out the mistake, otherwise the code is same as above code

class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1) return "1";
        if(n == 2) return "11";
        
        string ans = "11";
        for(int i=3; i<=n; i++){
            ans = ans+"$";
            string ans1 = "";
cout<<"inside 1 : ans : "<<ans<<endl;
            for(int j=1; j<ans.length(); j++){
                int cnt = 1;
cout<<"inside for "<<endl;
                while(ans[j]==ans[j-1]   &&   j<ans.length()){
cout<<"inside while "<<endl;
                    cnt++;
                    j++;
                }
                ans1 += to_string(cnt) + ans[j-1];
cout<<"otside while : ans1 : "<<ans1<<endl;
            }
            ans = ans1;
cout<<"outside for : ans : "<<ans<<endl;
        }
cout<<"finished";
        return ans;
    }
};
