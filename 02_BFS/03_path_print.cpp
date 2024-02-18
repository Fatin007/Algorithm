#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
bool vis[N];
int level[N];
int parent[N];
int dis[N];

void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    dis[src]=0;
    while(q.size()){
        int par=q.front();
        q.pop();
        for(auto child:graph[par]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                level[child]=level[par]+1;
                dis[child]=dis[par]+1;
                parent[child]=par;
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
    // int src; cin>>src;
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    memset(parent,-1,sizeof(parent));
    bfs(1);
    if(dis[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<dis[n]+1<<endl;
    int x=n;
    vector<int>path;
    while(x!=-1){
        path.push_back(x);
        x=parent[x];
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