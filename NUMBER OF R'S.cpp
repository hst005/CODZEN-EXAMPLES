#include <bits/stdc++.h>
using namespace std;
int A[1000000];

int main() {
    int t, i, cr, c_max, m, n, j, index;
    string S;
    cin>>t;

    while(t--) {
            cin>>S;
    cr=0;
    n=S.size();
    for(i=0;i<n;i++) {
            if(S[i]=='R') {
                A[i]=-1;
                cr++;
            }

            else A[i]=1;

            }
        if(cr==n) {
            cout<<n-1<<"\n";
            continue;
            }
            //Now find maximum subarray using kadane's algorithm
                c_max=0;m=0;
                for(i=0;i<n;i++) {
                        c_max=c_max+A[i];
                if(c_max<0)
                    c_max=0;
                if(c_max>m)
                    m=c_max;
                }

            cout<<m+cr<<"\n";
        }
    return 0;
}

/*#include <iostream>

using namespace std;

long int rs(string s){
long int n=s.length();
long int a[n];
a[0]=0;
for(int i=1;i<n;i++){
        long int c=0,flag=0;
        int j=i-1;
        while(s[j]=='R'){
            c++;
            j--;
        }
        flag=1;
        j--;
        c++;
    for(;j>=0;j--){
        if(s[j]=='K'){
            c++;
            break;
        }
        else{
            c++;
        }
    }
    a[i]=c;
}
long int m=a[0];
for(int i=0;i<n;i++){
    if(m<a[i])
        m=a[i];
}

return m;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<rs(s)<<endl;

    }
    return 0;
}
*/
