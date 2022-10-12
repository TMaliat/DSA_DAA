#include<bits/stdc++.h>
using namespace std;

int lcs_rec(string x,string y,int n,int m){
    if(n==0 || m==0) return 0;
    if(x[n-1]==y[m-1]) return 1+lcs_rec(x,y,n-1,m-1);
    else return max(lcs_rec(x,y,n,m-1),lcs_rec(x,y,n-1,m));
}

int main(){
    clock_t start,end;
    start=clock();
    freopen("input6.txt","r",stdin);
    freopen("output6.txt","w",stdout);
    string x,y; cin >> x >> y;
    int n=x.length(); int m=y.length();
    int len=lcs_rec(x,y,n,m); 
    cout << len << endl;
    end=clock();
    cout << "The time(milisecond) spent on this algorithm: " << end-start << endl;
}