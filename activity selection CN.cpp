#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct act{
//char name;
int start;
int finish;
};

bool cmp(act a,act b){
    return (a.finish<b.finish);
}

int maxact(act ar[],int n){
    int ans=1;
    sort(ar,ar+n,cmp);
    //cout<<"( "<<ar[0].start<<","<<ar[0].finish<<" )"<<endl;
    int i=0;
    for(int j=1;j<n;j++){
        if(ar[j].start>=ar[i].finish){
            //cout<<"( "<<ar[j].start<<","<<ar[j].finish<<" )"<<endl;
            ans++;
            i=j;
        }
    }
    return ans;
}
int main()
{
    int n;
    //cout<<"number of activities";
    cin>>n;
    act ac[n];
    for(int i=0;i<n;i++){
        cin>>ac[i].start>>ac[i].finish;
    }
    cout<<maxact(ac,n);
    return 0;
}
