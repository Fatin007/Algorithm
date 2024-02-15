#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
bool vis[N];
int level[N];
int parent[N];

void bfs(int src,int dest){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    parent[src]=0;
    while(q.size()){
        int par=q.front();
        q.pop();
        for(auto child:graph[par]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                level[child]=level[par]+1;
                parent[child]=par;
            }
            if(child==dest){
                return;
            }
        }
    }
}

int main(){
    int n,e; cin>>n>>e;
    while(e--){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);;
        graph[y].push_back(x);;
    }
    int src,dest; cin>>src>>dest;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    bfs(src,dest);
    int cur=dest;
    vector<int>path;
    while(69){
        if(cur==src){
            path.push_back(cur);
            break;
        }
        path.push_back(cur);
        cur=parent[cur];
    }
    reverse(path.begin(),path.end());
    for(auto x:path) cout<<x<<" ";
}
// 7 8
// 0 1 
// 1 2 
// 0 4 
// 1 3 
// 2 0
// 3 4
// 1 5
// 3 6