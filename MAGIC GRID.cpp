#include <iostream>

using namespace std;

long long magic(int **in,int r,int c){
int dp[r][c];
dp[r-1][c-1]=1;
dp[r-1][c-2]=1;
dp[r-2][c-1]=1;

for(int i=c-2;i>=0;i--){
    dp[r-1][i]=dp[r-1][i+1]-in[r-1][i];
    if(dp[r-1][i]<=0){
        dp[r-1][i]=1;
    }
}

for(int i=r-2;i>=0;i--){
    dp[i][c-1]=dp[i+1][c-1]-in[i][c-1];
    if(dp[i][c-1]<=0){
        dp[i][c-1]=1;
    }
}


for(int i=r-2;i>=0;i--){
        for(int j=c-2;j>=0;j--){
            //int temp=min()
            dp[i][j]=min(dp[i][j+1]-in[i][j],dp[i+1][j]-in[i][j]);
            if(dp[i][c-1]<=0){
                    dp[i][j]=1;
                }
        }
}

return dp[0][0];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        int **in=new int*[r];
        for(int i=0;i<r;i++)
            in[i]=new int[c];

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>in[i][j];
            }
        }
        cout<<magic(in,r,c)<<endl;
    }
    return 0;
}
