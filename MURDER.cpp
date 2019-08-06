#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int murder (int *ar,int n){
        int *solution=new int[n-1];
        memset(solution,0,(n-1)*sizeof(int));
        for(int j=1;j<n;j++){
            int s=0;
            for (int k=0;k<j;k++){
                if (ar[j]>ar[k]){
                    s+=ar[k];
                }
            }
            solution[j-1]=s;
        }
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum=sum+solution[i];

        }
        return sum;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long int n;
        cin>>n;
        int *ar=new int[n];

        for(int j=0;j<n;j++){
            cin>>ar[j];
        }
        long int ans=murder(ar,n);
        cout<<ans;
    }
    return 0;
}
