#include <iostream>
#include<bits/stdc++.h>
using namespace std;

   int binarySearch(int a[], int size, int element) {
    int start=0;
    int last=size-1;
    int mid;
    int m=element;
   // int pos;
    while(start<=last){
        mid=(start+last)/2;
        if(a[mid]==m){
            return mid;
        }
        else if(a[mid]>m){
            last=mid-1;
        }

        else if(a[mid]<m){
            start=mid+1;
        }
    }

}
int main()
{
    int k;
    cin>>k;
    int a[k];
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    cout<<"what to search"<<endl;
    int m;
    cin>>m;

    sort(a,a+k);
    int start=0;
    int last=k-1;
    int mid;
   // int pos;
    while(start<=last){
        mid=(start+last)/2;
        if(a[mid]==m){
            cout<<"found at sorted position "<<mid+1<<endl;
            break;
        }
        else if(a[mid]>m){
            last=mid-1;
        }

        else if(a[mid]<m){
            start=mid+1;
        }
    }
    cout<<binarySearch(a,k,35);
    return 0;
}
