// 0-1 Knapsack (Bottom Up Approach)
#include <bits/stdc++.h>
using namespace std;

int main(){
    // n = number of items
    // w = maximum weight of knapsack
    // value = value of items
    // weight = weight of items
    int n; cin>>n;
    int value[n], weight[n];
    for(int i=0;i<n;i++) cin>>weight[i];
    for(int i=0;i<n;i++) cin>>value[i];
    int w; cin>>w;
    int dp[n+1][w+1];
    // Initialize first row and col of the dp array
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=w;j++) dp[0][j]=0;
    
    // Fill the dp array
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(weight[i-1]<=j){
                int op1=dp[i-1][j-weight[i-1]]+value[i-1];
                int op2=dp[i-1][j];
                dp[i][j]=max(op1,op2);
            }
            else{
                int op2=dp[i-1][j];
                dp[i][j]=op2;
            }
        }
    }
    cout<<dp[n][w]; // Print Maximum value
}
// 4
// 2 3 4 5 
// 1 3 5 3
// 8