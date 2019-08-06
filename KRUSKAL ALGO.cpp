#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct edge{
int from,to,wgt;
};

bool cmp(edge a,edge b){
return a.wgt<b.wgt;
}
/*
int getpar(int vert1,int *parent){
	while(parent[vert1]!=vert1){
		vert1=parent[vert1];
	}

return parent[vert1];
}*/

int getpar(int vert1,int *parent){
	if(parent[vert1]==vert1){
		return vert1;
	}

return getpar(parent[vert1],parent);
}


bool checkcycle(edge abc,int *parent){
int vert1,vert2;
vert1=abc.from;
vert2=abc.to;
if(getpar(vert1,parent)==getpar(vert2,parent)){
	return true;
}
return false;
}

void mstkruskal(edge *in,int n,int e){
	edge *out=new edge[n-1];
	int *parent=new int[n];
	for(int i=0;i<n;i++){
		parent[i]=i;
	}
	int j=0;
	for(int i=0;i<e;i++){
		if(checkcycle(in[i],parent)){
			continue;
		}
		else{
			int p1=getpar(in[i].from,parent);
			int p2=getpar(in[i].to,parent);
			parent[p1]=p2;
			out[j++]=in[i];
			if(j==n-1){
				break;
			}
		}

	}
	for(int i=0;i<e-1;i++){
		if(out[i].from<out[i].to){
			cout<<out[i].from<<" "<<out[i].to<<" "<<out[i].wgt<<endl;
		}
		else {
			cout<<out[i].to<<" "<<out[i].from<<" "<<out[i].wgt<<endl;
		}
	}

	delete [] out;

}
int main(){
	int n,e;
	cin>>n>>e;

	edge in[e];
	for(int i=0;i<e;i++){
		cin>>in[i].from>>in[i].to>>in[i].wgt;
	}
	sort(in,in+e,cmp);


	//edge out=new edge[n-1];
	//out=
		mstkruskal(in,n,e);
		/*
	for(int i=0;i<e;i++){
		cout<<out[i].from<<" "<<out[i].to<<" "<<out[i].wgt<<endl;
	}
	delete [] out;
*/	return 0;

}
