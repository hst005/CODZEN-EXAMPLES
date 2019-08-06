#include <iostream>

using namespace std;

int coinchange(int *a,int n,int m,int **dp){
        if(m==0){
            return 1;
        }
        if(m<a[0]){
            return 0;
        }
        if(m<0){
            return 0;
        }
        if(n==0){
            dp[n][m]=0;
            return 0;
        }
      if(dp[n][m]>-1){
            return dp[n][m];
        }

        int t1=coinchange(a+1,n-1,m,dp);
        int t2=coinchange(a,n,m-a[0],dp);
       dp[n][m]=t1+t2;
    return t1+t2;
}
/*
int countWaysToMakeChange(int S[], int m, int n){
  int i, j, x, y;
    int table[n+1][m];
   for (i=0; i<m; i++)
        table[0][i] = 1;
    for (i = 1; i < n+1; i++){
        for (j = 0; j < m; j++)
        {
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
            y = (j >= 1)? table[i][j-1]: 0;
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}
*/
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *a=new int[n];
        for(int i=0;i<n;i++){
            cin>>a[i];

        }
        int m;
        cin>>m;
        int **dp=new int*[m+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int[m+1];
            for(int j=0;j<=m;j++){
                dp[i][j]=-1;
            }
        }
        int ans=coinchange(a,n,m,dp);
        cout<<ans<<endl;
   // cout<<countWaysToMakeChange(a,n,m);
    }
    return 0;
}
