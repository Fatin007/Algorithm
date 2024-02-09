#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int par[N];

int find(int node){
    // cout<<"fuck"<<endl;
    if(par[node]==-1) return node;
    par[node]=find(par[node]);
    return par[node];
}

int main(){
    memset(par,-1,sizeof(par));
    par[1]=3;
    par[2]=1;
    cout<<find(0)<<endl;
    cout<<find(1)<<endl;
    cout<<find(2)<<endl;
    cout<<find(3)<<endl;
}

// o(logn)