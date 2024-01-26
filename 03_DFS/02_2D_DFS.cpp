#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
char a[20][20];
bool vis[20][20];
vector<pair<int,int>>d={{0,1},{0,-1},{-1,0},{1,0}};
int n,m;
bool valid(int x,int y){
    return (x>=0 and x<n and y>=0 and y<m);
}

void dfs(int x,int y){
    cout<<x<<" "<<y<<endl;
    vis[x][y]=true;
    for(int i=0;i<4;i++){
        int ci=x+d[i].first;
        int cj=y+d[i].second;
        if(valid(ci,cj) and !vis[ci][cj]){
            dfs(ci,cj);
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
    memset(a,0,sizeof(a));
    dfs(x,y);
}