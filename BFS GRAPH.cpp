#include<iostream>
#include<queue>
using namespace std;

void edges(int n,int **edges,bool *visit,int sv){
	queque <int> next;
	q.push(sv);
	while(!q.empty()){
	int temp=q.pop();
	cout<<temp<<" ";
	for(int i=0;i<n;i++){
		if(visited[i]==true){
			continue;
		}
		if(edges[temp][i]==1){
			q.push(i);
			visited[i]=1;
		}
	}
	}
}

int main(){
	int n,e;
	cin>>n>>e;

	int **edges=new int*[n];
	for(int i=0;i<n;i++){
		edges[i]=new int[n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}

	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	bool *visit=new bool[n];
	for(int i=0;i<n;i++){
		visit[i]=false;
	}
	bfs(n,edges,visit);

}
