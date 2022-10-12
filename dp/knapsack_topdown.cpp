#include<bits/stdc++.h>
using namespace std;
int t[100][100];

int knapsack_topdown(int wt[],int val[],int w,int n){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j) t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][w];
}

int main(){
    clock_t start,end;
    start=clock();
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    int wt[100],val[100],w,n; cin >> n >> w;
    for(int i=0;i<n;i++){
        cin >> wt[i] ;
    }
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    int profit=knapsack_topdown(wt,val,w,n);
    cout << profit << endl;
    end=clock();
    cout << "The time(milisecond) spent on this algorithm: " << end-start << endl;
}