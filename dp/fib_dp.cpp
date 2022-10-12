#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[N];
int fib_dp(int n){
   if(n==0) return 0;
   if(n==1) return 0;
   if(n==2) return 1;
   if(dp[n]!=-1) return dp[n];
   else dp[n]=fib_dp(n-1)+fib_dp(n-2);
   return dp[n];
}

int main(){
   clock_t start,end;
   start=clock();
   freopen("input2.txt","r",stdin);
   freopen("output2.txt","w",stdout);
   for(int i=0;i<N;i++) dp[i]=-1;
   int n; cin >> n;
   cout << "Using DP:" << endl;
   cout << fib_dp(n) << endl;
   end=clock();
   cout << "The time(milisecond) spent on this algorithm: " << end-start << endl;
}