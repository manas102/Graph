/*
Topological Sort: a topological sort or topological ordering of a directed graph is a linear ordering of its vertices such that 
for every directed edge uv from vertex u to vertex v, u comes before v in the ordering (from wiki)

Kahn's Algorithm
1. Records number of incoming edge (indgree) for every node in a list(vector).
2. Pick up the node with no indgree 0 and insert into result ds(vector) || just output it 
3. Remove the node from graph and update the list(ref 1)
4. Repeat 1 to 3 until no node left 
5. If node remains then the graph is not DAG and topological sort is not possible

Code Reference: https://www.youtube.com/watch?v=9Wbej7Fy5Lw
*/

#include<iostream>	
#include<vector>
#include<queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

//if we want a lexiogrphic order of topological sort we can use a priority queue which will increase the time factor by log
//if we want to check whether Graph is DAG or not then we can keep a count on the number of node processed, if all the nodes are not processed then topSort is not possible and not a DAG
void topSort(vvi &adj,vi &inDegree){
	int n = adj.size();
	queue<int> q;
	for(int i=0;i<n;i++){
		if(inDegree[i] == 0)
			q.push(i);
	}
	while(!q.empty()){
		int u = q.front();
		cout<<u<<"-->";
		q.pop();
		for(int v: adj[u]){
			if(--inDegree[v] == 0){
				q.push(v);
			}
		}
	}
	return;
}
int main(){
	int n,e;//no. of nodes, no. of edges in graph
	cin>>n>>e;
	
	vvi adj(n);
	vi inDegree(n,0);
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;//node numbering start from 0
		adj[u].push_back(v);// Directed graph
		inDegree[v]++;
	}
	topSort(adj,inDegree);
	return 0;
}
