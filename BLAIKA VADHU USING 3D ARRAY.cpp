#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int max(int a,int b,int c){
if(a>b){
    if(b>c){
        return a;
    }
    else if(c>a){
            return c;
    }
    else{
        return a;
    }
}
else{
    if(a>c){
        return b;
    }
    else if(c>b){
            return c;
    }
    else{
        return b;
    }
}
}


int aloknath(string b1,string b2,int m,int n,int k){
int dp[m+1][n+1][k+1];
for(int i=0,j=0,l=0;i<1 && j<1 && l<1;i++,j++,l++){
        if(i==0){
    for(int p=0;p<=n;p++){
        for(int q=0;q<=k;q++){
            dp[i][p][q]=0;
        }
    }
        }
    if(j==0){
    for(int p=0;p<=m;p++){
        for(int q=0;q<=k;q++){
            dp[p][j][q]=0;
        }
    }
    }
    if(l==0){
    for(int p=0;p<=m;p++){
        for(int q=0;q<=n;q++){
            dp[p][q][l]=0;
        }
    }
    }

}
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        for(int l=k;l>0;l-- ){
            if(b1[m-i]==b2[n-j]){
                dp[i][j][l]=max(dp[i-1][j-1][l-1],dp[i-1][j][l],dp[i][j-1][l]);
            }
            else{
                dp[i][j][l]=max(dp[i][j-1][l],dp[i-1][j][l]);
            }
        }
    }
}

return dp[m][n][k];
}
int main()
{
    int t;
    cin>>t;
    while(t--){
            string b1,b2;
            cin>>b1>>b2;
            int k;
            cin>>k;
            int m,n;
            m=b1.length();
            n=b2.length();
            cout<<aloknath(b1,b2,m,n,k)<<endl;
    }
    return 0;
}
