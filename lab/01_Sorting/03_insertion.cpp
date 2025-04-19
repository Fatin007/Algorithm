// Insertion Sort
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
    for(int i=1; i<n; i++){
        int j=i-1;
        int key=a[i];
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    cout<<"\nSorted array: ";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}