#include <iostream>
#define ll long long
#include<bits/stdc++.h>
using namespace std;

struct j{
    ll start,fin,prof;

};
bool cmp(j a,j b){
    return a.fin<b.fin;
}

ll findlast(j *ar,int i){
    int ans=-1;
    int start=0,last=i-1;
    ll mid;
    while(start<=last){
        mid=(start+last)/2;
        if(ar[mid].fin<=ar[i].start){
            ans=mid;
            start=mid+1;
        }
        else{
            last=mid-1;
        }
    }

    return ans;

}
int main()
{
    ll n;
    cin>>n;
    j ar[n];
    ll dp[n];
    for(int i=0;i<n;i++){
        cin>>ar[i].start>>ar[i].fin>>ar[i].prof;
        dp[i]=0;
    }
    sort(ar,ar+n,cmp);
    dp[0]=ar[0].prof;
    for(int i=1;i<n;i++){
        ll inc=ar[i].prof;
        ll lastind;
        lastind=findlast(ar,i);
       /* for(ll j=i-1;j>=0;j--){
            if(ar[j].fin<=ar[i].start){
                lastind=j;
                break;
            }
        }*/
        if(lastind!=-1){
            inc+=dp[lastind];
        }

        dp[i]=max(dp[i-1],inc);
    }
    cout<<dp[n-1];
    return 0;
}
