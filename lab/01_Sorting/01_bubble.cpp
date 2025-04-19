// bubble sort
#include<bits/stdc++.h>
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
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
    cout<<"\nSorted array: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}