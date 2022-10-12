#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

int rod_cutting_dp(int price[], int index, int n)
{
    dp[index+1][n+1];
    for(int i=0;i<index+1;i++){
        for(int j=0;j<n+1;j++) dp[i][j]=-1;
    }
    if (index == 0) {
        return n * price[0];
    }
    if (dp[index][n] != -1)
        return dp[index][n];
    int notCut = rod_cutting_dp(price, index - 1, n);
    int cut = INT_MIN;
    int rod_length = index + 1;
 
    if (rod_length <= n)
        cut = price[index]+ rod_cutting_dp(price, index, n - rod_length);
 
    return dp[index][n]=max(notCut, cut);
    
}

int main()
{
    clock_t start,end;
    start=clock();
    freopen("input3.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    int len[100],price[100],index,n; cin >> n >> index;
    for(int i=0;i<n;i++){
        len[i]=i+1;
    }
    for(int i=0;i<n;i++){
        cin >> price[i];
    }
    int profit=rod_cutting_dp(price,index,n);
    cout << profit << endl;
    end=clock();
   cout << "The time(milisecond) spent on this algorithm: " << end-start << endl;
}