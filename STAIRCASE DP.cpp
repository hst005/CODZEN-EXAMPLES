#include <iostream>
#define mod 1000000007
using namespace std;

long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
long ot[n+1];
ot[0]=0;
ot[1]=1;
ot[2]=2;
ot[3]=4;
if(n>3){
for(int i=4;i<=n;i++){
    ot[i]=(ot[i-1]+ot[i-2]+ot[i-3]);
}
}

return ot[n];
}

int main()
{
    cin
    return 0;
}
