#include <iostream>

using namespace std;

long long merge(int  *a,long long  start,long long  mid,long long  end){
long long  sum=0;
long long  i,j,k;
i=start;
j=mid+1;
k=0;
long long  temp[end-start+1];
while(i<=mid && j<=end){
    if (a[i]>=a[j]){
        temp[k]=a[j];
        j++;
       // inv+=mid-i+1;


    }
    else{
        temp[k]=a[i];

            sum+=(a[i]*(end-j+1));
        i++;
    }
    k++;

}
while(i<=mid){
    temp[k]=a[i];
        i++;
        k++;
}

while(j<=end){
    temp[k]=a[j];
        j++;
        k++;
}

for(long long  i=0;i<=(end-start);i++){
    a[start+i]=temp[i];
}

return sum;
}




long long mergesort(int *ar,long long  start,long long  end){
long long sum=0;
if (start>=end){
    return 0;
}
long long  mid=start+(end-start)/2;
long long sum1=mergesort(ar,start,mid);
long long sum2=mergesort(ar,mid+1,end);
long long sum3=merge(ar,start,mid,end);

//inv=inv1+inv2+inv3;
sum=sum1+sum2+sum3;
return sum;

}
/*
long long solve(int A[], int n)
{
    long long temp=mergesort(A,0,n-1);
	// Write your code here.
	return temp;
}*/
int main()
{
    /*
    int ar[]={2,5,1,3,4};
    long long  n=sizeof(ar)/sizeof(ar[0]);
    //long long  inv=mergesort(ar,0,n-1);

    cout<<mergesort(ar,0,n-1);
    for(int i=0;i<n;i++){
     cout<<ar[i]<<" ";
    }
    cout<<endl;
    //cout<<inv<<endl;
int br[]={1,4,2,7,8,4};
    long long  nn=sizeof(br)/sizeof(br[0]);
    //long long  inv=mergesort(ar,0,n-1);

    cout<<mergesort(br,0,nn-1);
    for(int i=0;i<nn;i++){
     cout<<br[i]<<" ";
    }
    cout<<endl;
    int cr[]={1,5,3,6,4,7};
    long long  nm=sizeof(cr)/sizeof(cr[0]);
    //long long  inv=mergesort(ar,0,n-1);

    cout<<mergesort(cr,0,nm-1);
    for(int i=0;i<nm;i++){
     cout<<cr[i]<<" ";
    }
    cout<<endl;
    */
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long n;
        cin>>n;
        int *ar=new int[n];

        for(int j=0;j<n;j++){
            cin>>ar[j];
        }
        long long ans=mergesort(ar,0,n-1);
        cout<<ans;
    }
    return 0;

}
