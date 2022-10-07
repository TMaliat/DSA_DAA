#include<bits/stdc++.h>
using namespace std;
bool t[100][100];
bool subset_sum(int arr[],int sum,int n){
    for(int j=1;j<sum+1;j++) t[0][j]=false;
    for(int i=0;i<n+1;i++) t[i][0]=true;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j) t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}

int main(){
    int n,sum; int arr[100];
    cin >> n >> sum;
    for(int i=0;i<n;i++) cin >> arr[i];
    bool is_subset=subset_sum(arr,sum,n);
    cout << is_subset << endl;
}