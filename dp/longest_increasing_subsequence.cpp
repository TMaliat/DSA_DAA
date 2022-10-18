#include<bits/stdc++.h>
using namespace std;
int t[1001];

int lis(vector<int> &v,int size){
    if(t[size]!=-1) return t[size];
    t[size]=1;
    for(int i=0;i<size;i++){
        if(v[size]>v[i]) t[size]=max(t[size],1+(lis(v,i)));
    }
    return t[size];
}

int main(){
    memset(t,-1,sizeof(t));
    int size; cin >> size;
    vector<int> v(size);
    for(int i=0;i<size;i++) cin >> v[i];
    cout << lis(v,size-1) << endl;
}