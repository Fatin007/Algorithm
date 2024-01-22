#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e; cin>>n>>e;
    vector<int>graph[n];
    while(e--){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);;
        graph[y].push_back(x);;
    }
    for(auto x:graph[0]) cout<<x<<" ";
}