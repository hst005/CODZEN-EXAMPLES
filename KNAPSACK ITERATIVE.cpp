#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n;
    int w[n];
    int prof[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }

    for(int i=0;i<n;i++){
        cin>>prof[i];
    }

    cin>>k;
    int dp[n+1][k+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=0;
        }
    }

    //for(int i=0;i<=n;i++){
      int i=0;
        for(int j=0;j<=k;j++){
            dp[i][j]=0;
        }
        for(int j=0;j<=n;j++){
            dp[j][i]=0;
        }

    //}
    //int w=k;
   for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
                dp[i][j] = dp[i-1][j];
			if(w[i-1] <= j){
				dp[i][j] = max(dp[i][j],prof[i-1] + dp[i-1][j-w[i-1]]);
			}
        }
    }

    cout<<dp[n][k];
    return 0;
}
