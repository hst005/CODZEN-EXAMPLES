#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

template <typename T>

long int strtono( T numb )
{
stringstream abc(numb);
int x=0;
abc>>x;
return x;
}

long int gcd(long int a,long int b){

if(b==0){
    return a;
}

return gcd(b,a%b);
}
long int findgcd(long int a,string b){
if (a==0){
  return stoi(b);
}
    long int c=0;
      int temp=0,temp2=0;
    char *t=new char[1];
    t[0]=b[0];
    temp=atoi(t);
    temp=temp%a;
    for(int i=1;i<b.length();i++){
            t[0]=b[i];
        temp=(temp*10+atoi(t))%a;
    }
    long int ans=gcd(a,temp);

    return ans;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long int a;
        string b;
        cin>>a>>b;
        long int gcd;
        gcd=findgcd(a,b);
        cout<<gcd;
    }
    return 0;
}
