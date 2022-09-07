//BFS implementation using queue & visited array
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> G[N];
bool visited[N];

void BFS_queue(int src){
	vector<int>:: iterator it;
	memset(visited,false,sizeof(visited));
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int ver=q.front();
		q.pop();
		visited[ver]=true;
		cout << ver << " ";
		for(it=G[ver].begin();it!=G[ver].end();it++){
			if(!visited[*it]) q.push(*it);
		}
	}
}

int main(){
	int vertex,edge; cin >> vertex >> edge;
	for(int i=1;i<=edge;i++){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	BFS_queue(0);
}
