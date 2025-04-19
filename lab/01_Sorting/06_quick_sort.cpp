// Quick Sort (Extra)
#include<bits/stdc++.h>
using namespace std;

int partition(int *a, int l, int r){
    int pivot=a[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quick_sort(int *a, int l, int r){
    if(l>=r) return;
    int pi=partition(a,l,r);
    quick_sort(a,l,pi-1);
    quick_sort(a,pi+1,r);
}

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<"Before Sort: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    quick_sort(a,0,n-1);
    cout<<"\nAfter Sort: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}