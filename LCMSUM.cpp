#include<cstdio>
#include<iostream>
#include<cmath>
#define Lim  1000000
using namespace std;
long long mohit[1000010]  ;
long long  ret[1000010];

    void cal_mohit()
       {
          for(int i = 1 ;i <= Lim ; i++ ) mohit[i]=i;
          for(int i=2 ; i<= Lim ; i++ )
            if ( mohit[i] == i)
              for(int j = 2*i ; j <= Lim ; j += i) mohit[j] -=  mohit[j]/ i ;
          for(int i=2 ; i<= Lim ; i++) if ( mohit[i]==i) mohit[i] = i-1;
	  for(int i=1;i <= Lim ; i++) for (int j = i ; j <= Lim ; j += i  ) ret[j]+= i*mohit[i];
       }
    void func(long long n)
        {
	// Write your code here

          cal_mohit();
        long long sum;

          int t , i, sqt;
        sum = ( 1 + ret[n] ) * n / 2;
             printf("%lld\n",sum);

        }

    int main()
       {
            int n;
             scanf("%d",&n);
             func(n);

       }
