#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
ll dp[N];

ll fib(ll n){
    if(n==0 or n==1) return n;
    if(dp[n]!=-1) return dp[n];
    ll ans=fib(n-1)+fib(n-2);
    dp[n]=ans;
    cout<<dp[n]<<" ";
    return ans;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    ll n; cin>>n;
    cout<< //
    fib(n);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}