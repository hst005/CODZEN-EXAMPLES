#include <iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
string notostr( T Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}


void printSubsetsOfArray(int input[], int size,string output="") {
    if (size==0){
        cout<<output<<endl;
        return;
    }

    printSubsetsOfArray(input+1,size-1,output);

    printSubsetsOfArray(input+1,size-1,output + notostr(input[0]) + " ");

}
int main()
{
    int n[]={15,20,12};
    printSubsetsOfArray(n,3);
    return 0;
}
