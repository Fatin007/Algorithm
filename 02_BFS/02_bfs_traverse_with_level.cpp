#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10; 
vector<int>graph[N];
bool vis[N];
int level[N];

void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    while(q.size()){
        int par=q.front();
        q.pop();
        for(auto child:graph[par]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                level[child]=level[par]+1;
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
    int src; cin>>src;
    memset(vis,false,sizeof(vis));
    bfs(src);
    for(int i=0;i<n;i++){
        cout<<i<<" "<<level[i]<<endl;
    }
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