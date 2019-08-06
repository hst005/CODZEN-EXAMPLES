#include<bits/stdc++.h>
using namespace std;
int grundyNumber(int n){
    if (n == 0){
        return 0;
    }
    int* gn = new int[3];
    gn[0] = grundyNumber(n/2);
    gn[1] = grundyNumber(n/3);
    gn[2] = grundyNumber(n/6);

    sort(gn, gn + 3);

    int k = 0;
    for (int i = 0; i < 3; i++){
        if (gn[i] < k){
            continue;
        }
        else if (gn[i] == k){
            k++;
        }
        else{
            break;
        }
    }

    return k;
}


int main() {
    int n; cin >> n;
    cout << grundyNumber(n);
}
