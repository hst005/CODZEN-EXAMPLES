#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c,n;
        cin>>a>>b>>c>>n;
        int temp=0;
        int *ar=new int[n];
        ar[0]=a;
        ar[1]=b;
        temp=((a*10)%41+b%41)%41;
        int t1,t2;
        t1=a;t2=b;
        for(int i=2;i<n;i++){
            ar[i]=(t2*c+t1)%10;
            t1=t2;
            t2=ar[i];
            temp=(temp*10+ar[i]%41)%41;
        }
        if(temp==0){
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
