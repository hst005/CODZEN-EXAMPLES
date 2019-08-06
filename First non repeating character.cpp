#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
char nonRepeatingCharacter(string str){
    string::iterator it;
    string::iterator i;
  for ( it=str.begin();it<str.end();it++){
    char temp;
    temp=*it;
    i=find(it+1,str.end(),temp);

    if (i!=str.end() || ){
        return temp;
    }
  }
  return str[0];
  //Write your code here

}
void nonRepeatingCharacter(string str){
int n=str.length();
  for ( int i=0;i<n;i++){
   char t=str[i];
   cout<<t<<endl;
    string temp=str.substr(i+1,n-1);
    cout<<"temp is "<<temp<<endl;
    int pos=temp.find(t);
    cout<<pos<<endl;
    if(pos!=-1){
    //    return t;
    cout<<"found"<<endl;
    }
cout<<endl<<endl;
  }
  //return str[0];
  //Write your code here

}

char nonRepeatingCharacter(string str){
int n=str.length();
int flag=0;
  for ( int i=0;i<n;i++){
        flag++;
   char t=str[i];
    string temp=str.substr(i+1,n-1);
    int pos=temp.find(t);
    if(pos==-1){
           return t;
    }
  }
  if(flag==n)
    return str[n-1];
  return str[0];

}


char FirstNonRepeatedchar(const char* str, int len){
    int count[26]={0};
    for(int i=0;i<len;i++)
    {
        count[*(str+i)]++;
    }
    for(int i=0;i<len;i++)
    {
        if(count[*(str+i)]==1)
        return *(str+i);
    }
return '@';
}
*/
char nonRepeatingCharacter(string str){
map <char,int> ab;
int n=str.length();
  for (int i=0;i<n;i++){
    ab[str[i]]+=1;
  }
/*
  map <char,int>::iterator it;
  for(it=ab.begin();it!=ab.end();it++){
    cout<<it->first<<" "<<it->second<<endl;
  }
  *///Write your code here
 for (int i=0;i<n;i++){
    if (ab[str[i]]==1)
        return str[i];
  }
  return str[0];
}

int main()
{
    string s1;
    cin>>s1;
    char c;
    c=nonRepeatingCharacter(s1);
    cout<<c;
    return 0;
}
