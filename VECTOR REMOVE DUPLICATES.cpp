#include <iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> removeDuplicates(vector<int> input){
sort(input.begin(),input.end());
input.erase( unique( input.begin(), input.end() ), input.end() );
    // Write your code here
return input;
}

int main()
{
    vector <int> v1;
    //v1[0]=10;
    //v1[1]=2;v1[2]=7;v1[3]=3;v1[4]=1;v1[5]=2;v1[6]=3;v1[7]=10;v1[8]=1;v1[9]=7;v1[10]=10;
    v1.push_back(10);
    v1.push_back(2);
    v1.push_back(7);
    v1.push_back(3);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(10);
    v1.push_back(1);v1.push_back(7);
    v1.push_back(10);
vector<int>::iterator it;
v1=removeDuplicates(v1);
for(it=v1.begin();it<v1.end();it++){
    cout<<*it<<endl;
}

    return 0;
}
