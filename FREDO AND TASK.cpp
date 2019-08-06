#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007


int main()
{
  long int n;
  cin>>n;
  ll *ar=new ll[n];
  ll pro=1;
  for(long int i=0;i<n;i++){
    cin>>ar[i];
    pro=(pro*(ar[i]%mod))%mod;
  }
    cout<<pro<<endl;
    double div=1/double(n);
    cout<<div<<endl;
  double n1=pow(pro,div);
  cout<<n1<<endl;
  ll n2=pow(pro,div);

  if(n2==n1) {
    cout<<n2<<endl;
  }
  else {
    cout<<n2+1;
  }

	delete [] ar;
    return 0;
}
