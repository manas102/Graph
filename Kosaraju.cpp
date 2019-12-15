/*
Kosaraju using dfs and bfs
Kosaraju's Algorithm: Kosaraju's algorithm (also known as the Kosaraju–Sharir algorithm) is a linear time algorithm to find the strongly connected components of a directed graph

Reference: https://www.youtube.com/watch?v=9Wbej7Fy5Lw
*/
#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using qi = queue<int>;
using vb = vector<bool>;
using si = stack<int>;

void dfs(int u, vvi &adj, vb &visited, si &order){
	if(visited[u]) return;
	visited[u] = true;
	for(int v: adj[u]){
		dfs(v,adj,visited,order);
	}
	order.push(u);
}
void kosaraju(vvi &adj,vvi &rAdj){
	int n = adj.size();
	si order;
	vb visited(n,false);
	for(int i=0;i<n;i++){
		dfs(i,adj,visited,order);
	}
	int count = 0;
	vi ids(n,-1);
	qi q;
	while(!order.empty()){
		int u = order.top();order.pop();
		if(ids[u] != -1) continue;
		q.push(u);
		ids[u] = count;
		while(!q.empty()){
			int v= q.front();q.pop();
			for(int i: rAdj[v]){
				if(ids[i] == -1){
					ids[i] =  count;
					q.push(i);	
				}
			}
		}
		count++;	
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<i<<" : "<<ids[i]<<endl;
	}
	return;
}
int main(){
	int n,e;//number of nodes and edges respectively
	cin>>n>>e;
	
	vvi adj(n),rAdj(n);
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;//node numbering starts from 0
		adj[u].push_back(v);
		rAdj[v].push_back(u);
	}
	kosaraju(adj,rAdj);
	return 0;
}
