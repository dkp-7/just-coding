//  Leetcode :   686. Repeated String Match



class Solution {
public:
    int subCheck(string target, string source){
        if(target == source)    return 1;

        int n = source.length();
        int len = target.length();
        int i=0;
        for(int j=target.length()-1; j<source.length(); j++){
            if(source.substr(i,len) == target) return 1;
            i++;
        }
        return -1;
    }

    int repeatedStringMatch(string a, string b) {
        
        int alen = a.length();
        int blen = b.length();
        int cnt = 1;
        string ans = a;

        while(ans.length()  <  blen){
            //cout<<"reprating a"<<endl;
            ans = ans + a;
            cnt++;
        }

        if(subCheck(b, ans) != -1) return cnt;
        else if(subCheck(b, ans+a) != -1) return cnt+1;

        return -1;
    }
};
