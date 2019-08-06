#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool haspath(int n,int **edges,int sv,int e){
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
	if(temp==e){
		return true;
		}
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
	return false;
	delete [] visit;
}
/*
void pathbfs(int n,int **edges,int sv,int e){
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

	cout<<temp<<" ";
	if(temp==e){
		return;
	}
	for(int i=0;i<n;i++){
		if(i==temp){
			continue;
		}*/
		/*if(visit[i]==true){
			continue;
		}*/

		/*else if(edges[temp][i]==1 && visit[i]==false){
			q.push(i);
			visit[i]=true;
		}
	}
	}

	delete [] visit;
}
*/
/*
void pathdfs(int **edges,int n,int s,int e,bool *visited,vector <int> on){

		if(s==e){
		on.push_back(s);
		return;
		}

	for(int i=0;i<n;i++){
		if(edges[s][i]==1 && visited[i]==false){
			pathdfs(edges,n,i,e,visited,on);
			if(on.empty()){
				continue;
			}
			else{
				on.push_back(i);
			}
		}
	}



}

*/
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
	//int fir=0;
	for(int i=0;i<e;i++){
		int f,s;
		/*if(i==0){
			fir=f;
		}*/
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}

	int from,to;
	cin>>from>>to;
	/*
	if(haspath(n,edges,from,to)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	*/
	//pathbfs(n,edges,to,from);
	vector <int> v;
	bool visited[n];
	pathdfs(edges,n,from,to,visited,v);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	for(int i=0;i<n;i++){
		delete [] edges[i];

	}
	delete [] edges;

}
