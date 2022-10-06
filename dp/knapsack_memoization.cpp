#include<bits/stdc++.h>
using namespace std;
int t[100][100];
int knapsack_memoization(int wt[],int val[],int w,int n){
    if(n==0 || w==0) return 0;
    if(t[n][w]!=-1) return t[n][w];
    if(wt[n-1]<=w) t[n][w]=max(val[n-1]+knapsack_memoization(wt,val,w-wt[n-1],n-1),knapsack_memoization(wt, val,w,n-1));
    else t[n][w]=knapsack_memoization(wt,val,w,n-1);
    return t[n][w];
}

int main(){
    int wt[100],val[100],w,n; cin >> n >> w;
    for(int i=0;i<n;i++){
        cin >> wt[i] ;
    }
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    memset(t,-1,sizeof(t));
    int profit=knapsack_memoization(wt,val,w,n);
    cout << profit << endl;
}
