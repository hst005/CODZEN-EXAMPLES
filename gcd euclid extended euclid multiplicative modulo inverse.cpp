#include<iostream>
using namespace std;
#define m 1000000007

class Triplet{
public:
	int gcd;
	int x;
	int y;
};
Triplet gcdExtendedEuclid(int a,int b){
	//Base Case
	if(b==0){
		Triplet myAns;
		myAns.gcd = a;
		myAns.x = 1;
		myAns.y = 0;
		return myAns;

	}
	Triplet smallAns = gcdExtendedEuclid(b,a%b);
	//Extended euclid says

	Triplet myAns;
	myAns.gcd = smallAns.gcd;
	myAns.x  = smallAns.y;
	myAns.y = (smallAns.x - ((a/b)*(smallAns.y)));
	return myAns;
}

int gcd(int a,int b){

//Special case for a<b
	if(a<b){
		return gcd(b,a);
	}
	// Base case
	if(b == 0){
		return a;
	}

	// Answer step applying EUCLID'S ALGORITHM
	return gcd(b,a%b);
}

int modInverse(int A,int M){
	Triplet ans = gcdExtendedEuclid(A,M);
	return (ans.x%m+m)%m ;
}
int main(){

	int a = 5;
	long long int k = 10000000007;

	cout<<modInverse(2,k);
	//int ans = gcd(a,b);

	// Triplet ans = gcdExtendedEuclid(a,b);
	// cout<<ans.gcd<<endl;
	// cout<<ans.x<<endl;
	// cout<<ans.y<<endl;

	return 0;
}
