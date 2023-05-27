// Word Break Problem

// Question Link (Coding Ninja) : https://www.codingninjas.com/codestudio/problems/983635?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1



//this code will not be adding any extra space at the end of the sentence

#include <bits/stdc++.h> 

void helper(string s, vector<string> dictionary, int n, string sentence, vector<string> &ans){

    for(int i=1; i<=n; i++){
        string ss = s.substr(0 , i);
        bool flag = false;
        for(int j=0; j<dictionary.size(); j++){
            if(dictionary[j] == ss){
                flag = true;
                
            }
        }

        if(flag == true){
            if(i == n){
                sentence = sentence + ss;
                ans.push_back(sentence);
                return;
            }
            helper(s.substr(i,n-i) , dictionary, n-i, sentence+ss+" ", ans);
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


//----------------------------------------------------------------------------------------------------------------------------------------//

// 1 testcase is failing here & at the end of a sentence this code will add an extra space

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
