/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Smarsh Nicholas
 */


#include "std_lib_facilities (1).h"

//globar var for vector
vector<string> string_numbers;

//create all of the numbers 0-9 in written format
void create_vector()
{
  string_numbers.push_back("zero");
  string_numbers.push_back("one");
  string_numbers.push_back("two");
  string_numbers.push_back("three");
  string_numbers.push_back("four");
  string_numbers.push_back("five");
  string_numbers.push_back("six");
  string_numbers.push_back("seven");
  string_numbers.push_back("eight");
  string_numbers.push_back("nine");
}

// tries to read an integer from input; if this fails, input is cleared and read as a string
double getNumber()
{
  int number;
  //call for input
  if (cin>>number)
    return number;
  cin.clear();

  //if the number is written out, loop through the vector and whatever it matches, is the number to use.
  string number_s;
  cin >> number_s;
  for (int i = 0; i<10; ++i) {
    if (string_numbers[i] == number_s)
        return i;
  }

  //since we dont need negatives, we can use -1 as a flag for if the input is incorrect
  return(-1);
}

int main()
{
  //initilize the vector
  create_vector();

  //ask user for input
  cout << "enter 2 values and then enter an operator:\n(press enter between each input)\n";

  //while loop to continuously calculate
  while (true) 
  {
    //initilize variables
    double firstNumber = 0;
    double secondNumber = 0;
    char sign;

    //get input
    firstNumber = getNumber();
    secondNumber = getNumber();
    cin >> sign;

    //if either number is -1, then its written incorrectly
    if (firstNumber == -1 || secondNumber == -1)
      cout << "must be 0-9, or a spelt out single digit\n";

    //run switch and go through cases
    else 
    {
      switch(sign) 
      {
        //addition
        case '+':
          cout << "The sum of " << firstNumber << " and " <<secondNumber << " is " << firstNumber + secondNumber <<".\n";
          break;
        //subtraction
        case '-':
          cout << "The difference of " << firstNumber << " and "<< secondNumber << " is " << firstNumber - secondNumber<< ".\n";
          break;
        //multiplication
        case '*':
          cout << "The product of " << firstNumber << " and " <<secondNumber << " is " << firstNumber * secondNumber <<".\n";
          break;
        //division
        case '/':
          //if it divides by zero...
          if (secondNumber == 0)
              cout << "cannot divide by zero\n";
          else
              cout << "The quotient of " << firstNumber << " and " << secondNumber << " is " << firstNumber / secondNumber << ".\n";
          break;
        //if none of the cases work: run default
        default:
          cout << "not a valid sign (please use *, /, +, or -)\n";
          break;
      }
    }
  }
}