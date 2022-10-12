#include<bits/stdc++.h>
using namespace std;
//int t[100][100];

int rod_cutting_top_down(int len[],int price[],int length,int n){
    int t[length+1];
    memset(t,0,sizeof(t));

    for(int i=0;i<length+1;i++){
        for(int j=0;j<n;j++){
            if(len[j]<=i)
            t[i]=max(t[i],t[i-len[j]]+price[j]);
        }
    }
    return t[length];
}

int main(){
    clock_t start,end;
    start=clock();
    freopen("input3.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    int len[100],price[100],length,n; cin >> n >> length;
    for(int i=0;i<n;i++){
        len[i]=i+1;
    }
    for(int i=0;i<n;i++){
        cin >> price[i];
    }
    int profit=rod_cutting_top_down(len,price,length,n);
    cout << profit << endl;
    end=clock();
    cout << "The time(milisecond) spent on this algorithm: " << end-start << endl;
}