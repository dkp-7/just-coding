// Word Break Problem


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void helper(string s, vector<string> dictionary, int n, string sentence, vector<string> &ans){
    
    if(n == 0){
        ans.push_back(sentence);
        return;
    }

    for(int i=1; i<=n; i++){
        string ss = s.substr(0 , i);
        
        for(int j=0; j<dictionary.size(); j++){
            if(dictionary[j] == ss){
                helper(s.substr(i,n-i) , dictionary, n-i, sentence+ss+" ", ans);
            }
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    int n = s.size();
    string sentence = "";
    vector<string> ans;
    helper(s, dictionary, n, "", ans);
    return ans;

}

int main()
{
    string s = "godisnowherenowhere";
    vector<string> dictionary = {"god", "is", "now", "no", "where", "here"};
    vector<string> ans = wordBreak(s, dictionary);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
