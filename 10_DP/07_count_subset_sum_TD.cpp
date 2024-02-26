#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int dp[N][N];

int subsetSum(int n, vector<int>&v, int s){
    if(n==0){
        return s==0;
    }
    if(dp[n][s]!=-1) return dp[n][s];
    if(v[n-1]<=s){
        int op1=subsetSum(n-1,v,s-v[n-1]);
        int op2=subsetSum(n-1,v,s);
        return dp[n][s]=op1+op2;
    }
    else{
        int op2=subsetSum(n-1,v,s);
        return dp[n][s]=op2;
    }
}

int main(){
    int n; cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int s; cin>>s;
    int ans=subsetSum(n,v,s);
    cout<<ans<<endl;
}