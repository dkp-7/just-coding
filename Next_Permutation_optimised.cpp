void nextPermutation(vector<int>& nums) {

        int index = -1;
        int n = nums.size();

        //1. Finding longest prefix
        for(int i=n-2 ; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        //eDGE CASE: If index == -1, it means given no. is the largest no. that could be generated after   permutation, then just reverse whole number
        if(index == -1){
            reverse(nums.begin() , nums.end());
        }

        else{
            //2. Find the element *just* bigger than index element & swap it & break the loop immediately
            for(int i=n-1; i>index; i--){
                if(nums[i] > nums[index]){
                    swap(nums[i] , nums[index]);
                    break;
                }
            }

            //3. Now, all elements after index are in decreasing order
            //   just reverse those elements to get next permutation of number
            reverse(nums.begin()+(index+1) , nums.end());
}
