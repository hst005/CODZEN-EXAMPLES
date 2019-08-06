#include <iostream>
#include<bits/stdc++.h>

using namespace std;
/*
map <int,string> reveachwrd(string s){
map <int,string> temp;
for (int i=0;i<s.size();i++){

        string t="";
    while(s[i]!=' '){
        t=t+s[i];
        i++;
    }
    temp[i]=t;
}
return temp;
}
int main()
{
    string t="hst Hello world!";
    getline(cin,t);
    map <int,string> abc;
    abc=reveachwrd(t);
     map <int,string>::iterator it;
     for(it=abc.begin();it!=abc.end();it++){
        cout<<it->first<<"  "<<it->second<<endl;
     }
    return 0;
}
*/
/*
vector <string> rev(string s){
vector <string> res;
string temp="";
for(int i=0;i<s.size();i++){
    if(s[i]==' ' || i==s.size()-1){
        res.push_back(temp);
        i++;
        temp="";
    }
    temp=temp+s[i];
}
return res;
}*/
/*
string result="";
vector <string>::iterator it;
for (it=res.begin();it!=res.end();it++){
    string t=(*it);
    string ret;
    for(int i=t.length()-1;i>=0;i--){
        result=result+t[i];
    }
    result=result + " ";


}
*/

string rev(string s){
vector <string> res;
string temp="";
for(int i=0;i<s.size();i++){
    if(s[i]==' '|| i==s.size()-1){
        res.push_back(temp);
        i++;
        temp="";
    }
    temp=temp+s[i];
}
string result="";
vector <string>::iterator it;
for (it=res.begin();it!=res.end();it++){
    string t=(*it);
    string ret;
    for(int i=t.length()-1;i>=0;i--){
        result=result+t[i];
    }
    result=result + " ";


}
return result;
}

void reverseEachWord(char input[]){
    string s="";
    for (int i=0;input[i]!='\0';i++){
        s=s+input[i];
    }
    vector <string> res;
string temp="";
for(int i=0;i<s.size();i++){
    if(s[i]==' '|| i==s.size()-1){
        res.push_back(temp);
        i++;
        temp="";
    }
    temp=temp+s[i];
}
string result="";
vector <string>::iterator it;
for (it=res.begin();it!=res.end();it++){
    string t=(*it);
    string ret;
    for(int i=t.length()-1;i>=0;i--){
        result=result+t[i];
    }
    result=result + " ";


}
cout<<result;
}

int main()
{
    /*
    string t="";
    getline(cin,t);
    string l=rev(t);
    cout<<l<<endl;
    */
    char in[]="hdb sknvfv jkvsn vdskjn vskjn ";
    cout<<in<<endl;
   reverseEachWord(in);
    return 0;
}
