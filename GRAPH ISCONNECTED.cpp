#include<iostream>
#include<queue>
using namespace std;

bool  isconnectedbfs(int n,int **edges,int sv){
	bool *visit=new bool[n];

	for(int i=0;i<n;i++){
		visit[i]=false;
	}

	queue <int> q;
	q.push(sv);
	visit[sv]=true;
	while(!q.empty()){
	int temp=q.front();
	q.pop();

	//cout<<temp<<" ";
	for(int i=0;i<n;i++){
		if(i==temp){
			continue;
		}
		/*if(visit[i]==true){
			continue;
		}*/

		else if(edges[temp][i]==1 && visit[i]==false){
			q.push(i);
			visit[i]=true;
		}
	}
	}

	for(int i=0;i<n;i++){
		if(visit[i]==false){
			return false;
		}
	}



	delete [] visit;
	return true;

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
	int fir=0;
	for(int i=0;i<e;i++){
		int f,s;
		if(i==0){
			fir=f;
		}
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}

	bool ans=isconnectedbfs(n,edges,fir);
	if(ans==true){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	for(int i=0;i<n;i++){
		delete [] edges[i];

	}
	delete [] edges;

}
