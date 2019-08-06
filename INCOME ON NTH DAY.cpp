#include <iostream>
#define mod 1000000007
using namespace std;
typedef long long ll;

ll income(ll f0,ll f1,ll n){
if(n==0){
    return f0;
}
else if(n==1){
    return f1;
}
else{
    return (income(f0,f1,n-1)%mod+income(f0,f1,n-2)%mod+(income(f0,f1,n-2)%mod*income(f0,f1,n-1)%mod)%mod)%mod;
}
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll f0,f1,n;
        cin>>f0>>f1>>n;
        cout<<income(f0,f1,n)<<endl;

    }
    return 0;
}
