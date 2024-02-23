#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int dp[N][N];

int knapsack(int n,int weight[],int value[],int w){
    if(n<0 || w==0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(weight[n]<=w){
        int op1=knapsack(n-1,weight,value,w-weight[n]) + value[n];
        int op2=knapsack(n-1,weight,value,w);
        dp[n][w]=max(op1,op2);
        return max(op1,op2);
    }
    else{
        int op2=knapsack(n-1,weight,value,w);
        return op2;
    }
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n; cin>>n;
    int value[n], weight[n];
    for(int i=0;i<n;i++) cin>>weight[i];
    for(int i=0;i<n;i++) cin>>value[i];
    int w; cin>>w;
    cout<<knapsack(n-1,weight,value,w);
}
// 4
// 2 3 4 5 
// 1 3 5 3
// 8