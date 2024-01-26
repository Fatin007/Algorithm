#include <bits/stdc++.h>
#define endl '\n'
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,e; cin>>n>>e;
    while(e--){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);;
        graph[y].push_back(x);;
    }
    int q; cin>>q;
    while(q--){
        int src,dest; cin>>src>>dest;
        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));
        bfs(src);
        cout<<level[dest]<<endl<<endl;
    }
}


/*
Problem satement:
You will be given an undirected graph 
as input. Then you will be given a query Q. 
For each query, you will be given source S and
destination D. You need to print the shortest 
distance between S and D. If there is no path
 from S to D, print -1.

Input
6 7
0 1
0 2
1 2
0 3
4 2
3 5
4 3
6
0 5
1 5
2 5
2 3
1 4
0 0

Output 
2
3
3
2
2
0

*/