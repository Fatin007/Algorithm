#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int n, vector<int>&v, int s){
    if(n==0){
        return s==0;
    }
    if(v[n-1]<=s){
        bool op1=subsetSum(n-1,v,s-v[n-1]);
        bool op2=subsetSum(n-1,v,s);
        return op1 || op2;
    }
    else{
        bool op2=subsetSum(n-1,v,s);
        return op2;
    }
}

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int s; cin>>s;
    bool dp[n+1][s+1];
    dp[0][0]=true;
    for(int i=1;i<=s;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=true;
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=s;j++){
    //         if(dp[i][j]) cout<<"T ";
    //         else cout<<"F ";
    //     }cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(v[i-1]<=j){
                // bool op1=dp[i-1][j-v[i-1]];
                // bool op2=dp[i-1][j];
                // dp[i][j]=op1 || op2;
                dp[i][j]=dp[i-1][j-v[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(dp[i][j]) cout<<"T ";
            else cout<<"F ";
        }cout<<endl;
    }
    if(dp[n][s]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}