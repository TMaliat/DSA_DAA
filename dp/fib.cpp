#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int fib_tab(int n){
    vector <long long> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for (long long i=2; i<=n; i++)
        {
            dp[i] = (dp[i-1] + dp[i-2])%1000000007;
        }return dp[n];
}

int dp[N];

int fib(int n){
    if(n==0) return 0;
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    //else return fib(n-1)+ fib(n-2);
    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];
}

int main(){
    int n; cin >> n;
    for(int i=0;i<N;i++) dp[i]=-1;
    cout << fib(n) << endl;
    cout<<"Using tabulation method" << endl;
    cout <<fib_tab(n) << endl;
}
