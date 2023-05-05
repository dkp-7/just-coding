Question : Maximum Activities

Link : https://www.codingninjas.com/codestudio/problems/1062712?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TC :  O(n logn)                SC : O(n)


#include <bits/stdc++.h>

struct activity{
    int st;           //start time
    int ft;          //finish time
};

bool compare(activity a1 , activity a2){
    return (a1.ft < a2.ft);
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    
    // sort tasks based on their 'end' time, smallest end time comes first
    // then compare if(start[i] >= lastend), where 'lastend' is the 
    // end time of last task completed, increase cnt by 1 if true
    
    int n = start.size();
    activity activities[n];
    for(int i=0; i<n; i++){
        activities[i].st = start[i];
        activities[i].ft = finish[i];
    }
    sort(activities , activities+n , compare);
    
    //i starts with 1, bcz activity at 0th index will always be performed
    int cnt = 1;
    int limit = activities[0].ft;        //ending time of current meeting
    for(int i=1; i<n; i++){
        if(activities[i].st >= limit){
            cnt++;
            limit = activities[i].ft;
        }
    }
    return cnt;  
}
