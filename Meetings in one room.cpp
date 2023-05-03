// N meetings in one room
// LINK to question : https://www.codingninjas.com/codestudio/problems/1062658?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
/*

There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
Example 2:

Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output: 
1
Explanation:
Only one meetings can be held
with given start and end timings.

Your Task :
You don't need to read inputs or print anything. Complete the function maxMeetings() that takes two arrays start[] and end[] along with their size N as input parameters and returns the maximum number of meetings that can be held in the meeting room.


Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)



*/



#include <bits/stdc++.h> 

struct meeting{
    int s;
    int e;
    int pos;
};

//compare function to compare meeting end times for sorting purpose
bool compare(meeting m1, meeting m2){
    if(m1.e < m2.e)  return true;
    if(m1.e > m2.e)  return false;
    if(m1.pos < m2.pos)  return true;  //incase if end times are equal, compare position
    return false;
}


vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    
    vector<int> ans;
    int n = start.size();
    
    //Storing each meeting with timings & index in meeting structure
    struct meeting meet[n];
    for(int i=0; i<n; i++){
        meet[i].s = start[i];
        meet[i].e = end[i];
        meet[i].pos = i+1;
    }

    //Sorting meeting based on its end time
    sort(meet , meet+n , compare);
    
    //1st meeting in sorted "meet" will always happen
    ans.push_back(meet[0].pos);
    int limit = meet[0].e;
    
    //now checking which other meetings will happen
    for(int i=0; i<n; i++){
        if(meet[i].s > limit){
            ans.push_back(meet[i].pos);
            limit = meet[i].e;
        }
    }
    return ans;
}
