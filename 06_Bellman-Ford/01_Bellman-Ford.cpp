#include <bits/stdc++.h>
using namespace std;
class edge {
    public:
    int u,v,c;
    edge(int u,int v,int c){
        this->u=u;
        this->v=v;
        this->c=c;
    }
};
const int N=1e5+10;
int dis[N];
vector<edge>edgelist;

int main(){
    int n,e; cin>>n>>e;
    while(e--){
        int u,v,c; cin>>u>>v>>c;
        edgelist.push_back(edge(u,v,c));
    }
    // memset(dis,INT_MAX,sizeof(dis));
    for(int i=0;i<n;i++){
        dis[i]=INT_MAX;
    }
    dis[0]=0;
    ///////Belman-ford//////
    for(int i=0;i<n-1;i++){
        for(auto ed:edgelist){
            int u=ed.u;
            int v=ed.v;
            int c=ed.c;
            if(dis[u]!=INT_MAX and dis[u]+c<dis[v]){
                dis[v]=dis[u]+c;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" -> "<<dis[i]<<endl;
    }
}
// 4 4
// 0 2 5
// 0 3 12
// 2 1 2
// 1 3 3