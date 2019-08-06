#include<iostream>
#include<queue>
#include<map>
using namespace std;

vector<int> *pathbfs(int n,int **edges,int sv,int ev){
	bool *visit=new bool[n];
	map <int,int> temp;
	for(int i=0;i<n;i++){
		visit[i]=false;
	}

	queue <int> q;
	q.push(sv);
	visit[sv]=true;
	while(!q.empty()){
	int temp=q.front();
	q.pop();
	if(temp==ev){
		vector<int> *ot=new vector();
		int t=ev;
		ot.push_back(t);
		t=temp[t];
		while(t>=0){
			ot.push_back(t);
			t=temp[t];
		}
		return ot;
	}
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
			pair <int,int> abc;
			abc.first=temp;
			abc.second=i;
			temp.insert(abc);
			visit[i]=true;
		}
	}
	}

	delete [] visit;

	return NULL;
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
	vector <int>* output=pathbfs(n,edges,from,to);

	for(int i=0;i<output.size();i++){
		cout<<output[i];
	}
	for(int i=0;i<n;i++){
		delete [] edges[i];

	}
	delete [] edges;

}
