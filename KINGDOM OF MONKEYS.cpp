#include<bits/stdc++.h>
using namespace std;
vector<vector<long>> dp;
vector<bool> vis;
vector<long> mon;
long bfs(long j)
{
    if(vis[j])
    return 0;
    vis[j]=true;
    queue<long> q;
    q.push(j);
    long sum=0;
    while(!q.empty())
    {
        long ff=q.front();
        q.pop();
        sum+=mon[ff];
        for(long i=0;i<dp[ff].size();i++)
        {
            if(!vis[dp[ff][i]])
            {
                vis[dp[ff][i]]=true;
                q.push(dp[ff][i]);
            }

        }
    }
    return sum;



}
int main()
{
    long t;
    cin>>t;
    while(t--)
    {
        long n,m;
        cin>>n>>m;
        dp.resize(n);
        vis.resize(n);
        mon.resize(n);
        for(long i=0;i<m;i++)
        {
            long x,y;
            cin>>x>>y;
            --x;--y;
            dp[x].push_back(y);
            dp[y].push_back(x);
        }
        for(long i=0;i<n;i++)
        {
            cin>>mon[i];
            vis[i]=false;
        }
        long g=0;
        for(long i=0;i<n;i++)
        {
            long tt=bfs(i);
            if(g<tt)
            g=tt;

        }
        cout<<g<<endl;
        dp.clear();
    }



}
/*#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct monk{
int f,s;
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int *ar=new int[n+1];
        vector <int> go[n+1];
        for(int i=0;i<m;i++ ){
            int a,b;
            cin>>a>>b;
            go[a].push_back(b);
            go[a].push_back(b);
        }

        for(int i=1;i<=n;i++){
            cin>>ar[i];
        }

        vector <int> res;
        bool *was=new bool[n+1];
        for(int i=0;i<n;i++){
            was[i]=false;
        }
        for(int k=1;k<=n;k++){
        if(was[k]==true){
            continue;
        }
        vector <int> q;
        int i=0;
        q.push_back(i);
        was[k]=true;
        while(i<q.size()){
                int curr=q[i];i++;
                //q.pop();
                for(int l=0;l<go[curr].size();l++){
                        if(was[go[curr][l]]==false){
                    q.push_back(go[curr][l]);
                    was[go[curr][l]]=true;
                        }
                }

        }
        int sum=0;
        for(int m=0;m<q.size();m++){
            sum+=ar[q[m]];
        }
        res.push_back(sum);
        }
        sort(res.begin(),res.end(),greater <int>());
        //cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;
        cout<<res[0]<<endl;
        //cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;
    }
    return 0;
}
*/
s
