#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,s=0; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        s+=v[i];
    }
    bool dp[n+1][s+1];
    dp[0][0]=true;
    for(int i=1;i<=s;i++) dp[0][i]=false;
    for(int i=1;i<=n;i++) dp[i][0]=true;
    vector<int>ans;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(v[i-1]<=j){
                dp[i][j]=dp[i-1][j-v[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
            if(dp[i][j] and i==n) ans.push_back(j);
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=s;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(auto x:ans) cout<<x<<" ";
    int mn=INT_MAX;
    for(auto x:ans){
        int s1=x;
        int s2=s-s1;
        mn=min(mn,abs(s1-s2));
    }
    cout<<mn<<endl;
}
// Target sum is also same....