#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout<<"Enter TOTAL no. of rows you want to print in pascal triangle ";
    int Trow;
    cin>>Trow;
    
    vector<vector<int>> pascal;
    
    for(int row=1; row<=Trow; row++){
        
        vector<int> answer;
        answer.push_back(1);
        
        for(int col=1; col<(row-1); col++){
            
            int ans = answer[col-1]*(row-col);
            ans = ans/col;
            answer.push_back(ans);
        }
        if(row>1){
            answer.push_back(1);
        }
        pascal.push_back(answer);
    }
    
    for(int i=0; i<Trow; i++){
        for(int j=0; j<pascal[i].size(); j++){
            cout<<pascal[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}
