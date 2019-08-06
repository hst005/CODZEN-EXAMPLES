#include <iostream>

using namespace std;
typedef long long ll;
ll modexponen(ll a,ll b,ll c){
if(b==0){
    return 1;
}
else if(b%2==0){
    return modexponen((a*a)%c,b/2,c)%c;
}
else if(b%2==1){
    return ((a%c)*modexponen((a*a)%c,b/2,c)%c)%c;
}

}

ll modinvp(ll a,ll p){
return modexponen(a,p-2,p);
}

ll boring(ll n,ll p){
if(n>=p){
    return 0;
}
else{
ll sum=1;
for(ll i=n+1;i<p;i++){
    sum=((sum%p)*modinvp(i,p))%p;
}
 return p-((sum+p)%p);
}


}

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n,p;
        cin>>n>>p;
        cout<<boring(n,p)<<endl;


    }
    return 0;
}
