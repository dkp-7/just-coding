// Leetcode :  347. Top K Frequent Elements


// most optimal approach   TC : O(N)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int> um;
        for(int i=0; i<n; i++){
            um[nums[i]]++;
        }

        vector<vector<int>> counts(n+1);
        for(auto it : um){
            counts[it.second].push_back(it.first);
        }

        vector<int> ans(k);
        int c=0;
        for(int i=n; i>0; i--){
            if(!counts[i].empty()){

                for(int j=0; j<counts[i].size(); j++){
                    ans[c++] = counts[i][j];
                    if(c == k) break;
                }
                if(c == k) break;
            }        
        }
        return ans;
    }
};


-----------------------------------------------------------------------------------------------

// using priority queue (and make_pair() function in range based loop)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto it : um){
            pq.push(make_pair(it.second , it.first));
        }

        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};


--------------------------------------------------------------------------------------

// using priority queue
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto i=um.begin(); i != um.end(); i++){
            pair<int,int> p1;
            p1.first = i->second;
            p1.second = i->first;
            pq.push(p1);
        }
        vector<int> ans(k);
        int p=0;
        while(k--){
            ans[p++] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};


--------------------------------------------------------------------------------

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
