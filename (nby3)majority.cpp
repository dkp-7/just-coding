// Leetcode : 229. Majority Element II     (Elements in the array that are present more than n/3 times)

/*
Maximum possible no. of elements that could be answer in these kind of questions are:
If Questionasks for greater than

n/2 elements of array  -->   then at max only 1 elements as answer is possible
n/3 elements of array  -->   then at max only 2 elements as answer is possible
n/4 elements of array  -->   then at max only 3 elements as answer is possible
n/5 elements of array  -->   then at max only 4 elements as answer is possible
*/

vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ans;
        int number1 = INT_MAX;
        int number2 = INT_MAX;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();
        
        for(int ele : nums){
            
            if(number1 == ele){
                count1++;
            }
            else if(number2 == ele){
                count2++;
            }
            else if(count1 == 0){
                number1 = ele;
                count1++;
            }
            else if(count2 == 0){
                number2 = ele;
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        
        for(int ele : nums){
            
            if(ele == number1){
                count1++;
            }
            if(ele == number2){
                count2++;
            }
        }
        
        if(count1 > (n/3)) ans.push_back(number1);
        if(count2 > (n/3)) ans.push_back(number2);
        
        return ans;
        
}



/////////////////////////////////////////////////////////////////


/*

vector<int> majorityElement(vector<int>& nums) {
        
        int prev = INT_MAX;
        unordered_map<int,int> um;
        vector<int> ans ;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i=0; i<n; i++){
            um[nums[i]]++;
            
            if((um[nums[i]] > n/3)  &&  (nums[i] != prev) ){
                ans.push_back(nums[i]);
                prev = nums[i];
            }
        }
        return ans;
    }
    
    
    */
