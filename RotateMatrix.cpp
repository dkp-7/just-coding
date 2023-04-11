//Rotating (n x n) matrix by 90 degrees clockwise using 1 extra matrix for help


#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    
    int n= matrix.size();
    vector<vector<int>> temp(n, vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //temp[i][j] = matrix[(n-1)-j][i];
            temp[j][(n-1)-i] = matrix[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix[i][j] = temp[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n= matrix.size();
    cout<<"Before"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;
    rotate(matrix);
    cout<<"After"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<"   ";
        }
        cout<<endl;
    }

    return 0;
}



/*
OR




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    
    int n= matrix.size();
    vector<vector<int>> temp;
    for(int i=0; i<n; i++){
        vector<int> inn;
        for(int j=0; j<n; j++){
            inn.push_back(matrix[(n-1)-j][i]);
            //temp[j][(n-1)-i] = matrix[i][j];
        }
        temp.push_back(inn);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix[i][j] = temp[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n= matrix.size();
    cout<<"Before"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;
    rotate(matrix);
    cout<<"After"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<"   ";
        }
        cout<<endl;
    }

    return 0;
}

*/
