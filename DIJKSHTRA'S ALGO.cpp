#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int findminver(int *d,bool *visited,int n){
	int max=INT_MAX;
	int ind=-1;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			if(max>d[i]){
			max=d[i];
			ind=i;
			}
		}
	}
	return ind;
}


void dijkshtra(int **edges,int n){
	bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	int *dist=new int[n];
	dist[0]=0;
	for(int i=1;i<n;i++){
		dist[i]=INT_MAX;
	}

	for(int i=0;i<n-1;i++){
		int curr=findminver(dist,visited,n);
		visited[curr]=true;
		for(int j=0;j<n;j++){
			//if(!visited[j] && dist[j]>dist[curr]+edges[curr][j]){
			if(!visited[j] && edges[curr][j]!=0){
				int d=dist[curr]+edges[curr][j];
				if(d<dist[j]){
					dist[j]=d;
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<i<<" "<<dist[i]<<endl;
	}
	delete [] visited;
	delete [] dist;
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
		int f,s,wgt;

		cin>>f>>s>>wgt;
		edges[f][s]=wgt;
		edges[s][f]=wgt;
	}

	dijkshtra(edges,n);
	for(int i=0;i<n;i++){
		delete [] edges[i];

	}
	delete [] edges;
	return 0;
}
