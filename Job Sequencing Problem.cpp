// Question : Job Sequencing Problem
// Link 1 : https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Link 2 : https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

// TC : O(N)+O(N LOGN)+O(N*M)
// SC : O(M)  (it depends on maximum deadline in an array)



#include <bits/stdc++.h> 

bool compare(vector<int> j1 , vector<int> j2){
    return (j1[1] > j2[1]);
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    
    //find max deadline 
    int maxdl = 0;
    for(int i=0; i<n; i++){
        if(jobs[i][0] > maxdl)   maxdl = jobs[i][0];
    }
    
    //make an array of size equal to maxdl days
    vector<int> days(maxdl+1 , -1);
    days[0] = 2;
    
    //sort the jobs array in descending order of profit
    sort(jobs.begin() , jobs.end(), compare);
    
    //sTART iterating over all elements of sorted array 'jobs'
    //and execute the jobs as per the the deadline
    // perform job with longest of deadlines toward its last day if possible to gain max profit
    
    int profit=0;
    //int cnt=0;
    
    for(int i=0; i<n; i++){      //to iterate iver 'job' array
        
        int dl = jobs[i][0];    //getting deadline of a particular job
        
        while(days[dl] != -1   &&   dl>1){
            dl--;
        }
        
        if(days[dl] == -1){
            days[dl] = 1;
            profit += jobs[i][1];
            //cnt++;   //to count how many jobs are executed if asked
        }

    }
    return profit;
}
