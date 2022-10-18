#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int i,int j){
    if(i>=j) return 0;
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(temp<mn) mn=temp;
    }
    return mn;
}

int main(){
    int size; cin >> size; int arr[1000];
    for(int i=0;i<size;i++) cin >> arr[i];
    int cost=solve(arr,1,size-1); 
    cout << cost << endl;
}