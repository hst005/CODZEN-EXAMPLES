#include <iostream>
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;


long long int alpha(int *in,int n){
long long *output=new long long[n+1];
output[0]=1;
output[1]=1;
for(int i=2;i<=n;i++){
  output[i]=0;
  if(in[i-1]!=0)
  output[i]=output[i-1];

  if(in[i-2]*10+in[i-1]<=26 && in[i-2]*10+in[i-1]>=10 ){
        output[i]=((output[i]%mod)+(output[i-2]%mod))%mod;
    }
  if(output[i]==0 || (in[i-1]==0 && in[i-2]==0)){
    output[n]=0;
    break;
  }
  /*
   if(in[i-1]==0 ){
     if(in[i-2]<3){
        output[i]=output[i-2];
    }
     else{
       output[i]= 0;
     }
   }*/

}
int temp=output[n];
delete [] output;
return temp;

}
int main()
{
    string s;
    cin>>s;
    while(s!="0"){
        int n=s.length();
        int in[n];
        for(int i=0;i<s.length();i++){
                //string temp=""+s[i];
            in[i]=s[i]-'0';
        }
/*
        for(int i=0;i<s.length();i++){
            cout<<in[i]<<endl;
        }
  */      cout<<alpha(in,n)<<endl;
        cin>>s;
    }
    return 0;
}
