#include<bits/stdc++.h>
using namespace std;


/*

        MIN HEAP

        insertion() -> O(log(n));
        remove() -> O(log(n));
        top() -> O(1)


*/


vector<int> heap;
void printHeap(){
    for(int v:heap){
        cout<<v<<" ";
    }
    cout<<endl;
}

void swap(int i,int j){
    int temp=heap[i];
    heap[i]=heap[j];
    heap[j]=temp;
}

void upheapify(int i){
    if(i==0){
        return;
    }

    int pi=(i-1)/2;
    if(heap[i] < heap[pi]){
        swap(i,pi);
        upheapify(pi);
    }
}

void downheapify(int pi){

    int mn=pi;

    //checking left child
    int left_child=2*pi+1;

    if(left_child < heap.size() && heap[left_child] < heap[mn]){
        mn=left_child;
    }

    //checking for right child

    int right_child=2*pi+2;

    if(right_child < heap.size() && heap[right_child] < heap[mn]){
        mn=right_child;
    }

    if(mn!=pi){
        swap(pi,mn);
        downheapify(mn);
    }

}

int top(){
    if(heap.size()==0){
        cout<<"heap is empty"<<endl;
        return -1;
    }
    return heap[0];
}


void insert(int val){
    heap.push_back(val);
    int id=heap.size()-1;
    upheapify(id);
}

int remove(){
    if(heap.size()==0){
        cout<<"cant remove heap is empty"<<endl;
        return -1;
    }else{
        swap(0,heap.size()-1);
        int val=heap[heap.size()-1];
        heap.pop_back();
        downheapify(0);
        return val;
    }
}


int main(){
    int n;
    cin>>n;
    
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        insert(a[i]);
    }

    while(heap.size() > 0){
        cout<<remove()<<" ";
    }
    cout<<endl;

    return 0;
}