// Merge Sort
#include <bits/stdc++.h>
using namespace std;

void Merge(int *a, int l, int r, int m){
    int i=l;
    int j=m+1;
    int tmp[r-l+1]; // size of the segment to be merged = r-l+1
    int k = 0;

    while(i<=m&&j<=r){ // while both segments have elements to compare
        // tmp[k++]=(a[i]<a[j]) ? a[i++] : a[j++];  // eita shortcut
        if(a[i]<a[j]){
            tmp[k]=a[i];
            k++;
            i++;
        }
        else{
            tmp[k]=a[j];
            k++;
            j++;
        }
    }
    
    while(i<=m){
        tmp[k]=a[i];
        k++;
        i++;
    }
    while(j<=r){
        tmp[k]=a[j];
        k++;
        j++;
    }
    
    // Uporer duita loop er shortcut holo nicher duita
    // while(i<=m) tmp[k++]=a[i++];
    // while (j<=r) tmp[k++]=a[j++];

    k=0;
    for(int x=l;x<=r;x++) a[x]=tmp[k++];
}

void divide(int *a, int l, int r){
    if(l==r) return;
    int m=(l+r)/2;
    divide(a,l,m);
    divide(a,m+1,r);
    Merge(a,l,r,m);
}

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    cout<<"Before Sort: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";

    int l=0;
    int r=n-1;
    divide(a,l,r);

    cout<<"\nAfter Sort: ";
    for(int i=0; i<n;i++) cout<<a[i]<<" ";
}
