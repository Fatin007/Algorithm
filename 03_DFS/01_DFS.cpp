#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+10; 
vector<int>graph[N];
bool vis[N];

void dfs(int src){
    cout<<src<<endl;
    vis[src]=true;
    for(auto child:graph[src]){
        if(!vis[child]) dfs(child);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,e; cin>>n>>e;
    while(e--){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);;
        graph[y].push_back(x);;
    }
    int src; cin>>src;
    memset(vis,false,sizeof(vis));
    dfs(src);
}