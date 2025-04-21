#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
// int dp[N][N];
map<pair<int, int>, int> dp;
map<pair<int, int>, int> bracket;

int MCM(vector<int> &a, int i, int j){
   if(i == j) return 0;
   // if(dp[i][j]!=0) return dp[i][j];
   if(dp[{i, j}]) return dp[{i, j}];
   int mn=INT_MAX;
   for(int k=i; k<j; k++){
      int left=MCM(a, i, k);
      int right=MCM(a, k+1, j);
      int cost=left+right+a[i-1]*a[k]*a[j];
      if(cost<mn){
         mn=cost;
         bracket[{i, j}]=k;
      }
   }
   // return dp[i][j]=mn;
   return dp[{i, j}]=mn;
}

void printBracket(int i, int j){
   if(i == j) cout<<char('A'+i-1);
   else{
      cout<<"(";
      printBracket(i, bracket[{i, j}]);
      printBracket(bracket[{i, j}]+1, j);
      cout<<")";
   }
}

int main(){
   int n; cin>>n;
   vector<int> a(n+1);
   for(auto &i : a) cin>>i;
   cout<<"Minimum multiplication cost: "<<MCM(a, 1, n)<<endl;
   cout<<"Bracketing: ";
   printBracket(1, n);
   cout<<endl;
}