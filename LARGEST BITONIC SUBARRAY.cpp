#include <iostream>

using namespace std;

	int longestBitonicSubarray(int *input, int n) {

	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
     	int* output = new int[n];
     	int* inc = new int[n];
     	int* dec = new int[n];
     	inc[0]=1;
     	dec[0]=1;
     	inc[1]=1;
     	dec[1]=1;

	output[0] = 1;
	for(int i=1;i<n;i++){
            inc[i]=1;
           // dec[i]=1;
        for(int j = i - 1; j >= 0; j--) {
			if (input[j] >= input[i]) {
				continue;
			}
			int possibleAns = inc[j] + 1;
			if (possibleAns > inc[i]) {
				inc[i] = possibleAns;
			}
		}
	}
	dec[n-1]=1;
	for(int i=n-2;i>=0;i--){
        dec[i]=1;
        for(int j=i+1;j<n;j++){
                if(input[i]<=input[j]){
                    continue;
                }

			int possibleAns = dec[j] + 1;
			if (possibleAns > dec[i]) {
				dec[i] = possibleAns;
			}

        }
	}

	int  max = inc[0] + dec[0] - 1;
    for (int i = 1; i < n; i++)
        if (inc[i] + dec[i] - 1 > max)
            max = inc[i] + dec[i] - 1;

    delete [] inc;
 	delete [] dec;
    delete [] output;

    return max;
    }

int main()
{
    long int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    cout<<longestBitonicSubarray(ar,n);
    return 0;
}
