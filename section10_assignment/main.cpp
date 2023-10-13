/*Write a C++ program that displays a Letter Pyramid from a user-provided std::string.

Prompt the user to enter a std::string and then from that string display a Letter Pyramid as follows:

It's much easier to understand the Letter Pyramid given examples.

If the user enters the string "ABC", then your program should display:

  A                                                                                                                    
 ABA                                                                                                                   
ABCBA 

If the user enters "C++isFun!", then your program should display:

 

        C                                                                                                              
       C+C                                                                                                             
      C+++C                                                                                                            
     C++i++C                                                                                                           
    C++isi++C                                                                                                          
   C++isFsi++C                                                                                                         
  C++isFuFsi++C                                                                                                        
 C++isFunuFsi++C                                                                                                       
C++isFun!nuFsi++C
*/

#include <algorithm>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::reverse;

int main(){

  string sentence;
  string substring;
  string line_to_print;


  cout << "Write sentence:" << endl;
  std::getline(cin, sentence);

  // Total spaces to print are sentence.length() - 2.
  // thats because we start from ____0____ and go to __01210__ and so on.
  // Total lenght is sentence.length() - 1 and we sub another -1 due to the 
  // first element printed.
  int sentence_length = static_cast<int>(sentence.length());
  int total_blankspaces = sentence_length * 2 - 2; // note: this will always be even 

  //idea is to save from 0 to sentence[i-1], then reverse it, concat with
  // sentence[i] and lastly with sentence_reversed
  for (int i = 0; i < sentence_length; i++){
    string spaces_left_and_right (total_blankspaces/2, ' ');
    if (i == 0){
      line_to_print = spaces_left_and_right + sentence[0] + spaces_left_and_right;
      cout << line_to_print << endl;
      total_blankspaces -= 2;
      continue;
    }
    // note: substr goes from 0 to i - 1 actually
    substring = sentence.substr(0, i);
    line_to_print = substring + sentence.at(i);
    reverse(substring.begin(), substring.end());
    line_to_print += substring;
    cout << spaces_left_and_right + line_to_print + spaces_left_and_right<< endl;
    total_blankspaces -= 2;
  }

  return 0;
}

