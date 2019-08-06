#include<iostream>
//#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007


using namespace std;
ll modular_pow(ll base, ll exponent, int modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

ll gcd(ll a,ll b){
	if(b>a){
		return gcd(b,a);
	}
	else if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

ll llgcdmod(ll a,ll b,ll n ){
	return gcd(modular_pow(a,n,mod)+modular_pow(b,n,mod),a-b);
}

int main(){
	int t;
	cin>>t;
	//cout<<gcd(1,5)<<" "<<gcd(15,5)<<" "<<gcd(111,5)<<" "<<gcd(21,63)<<" ";
	while(t--){
	ll a,b,n;
		cin>>a>>b>>n;
		cout<<llgcdmod(a,b,n)<<endl;
	}

	return 0;
}
