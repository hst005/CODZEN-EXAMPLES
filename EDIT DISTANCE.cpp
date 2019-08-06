#include <iostream>

using namespace std;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int editDistance(string s1, string s2){

    int m=s1.length();
    int n=s2.length();

  int **dp=new int*[m+1];
  for(int i=0;i<=m;i++){
    dp[i]=new int[n+1];
  }
  for(int i=0;i<=m;i++){
    dp[i][0]=i;
  }
  for(int i=0;i<=n;i++){
    dp[0][i]=i;
  }

  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(s1[i-1]==s2[j-1]){
        dp[i][j]=dp[i-1][j-1];
      }
      else{
        dp[i][j]=1+bcmin(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
      }

    }
  }

  return dp[m][n];

}


int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<editDistance(s1,s2);
    return 0;
}
