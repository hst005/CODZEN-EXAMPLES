#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int keypad(int num, string output[]){
    map <int,string> numbers;
    numbers[0]="";
    numbers[1]="";
    numbers[2]="abc";
    numbers[3]="def";
    numbers[4]="ghi";
    numbers[5]="jkl";
    numbers[6]="mno";
    numbers[7]="pqrs";
    numbers[8]="tuv";
    numbers[9]="wxyz";

    if(num==0 ){
        output[0]="";
        return 1;
    }
    else{
            int t;
    t=num%10;
            //num=num/10;

        int small=keypad(num/10,output);
        string temp=numbers[t];
        /*
       for(int i=0;i<temp.size();i++){
                for(int j=0;j<small;j++){
            output[temp.size()*i+j]=output[j];
                }

        }*/

	string* abc = new string[1000];
        for(int i=0;i<temp.size();i++){
                for(int j=0;j<small;j++){
            abc[small*i+j]=output[j]+temp[i];
                }

        }
        for(int i=0;i<temp.size()*small;i++){
            output[i]=abc[i];
        }
        delete [] abc;
        return temp.size()*small;

    }




}

int main()
{
   int numb;
   cin>>numb;

	string* output = new string[1000];
	int count = keypad(numb, output);
	for (int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}
	delete [] output;
    return 0;
}
