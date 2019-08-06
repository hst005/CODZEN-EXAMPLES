
#include<bits/stdc++.h>
using namespace std;
//baad waala khud try kra tha

void printSolution(int** solution,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << solution[i][j] << " ";
		}
	}
	cout<<endl;
}
void mazeHelp(int maze[][20],int n,int** solution,int x,int y){


	if(x == n-1 && y == n-1){
		solution[x][y] =1;
		printSolution(solution,n);
      	solution[x][y] =0;
		return;
	}
	if(x>=n || x<0 || y>=n || y<0 || maze[x][y] ==0 || solution[x][y] ==1){
		return;
	}
	solution[x][y] = 1;
	mazeHelp(maze,n,solution,x-1,y);
	mazeHelp(maze,n,solution,x+1,y);
	mazeHelp(maze,n,solution,x,y-1);
	mazeHelp(maze,n,solution,x,y+1);
	solution[x][y] = 0;
}
void ratInAMaze(int maze[][20], int n){

  int** solution = new int*[n];
  for(int i=0;i<n;i++){
  	solution[i] = new int[n];
  }
  mazeHelp(maze,n,solution,0,0);


}
int main(){
    	int maze[3][]={{1,0,1},{1,0,1},{1,1,1}};
	ratInAMaze(maze,3);
	return 0;
}


/*
#include <iostream>
using namespace std;
//try code so not optimized
bool islpossible(int maze[][20],int n,int row,int col,int **solution){
if (maze[row][col-1]==1 && solution[row][col-1]==0 && col>=0)
    return true;
else
    return false;
}

bool isrpossible(int maze[][20],int n,int row,int col,int **solution){
if (maze[row][col+1]==1 && solution[row][col+1]==0 && col<n)
    return true;
else
    return false;
}

bool isupossible(int maze[][20],int n,int row,int col,int **solution){
if (maze[row-1][col]==1 && solution[row-1][col-1]==0 && row>=0)
    return true;
else
    return false;
}

bool isdpossible(int maze[][20],int n,int row,int col,int **solution){
if (maze[row+1][col]==1 && solution[row+1][col-1]==0 && row<n)
    return true;
else
    return false;
}

void mazeprob(int maze[][20],int n,int **solution,int row,int col){
if (row==n-1 && col==n-1){

   for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<" ";
        }
   }
   cout<<endl;
   return ;
}

for(int i=0;i<n;i++){
    if(islpossible(maze,n,row,i,solution)){
            solution[row][i]=1;
        mazeprob(maze,n,solution,row,col-1);
            solution[row][i]=0;
    }
    if(isrpossible(maze,n,row,i,solution)){
            solution[row][i]=1;
        mazeprob(maze,n,solution,row,col+1);
            solution[row][i]=0;
    }
}

}

void ratInAMaze(int maze[][20], int n){

  int** solution = new int*[n];
   for(int i=0;i<n;i++){
  	solution[i] = new int[n];
  }
   for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            solution[i][j] = 0;
        }
   }

  mazeprob(maze,n,solution,0,0);

}*/
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
