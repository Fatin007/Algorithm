#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10; 
vector<int>graph[N];
bool vis[N];
int parent[N];
bool ans;

void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(q.size()){
        int par=q.front();
        q.pop();
        for(auto child:graph[par]){
            if(vis[child] and parent[par]!=child){ //this condition is game changer
                ans=true;
            }
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
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
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    ans=false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(i);
        }
    }
    if(ans) cout<<"Cycle detected"<<endl;
    else cout<<"Cycle not detected"<<endl;
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