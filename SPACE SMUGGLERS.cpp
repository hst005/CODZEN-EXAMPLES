#include <iostream>
#define ll long long
#define mod 1000000007
using namespace std;

ll findminver(ll *d,bool *visited,ll n){
	ll max=INT_MAX;
	ll ind=-1;
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

ll dijkshtra(ll **edges,ll n,ll s,ll e){
	bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	ll *dist=new ll[n];
	dist[s]=0;
	for(int i=0;i<n;i++){
            if(i!=s){
                dist[i]=INT_MAX;
            }
	}

	for(int i=0;i<n-1;i++){
		ll curr=findminver(dist,visited,n);
		visited[curr]=true;
		for(int j=0;j<n;j++){
			//if(!visited[j] && dist[j]>dist[curr]+edges[curr][j]){
			if(!visited[j] && edges[curr][j]!=0){
				ll d=dist[curr]+edges[curr][j];
				if(d<dist[j]){
					dist[j]=d;
				}
			}
		}
	}

	ll temp=dist[e];
	delete [] visited;
	delete [] dist;
	return temp;
}



ll space(ll **edges,ll n,ll s,ll t){
    ll ans=INT_MAX;
    ll via=0;
    for(ll i=1;i<=n;i++){
        if(i==t || i==s){
            continue;
        }
        ll t1=dijkshtra(edges,n+1,s,i);
        ll t2=dijkshtra(edges,n+1,i,t);
        ll t3=dijkshtra(edges,n+1,t,i);
        ll t4=dijkshtra(edges,n+1,i,s);
        ll d=(t1%mod+t2%mod+t3%mod+t4%mod)%mod;
        if(d<ans){
            via=i;
            ans=d;
        }
    }
   // cout<<via;
    return ans;
}
int main()
{
    ll n,m,s,t;
    cin>>n>>m>>s>>t;
    ll **edges=new ll*[n+1];
    for(int i=0;i<=n;i++){
        edges[i]=new ll[n+1];
        for(int j=0;j<=n;j++){
            edges[i][j]=0;
        }
    }
    for(int k=0;k<m;k++){
        ll a,b,c;
        cin>>a>>b>>c;
        edges[a][b]=c;
    }
    cout<<space(edges,n,s,t);

    return 0;
}
