#include <iostream>
#include<bits/stdc++.h>
#include <string.h>
using namespace std;



int getCodes(string input, string output[10000]) {
    //char key[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


if (input.size()==1){
        int t=input[0]-'0';
        output[0]=t+'a'-1;
    return 1;
}

int smalltemp=getCodes(input.substr(1),output);
char *temparr=new char[10000];
int t=input[0]-'0';
char temp=t+'a'-1;
int i;
for (i=0;i<smalltemp;i++){
    output[i]=output[i]+temp;
}

int smalltemp2=getCodes(input.substr(2),output);

int flag=0;
 t=(input[0]-'0')*10+(input[1]-'0');
if (t>=10 && t<=26){
        flag=1;
char temp=t+'a'-1;
for (int j=0;j<smalltemp2;j++){
    output[i]=output[i]+temp;
    i++;
}
}




return smalltemp2*flag + smalltemp;

}


int main()
{
    cout<<5+'a'-1;
    string o[10000];
    cout<<getCodes("1123",o);
    /*
    char t1='1';
    char t2='2';
    char t3='3';
    char t4='4';
    cout<<t4-'1';
    cout<<t3-t2;


    cout << "Hello world!" << endl;
    */
    return 0;
}

