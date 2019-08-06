#include <iostream>
#include<math.h>
using namespace std;
/*
int balancedBTs(int h){
if(h==0 || h==1){
    return 1;
}

long long int x=balancedBTs(h-1);
long long int y=balancedBTs(h-2);
long long int m=pow(10,9)+7;
return ((((x%m)*(x%m))%m)+((2*x%m*y%m)%m))%m;
}*/
//also
int balancedBTs(int h){

	if(h==0 || h==1){
		return 1;
	}

	int m = pow(10,9) + 7;
	int x = balancedBTs(h-1);
	int y = balancedBTs(h-2);

	long res1 = (long)x*x;
	long res2 = (long)x*y*2;

	int ans1 = (int)(res1%m);
	int ans2 = (int)(res2%m);

	int ans = (ans1+ans2)%m;

	return ans;
}

int main()
{
    int h;
    cin>>h;
    cout<<balancedBTs(h);
    return 0;
}
