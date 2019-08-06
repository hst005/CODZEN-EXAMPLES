#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int k1(int val[], int wt[], int n, int W)
{
    // matrix to store final result
    int mat[2][W+1];
    memset(mat, 0, sizeof(mat));

    // iterate through all items
    int i = 0;
    while (i < n) // one by one traverse each element
    {
        int j = 0; // traverse all wieghts j <= W

        // if i is odd that mean till now we have odd
        // number of elements so we store result in 1th
        // indexed row
        if (i%2!=0)
        {
            while (++j <= W) // check for each value
            {
                if (wt[i] <= j) // include element
                    mat[1][j] = max(val[i] + mat[0][j-wt[i]],
                                    mat[0][j] );
                else           // exclude element
                    mat[1][j] = mat[0][j];
            }

        }

        // if i is even that mean till now we have even number
        // of elements so we store result in 0th indexed row
        else
        {
            while(++j <= W)
            {
                if (wt[i] <= j)
                    mat[0][j] = max(val[i] + mat[1][j-wt[i]],
                                     mat[1][j]);
                else
                    mat[0][j] = mat[1][j];
            }
        }
        i++;
    }

    // Return mat[0][W] if n is odd, else mat[1][W]
    return (n%2 != 0)? mat[0][W] : mat[1][W];
}
int knapsack(int* weights, int* values, int n, int max){



return k1(values,weights,n,max);
}
int main(){
    int val[] = {5,4,8,6};
	int wt[] = {1,2,3,5};

	int W = 5;
	int n = 4;

	cout << knapsack(wt,val,n,W)<<endl;
    return 0;
}
