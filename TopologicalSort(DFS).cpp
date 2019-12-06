/*
Topological Sort: a topological sort or topological ordering of a directed graph is a linear ordering of its vertices such that 
for every directed edge uv from vertex u to vertex v, u comes before v in the ordering (from wiki)

DFS: 
1. keep a track of states(0= unmarked,1 = in call stack, 2= done) of all nodes. 
2. At begining state of all nodes are 0
3. start dfs from a node and push the node to result ds(stack) after all of its children are processed
4. if there is backedge(refer to reference) then the graph has cycle and topSort not possible
5. when all the nodes are processed, the result is bottom to top of result stack

Code Reference: https://www.youtube.com/watch?v=9Wbej7Fy5Lw
*/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

bool dfs(int u, vvi &adj, vi &state, stack<int> &result){
	if(state[u] == 2) return false;//cross edge
	if(state[u] == 1) return true;//back edge
	
	state[u] = 1;//in call stack
	for(int v: adj[u]){
		if(dfs(v,adj,state,result))
			return true;
	}
	state[u] = 2;//done
	result.push(u);
	return false;
}

//if we want a lexiogrphic order of topological sort we can use a priority queue which will increase the time factor by log
void topSort(vvi &adj){
	int n = adj.size();
	vi state(n,0);
	stack<int> result;
	bool hasCycle = false;
	for(int i=0;i<n;i++){
		if(state[i] == 0)
			hasCycle |= dfs(i,adj,state,result);
	}
	if(!hasCycle){
		while(!result.empty()){
			cout<<result.top()<<"-->";
			result.pop();
		}
	}else{
		cout<<"not a DAG\n";
	}
}
int main(){
	int n,e;//no. of nodes, no. of edges in graph
	cin>>n>>e;
	
	vvi adj(n);
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;//node numbering start from 0
		adj[u].push_back(v);// Directed graph
	}
	topSort(adj);
	return 0;
}
