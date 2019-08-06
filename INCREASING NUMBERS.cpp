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


void printhelper(int n,int start,string s){
string temp=s;
if(n==0){
    cout<<s<<" ";
}

if(n==9 || 9-start<n-1){
        //cout<<"end";
return;
}

for(int i=start;i<=9;i++){
    s+=notostr(i);
    printhelper(n-1,i+1,s);
    s=temp;
    }


}

void printIncreasingNumbers(int n) {

	string s="";
	printhelper(n,1,s);

}


int main()
{
    printIncreasingNumbers(6);
    return 0;
}
