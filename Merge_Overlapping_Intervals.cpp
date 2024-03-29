/*   leetcode :   Question 56
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/


vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin() , intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;

        vector<int> pair(2,0);
        pair[0] = intervals[0][0];
        pair[1] = intervals[0][1];

        if(n==1){
            ans.push_back(pair);
            return ans;
        }

        for(int i=1; i<n; i++){
            if(pair[1] >= intervals[i][0]){
                pair[1] = max(pair[1] , intervals[i][1]);
            }
            else{         //if(pair[1] < intervals[i][0]){
                ans.push_back(pair);
                pair[0] = intervals[i][0];
                pair[1] = intervals[i][1];
            }
        }
        ans.push_back(pair);    //for last pair which is not inserted

        return ans;
}




/*
OR

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();

        if(n==0  ||  n==1){
            return intervals;
        }
        vector<int> pair = intervals[0];

        for(auto it : intervals){
            if(pair[1] >= it[0]){
                pair[1] = max(pair[1] , it[1]);
            }
            else{         //if(pair[1] < it[0]){
                ans.push_back(pair);
                pair = it;
            }
        }
        ans.push_back(pair);       //for last pair which is not inserted

        return ans;
}

*/

