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

class edge{
public:
    int u,v,w;
    edge(int uu,int vv,int ww){
        u=uu; v=vv; w=ww;
    }
};
bool cmp(edge a, edge b){
    return a.w<b.w;
}
int main(){
    memset(par,-1,sizeof(par));
    memset(Size,1,sizeof(Size));
    int n,e; cin>>n>>e;
    vector<edge>graph;
    while(e--){
        int u,v,w; cin>>u>>v>>w;
        graph.push_back(edge(u,v,w));
    }
    sort(graph.begin(),graph.end(),cmp);
    int total=0;
    for(auto ed:graph){
        int leadU=find(ed.u);
        int leadV=find(ed.v);
        if(leadU==leadV) continue;
        else{
            unionn(ed.u,ed.v);
            total+=ed.w;
        }
    }
    cout<<total<<endl;
}
// 5 7
// 0 1 2 
// 0 2 3 
// 0 3 3 
// 3 4 6 
// 2 4 4 
// 2 1 7
// 1 4 5
