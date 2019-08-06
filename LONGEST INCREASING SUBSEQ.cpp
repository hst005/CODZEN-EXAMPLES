#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int lis(int n,int* input) {
	int* output = new int[n];
	output[0] = 1;
	for (int i = 1; i < n; i++) {
		output[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (input[j] > input[i]) {
				continue;
			}
			int possibleAns = output[j] + 1;
			if (possibleAns > output[i]) {
				output[i] = possibleAns;
			}
		}
	}
	int best = 0;
	for (int i = 0; i < n; i++) {
		if (best < output[i]) {
			best = output[i];
		}
	}
	delete [] output;
	return best;
}
int lisbruteforce(int n,int *ar){

int op[n];
op[0]=1;
//fill_n(op,op+sizeof(op),1);

for(int i=1;i<n;i++){
    for(int j=i-1;j>=0;j--){
        if(ar[j]<ar[i]){
            op[i]=max(op[i],op[j]+1);
            break;
        }
    }
}
sort(op,op+n);
return op[n-1];

}


int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    cout<<lis(n,ar);
    return 0;
}
