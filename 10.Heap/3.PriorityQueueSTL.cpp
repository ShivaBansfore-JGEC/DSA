#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq;

    pq.push(10);
    pq.push(-10);
    pq.push(50);
    pq.push(80);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    cout<<endl;

    priority_queue<int,vector<int>,greater<int>> pq1;

    pq1.push(10);
    pq1.push(-10);
    pq1.push(50);
    pq1.push(80);

    while(!pq1.empty()){
        cout<<pq1.top()<<" ";
        pq1.pop();
    }

/* 
 In heap or priority queue 

 push and remove -> log(n) time

 top() -> O(1) time



*/

 

    return 0;
}