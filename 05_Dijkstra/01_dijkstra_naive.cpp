#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10; 
vector<pair<int,int>>graph[N];
int dis[N];

void dijkstra(int src){
    queue<pair<int,int>>q;
    q.push({src,0});
    dis[src]=0;
    while(q.size()){
        auto par=q.front();
        q.pop();
        int node=par.first;
        int cost=par.second;
        for(auto child:graph[node]){
            int childNode=child.first;
            int childCost=child.second;
            if(cost+childCost<dis[childNode]){
                dis[childNode]=cost+childCost;
                q.push({childNode,cost+childCost});
            }
        }
    }
}

int main(){
    int n,e; cin>>n>>e;
    while(e--){
        int x,y,z; cin>>x>>y>>z;
        graph[x].push_back({y,z});;
        graph[y].push_back({x,z});;
    }
    // int src; cin>>src;
    // memset(dis,INT_MAX,sizeof(dis));
    for(int i=0;i<n;i++) dis[i]=INT_MAX;
    dijkstra(0);
    for(int i=0;i<n;i++) cout<<dis[i]<<" ";
}
// 5 8
// 0 1 10 
// 0 2 7
// 0 3 4
// 1 4 3
// 2 4 5
// 2 1 1
// 3 4 5
// 3 2 1