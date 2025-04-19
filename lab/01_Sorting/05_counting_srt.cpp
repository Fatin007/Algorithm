// Counting Sort (Extra)
#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the number of elements: ";
    int n, mx=-9999999969; cin>>n;
    int a[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    cout<<"Before Sort: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    int cnt[mx+1]={0}; // Count array
    for(int i=0;i<n;i++) cnt[a[i]]++; 
    cout<<"After Sort: ";
    for(int i=1; i<=mx; i++){
        while(cnt[i]--) cout<<i<<" ";
    }
}