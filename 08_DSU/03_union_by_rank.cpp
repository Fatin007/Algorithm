#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int par[N];
int level[N];

int find(int node){
    if(par[node]==-1) return node;
    par[node]=find(par[node]);
    return par[node];
}
void union_by_rank(int node1,int node2){
    int lead1=find(node1);
    int lead2=find(node2);
    if(level[lead1]>level[lead2]){
        par[lead2]=lead1;
    }
    else if(level[lead1]<level[lead2]){
        par[lead1]=lead2;
    }
    else{
        par[lead1]=lead2;
        level[lead2]++;
    }
}

int main(){
    memset(par,-1,sizeof(par));
    memset(level,0,sizeof(level));
    union_by_rank(1,2);
    union_by_rank(3,2);
    union_by_rank(4,5);
    union_by_rank(6,5);
    union_by_rank(1,5);
    cout<<find(1)<<endl;
    cout<<find(4)<<endl;
}
// o(αn)