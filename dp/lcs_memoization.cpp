#include<bits/stdc++.h>
using namespace std;
int t[100][100];

int lcs_memoization(string x,string y,int n,int m){
    if(n==0 || m==0) return 0;
    if(t[n][m]!=-1) return t[n][m];
    else{
        if(x[n-1]==y[m-1]) t[n][m]= 1+lcs_memoization(x,y,n-1,m-1);
        else t[n][m]=max(lcs_memoization(x,y,n,m-1),lcs_memoization(x,y,n-1,m));
    }
    return t[n][m];
}

int main(){
    clock_t start,end;
    start=clock();
    freopen("input6.txt","r",stdin);
    freopen("output6.txt","w",stdout);
    string x,y; cin >> x >> y;
    int n=x.length(); int m=y.length();
    memset(t,-1,sizeof(t));
    int len=lcs_memoization(x,y,n,m); 
    cout << len << endl;
    end=clock();
    cout << "The time(milisecond) spent on this algorithm: " << end-start << endl;
}