
#include <iostream>
#include <bits/stdc++.h>
#define m 1000000007
#define max7 750000
using namespace std;
typedef long long int ll;

ll goodsets(ll *uni,ll *ar,ll n){
    for(ll i=0;i<n;i++){
        uni[ar[i]]=1;
    }
    for(ll i=0;i<n;i++){
            if(uni[ar[i]]>0){
                for(ll j=ar[i]*2;j<=ar[n-1];j=j+ar[i]){
                    if(uni[j]>0){
                        uni[j]+=uni[ar[i]];
                    }
                }
            }

    }
    ll sum=0;
    for(ll i=0;i<n;i++){
        sum=(sum+(uni[ar[i]]%m))%m;
    }
    return sum;
}
int main()
{
    int t;
    cin>>t;
    ll *uni=new ll[max7];

    while(t--){
        ll n;
        cin>>n;
    fill_n(uni,max7,0);
        ll *ar=new ll[n];
        for(ll i=0;i<n;i++){
            cin>>ar[i];
        }
        sort(ar,ar+n);
    cout<<goodsets(uni,ar,n)<<endl;
    }
    return 0;
}

/*
#include <iostream>
#include <bits/stdc++.h>
#define m 1000000007
#define max7 750000
using namespace std;
typedef long long int ll;

ll goodsets(ll *uni,ll *ar,ll n){
    fill_n(uni,n,0);
    for(ll i=0;i<n;i++){
        uni[ar[i]]=1;
    }
    for(ll i=0;i<n;i++){
            if(uni[ar[i]]>0){
                for(ll j=i*2;j<=ar[n-1];j=j+i){
                    if(uni[j]>0){
                        uni[j]+=uni[ar[i]];
                    }
                }
            }

    }
    ll sum=0;
    for(ll i=0;i<n;i++){
        sum=(sum+(uni[ar[i]]%m))%m;
    }
    return sum;
}
int main()
{
    int t;
    cin>>t;
    //ll *uni=new ll[max7];
    //fill_n(uni,max7,0);
    while(t--){
        ll n;
        cin>>n;

        ll *ar=new ll[n];
        for(ll i=0;i<n;i++){
            cin>>ar[i];
        }
        sort(ar,ar+n);
        ll *uni=new ll[ar[n-1]];
    cout<<goodsets(uni,ar,n)<<endl;
    }
    return 0;
}
*/
