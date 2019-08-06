#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void checkassign(int *x,int d,bool check,int cows,int n){
    int *sol=new int[cows];
    sol[0]=x[0];
    int j=1;
for(int i=1;i<n;i++){
    if(x[i]-sol[j-1]>=d){
        sol[j]=x[i];
        j++;
    }
    if(j==cows){
            check==1;
        break;
    }
}

}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long int n,c;
        cin>>n>>c;
        int *x=new int[n];
        for(int j=0;j<n;j++){
            cin>>x[i];
        }
    sort(x,x+n);

    long int end,mid,start=0;
    end=x[n-1]-x[0];
    int d=-1;

    //int d=0;
    bool check=0;
    while(start<=end){
        mid=(start+end)/2;
    check=0;

    checkassign(x,mid,check,c,n);
    if(check==0){
        end=mid-1;
    }
    else if(check==1){
            d=mid;
        start=mid+1;
    }
    }
    cout<<d;
    }
    return 0;
}
