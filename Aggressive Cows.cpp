// Question (Coding Ninjas) :  Aggressive Cows
// Question Link : https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTab=0


bool isPossible(vector<int> &stalls, int k, int mid){

    int cows = k-1;                  //because 1st cow will always be put inside the 1st stall
    int lastPlacedCow = stalls[0];
    for(int i=1; i < stalls.size(); i++){
        if(cows == 0) return true;
        if(stalls[i]-lastPlacedCow >= mid){
            lastPlacedCow = stalls[i];
            cows--;
        }
    }
    if(cows > 0) return false;
    return true;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin() , stalls.end());
    int n = stalls.size();
    if(k > n) return -1;
    int low = 1;
    int high = stalls[n-1] - stalls[0];
    int ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(isPossible(stalls , k , mid)){
            ans = mid;
            low = mid + 1;
        }
        else high = mid-1;
    }
    return ans;
}
