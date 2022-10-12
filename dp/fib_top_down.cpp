#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[N];

int fib_tab(int n){
    vector <long long> dp(n+1);
        dp[0]=0;dp[1]=1;
        for (long long i=2; i<=n; i++) dp[i] = (dp[i-1] + dp[i-2])%1000000007;
    return dp[n];
}

int main(){
   clock_t start,end;
   start=clock();
   freopen("input2.txt","r",stdin);
   freopen("output2.txt","w",stdout);
   for(int i=0;i<N;i++) dp[i]=-1;
   int n; cin >> n;
   cout << "Using Tabulation:" << endl;
   cout << fib_tab(n) << endl;
   end=clock();
   cout << "The time(milisecond) spent on this algorithm: " << end-start << endl;
}