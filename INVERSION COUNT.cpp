#include <iostream>

using namespace std;

long long merge(int  *a,long long  start,long long  mid,long long  end){
long long  inv=0;
long long  i,j,k;
i=start;
j=mid+1;
k=0;
long long  temp[end-start+1];
while(i<=mid && j<=end){
    if (a[i]>a[j]){
        temp[k]=a[j];
        j++;
        inv+=mid-i+1;


    }
    else{
        temp[k]=a[i];
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

return inv;
}




long long mergesort(int *ar,long long  start,long long  end){
long long inv=0;
if (start>=end){
    return 0;
}
long long  mid=start+(end-start)/2;
long long inv1=mergesort(ar,start,mid);
long long inv2=mergesort(ar,mid+1,end);
long long inv3=merge(ar,start,mid,end);

inv=inv1+inv2+inv3;

return inv;

}

long long solve(int A[], int n)
{
    long long temp=mergesort(A,0,n-1);
	// Write your code here.
	return temp;
}
int main()
{
    int ar[]={2,5,1,3,4};
    long long  n=sizeof(ar)/sizeof(ar[0]);
    //long long  inv=mergesort(ar,0,n-1);
    for(int i=0;i<n;i++){
     cout<<ar[i]<<" ";
    }
    //cout<<inv<<endl;
    cout<<solve(ar,n);
    return 0;
}
