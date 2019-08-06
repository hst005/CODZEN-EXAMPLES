//#include <bits/stdc++.h>
#include<vector>
//#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define max 100005

int main() {
	int t,i0;
	cin>>t;
	for(i0=0;i0<t;i0++) {
		int n,m,i,j;
		cin>>n>>m;
		vector <int> brid[max];
		for(i=0;i<m;i++) {
			int x,y;
			cin>>x>>y;
			brid[x].push_back(y);
			brid[y].push_back(x);
		}
		//cout<<bfs(1,n)<<endl;
		queue <int> q;
		int level[max];
		bool visited[max];
		for(i=0;i<max;i++) {
			visited[i]=false;
		}
		q.push(1);
		visited[1]=true;
		level[1]=0;
		while(!q.empty()) {
			int p=q.front();
			q.pop();

			for(i=0;i<brid[p].size();i++) {
				if(visited[brid[p][i]]==false) {
					level[brid[p][i]]=level[p] + 1;
					q.push(brid[p][i]);
					visited[brid[p][i]]=true;
				}

			 }
		  }
			cout<<level[n]<<endl;
		}
	 }


/*#include<vector>
//#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#include<queue>
//#define pb push_back;


using namespace std;


//int shortest(vector <int> brid[n+])
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> brid[n+1];
		for(int i=1;i<=m;i++){
			int a,b;
			cin>>a>>b;
			brid[a].push_back(b);
			brid[b].push_back(a);
		}
		queue <int> q;
		bool *visit=new bool[n+1];
		for(int i=0;i<=n;i++){
			visit[i]=false;
		}
		int st=1;
		visit[1]=true;
		q.push(1);
		map <int,int> parent;
		pair <int,int> t;
		t.first=st;
		t.second=-1;
		bool done=false;
		while(!q.empty() && !done){
			int curr=q.front();
			q.pop();

			for(int i=0;i<brid[curr].size();i++){
				if(!visit[brid[curr][i]]){
				visit[brid[curr][i]]=true;
				q.push(brid[curr][i]);
				pair <int,int> temp;
				temp.first=brid[curr][i];
				temp.second=curr;
				parent.insert(temp);
				if(brid[curr][i]==n){
					done=true;
					break;
				}
			}
			}
		}
		int ans=0;
		if(done==true){
			int temp2=n;
			while(temp2!=-1){
				ans++;
				temp2=parent[temp2];
			}

		cout<<ans<<endl;
		}

	}

	return 0;
}*/
