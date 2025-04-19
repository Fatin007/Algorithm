// Fractional Knapsack (with STL priority queue)
#include <bits/stdc++.h>
using namespace std;

class cmp{ // Custom comparator for priority queue that sorts based on profit/weight ratio (per unit profit)
public:
    bool operator()(auto &a, auto &b){
        float perA=(float)a.first/a.second;
        float perB=(float)b.first/b.second;
        return perA<perB;
    }
};

int main(){
    // n=number of items, k=capacity of knapsack
    // w[i]=weight of ith item, p[i]=profit of ith item
    int n,k; cin>>n>>k;
    vector<int>w(n),p(n);
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) cin>>p[i];
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp>pq;
    for(int i=0;i<n;i++){
        pq.push({p[i],w[i]});
    }

    float total=0.0;
    while(!pq.empty() and k>0){
        auto [profit,weight]=pq.top();
        pq.pop();
        if(k>=weight){ // If the knapsack can hold the entire item
            total+=profit;
            k-=weight;
        }
        else{ // If the knapsack can only hold a fraction of the item
            total+=(profit*(float)k/weight);
            k=0;
        }
    }
    cout<<total<<endl;
}