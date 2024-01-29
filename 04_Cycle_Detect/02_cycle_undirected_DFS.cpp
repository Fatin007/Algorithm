#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+10; 
vector<int>graph[N];
bool vis[N]; 
int parent[N]; 
bool ans;

void dfs(int par){
    // cout<<par<<endl;
    vis[par]=true;
    for(auto child:graph[par]){
        if(vis[child] and parent[par]!=child){
            ans=true;
        }
        if(!vis[child]){
            parent[child]=par; // age track korte hobe
            dfs(child);
        }
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
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    ans=false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(ans) cout<<"Cycle detected"<<endl;
    else cout<<"Cycle not detected"<<endl;
}