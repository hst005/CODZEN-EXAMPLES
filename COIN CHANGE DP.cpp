#include <iostream>

using namespace std;
/*int coinchange(int *d,int numd,int val,int ot){
if(val==0){
    return 1;
}
if(numd==0 || val<0){
    return 0;
}

if(ot[val][numd]>-1)
    return ot[val][numd];

 int temp1=coinchange(d+1,numd-1,val,ot);
 int temp2=coinchange(d,numd,val-d[0],ot);
 ot[val][numd]=temp1+temp2;

       return ot[val][numd];


}
int countWaysToMakeChange(int d[], int numd, int v){
*/
  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
/*

for(int i=0;i<=numd;i++){
        }
*/
    //int ot[v+1][numd+1];
	/*int **ot=new int*[numd+1];
	for(int i = 0; i <=numd; ++i){
        ot[i]=new int[val+1];
	}*/
	/*int **ot=new int*[v+1];
	for(int i = 0; i <=v; ++i){
        ot[i]=new int[numd+1];
	}
	for(int i=0;i<v+1;i++){
        for(int j=0;j<numd+1;j++){
            ot[i][j]=-1;
        }
	}
return coinchange(d,numd,v,ot);
}
*/
int countWaysToMakeChange(int S[], int m, int n){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
  int i, j, x, y;

    // We need n+1 rows as the table is constructed
    // in bottom up manner using the base case 0
    // value case (n = 0)
    int table[n+1][m];

    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;

    // Fill rest of the table entries in bottom
    // up manner
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;

            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];


}

    int main() {

	int numd;
	cin>>numd;
	int d[numd];
	for(int i=0;i<numd;i++){
        cin>>d[i];
	}
	int v;
	cin>>v;

	cout<<countWaysToMakeChange(d,numd,v)<<endl;

    return 0;
}

