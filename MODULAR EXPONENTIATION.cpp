#include <iostream>
#define m 1000000007
using namespace std;
typedef long long ll;

ll modrecursive(ll a,ll b,ll c){
if (b==0){
    return 1;
}
if(b%2==0){
    return (modrecursive((a*a)%c,b/2,c))%c;
}
else {
    return ((a%c)*modrecursive((a*a)%c,b/2,c))%c; //kyunki odd ke case mein b-1/2 aur b/2 same hai
 }
}

ll moditerative(ll a,ll b,ll c){
    ll ans;
    while(b>0){
        a=a*a;
        b=b/2;

    }

}


int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<modrecursive(a,b,c);
    return 0;
}
