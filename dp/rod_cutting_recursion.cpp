#include <bits/stdc++.h>
using namespace std;

int rod_cutting_recursion(int price[], int index, int n)
{
	if (index == 0) return n * price[0];
	int notCut = rod_cutting_recursion(price,index - 1,n);
	int cut = INT_MIN;
	int rod_length = index + 1;

	if (rod_length <= n)
		cut = price[index]+ rod_cutting_recursion(price,index,n - rod_length);
	return max(notCut, cut);
}
int main()
{
    clock_t start,end;
    start=clock();
    freopen("input3.txt","r",stdin);
    freopen("output3.txt","w",stdout);
	int len[100],price[100],length,n; cin >> n >> length;
    for(int i=0;i<n;i++) len[i]=i+1;
    for(int i=0;i<n;i++) cin >> price[i];
    int profit=rod_cutting_recursion(price,length,n);
    cout << profit << endl;
    end=clock();
    cout << "The time(milisecond) spent on this algorithm: " << end-start << endl;
}

