#include <iostream>
#define getpoint
using namespace std;
#include<bits/stdc++.h>
double crossproduct(int *x,int *y,int i,int j){
    return x[i]*y[j]-x[j]*y[i];
}
double triarea(int *x,int *y,int i){
    int xline1=x[i]-x[0];
    int xline2=x[i+1]-x[0];
    int yline1=y[i]-y[0];
    int yline2=y[i+1]-y[0];
    // (xline1,yline1)*(xline2,yline2);

    return ((double)(xline1*yline2-xline2*yline1)/2.0);
}
int main()
{
    int n;
    cin>>n;
    int x[n],y[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        cin>>y[i];
    }
        double ans=0;
    for(int i=1;i<n-1;i++){
        ans+=triarea(x,y,i);
    }

  //  cout<<fixed<<setprecision(30)<<abs(ans);
    cout<<abs(ans);
    return 0;
}
