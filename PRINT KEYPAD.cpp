
#include <iostream>
#include<bits/stdc++.h>

using namespace std;
void printKeypadHelper(int num, string output, string options[10]){
     if(num == 0)
        { cout << output << endl;
     return; }
      int digit = num % 10;
       int i = 0;
        while(i < options[digit].length()){
                printKeypadHelper(num / 10, options[digit][i] + output, options);
        i++;
         }
         return;
          }
          void printKeypad(int num){
              string options[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
              printKeypadHelper(num, "", options);
               return;
               }
/*
void printKeypad(int num,string output=""){
 string numbers[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

 if(num==0){
    cout<<output;
    return;
 }

 while(){

 }

}

int main()
{
   int numb;
   cin>>numb;

	printKeypad(numb);
	return 0;
}

*/

/*

#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>
#include <string.h>
 #include<bits/stdc++.h>


// hashTable[i] stores all characters that correspond to digit i in phone
const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};

// A recursive function to print all possible words that can be obtained
// by input number[] of size n.  The output words are one by one stored
// in output[]
void  printWordsUtil(int number[], int curr_digit, char output[], int n)
{
    // Base case, if current output word is prepared
    int i;
    if (curr_digit == n)
    {
        printf("%s ", output);
        return ;
    }

    // Try all 3 possible characters for current digir in number[]
    // and recur for remaining digits
    for (i=0; i<strlen(hashTable[number[curr_digit]]); i++)
    {
        output[curr_digit] = hashTable[number[curr_digit]][i];
        printWordsUtil(number, curr_digit+1, output, n);
        if (number[curr_digit] == 0 || number[curr_digit] == 1)
            return;
    }
}

// A wrapper over printWordsUtil().  It creates an output array and
// calls printWordsUtil()
void printWords(int number[], int n)
{
    char result[n+1];
    result[n] ='\0';
    printWordsUtil(number, 0, result, n);
}

void printKeypad(int tr){

int temp=tr;
int dig=0;
    while(tr!=0){
        dig++;
        tr=tr/10;
    }

    int *number=new int[dig];
    int i=0;
    tr=temp;
    while(tr!=0){
        number[dig-i-1]=tr%10;
        tr=tr/10;
        i++;
    }
  printWords(number, dig);
  }

*/
/*


#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>
#include <string.h>
 #include<bits/stdc++.h>


// hashTable[i] stores all characters that correspond to digit i in phone
const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};

// A recursive function to print all possible words that can be obtained
// by input number[] of size n.  The output words are one by one stored
// in output[]
void  printWordsUtil(int number[], int curr_digit, char output[], int n)
{
    // Base case, if current output word is prepared
    int i;
    if (curr_digit == n)
    {
        cout<<output<<endl;
        return ;
    }

    // Try all 3 possible characters for current digir in number[]
    // and recur for remaining digits
    for (i=0; i<strlen(hashTable[number[curr_digit]]); i++)
    {
        output[curr_digit] = hashTable[number[curr_digit]][i];
        printWordsUtil(number, curr_digit+1, output, n);
        if (number[curr_digit] == 0 || number[curr_digit] == 1)
            return;
    }
}

// A wrapper over printWordsUtil().  It creates an output array and
// calls printWordsUtil()
void printWords(int number[], int n)
{
    char result[n+1];
    result[n] ='\0';
    printWordsUtil(number, 0, result, n);
}

void printKeypad(int tr){

int temp=tr;
int dig=0;
    while(tr!=0){
        dig++;
        tr=tr/10;
    }

    int *number=new int[dig];
    int i=0;
    tr=temp;
    while(tr!=0){
        number[dig-i-1]=tr%10;
        tr=tr/10;
        i++;
    }
  printWords(number, dig);
  }
*/
int main()
{
    int numb;
   cin>>numb;
printKeypad(numb);
    return 0;
}


