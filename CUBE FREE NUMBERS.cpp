#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int t;
    cin>>t;
    for(long int i=0;i<t;i++) {
        int k;
        cin>>k;
        float m;
        m=pow(k,(1.0/3.0));
        int t=(int)m;
        if(m==t && m!=1){
            cout<<"Case "<<i+1<<": "<<"Not Cube Free"<<endl;
        }
        else{
            cout<<"Case "<<i+1<<": "<<k-t+1<<endl;
        }
    }
    return 0;
}
