#include<bits/stdc++.h>
using namespace std;

bool subset_sum_rec(int arr[], int n, int sum)
{
    if (sum == 0) return true;
    if (n < 0 || sum < 0) return false;

    bool isThere = subset_sum_rec(arr, n - 1, sum - arr[n]);
    bool notThere = subset_sum_rec(arr, n - 1, sum);
    return isThere || notThere;
}

int main()
{
    clock_t start,end;
    start=clock();
    freopen("input4.txt","r",stdin);
    freopen("output4.txt","w",stdout);
    int n,sum; int arr[100];
    cin >> n >> sum;
    for(int i=0;i<n;i++) cin >> arr[i];
    bool is_subset=subset_sum_rec(arr,sum,n);
    cout << is_subset << endl;
    end=clock();
    cout << "The time(milisecond) spent on this algorithm: " << end-start << endl;
}