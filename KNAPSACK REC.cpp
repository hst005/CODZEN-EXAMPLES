#include <iostream>
#include<algorithm>
using namespace std;
//chala nahi

struct bag{
int w,prof;
};
bool cmp(bag a,bag b){
return a.w<b.w;
}

long long int knapsnack(bag *ar,int n,int k,int **dp){
if(n==0 || k<=0){
    return 0;
}
if(ar[0].w<k){
if(dp[n][k]>-1){
    return dp[n][k];
}
else{
    dp[n][k]=max(knapsnack(ar+1,n-1,k-ar[0].w,dp)+ar[0].prof,knapsnack(ar+1,n-1,k,dp));
}
}
else{
    return 0;
}
return dp[n][k];
}


int main()
{
    int n;
    cin>>n;
    bag ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i].w;
    }

    for(int i=0;i<n;i++){
        cin>>ar[i].prof;
    }
    int k;
    cin>>k;
    int **dp=new int*[n+1];

    for(int i=0;i<n;i++){
        dp[i]=new int[k+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=-1;
        }
    }
    sort(ar,ar+n,cmp);
    cout<<knapsnack(ar,n,k,dp);
    return 0;
}
