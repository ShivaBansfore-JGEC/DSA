#include<bits/stdc++.h>
using namespace std;


class MaxHeap{
    public:
    vector<int> heap;

    void swap(int i,int j){
        int temp=heap[i];
        heap[i]=heap[j];
        heap[j]=temp;
    }

    void upheapify(int child_idx){
        if(child_idx==0){
            return;
        }

        int parent_idx=(child_idx-1)/2;
        if(heap[parent_idx] < heap[child_idx]){
            swap(child_idx,parent_idx);
            upheapify(parent_idx);
        }
    }

    void downheapify(int parent_idx){
        int max_idx=parent_idx;

        //check left child

        int left_child_idx=2*parent_idx+1;

        if(left_child_idx < heap.size() && heap[left_child_idx] > heap[max_idx]){
            max_idx=left_child_idx;
        }

        //check the right index

        int right_child_idx=2*parent_idx+2;
        if(right_child_idx < heap.size() && heap[right_child_idx] > heap[max_idx]){
            max_idx=right_child_idx;
        }

        if(max_idx!=parent_idx){
            swap(max_idx,parent_idx);
            downheapify(max_idx);
        }

    }

    void insert(int val){
        heap.push_back(val);
        upheapify(heap.size()-1);
    }

    int remove(){
        if(heap.size()==0){
            cout<<"no element to delete"<<endl;
            return -1;
        }

        swap(0,heap.size()-1);
        //remove element in O(1)
        int val=heap[heap.size()-1];
        heap.pop_back();
        downheapify(0);
        return val;
    }

    int top(){
        return heap.front();
    }
    int size(){
        return heap.size();
    }

    void printHeap(){
        for(int u:heap){
            cout<<u<<" ";
        }
        cout<<endl;
    }

};


int main(){
    int n;
    cin>>n;

    MaxHeap heap;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        heap.insert(x);
    }

    // heap.printHeap();
    // heap.remove();
    // heap.printHeap();
    // heap.remove();
    // heap.printHeap();

    while(heap.size()>0){
        heap.printHeap();
        heap.remove();
    }
    cout<<endl;

    return 0;
}