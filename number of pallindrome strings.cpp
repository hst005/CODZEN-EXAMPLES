#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int oddps(char s[],int n){
//int mid=1;
int coun=0;
for(int mid=1;mid<=n;mid++){

int left=mid-1;
int right=mid+1;
while(left>=0 && right<=n && s[left]==s[right]){
    coun++;
    left--;
    right++;
}

}
return coun;
}

int evenps(char s[],int n){
//int mid=1;
int coun=0;
for(int mid=1,mid2=0;mid<=n && mid2<n ;mid++,mid2++){
if(s[mid]==s[mid2]){
int left=mid2-1;
int right=mid+1;
while(left>=0 && right<=n && s[left]==s[right]){
    coun++;
    left--;
    right++;
}
}
}
return coun;
}

int countPalindromeSubstrings(char s[]) {
	// Write your code here
	int n=strlen(s);
  return oddps(s,n)+evenps(s,n)+n;


}

/*#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int oddps(char s[],int n){
//int mid=1;
int coun=0;
for(int mid=1;mid<n;mid++){

int left=mid-1;
int right=mid+1;
while(left>=0 && right<=n && s[left]==s[right]){
    coun++;
    left--;
    right++;
}

}
return coun;
}

int evenps(char s[],int n){
//int mid=1;
int coun=0;
for(int mid=1,mid2=0;mid<=n && mid2<n ;mid++,mid2++){
if(s[mid]==s[mid2]){
int left=mid2-1;
int right=mid+1;
while(left>=0 && right<=n && s[left]==s[right]){
    coun++;
    left--;
    right++;
}
}
}
return coun;
}

int countPalindromeSubstrings(char s[]) {
	// Write your code here
	int n=strlen(s);
  return oddps(s,n)+evenps(s,n)+n;


}*/
int main()
{
    char s[]="aba";
    cout<<countPalindromeSubstrings(s);

    return 0;
}
