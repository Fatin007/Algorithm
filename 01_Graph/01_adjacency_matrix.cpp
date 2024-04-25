#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e; cin>>n>>e;
    int graph[n][n];
    memset(graph,0,sizeof(graph));
    while(e--){
        int x,y; cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}