#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int par[N];
int Size[N];

int find(int node){
    // cout<<"fuck"<<endl;
    if(par[node]==-1) return node;
    par[node]=find(par[node]);
    return par[node];
}
void unionn(int node1,int node2){
    int lead1=find(node1);
    int lead2=find(node2);
    if(Size[lead1]>Size[lead2]){
        par[lead2]=lead1;
        Size[lead1]=Size[lead1]+Size[lead2];
    }
    else{
        par[lead1]=lead2;
        Size[lead2]=Size[lead2]+Size[lead1];
    }
}

int main(){
    memset(par,-1,sizeof(par));
    memset(Size,1,sizeof(Size));
    unionn(1,2);
    unionn(3,2);
    unionn(4,5);
    unionn(6,5);
    unionn(1,5);
    cout<<find(1)<<endl;
    cout<<find(4)<<endl;
}

// o(αn)