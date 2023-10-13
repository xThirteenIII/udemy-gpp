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

  //idea is to save from 0 to sentence[i-1], then reverse it, concat with
  // sentence[i] and lastly with sentence_reversed
  for (int i = 0; i < static_cast<int>(sentence.length()); i++){
    if (i == 0){
      line_to_print = sentence[0];
      continue;
    }
    substring = sentence.substr(0, i - 1);
    line_to_print = substring + sentence.at(i);
    reverse(substring.begin(), substring.end());
    line_to_print += substring;
    cout << line_to_print << endl;
  }

  return 0;
}

