#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+10; 
vector<int>graph[N];
bool vis[N]; 
bool path[N]; //path is important
int parent[N]; 
bool ans;

void dfs(int par){
    // cout<<par<<endl;
    vis[par]=true;
    path[par]=true;
    for(auto child:graph[par]){
        if(path[child]){
            ans=true;
        }
        if(!vis[child]){
            parent[child]=par; // age track korte hobe
            dfs(child);
        }
    }
    path[par]=false; //bair hobar age path clear korbo
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,e; cin>>n>>e;
    while(e--){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);
    }
    memset(vis,false,sizeof(vis));
    memset(path,false,sizeof(path));
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
// 7 7
// 5 6 
// 4 5
// 0 4
// 0 6
// 1 0
// 1 2
// 2 3



// 7 8
// 5 6 
// 4 5
// 0 4
// 0 6
// 1 0
// 1 2
// 2 3
// 3 1