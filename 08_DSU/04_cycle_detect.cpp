#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int par[N];
int Size[N];

int find(int node){
    if(par[node]==-1) return node;
    par[node]=find(par[node]);
    return par[node];
}
void union_by_size(int node1,int node2){
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
    int n,e; cin>>n>>e;
    bool cycle=false;
    while(e--){
        int x,y; cin>>x>>y;
        int leadX=find(x);
        int leadY=find(y);
        if(leadX==leadY) cycle=true;
        else union_by_size(x,y);
    }
    if(cycle) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
}