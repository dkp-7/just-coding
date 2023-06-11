// Question Links:
// Coding Ninja : https://www.codingninjas.com/codestudio/problems/981273?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// GFG : https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1


#include <bits/stdc++.h> 

bool isPossible(vector<vector<int>> &mat, int v, int clr, vector<int> colour){
    
    for(int j=0; j<mat[v].size(); j++){
        if(mat[v][j] == 1){
            if(colour[j] == clr)  return false; 
        }
    }
    return true;
}

bool helper(vector<vector<int>> &mat, int m, int n, int v, vector<int> colour){
    
    if(v == n) return true;
    
    for(int clr=1; clr<=m; clr++){
        if(isPossible(mat , v , clr , colour)){
            colour[v] = clr;
            if(helper(mat, m, n, v+1, colour) == true){
                return true;
            }
            colour[v] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {

    int n = mat.size();
    int v = 0;
    vector<int> colour(n , 0);
    bool ans = helper(mat , m , n , v , colour);
    
    if(ans == true) return "YES";
    return "NO";
    
}
