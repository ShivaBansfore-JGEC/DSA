#include<bits/stdc++.h>
using namespace std;

priority_queue<int> leftpq;
priority_queue<int,vector<int>,greater<>> rightpq;

void add(int val){
    if(rightpq.size() > 0 && val > rightpq.top()){
        rightpq.push(val);
    }else{
        leftpq.push(val);
    }

    if(leftpq.size()-rightpq.size()==2){
        rightpq.push(leftpq.top());
        leftpq.pop();
    }else if(rightpq.size()-leftpq.size()==2){
        leftpq.push(rightpq.top());
        rightpq.pop();
    }
}

int remove(){
    if(leftpq.size()==0 && rightpq.size()==0){
        return -1;
    }
    
    if(leftpq.size()>=rightpq.size()){
        int val=leftpq.top();
        leftpq.pop();
        return val;
    }else{
        int val=rightpq.top();
        rightpq.pop();
        return val;
    }
}


int  peek(){
    if(leftpq.size()==0 && rightpq.size()==0){
        return -1;
    }

    if(leftpq.size()>=rightpq.size()){
        return leftpq.top();
    }else{
        return rightpq.top();
    }

}



int main(){


    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        add(x);
    
    }
    cout<<peek()<<endl;
    cout<<remove()<<endl;
    cout<<remove()<<endl;


    return 0;
}