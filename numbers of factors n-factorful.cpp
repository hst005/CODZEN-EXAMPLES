#include <iostream>
#include<bits/stdc++.h>
#define max6 1000001
#define pb push_back
#define MAX 1000001
typedef long long ll;
typedef long l;

using namespace std;

vector<int>* sieve(){
	bool isPrime[MAX];

	vector<int>* primes = new vector<int>();
	for(int i=2;i<=MAX;i++){
		isPrime[i] = true;
	}
	for(int i=2;i*i<=MAX;i++){

		if(isPrime[i]){
			for(int j=i*i;j<=MAX;j+=i){
				isPrime[j] = false;
			}
		}
	}

	primes->pb(2);
	for(int i=3;i<=MAX;i+=2){
		if(isPrime[i]){
			primes->pb(i);
		}
	}
	return primes;

}

void sievefactors(int *si){
    fill_n(si,max6,0);
	vector<int>* primes = sieve();
	vector<int>::iterator it;
	/*it=primes->begin();
	cout<<*it;
    it=primes->end();
	cout<<*it;
	*/
	for(it=primes->begin();it!=primes->end();it++){
        l temp=*it;
        for(l j=1;j*temp<=max6;j++){
            si[j*temp]+=1;
        }
	}
}

int main()
{
    int *si=new int[max6];
    sievefactors(si);
    l t;
    cin>>t;
    while(t--){
        l a,b;
        int n;
        cin>>a>>b>>n;
        int c=0;
        for(l i=a;i<=b;i++){
            if(si[i]==n){
                c++;
            }
        }
        cout<<c<<endl;

    }
    return 0;
}
