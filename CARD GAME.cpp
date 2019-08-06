#include <bits/stdc++.h>
#define ll long long int
#define PII pair<int, int>
#define f first
#define s second
#define mk make_pair
#define pb push_back

using namespace std;
int main() {
     int n, i, j;
      ll k, x, ans=0;
       cin>>n>>k;
        x=k;
        vector<ll>a(n);
        for(i=0;i<n;i++)
            cin>>a[i];
        vector<PII> vp;
        //store prime factors of k with respective powers
        for(i=2;i*i<=x;i++) {
                if(x%i==0) {
                    int cn=0;
        while(x%i==0) {
                x/=i;
                cn++;
                }
                vp.pb(mk(i, cn));
            }
        }
        if(x!=1) {
                vp.pb(mk(x, 1));
        }
        //vq contains all prime factors of k with their respective powers 0
        vector<PII> vq=vp;
        for(i=0;i<vq.size();i++)
            vq[i].s=0;
        //j is back pointer and i is front pointer
        //We are checking if j..i is divisible by k by adding prime factors of a[i] to vq
        //If it is divisible, then j...z for all z > i is also divisible by k
        //So we add n-i to answer
        //Then we remove j's contribution by subtracting it's prime factors from vq
        j=0;
        for(i=0;i<n;i++) {
        //add factors of a[i]
            for(int z=0;z<vp.size();z++) {
                    if(a[i]%vp[z].f==0) {
                        x=a[i];
                        int cn=0;
                        while (x%vp[z].f==0) {
                                x/=vp[z].f;
                                cn++;
                            }
                        vq[z].s+=cn;
                        }
                    }
                    while(j<=i) {
                        int z;
        //check if divisible by k from j to i
        for(z=0;z<vp.size();z++) {
                if(vp[z].s>vq[z].s)
                    break;
        }
        if(z!=vp.size())
            break;
        //if divisible update ans
        ans+=n-i;
        //remove factors of a[j] from vq
        for(int z=0;z<vp.size();z++) {
            if(a[j]%vp[z].f==0) {
                x=a[j];
        int cn=0;

        while(x%vp[z].f==0) {
                x/=vp[z].f;
                cn++;
                    }

        vq[z].s-=cn;

            }

        }

        j++;
        }

    }
         cout<<ans;

         return 0;
         }
