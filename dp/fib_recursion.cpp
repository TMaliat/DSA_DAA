#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int fib_recursion(int n){
   if(n==0) return 0;
   if(n==1) return 0;
   if(n==2) return 1;
   else return fib_recursion(n-1)+fib_recursion(n-2);
}

int main(){
   clock_t start,end;
   start=clock();
   freopen("input2.txt","r",stdin);
   freopen("output2.txt","w",stdout);
   int n; cin >> n;
   cout << "Using Recursion:" << endl;
   cout << fib_recursion(n) << endl;
   end=clock();
   cout << "The time(milisecond) spent on this algorithm: " << end-start << endl;
}