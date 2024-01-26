#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
char a[20][20];
bool vis[20][20];
int dis[20][20];
vector<pair<int,int>>d={{0,1},{0,-1},{-1,0},{1,0}};
int n,m;
bool valid(int x,int y){
    return (x>=0 and x<n and y>=0 and y<m);
}

void bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=true;
    dis[x][y]=0;
    while(q.size()){
        pair<int,int> par=q.front();
        int a=par.first, b=par.second;
        // cout<<a<<" "<<b<<endl;
        q.pop();
        for(int i=0;i<4;i++){
            int ci=a+d[i].first;
            int cj=b+d[i].second;
            if(valid(ci,cj) and !vis[ci][cj]){
                q.push({ci,cj});
                vis[ci][cj]=true;
                dis[ci][cj]=dis[a][b]+1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int x,y; cin>>x>>y;
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    memset(a,0,sizeof(a));
    bfs(x,y);
    cout<<dis[0][3];
}
/*
3 4 
....
....
....
0 0
*/