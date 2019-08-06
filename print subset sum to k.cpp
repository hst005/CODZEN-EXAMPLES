#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printSubsetsOfArrayHelper(int input[], int startIndex, int size, int output[], int oSize ,int k){
     if(startIndex == size){
            int sum=0,flag=0;
      for(int i = 0; i < oSize; i++) {
            sum+=output[i];
      }

      if (sum==k){
      for(int i = 0; i < oSize; i++) {
            cout << output[i] << " ";
      }
      cout << endl;
      return;
      }
      else{
        return;
      }
       }
    int smallOutput[40], smallOSize = 0;
     printSubsetsOfArrayHelper(input, startIndex+1, size, output, oSize,k);
      int i;
      for(i = 0; i < oSize; i++) {
            smallOutput[i] = output[i];
      }
      smallOutput[i] = input[startIndex];
    printSubsetsOfArrayHelper(input, startIndex+1, size, smallOutput, oSize+1,k);
     }

void printSubsetSumToK(int input[], int size ,int k) {
    int output[1000];
    return printSubsetsOfArrayHelper(input, 0, size, output, 0 ,k);
}

int main()
{
    int n[]={5,12,3,17,1,18,15,3,17};
    printSubsetSumToK(n,9,6);
    return 0;
}
