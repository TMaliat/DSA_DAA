#include<bits/stdc++.h>
using namespace std;
bool t[100][100];
bool subset_sum(int arr[],long sum,int n){
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

bool equal_sum_partition(int arr[],int n){
    long sum=0;bool res=false;
    for(int i=0;i<n;i++) sum+=arr[i];
    if(sum%2!=0) return false;
    else if(sum%2==0) res=subset_sum(arr,sum/2,n);
    return res;
}

int main(){
    int n; int arr[100];
    cin >> n ; 
    for(int i=0;i<n;i++) cin >> arr[i];
    bool is_equal_partition=equal_sum_partition(arr,n);
    cout << is_equal_partition << endl;
}