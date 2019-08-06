#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
bool issafe()
void placeNQueens(int n){
    int row=0;
    if(row>=n)
        return;
    int ** ar=new int*[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ar[i][j]=0;
        }
    }



}
*/
int board[11][11];
bool ispossible(int n,int row,int col){
/*for(int i=0;i<row;i++){
    if(board[i][col]==1)
        return false;
}
for(int i=0;i<row ;i++){
        if(row-i-1>=0 && col-i-1>=0){
    if(board[row-i-1][col-i-1]==1)
        return false;
        }
}

for(int i=0;i<row;i++){
        if(row-i-1>=0 && col +i<n){
    if(board[row-i-1][col+i]==1)
        return false;
        }

}*/
 for(int i=row-1;i>=0;i--){
    if(board[i][col] == 1){
      return false;
    }
  }
//Upper Left Diagonal
  for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--){
    if(board[i][j] ==1){
      return false;
    }
  }

  // Upper Right Diagonal

  for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++){
    if(board[i][j] == 1){
      return false;
    }
  }
return true;
}
void placequeens(int n,int row){
if (row==n){
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";

        }
     }
     cout<<endl;
}
for(int j=0;j<n;j++){

    if(ispossible(n,row,j)){
            board[row][j]=1;
        placequeens(n,row+1);
        board[row][j]=0;

    }

}
return;

}
void placeNQueens(int n){

    memset(board,0,11*11*sizeof(int));
    placequeens(n,0);


}
int main()
{


  placeNQueens(4);
  return 0;
}

