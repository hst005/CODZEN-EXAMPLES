#include <iostream>
#define ll long
using namespace std;

void buildtree(ll *ar,ll start,ll end,ll *tree,ll treenode){
    if(start==end){
        tree[treenode]=ar[start];
        return;
    }
    ll mid=(start+end)/2;
    buildtree(ar,start,mid,tree,2*treenode);
    buildtree(ar,mid+1,end,tree,2*treenode+1);
    tree[treenode]=min(tree[2*treenode],tree[2*treenode+1]);

}


void update(ll *ar,ll start,ll end,ll *tree,ll treenode,ll index,ll val){
    if(start>end || start>index || end<index){
        return;
    }
    if(start==end){
        ar[index]=val;
        tree[treenode]=val;
        return;
    }
    ll mid=(start+mid)/2;
    if(index<=mid){
        update(ar,start,mid,tree,2*treenode,index,val);
    }
    else{
        update(ar,mid+1,end,tree,2*treenode+1,index,val);
    }
    tree[treenode]=min(tree[2*treenode],tree[2*treenode+1]);
}

ll query(ll start, ll end,ll *tree,ll treenode,ll left,ll right){
if(start>right || end<left){
    return INT_MAX;
}
if(start>=left && end<=right){
    return tree[treenode];
}
ll mid=(start+end)/2;
ll ans1=query(start,mid,tree,2*treenode,left,right);

ll ans2=query(mid+1,end,tree,2*treenode+1,left,right);
return min(ans1,ans2);
}
int main()
{
    ll n,q;
    cin>>n>>q;
    ll *ar=new ll[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    ll *tree=new ll[4*n];
    buildtree(ar,0,n-1,tree,1);
    while(q--){
        char ask;cin>>ask;
        int c,d;
        cin>>c>>d;
        if(ask=='q'){
            cout<<query(0,n-1,tree,1,c-1,d-1)<<endl;
        }
        else{
            update(ar,0,n-1,tree,1,c-1,d);
        }
    }
    return 0;
}
