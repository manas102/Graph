/*
Kosaraju using dfs and dfs
Kosaraju's algorithm (also known as the Kosaraju–Sharir algorithm) is a linear time algorithm to find the strongly connected components of a directed graph

Reference: https://www.youtube.com/watch?v=9Wbej7Fy5Lw
*/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using si = stack<int>;

si order;

void dfs(int u,vvi &adj,vb &visited){
	visited[u] = true;
	for(int v: adj[u]){
		if(!visited[v])
			dfs(v,adj,visited);
	}
	order.push(u);
}

void dfs2(int u,vvi &adj,vi &ids, int count){
	ids[u] = count;
	for(int v: adj[u]){
		if(ids[v] == -1)
			dfs2(v,adj,ids,count);
	}
}
void kosaraju(vvi &adj, vvi &rAdj){
	int n = adj.size();
	vb visited(n,false);
	for(int i=0;i<n;i++){
		if(!visited[i])
			dfs(i,adj,visited);//considered node indexing start from 0	
	}
	vi ids(n,-1);
	int count = 0;
	while(!order.empty()){
		int u = order.top();order.pop();
		if(ids[u] == -1){
			dfs2(u,rAdj,ids,count);
			count++;
		}
	}
	for(int i=0;i<n;i++){
		cout<<i<<" : "<<ids[i]<<endl;
	}
	return;
}
int main(){
	int n,e;//nodes and edges
	cin>>n>>e;
	
	vvi adj(n),rAdj(n);
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		rAdj[v].push_back(u);
	}
	kosaraju(adj,rAdj);
	return 0;
}
