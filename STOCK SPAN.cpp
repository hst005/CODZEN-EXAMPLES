#include <iostream>

using namespace std;
int* stockSpan(int *ar, int n) {
	int *res=new int[n];
	res[0]=1;
	for(int i=1;i<n;i++){
            int flag=1;
        for(int j=i-1;j>=0;j--){
            if(ar[i]>ar[j]){
                flag++;
            }
            else{
                break;
            }
        }
        res[i]=flag;
	}
	return res;

}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int *res=new int[n];
    res=stockSpan(a,n);
     for (int i=0;i<n;i++){
        cout<<res[i];
    }
    return 0;
}
