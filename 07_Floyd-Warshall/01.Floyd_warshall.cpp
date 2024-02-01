#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e; cin>>n>>e;
    long long graph[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                graph[i][j]=0;
                continue;
            }
            graph[i][j]=INT_MAX;
        }
    }
    while(e--){
        long long a,b,c; cin>>a>>b>>c;
        graph[a][b]=c;
    }
    //Here is the algoooo
    for(int k=0;k<n;k++){ 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][k]+graph[k][j]<graph[i][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
    ///end
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]>=INT_MAX) cout<<"INF ";
            else cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
// 4 6
// 3 2 8 
// 2 1 5
// 1 0 2
// 3 0 20
// 0 1 3
// 1 2 2
