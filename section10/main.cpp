// Section 10
// Challenge - 
// Substitution Cipher

/*
A simple and very old method of sending secret messages is the substitution cipher.
You might have used this cipher with your friends when you were a kid.
Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

Write a program thats ask a user to enter a secret message.

Encrypt this message using the substitution cipher and display the encrypted message.
Then decryped the encrypted message back to the original message.

You may use the 2 strings below for  your subsitition.
For example, to encrypt you can replace the character at position n in alphabet 
with the character at position n in key.

To decrypt you can replace the character at position n in key
with the character at position n in alphabet.

Have fun! And make the cipher stronger if you wish!
Currently the cipher only substitutes letters - you could easily add digits, puncuation, whitespace and so
forth. Also, currently the cipher always substitues a lowercase letter with an uppercase letter and vice-versa.
This could also be improved.

Remember, the less code you write the less code you have to test!
Reuse existing functionality in libraries and in the std::string class!
*/

#include <iostream>
#include <string>
#include <variant>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// No punctuation 
string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ "};
string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr "};

string encrypt(string msg){

  int letterIndex;
  string encrypted_msg {};
  for (char ch:msg){
    
    letterIndex = alphabet.find_first_of(ch);
    if (letterIndex == -1){
      encrypted_msg+=ch;
      continue;
    }
    encrypted_msg += key.at(letterIndex);
  }

  return encrypted_msg;
}

string decrypt(string msg){

  int letterIndex;
  string decrypted_msg;

  for (char ch:msg){
    
    letterIndex = key.find_first_of(ch);
    if (letterIndex == -1){
      decrypted_msg+=ch;
      continue;
    }
    decrypted_msg += alphabet.at(letterIndex);
  }

  return decrypted_msg;
}

int main() {
    
    
    string original_msg;

    cout << "Write secret message:" << endl;

    getline(cin, original_msg);

    string encrypted_msg = encrypt(original_msg);

    cout << "Encrypted message: " << encrypted_msg << endl;

    cout << "Decrypted message: " << decrypt(encrypted_msg) << endl;

    cout << "Goodbyessss" << endl;

    
    return 0;
}
