#include <iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool ispossible(ll *ar,ll n,ll val,ll k){
ll start=0;
ll end=n-1;
for(ll i=end;k>0 && i>=start ;i--){
    ll temp;
    temp=ar[i]/val;
    k=k-temp;
}
if(k<=0){
    return true;
}

return false;
}
long long int distributecand(long long int *ar,long long int n,long long int k){
    ll start=0;
    ll end=n-1;
    ll mid=0;ll temp=0;
    while(start<=end){
    mid=(ar[start] + ar[end])/2;

    if(ispossible(ar,n,mid,k)==true){
            //temp=(temp < mid) ? mid : temp;
            temp=max(temp,mid);
            start=mid+1;

    }
    else{
        end=mid-1;
        //mid=0;
    }

    }



    return temp;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
            ll n,k;
    cin>>n>>k;
    //ll sum=0;
    ll *ar=new ll[n];
    for(ll i=0;i<n;i++){
        cin>>ar[i];
        //sum+=ar[i];
    }
    sort(ar,ar+n);
    ll ans=distributecand(ar,n,k);
    cout<<ans<<endl;

    }

    return 0;
}
