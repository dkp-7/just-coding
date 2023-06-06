// Leetcode :  347. Top K Frequent Elements



class Solution {
public:

    static bool compare(pair<int,int> it1 , pair<int,int> it2){
        return it1.second > it2.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> um;
        for(int i=0; i<nums.size(); i++){
            um[ nums[i] ]++;
        }
        vector<pair<int,int>> temp(um.begin(),um.end());

        sort(temp.begin() , temp.end() , compare);

        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};
