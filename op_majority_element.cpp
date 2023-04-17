// If we are sure array have a single majority element, then the last element standing in the element variable will be our answer

//Moore's Voting Algorithm


int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int ele;
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            
            if(cnt == 0){
                ele = nums[i];
                cnt++;
            }
            else if(ele == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }    
        }
        
        return ele;
        
    }



////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

// If we are not sure whether array have a majority element or not (we are using 2nd loop for it)

int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int ele;
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            
            if(cnt == 0){
                ele = nums[i];
                cnt++;
            }
            else if(ele == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }    
        }
        
        int cnt1=0;
        for(int i=0; i<n; i++){
            
            if(ele == nums[i]){
                cnt1++;
            }
        }
        
        if(cnt1 > n/2) return ele;
        else return -1;
        
    }
    
    */
