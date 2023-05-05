Question :  Fractional Knapsack Problem

Link1 : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
Link2 : https://www.codingninjas.com/codestudio/problems/975286?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=3






// it is working generally, BUT not working on Coding Ninja wesite

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 

struct goods{
    int weight;
    int value;
    double eff;
};

bool compare(goods g1 , goods g2){
    return (g1.eff > g2.eff);
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    
    struct goods goods1[n];
    
    for(int i=0; i<n; i++){
        goods1[i].weight = items[i].first;
        goods1[i].value = items[i].second;
        goods1[i].eff = (double)items[i].second / items[i].first ;
    }
    cout<<"Before sorting"<<endl;
    for(int i=0; i<n; i++){
        cout<<"   weight : "<<goods1[i].weight;
        cout<<"   value : "<<goods1[i].value;
        cout<<"   Efficiency : "<<goods1[i].eff;
        cout<<endl;
    }
    
    sort(goods1 , goods1+n , compare);
    cout<<"After sorting"<<endl;
    for(int i=0; i<n; i++){
        cout<<"   weight : "<<goods1[i].weight;
        cout<<"   value : "<<goods1[i].value;
        cout<<"   Efficiency : "<<goods1[i].eff;
        cout<<endl;
    }
    double profit = 0;
    int k = 0;
    
    cout<<"Changing weights"<<endl<<w<<endl;
    while(w > 0){
        
        if(w >= goods1[k].weight){
            w = w - goods1[k].weight;
            cout<<w<<endl;
            goods1[k].weight = 0;
            profit += goods1[k].value;
            k++;
            cout<<"PROFIT : "<<profit<<endl;
        }
        
        else if(w < goods1[k].weight){
            
            profit += ((double) goods1[k].value/goods1[k].weight) * w;
            goods1[k].weight = goods1[k].weight - w;
            w = 0;
            cout<<w<<endl;
            cout<<"PROFIT : "<<profit<<endl;
        }
        
    }
    cout<<"After operation"<<endl;
    for(int i=0; i<n; i++){
        cout<<"   weight : "<<goods1[i].weight;
        cout<<"   value : "<<goods1[i].value;
        cout<<"   Efficiency : "<<goods1[i].eff;
        cout<<endl;
    }

    return profit;
}


int main()
{
    vector<pair<int, int>> items = { {20 , 100},{10 ,60},{30 , 120} };
    int n =3;
    int w = 50;
    double ans = maximumValue(items, n, w);
    cout<<ans;
    return 0;
}
