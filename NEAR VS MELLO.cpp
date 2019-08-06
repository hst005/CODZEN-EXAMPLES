#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int sum=0;
    long int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    sum+=ar[i];
    }
    sort(ar,ar+n);
    sum=sum-(ar[n-1]+ar[n-2]);
    sum=(n-2)*ar[n-2]-sum;
    cout<<sum;

    return 0;
}
