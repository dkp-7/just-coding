// Minimum no. of platforms
//Link : Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
//Link : https://www.codingninjas.com/codestudio/problems/799400?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

/*
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.


Example 1:

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.
Example 2:

Input: n = 3
arr[] = {0900, 1100, 1235}
dep[] = {1000, 1200, 1240}
Output: 1
Explanation: Only 1 platform is required to 
safely manage the arrival and departure 
of all trains. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPlatform() which takes the array arr[] (denoting the arrival times), array dep[] (denoting the departure times) and the size of the array as inputs and returns the minimum number of platforms required at the railway station such that no train waits.

Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this may be > 59).

/*

Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.

Example 1:
Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.

Example 2:
Input: n = 3
arr[] = {0900, 1100, 1235}
dep[] = {1000, 1200, 1240}
Output: 1
Explanation: Only 1 platform is required to 
safely manage the arrival and departure 
of all trains. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPlatform() which takes the array arr[] (denoting the arrival times), array dep[] (denoting the departure times) and the size of the array as inputs and returns the minimum number of platforms required at the railway station such that no train waits.

Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this may be > 59).

*/

int calculateMinPatforms(int at[], int dt[], int n) {
    
    int ans = 1;
    sort(at , at+n);
    sort(dt , dt+n);
    
    int i=1;   //pointer for 'at' array, it starts with 1st index because 1st train will always arrive 
    int j=0;    //pointer for 'dt' array
    int pf = 1;
    while(i<=n-1){
        
        //last train is still standing at platform, for new arriving train an extra platform is needed
       if(at[i] <= dt[j]){
           i++;
           pf++;
           ans = max(ans,pf);
       }
       //last train have completed its stay time, it will leave now and vacant a platform
       else{      // if(dt[j]<at[i])   or  if(at[i]>dt[j])
           pf--;
           j++;
           //ans = max(ans , pf);
       }
    }
    return ans;  
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//this code is not working in Coding ninja, not checked for GFG

int calculateMinPatforms(int at[], int dt[], int n) {
    
    //we have to find how many train is stopping at a station at a given particulR TIME,
    //tHIS WILL tell us no. of minimum platform required at station
    // OR, we need to find how mant trains time clashes/overlaps at a given moment,
    //when 1 train is already standing at a station/platform (we have to check this for each train)
    //and return the max value for no. of platforms reqd. among all trains
    
    int ans = 1;  //platform
    for(int i=0; i<n; i++){
        int count = 1;
        for(int j=i+1; j<n; j++){
            if( (at[i]<=at[j] && dt[i]>=at[j] ) || (at[i]>=at[j] && dt[j]>=at[i]) ){
                count++;
                
            }
        }
        ans = max(ans , count);
    }
    return ans;
    }
