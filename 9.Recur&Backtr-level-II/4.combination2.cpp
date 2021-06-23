#include<bits/stdc++.h>
using namespace std;


void combination2(vector<int> box,int tot_item,int ci,int lb_used){

    if(ci > tot_item){
        for(int v:box){
            if(v!=0){
                cout<<"i";
            }else{
                cout<<"-";
            }
        }
        cout<<endl;

        return;
    }

    for(int i=lb_used+1;i<box.size();i++){
        box[i]=ci;
        combination2(box,tot_item,ci+1,i);
        box[i]=0;

    }
}



int main(){
    int no_of_box,item;
    cin>>no_of_box>>item;

    vector<int> box(no_of_box);
    combination2(box,item,1,-1);



    return 0;
}