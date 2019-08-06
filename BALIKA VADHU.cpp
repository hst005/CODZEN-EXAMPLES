#include <iostream>
#define  f first
#define s second
#include<bits/stdc++.h>
using namespace std;

int aloknath(string b1,string b2,int m,int n,int k){
/*string dp[m+1][n+1];
for(int i=0;i<=m;i++){
    dp[i][0]="";
}
for(int i=0;i<=n;i++){
    dp[0][i]="";
}

for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(b1[m-i]==b2[n-j]){
                dp[i][j]=dp[i-1][j-1]+b1[m-i];
        }
        else{
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
}
*/
pair<string,int> dp[m+1][n+1];
for(int i=0;i<=m;i++){
    dp[i][0].first="";
    dp[i][0].second=0;
}
for(int i=0;i<=n;i++){
    dp[0][i].f="";
    dp[0][i].s=0;
}

for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(b1[m-i]==b2[n-j]){
                dp[i][j].f=dp[i-1][j-1].f+b1[m-i];
                dp[i][j].s=dp[i-1][j-1].s+(int)b1[m-i];
                //string tem=dp[i][j].f;
                //sort(dp[i][j].f.begin(),dp[i][j].f.end());
                /*if(tem.length()>k){
                    for(int l=0;l<tem.length()-k;l++){
                        dp[i][j].s=dp[i][j].s-(dp[i][j].f)[0];
                    dp[i][j].f.erase(dp[i][j].f.begin());

                    }*/
                }

        else{
               /* if(dp[i-1][j].s+(int)b1[m-i]>dp[i][j-1].s+(int)b2[n-j]){
            dp[i][j].s=dp[i-1][j].s+(int)b1[m-i];
            dp[i][j].f=dp[i-1][j].f+(int)b1[m-i];

            }
             else if(dp[i-1][j].s+(int)b1[m-i]<dp[i][j-1].s+(int)b2[n-j]){
            dp[i][j].s=dp[i][j-1].s+(int)b2[n-j];
            dp[i][j].f=dp[i][j-1].f+(int)b2[n-j];

            }
            */
            if(dp[i-1][j].s>dp[i][j-1].s){
            dp[i][j].s=dp[i][j-1].s;
            dp[i][j].f=dp[i][j-1].f;
            }
            else if(dp[i-1][j].s<dp[i][j-1].s){
            dp[i][j].s=dp[i-1][j].s;
            dp[i][j].f=dp[i-1][j].f;
            }
            else{
                dp[i][j].s=dp[i-1][j].s;
                dp[i][j].f=dp[i-1][j].f;

            }



        }
    }
    }
if(dp[m][n].f.length()>k){

string tem=dp[m][n].f;
                sort(dp[m][n].f.begin(),dp[m][n].f.end());
                if(tem.length()>k){
                    for(int l=0;l<tem.length()-k;l++){
                        dp[m][n].s=dp[m][n].s-(dp[m][n].f)[0];
                    dp[m][n].f.erase(dp[m][n].f.begin());

                    }

}
}
if(dp[m][n].f.length()<k){
 return 0;
}

return dp[m][n].s;
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
