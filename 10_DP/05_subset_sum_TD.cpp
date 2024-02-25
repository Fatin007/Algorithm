#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int dp[N][N];

bool subsetSum(int n, vector<int>&v, int s){
    if(n==0){
        return s==0;
    }
    if(dp[n][s]!=-1) return dp[n][s];
    if(v[n-1]<=s){
        bool op1=subsetSum(n-1,v,s-v[n-1]);
        bool op2=subsetSum(n-1,v,s);
        return dp[n][s]=op1 || op2;
    }
    else{
        bool op2=subsetSum(n-1,v,s);
        return dp[n][s]=op2;
    }
}

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int s; cin>>s;
    if(subsetSum(n,v,s)){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}