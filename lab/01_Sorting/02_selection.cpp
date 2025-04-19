// Selection Sort
#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the number of elements: ";
    int n; cin>>n;
    int a[n];
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<"Original array: ";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    for(int i=0;i<n;i++){
        int mn_idx=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mn_idx]) mn_idx = j;
        }
        swap(a[i],a[mn_idx]);
    }
    cout<<"\nSorted array: ";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}