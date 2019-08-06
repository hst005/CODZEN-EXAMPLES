/*#include <iostream>
#include<bits/stdc++.h>
using namespace std;
double finddistance(int x1,int x2,int y1,int y2){

return pow(abs(pow(x1-x2,2)-pow(y1-y2,2)),0.5);
}
double max(float a,float b){
if(a>b){
    return a;
}
else{
    return b;
}
}
int main()
{
    int n;
    cin>>n;
    long int x[n],y[n],f[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>f[i];
    }
    float dp[n];
    //int happy=f[0];
    dp[0]=f[0];
    for(int i=1;i<n;i++){
        dp[i]=-1*FLT_MAX;
        //int maxi=INT_MIN;
        for(int j=i-1;j>=0;j--){
            double temp=finddistance(x[i],x[j],y[i],y[j]);
            dp[i]=max(dp[i],dp[j]-temp);
        }
        dp[i]+=f[i];
            }
    cout<<fixed<<setprecision(6)<<dp[n-1];
    //int maxi=f[0]+f[n-1];

    return 0;
}
*/
//solution
#include <bits/stdc++.h>
#define mod 1000000007
#define inf 1000000000000
#define root2 1.41421
#define root3 1.73205
#define pi 3.14159
#define MAX 100001
#define ll long long int
#define PII pair<int, int>
#define f first
#define s second
#define ss(n) scanf("%lld", &n)
#define ssf(n) scanf("%lf", &n)
#define mk make_pair
#define PDD pair<double , double>
#define gc getchar
#define pb push_back

using namespace std;
double dp[3001], F[3001];
PDD d[3001]; ll n;
double fun(PDD d1, PDD d2) {
    return sqrt((d2.f-d1.f)*(d2.f-d1.f)+(d2.s-d1.s)*(d2.s-d1.s));
    }

    int main() {
        ll i, j;
        double x, y;
        cin>>n;
        for(i=0;i<n;i++) {
                cin>>x>>y;
        d[i]=mk(x, y); cin>>F[i];
        }

        dp[0]=F[0];
        for(i=1;i<n;i++) {
                dp[i]=-inf;
        for(j=0;j<i;j++) {
                x=fun(d[i], d[j]);
        //Find distance between i and j
        dp[i]=max(dp[i], dp[j]-x);
        //Maximize over all possible differences
        }
        dp[i]+=F[i];
        } cout<<fixed;
        cout<<setprecision(6)<<dp[n-1]<<endl;
    return 0;
}
