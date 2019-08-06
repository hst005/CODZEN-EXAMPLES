#include <iostream>
#define ll long long
#define mod2 4294967296
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    ll temp,pres;

    ll tv,pv;
    tv=0;
    pv=((tv%m)*a + b)%mod2;
    pres=pv/256;
    ll prof=0;

    while(n--){
            tv=pv;
            pv=((tv%m)*a + b)%mod2;
            temp=pv/256;
            if(pv>tv){
                prof+=temp-pres;
                pres=temp;
            }
    }
    cout<<prof;
    return 0;
}
