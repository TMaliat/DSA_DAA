#include<bits/stdc++.h>
using namespace std;
const int INF=999999;
typedef pair<int, int> p;
void primMST(vector<pair<int,int> > adj[], int V)
{
    priority_queue< p, vector <p> , greater<p> > pq;
 
    int src = 0; 
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
          if(inMST[u] == true){
            continue;
        }
       
        inMST[u] = true; 
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
 
    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

int main()
{
    //int V = 9;
    int V,E; cin >> V >> E;
    vector<p> adj[V];
    for(int i=1;i<=E;i++){
        int u,v,wt; cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }
 
    primMST(adj, V);
}
