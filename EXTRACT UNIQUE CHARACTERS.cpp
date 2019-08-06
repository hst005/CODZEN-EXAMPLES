#include <iostream>
#include<bits/stdc++.h>
#include<unordered_map>
# define NO_OF_CHARS 256
# define bool int
using namespace std;
 /*
 set <string> uniqueChar(char *str){
/*
    map <char,int> ab;
    size_t n=strlen(str);
  for (int i=0;i<n;i++){
    ab[str[i]]+=1;
  }
  string s="";
  for (int i=0;i<n;i++){
    if (ab[str[i]]==1)
        s=s+str[i];
  }
  int k=s.length();
  //   char *res=new char[n];
//     strncpy(res,s,k);
  return s;



 vector <string> t;

    size_t n=strlen(str);
  for (int i=0;i<n;i++){
    t.push_back(str[i]);
  }
  set <string> res=(t.begin(),t.end());

  return res;

}
*/
/*

char* uniqueChar(char *str){
    size_t n=strlen(str);
    // Write your code here
// Used as index in the modified string
   int index = 0;

   // Traverse through all characters
   for (int i=0; i<n; i++) {

     // Check if str[i] is present before it
     int j;
     for (j=0; j<i; j++)
        if (str[i] == str[j])
           break;

     // If not present, then add it to
     // result.
     if (j == i)
        str[index++] = str[i];
   }

   return str;
}


int main()
{
    cout << "Hello world!" << endl;
    char *ab="Hello world!";
    cout<<ab;
    set <string> res1;
    string s="hello world";
    ab=uniqueChar(ab);
    cout<<ab;
    return 0;
}
*/


/*
char *removeDuplicate(char str[])
{
    int n = sizeof(str) / sizeof(str[0]);

   // Used as index in the modified string
   int index = 0;

   // Traverse through all characters
   for (int i=0; i<n; i++) {

     // Check if str[i] is present before it
     int j;
     for (j=0; j<i; j++)
        if (str[i] == str[j])
           break;

     // If not present, then add it to
     // result.
     if (j == i)
        str[index++] = str[i];
   }
   char *res=new char[index];

   for(int l=0;l<index;l++){
    res[l]=str[l];
   }

   return res;
}

char *uniqueChar(char *str)
{
  bool bin_hash[NO_OF_CHARS] = {0};
  int ip_ind = 0, res_ind = 0;
  char temp;

  // In place removal of duplicate characters
  while (*(str + ip_ind))
  {
    temp = *(str + ip_ind);
    if (bin_hash[temp] == 0)
    {
        bin_hash[temp] = 1;
        *(str + res_ind) = *(str + ip_ind);
        res_ind++;
    }
    ip_ind++;
  }

  // After above step string is stringiittg.
    // Removing extra iittg after string
  *(str+res_ind) = '\0';

  return str;
}*/
// Driver code
char* uniqueChar(char *str){
     int len = strlen(str);
      if(len == 0)
        { char *ans = new char[1];
      ans[0] = '\0';
      return ans; }
      char *ans = new char[len + 1];
       unordered_map <char, bool> hm;
       int i = 0;
       for(int currIndex = 0; currIndex < len; currIndex++){
            char currChar = str[currIndex];
       if(hm.count(currChar) == 0){
            hm[currChar] = true;
       ans[i++] = currChar;
        }
         }
          ans[i] = '\0';
           return ans;
}
int main()
{
   char str[]= "geeksforgeeks";
   int n = sizeof(str) / sizeof(str[0]);
   //cout << removeDuplicate(str);
   cout<<uniqueChar(str);
   return 0;
}
