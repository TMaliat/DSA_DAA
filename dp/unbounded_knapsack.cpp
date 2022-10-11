#include<bits/stdc++.h>
using namespace std;
//int t[100][100];

int knapsack_unbounded(int wt[],int val[],int w,int n){
    int t[w+1];
    memset(t,0,sizeof(t));

    for(int i=0;i<w+1;i++){
        for(int j=0;j<n;j++){
            if(wt[j]<=i)
            t[i]=max(t[i],t[i-wt[j]]+val[j]);
        }
    }
    return t[w];
}

int main(){
    int wt[100],val[100],w,n; cin >> n >> w;
    for(int i=0;i<n;i++){
        cin >> wt[i] ;
    }
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    int profit=knapsack_unbounded(wt,val,w,n);
    cout << profit << endl;
}

//answer was supposed to be 300 but 500 is the output
