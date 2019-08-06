#include <iostream>

using namespace std;

int mincost(int **in,int m,int n){
int **dp=new int*[m];
for(int i=0;i<m;i++)
    dp[i]=new int[n];

dp[m-1][n-1]=in[m-1][n-1];
for(int i=n-2;i>=0;i--){
    dp[m-1][i]=in[m-1][i]+dp[m-1][i+1];
}

for(int i=m-2;i>=0;i--){
    dp[i][n-1]=in[i][n-1]+dp[i+1][n-1];
}

for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            //int temp=min()
            dp[i][j]=in[i][j]+min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
        }
}
int temp=dp[0][0];
delete []dp;
return temp;

}

int main()
{
    int ** input = new int*[3];
	input[0] = new int[3];
	input[1] = new int[3];
	input[2] = new int[3];
	input[0][0] = 4;
	input[0][1] = 3;
	input[0][2] = 2;
	input[1][0] = 1;
	input[1][1] = 8;
	input[1][2] = 3;
	input[2][0] = 1;
	input[2][1] = 1;
	input[2][2] = 8;

	//cout << min_cost(input, 0,0,2,2) << endl;
	//cout << min_cost2(input,3,3) << endl;
	cout<<mincost(input,3,3);
	delete [] input[0];
	delete [] input[1];
	delete [] input[2];
	delete [] input;


    return 0;
}
