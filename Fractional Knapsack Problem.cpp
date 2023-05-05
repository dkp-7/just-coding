Question :  Fractional Knapsack Problem

Link1 : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
Link2 : https://www.codingninjas.com/codestudio/problems/975286?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=3



SC : O(1)        TC : O(n log n)

#include <bits/stdc++.h> 

bool compare(pair<int,int> p1 , pair<int,int> p2){
    
    //sorting based on value/weight(kg)
    double a = (double)p1.second / p1.first;
    double b = (double)p2.second / p2.first;
    return a>b;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    if(n>1){
        sort(items.begin() , items.end() , compare);
    }
    

    //here using for loop is important, 
    //because if using : while(w>0), there may be a casethat all the
    // items are filled in the bag, but the bag still has space left
    
    double profit = 0;
    for(int k=0; k<n; k++){
        
        if(w >= items[k].first   &&  w>0){
            profit += items[k].second;
            w = w - items[k].first;
            items[k].first = 0;
        }
        else if(w < items[k].first){
            profit += ((double)items[k].second / items[k].first)*(double)w;
            items[k].first -= w;
            w=0;
        }
    }
    return profit;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////

SC : O(1)        TC : O(n log n)

//Not passing all the test cases

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 

bool compare(pair<int,int> p1 , pair<int,int> p2){
    
    //sorting based on value/weight(kg)
    double a = (double)p1.second / p1.first;
    double b = (double)p2.second / p2.first;
    return a>b;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    cout<<"Before Sort"<<endl;
    for(int i=0; i<n; i++){
        cout<<"weight : "<<items[i].first<<"         value : "<<items[i].second<<endl;
    }

    if(n>1){
        sort(items.begin() , items.end() , compare);
    }
    
    cout<<"After Sort"<<endl;
    for(int i=0; i<n; i++){
        cout<<"weight : "<<items[i].first<<"         value : "<<items[i].second<<endl;
    }
    double profit = 0;
    int k=0;
    while(w > 0){
        
        if(w >= items[k].first){
            profit += items[k].second;
            w = w - items[k].first;
            items[k].first = 0;
            k++;
        }
        else if(w < items[k].first){
            profit += ((double)items[k].second / items[k].first)*(double)w;
            items[k].first -= w;
            w=0;
        }
    }
    cout<<"After Operation"<<endl;
    for(int i=0; i<n; i++){
        cout<<"weight : "<<items[i].first<<"         value : "<<items[i].second<<endl;
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



/////////////////////////////////////////////////////////////////////////////////////////////////

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
