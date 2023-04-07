//Next permutation in Lexicographical order     (leetcode :  31.Next Permutation)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permute(string &number, int n, int i, vector<string> &ans){

        if(i == n){
            ans.push_back(number);
            return;
        }
        for(int j=i; j<n; j++){
            swap(number[i] , number[j]);
            permute(number, n, i+1, ans);
            swap(number[i] , number[j]);
        }
    }

void nextPermutation(vector<int>& nums) {
        
        string number = to_string(nums[0]);
        string oldnumber = number;
        sort(number.begin() , number.end());
        cout<<number<<endl;
        int n = number.length();
        vector<string> ans;
        int i=0;
        permute(number , n, i, ans);
        for(string x : ans){
            cout<<x<<"  ";
        }
        cout<<endl;
        nums.clear();
        
        for(int i=0; i<ans.size()-1; i++){
            if(ans[i] == oldnumber){
                int a = stoi(ans[i+1]);
                nums.push_back(a);
            }
        }
        
        if(ans[ans.size()-1] == oldnumber){
            int a = stoi(ans[0]);
            nums.push_back(a);
        }

        cout<<nums[0]<<endl;
    }

int main()
{
    vector<int> nums = {312};
    nextPermutation(nums);
    cout<<"Hello World";

    return 0;
}
