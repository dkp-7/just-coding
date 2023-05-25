//  Question : Rat in a Maze



//  This code will only return single answer path to reach destination (i.e. from  0,0  to  n-1,n-1)  

#include <iostream>
#include <vector>
using namespace std;

bool helper(vector<vector<int>> &maze, int n, int row, int col, vector<vector<int>> &ans, vector<vector<int>> &ans2){

  if(row==n-1  &&  col==n-1){
      ans[row][col] = 1;
      for(int i = 0 ; i<n; i++){
        for(int j=0; j<n; j++){
          ans2[i][j] = ans[i][j];
        }
      }
      return true;
    }

//down
  if(row<n-1  &&  maze[row+1][col] != 0  &&  ans[row+1][col] != 1){
    ans[row][col] = 1;
    if(helper(maze, n, row+1, col, ans, ans2) == true){
      return true;
    }
    ans[row][col] = 0;
  }
  
//right
  if(col<n-1  &&  maze[row][col+1] != 0  &&  ans[row][col+1] != 1){
    ans[row][col] = 1;
    if(helper(maze, n, row, col+1, ans, ans2) == true){
      return true;
    }
    ans[row][col] = 0;
  }

//left
  if(col>0  &&  maze[row][col-1] != 0  &&  ans[row][col-1] != 1){
    ans[row][col] = 1;
    if(helper(maze, n, row, col-1, ans, ans2) == true){
      return true;
    }
    ans[row][col] = 0;
  }

//up
  if(row>0  &&  maze[row-1][col] != 0  &&  ans[row-1][col] != 1){
    ans[row][col] = 1;
    if(helper(maze, n, row-1, col, ans, ans2) == true){
      return true;
    }
    ans[row][col] = 0;
  }
  return false;
}



vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n){

  int row = 0;
  int col = 0;

  vector<vector<int>> ans(n, vector<int>(n,0));
  vector<vector<int>> ans2(n, vector<int>(n,0));
  
  if(n == 0){
    ans2[0][0] = 1;
    return ans;
  }

  bool answer = helper(maze, n, row, col, ans, ans2);
  if(answer == true) return ans;
  else{
    ans2.clear();
    return ans2;
  }
  
}

int main()
{
    vector<vector<int>> maze = { {1,1,0,0} , {1,1,1,1} , {0,1,0,1} , {0,1,1,1} };
    int n = maze.size();
    vector<vector<int>> ans = ratInAMaze(maze , n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}
