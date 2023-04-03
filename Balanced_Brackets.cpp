#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<char>> tokens = { {'(',')'}, {'{','}'}, {'[',']'} } ;
stack<char> s;

bool isOpen(char c){
    for(vector<char> check : tokens){
        if(check[0] == c){
            return true;
        }
    }
    return false;
}

bool matches(char open , char close){
    for(vector<char> check : tokens){
        if(check[0] == open){
            if(check[1] == close){
                s.pop();
                return true;
            } 
        }
    }
    return false;
}

bool isBalanced(string str){
    
    for(char c : str){
        if(isOpen(c)){
            s.push(c);
        }
        else{
            if(s.empty()  ||  !matches(s.top() , c) ){
                return false;
            }
            
        }
    }
    return s.empty();
}

int main()
{
    string str = "{()[{({})[]()}]}([])";
    bool ans = isBalanced(str);
    cout<<"Answer is "<<ans;

    return 0;
}
