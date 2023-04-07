//Next permutation in Lexicographical order

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permute(string &number, int n, int i, vector<string> &ans){

        if(i == n){           // or n-1
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
        int n = number.length();
        vector<string> ans;
        int i=0;
        permute(number , n, i, ans);
        for(string x : ans){
            cout<<x<<"  ";
        }
        cout<<endl;
        sort(ans.begin() , ans.end());
        for(string x : ans){
            cout<< x <<"  ";
        }
        cout<<endl;
        nums.clear();
        if(ans[0] == number){
            int a = stoi(ans[1]);
            nums.push_back(a);
        }
        else{
            int a = stoi(ans[0]);
            nums.push_back(a);
        }
        cout<<nums[0]<<endl;
    }

int main()
{
    vector<int> nums = {231};
    nextPermutation(nums);
    cout<<"Hello World";

    return 0;
}
