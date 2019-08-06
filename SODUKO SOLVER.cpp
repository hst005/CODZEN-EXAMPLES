#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
vector <int> opt(int ar[9][9],int x,int y){
    vector <int> res;
for(int i=1;i<=9;i++){
    int flag=0;
    for(int j=0;j<9;j++){
        if(ar[x][j]==i){
            flag=1;
            break;
        }
    }
    if(flag==1){
        break;
    }
    for(int j=0;j<9;j++){
        if(ar[j][y]==i){
            flag=1;
            break;
        }
    }
    if(flag==1){
        break;
    }
    int tempx=0,tempy=0;
    tempx=x/3;tempy=y/3;
    for(int k=tempx*3;k!=(tempx+1)*3;k++){
        for(int j=tempy*3;j!=(tempy+1)*3;j++){
            if(ar[k][j]==i){
                flag=1;
                break;

            }
        }
    }
     if(flag==1){
        break;
    }
    res.push_back(i);

}
}
*/


bool check(int board[][9],int row,int col,int val) {
     for(int k=0;k<9;k++) {
            if(board[row][k]==val)
                return false;
            if(board[k][col]==val)
                return false;
            }
    int TopRowIndice=row-row%3;
    int TopColIndice=col-col%3;
     for(int c=TopRowIndice;c<TopRowIndice+3;c++) {
            for(int d=TopColIndice;d<TopColIndice+3;d++) {
                if(board[c][d]==val) {
                    return false;
                }
            }
        }
    return true;
    }

bool helper(int board[][9],int row,int col) {
     if(row==9) {
            return true;
     }

    if(col==9)
        return helper(board,row+1,0);
    if(board[row][col]!=0) {
            return helper(board,row,col+1);
    }

    for(int k=1;k<=9;k++) {
            if(check(board,row,col,k)) {
                 board[row][col]=k;
            if(helper(board,row,col+1))
                return true;
            }
        board[row][col]=0;
    }
    return false;
    }

bool sudokuSolver(int board[9][9]){
        return helper(board,0,0);
    }


int main()
{
   /* int **ar=new int*[9];
    for(int i=0;i<9;i++){
        ar[i]=new int[9];
    }*/
    int ar[9][9];
/*
    9 0 0 0 2 0 7 5 0
    6 0 0 0 5 0 0 4 0
    0 2 0 4 0 0 0 1 0
    2 0 8 0 0 0 0 0 0
    0 7 0 5 0 9 0 6 0
    0 0 0 0 0 0 4 0 1
    0 1 0 0 0 5 0 8 0
    0 9 0 0 7 0 0 0 4
    0 8 2 0 4 0 0 0 6
    */
    ar[0][0]=9;ar[0][1]=0;ar[0][2]=0;ar[0][3]=0;ar[0][4]=2;ar[0][5]=0;ar[0][6]=7;ar[0][7]=5;ar[0][8]=0;
    ar[1][0]=6;ar[1][1]=0;ar[1][2]=0;ar[1][3]=0;ar[1][4]=5;ar[1][5]=0;ar[1][6]=0;ar[1][7]=4;ar[1][8]=0;
    ar[2][0]=0;ar[2][1]=2;ar[2][2]=0;ar[2][3]=4;ar[2][4]=0;ar[2][5]=0;ar[2][6]=0;ar[2][7]=1;ar[2][8]=0;
    ar[3][0]=2;ar[3][1]=0;ar[3][2]=8;ar[3][3]=0;ar[3][4]=0;ar[3][5]=0;ar[3][6]=0;ar[3][7]=0;ar[3][8]=0;
    ar[4][0]=0;ar[4][1]=7;ar[4][2]=0;ar[4][3]=5;ar[4][4]=0;ar[4][5]=9;ar[4][6]=0;ar[4][7]=6;ar[4][8]=0;
    ar[5][0]=0;ar[5][1]=0;ar[5][2]=0;ar[5][3]=0;ar[5][4]=0;ar[5][5]=0;ar[5][6]=4;ar[5][7]=0;ar[5][8]=1;
    ar[6][0]=0;ar[6][1]=1;ar[6][2]=0;ar[6][3]=0;ar[6][4]=0;ar[6][5]=5;ar[6][6]=0;ar[6][7]=8;ar[6][8]=0;
    ar[7][0]=0;ar[7][1]=9;ar[7][2]=0;ar[7][3]=0;ar[7][4]=7;ar[7][5]=0;ar[7][6]=0;ar[7][7]=0;ar[7][8]=4;
    ar[8][0]=0;ar[8][1]=8;ar[8][2]=2;ar[8][3]=0;ar[8][4]=4;ar[8][5]=0;ar[8][6]=0;ar[8][7]=0;ar[8][8]=6;
/*
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
            cin>>ar[i][j];
        }
    }*/
/*
    vector <int> try1=opt(ar,2,2);
    vector <int> ::iterator it;
    for(it=try1.begin();it!=try1.end();it++){
        cout<<*it<<endl;
    }*/
    cout<<sudokuSolver(ar);
    return 0;
}
