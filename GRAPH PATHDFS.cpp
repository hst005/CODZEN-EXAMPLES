#include<vector>
#include<iostream>
//abhi kaafi galtiyan hai isme
using namespace std;

vector<int>* getPathHelper(int** edges, int n, int sv, int ev, bool* visited) {
	if (sv == ev) {
		vector<int>* output = new vector<int>();
		output->push_back(ev);
		return output;
	}
	visited[sv] = true;
	for (int i = 0; i < n; i++) {
		if (edges[sv][i] && !visited[i]) {
			vector<int>* smallOutput = getPathHelper(edges, n, i, ev, visited);
			if (smallOutput != NULL) {
				smallOutput->push_back(sv);
				return smallOutput;
			}
		}
	}
	return NULL;
}

vector<int>* getPath(int** edges, int n, int sv, int ev) {
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	vector<int>* output = getPathHelper(edges, n, sv, ev, visited);
	delete [] visited;
	return output;
}

int main() {
	int n; int e; cin >> n >> e;
	int** edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++) {
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	int sv, ev;
	cin >> sv >> ev;
	vector<int>* output = getPath(edges, n, sv, ev);
	if (output != NULL) {
		for (int i = 0; i < output->size(); i++) {
			cout << output->at(i) << " ";
		}

		 delete output;
	 }

	 for (int i = 0; i < n; i++) {
		 delete [] edges[i];
	 }

	 delete [] edges;

 }

/*
vector<int> dfspath(int **edges,int n,int from,int to,bool *visit){
	if(from==to){
		vector <int> out;
		out.push_back(from);
		return out;
	}
	visit[from]=true;
	for(int i=0;i<n;i++){
		if(edges[from][i]==1 && visit[i]==false){
			vector <int> small=dfspath(edges,n,i,to,visit);
			if(!small.empty()){
			small.push_back(i);
			return small;
			}
		}
	}
	vector <int> ab;
	return ab;
}


vector<int> pathdfs(int **edges,int n,int from,int to){
	bool visit[n];
	for(int i=0;i<n;i++){
		visit[i]=false;
	}
	vector <int> ot=dfspath(edges,n,from,to,visit);
	return ot;
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

	int from,to;
	cin>>from>>to;
	vector <int> v=pathdfs(edges,n,from,to);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	for(int i=0;i<n;i++){
		delete [] edges[i];

	}
	delete [] edges;

}*/
