#include <iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
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
int countprimes(int n){
bool *visit=new bool[n];
memset(visit,false,n*sizeof(bool));
visit[0]=true;
visit[1]=true;
int count=0;
for(int i=2;i<=n;i++){
    if(visit[i]==false){
            visit[i]=true;
        bool temp=checkprime(i);
        if(temp==true){
            count++;
        for(int k=2;k*i<=n;k++){
            visit[k*i]=true;
        }
        }

    }

}
return count;

}
*/
int countprimes(int n){
bool *avail=new bool[n];
memset(avail,true,n*sizeof(bool));
avail[0]=false;
avail[1]=false;
int count=0;

for(int j=2;j<=pow(n,0.5);j++){
    if(avail[j]==true){
        bool temp=checkprime(j);
        if(temp==true){
            for(int k=j;k*j<=n;k++){
            avail[k*j]=false;
        }
        }


    }
}
for(int i=0;i<n;i++){
    if (avail[i]==true){
        count++;
    }
}
return count;
}

int main()
{
    int k;
    cout<<checkprime(167)<<endl;
    cin>>k;
    int count=0;
    int count2=countprimes(k);
    cout<<count2<<endl;
    for(int n=2;n<=k;n++){
    int flag=0;
    for(int i=2;i<=pow(n,0.5);i++){
        if(n%i==0){
            flag=1;
            break;
        }
    }
    if (flag==0){
        count++;
    }
    }
    cout<<count;
    return 0;
}
