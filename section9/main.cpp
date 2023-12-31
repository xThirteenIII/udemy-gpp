// Section 9
// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.
Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void displayMenu(){
  
  cout << "\nP - Print Numbers" << endl;
  cout << "A - Add a number" << endl;
  cout << "M - Display mean of the numbers" << endl;
  cout << "S - Display smallest number" << endl;
  cout << "L - Display largest number"<< endl;
  cout << "Q - Quit" << endl;
  cout << "\nEnter your choice: " << endl;
}

// global variables
const vector<char> validChoices {'p', 'a', 'm', 's', 'l', 'q'};

vector<int> vectorOfInt;

float mean = 0.0;
int smallest, largest = 0;

// Menu functions:
void printNumbers(){
  
  if (!vectorOfInt.empty()){

    cout << "[ ";
    for (auto number:vectorOfInt){
      cout << number << " ";
    }
    cout <<"]" << endl;
  }else{

    cout << "[] - the list is empty" << endl;
  }
  return;
}

void addNumber(){

  int number;
  
  
  do {
    cout << "Type number to add to the list: ";
    cin >> number;
  }while(
    !cin.good()
  );

  vectorOfInt.push_back(number);

  cout << "Added " << number << endl;

  return;
}

void displayMean(){

  if (vectorOfInt.empty()){

    cout << "Unable to calculate the mean - no data" << endl;
    return;
  }

  int sum = 0;

  for (auto number:vectorOfInt){
    sum += number;
  }

  mean = static_cast<float>(sum) / vectorOfInt.size();

  cout << "Vector mean value: " << setprecision(2) << mean << endl;
  return;

}

void displayLargest(){

  int max = 0;
  
  if (vectorOfInt.empty()){
    cout << "Unable to determine the smallest number - list is empty" << endl;
    return;
  }

  for (auto number:vectorOfInt){
    if (number > max){
      max = number;
    }
  }

  cout << "Largest number in the list is: " << max << endl;
  return;
}

void displaySmallest(){

  int min = 0;

  if (vectorOfInt.empty()){
    cout << "Unable to determine the largest number - list is empty" << endl;
    return;
  }

  for (auto number:vectorOfInt){
    if (number < min) {
      min = number;
    }
  }

  cout << "Smallest number in the list is: " << min << endl;
  return;
}



bool isAValidChoice(char character){
  
  for (auto choice:validChoices) {
    if (character == choice){
      return true;
    }
  }

  return false;
}

// executes clear cmd, working on bash
void clearScreen(){
    system("clear");
}

void makeActionCorrespondingTo(char choice){

  //check if choice is valid
  switch (choice) {
    case 'p':
      printNumbers();
      break;
    case 'a':
      addNumber();
      break;
    case 'm':
      displayMean();
      break;
    case 's':
      displaySmallest();
      break;
    case 'l':
      displayLargest();
      break;
    case 'q':
      cout << "Goodbye" << endl;
      break;
    default:
      cout << "Unknown selection, please try again" << endl;
  }

}

int main() {
  
  char userChoice, lowerUserChoice;

  do{

    displayMenu();
    cin >> userChoice;
    lowerUserChoice = static_cast<char>(tolower(userChoice));
    clearScreen();
    makeActionCorrespondingTo(lowerUserChoice);
  }while(
    isAValidChoice(lowerUserChoice) && lowerUserChoice != 'q'
  );
  


  return 0;
}

