#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,s=0; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        s+=v[i];
    }
    if(s&1){
        cout<<"NO"<<endl;
        return 0;
    }
    s/=2;
    bool dp[n+1][s+1];
    dp[0][0]=true;
    for(int i=1;i<=s;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=true;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(v[i-1]<=j){
                dp[i][j]=dp[i-1][j-v[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    if(dp[n][s]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}