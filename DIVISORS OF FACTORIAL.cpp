#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//approach sahi hai but thoda optimized nhi hai aur kayi thoda galat hogya toh firse dekh lo dosri file mein
bool checkprime(int n){
    int flag=0;
    for(int i=2;i<=pow(n,0.5);i++){
        if(n%i==0){
            flag=1;
            break;
        }
    }
    if (flag==0){
        return  true;
    }
    else {
        return false;

    }

}
/*
long int countprime(long int n,vector <long int> ot){
bool si[n];
memset(si,true,n*sizeof(long int));
si[0]=false;
si[1]=false;
for(int i=2;i<=(pow(n,0.5);i++){
    if(si[i]==true){
        if (checkprime(i)==true){
            int k=2;
            int j=k*i;
            while(j<=n){
                si[j]=false;
                k++;
                j=k*i;
            }
        }
    }
}
int count=0;
for(int i=2;i<n;i++){
    if(si[i]==true){
        ot.push_back(i);
        count++;
    }
}
return count;
}*/

long int countprimes(long int n,long int* ot){
bool *avail=new bool[n];
memset(avail,true,n*sizeof(bool));
avail[0]=false;
avail[1]=false;
long int count=0;

for(long int j=2;j<=pow(n,0.5);j++){
    if(avail[j]==true){
        bool temp=checkprime(j);
        if(temp==true){
            for(int k=j;k*j<=n;k++){
            avail[k*j]=false;
        }
        }


    }
}
long int j=0;
for(long int i=0;i<n;i++){
    if (avail[i]==true){
            ot[j]=i;
            j++;
        count++;
    }
}
return count;
}


long long int divfact(int n,long int *ot,int no){
long long int temp=1,sum=0;
for(int i=0;i<no;i++){
        sum=0;
    sum=n/ot[i];
    for(int j=2;pow(ot[i],j)<=n;j++){
        sum+=n/pow(ot[i],j);
    }
    ot[i]=sum+1;
}
long long int m =pow(10,9)+7;
for(int i=0;i<no;i++){
    temp=((temp%m)*(ot[i]%m))%m;
}

return temp;

}
int main()
{
    int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        long long int temp,ans;
       // ans=divoffact(n);
       long int *ot=new long int[n];
        temp=countprimes(n,ot);
        ans=divfact(n,ot,temp);
      cout<<ans<<endl;
        }
    return 0;
}
