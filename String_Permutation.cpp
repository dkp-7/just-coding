#include <iostream>
#include <vector>

using namespace std;

void permute(string &nums , int i, int n, vector<string> &ans){
    if(i == n-1){           //when only 1 elemnt is left
        ans.push_back(nums);
        return;
    }
    for(int j=i; j<n; j++){
        swap(nums[i] , nums[j]);
        permute(nums , i+1 , n, ans);
        swap(nums[i] , nums[j]);
    }
    return;
}

void nextPermutation(string &nums) {
    vector<string> ans;
    int n = nums.length();
    int i=0;
    permute(nums , i , n , ans);
   
    for(int j=0; j<6; j++){
        cout<<ans[j]<<"  ";
    }
    cout<<endl;
    
}

int main()
{
    string nums = "abc";
    nextPermutation(nums);
    
    cout<<"finished";
    
    return 0;
}
