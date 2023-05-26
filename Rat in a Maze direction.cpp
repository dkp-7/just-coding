

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void helper(vector<vector<int>> maze , vector<vector<int>> temp , int row, int col, vector<int> r, vector<int> c, int i, int j, string path, vector<string> &ans){
    if(i==row-1   &&   j==col-1){
        ans.push_back(path);
        return;
    }
    
    string dir = "DLRU";
    for(int ind=0; ind<4; ind++){
        int nexti = i+r[ind];
        int nextj = j+c[ind];
        if(nexti>=0  &&  nexti<row  &&  nextj>=0  &&  nextj<col  &&  temp[nexti][nextj]!=1  &&  maze[nexti][nextj]==1){
            temp[i][j] = 1;
            helper(maze , temp , row, col, r, c, nexti, nextj, path+dir[ind], ans);
            temp[i][j] = 0;
        }
    }
}

vector<string> ratInMaze(vector<vector<int>> maze, int row, int col){
    
    vector<vector<int>> temp(row, vector<int>(col,0));
    vector<int> r = {+1 , 0 , 0 , -1};
    vector<int> c = {0 , -1 , +1 , 0};
    
    vector<string> ans;
    helper(maze, temp, row, col, r , c  , 0 , 0 , "" , ans);
    return ans;
}

int main()
{
    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    int row = maze.size();
    int col = maze[0].size();
    vector<string> ans = ratInMaze(maze , row , col);
    
    for(int k=0; k<ans.size(); k++){
        cout<<ans[k]<<endl;
    }
}
