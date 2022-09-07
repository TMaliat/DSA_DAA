#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef pair<int,int> p;
vector<p> G[N];
const int INF=99999;

void dijkstra_BFS(int src,int vertex){
    priority_queue<p,vector<p>,greater<p>> pq;
    vector<int> dist(vertex,INF);
    vector<p>::iterator it;
    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty()){
        int u=pq.top().second; pq.pop();
        for(it=G[u].begin();it!=G[u].end();++it){
            int v=(*it).first;
            int weight=(*it).second;
            if(dist[u]+weight<dist[v]){
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < vertex; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main(){
    int vertex,edge; cin >> vertex >> edge;
    for(int i=1;i<=edge;i++){
        int u,v,w;cin >> u >> v >> w;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    dijkstra_BFS(0,vertex);
}
