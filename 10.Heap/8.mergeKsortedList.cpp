#include<bits/stdc++.h>
using namespace std;

struct Pair{
    int li,di,val;
};


struct compareVal{
    bool operator()( Pair const& p1,Pair const& p2){
        return p1.val > p2.val;
    }

};


vector<int> mergeKsortedList(vector<vector<int>> &list){
    
    vector<int> mergedList;
    priority_queue<Pair,vector<Pair>,compareVal> pq;
    
    for(int i=0;i<list.size();i++){
        Pair p;
        p.li=i;
        p.di=0;
        p.val=list[i][0];
        pq.push(p);
    }

    while(pq.size() > 0){
        Pair p=pq.top();
        pq.pop();
        mergedList.push_back(p.val);
        p.di++;

        if(p.di < list[p.li].size()){
            p.val=list[p.li][p.di];
            pq.push(p);
        }
    }

    return mergedList;
   

}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> list;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<int> a(m);
        for(int i=0;i<m;i++){
            cin>>a[i];
        }
        list.push_back(a);
    }
    
    vector<int> mergeList= mergeKsortedList(list);
    for(int u:mergeList){
        cout<<u<<" ";
    }

    cout<<endl;

    return 0;
}