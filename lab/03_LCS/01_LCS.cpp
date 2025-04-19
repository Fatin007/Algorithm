// Longest Common Subsequence
// LCS
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s1,s2; cin>>s1>>s2;
    int n=s1.size(), m=s2.size();
    int dp[n+1][m+1];  
    char dir[n+1][m+1];  // for direction
    for(int i=0; i<=n; i++) dp[i][0]=0;
    for(int i=0; i<=m; i++) dp[0][i]=0;
    for(int i=0; i<=n; i++) dir[i][0]='#';
    for(int i=0; i<=m; i++) dir[0][i]='#';


    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){ // if both characters are same then add 1 to the diagonal value
                dp[i][j]=dp[i-1][j-1]+1;
                dir[i][j]='D'; // D for diagonal direction
            }
            else if(dp[i-1][j]>dp[i][j-1]){ // if top value is greater than left value then take top value
                dp[i][j]=dp[i-1][j];
                dir[i][j]='U'; // U for up direction
            }
            else{ // if left value is greater than top value then take left value
                dp[i][j]=dp[i][j-1];
                dir[i][j]='L'; // L for left direction
            }
        }
    }
    cout<<dp[n][m]<<endl; // length of LCS

    // for printing the dp table and direction table
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    // cout<<endl;
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++) cout<<dir[i][j]<<" ";
    //     cout<<endl;
    // }

    // backtracking the LCS string
    string ans="";
    int i=n, j=m;
    while(i>0 and j>0){
        if(dir[i][j]=='D'){ // if direction is diagonal then add the character to the ans string
            ans+=s1[i-1];
            i--; j--;
        }
        else if(dir[i][j]=='U') i--; // if direction is up then move up
        else j--; // if direction is left then move left
    }
    reverse(ans.begin(), ans.end()); // reverse the string to get the correct order
    cout<<ans<<endl;
}