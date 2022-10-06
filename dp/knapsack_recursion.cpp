#include<bits/stdc++.h>
using namespace std;
int knapsack_rec(int wt[],int val[],int w,int n){
    if(n==0 || w==0) return 0;
    if(wt[n-1]<=w) return max(val[n-1]+knapsack_rec(wt,val,w-wt[n-1],n-1),knapsack_rec(wt, val,w,n-1));
    else return knapsack_rec(wt,val,w,n-1);
}

int main(){
    int wt[100],val[100],w,n; cin >> n >> w;
    for(int i=0;i<n;i++){
        cin >> wt[i] ;
    }
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    int profit=knapsack_rec(wt,val,w,n);
    cout << profit << endl;
}
