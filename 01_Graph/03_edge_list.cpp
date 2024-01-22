#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e; cin>>n>>e;
    vector<pair<int,int>>graph;
    while(e--){
        int x,y; cin>>x>>y;
        graph.push_back({x,y});
    }
    for(auto x:graph) cout<<x.first<<" "<<x.second<<endl;
}