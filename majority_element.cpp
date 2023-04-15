
int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority=0; int element;
        unordered_map<int,int> um;
        for(int i=0; i<n; i++){
            um[nums[i]]++;
            if(um[nums[i]]  >  majority){
                majority = um[nums[i]];
                element = nums[i];
            }
        }

        return element;    
}


/*

int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> um;
        for(int i=0; i<n; i++){
            um[nums[i]]++;
        }
        //map<int, int>::iterator it;
        int majority=0; int element; 
        for(auto it : um){
            if(it.second > majority){
                majority = it.second;
                element = it.first;
            }
        }
        return element;
}

*/
