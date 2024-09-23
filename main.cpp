#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

bool check_number(string str) {
   for (int i = 0; i < str.length(); i++) {
    if (isdigit(str[i]) == false) {
      return false;
    }
  }
  return true;
}

int main() {
    srand(time(NULL));
    int correctNumber = rand() % 100 + 1;
    int guess;
    int guess_times = 0;
    bool guessedCorrectly = false;
    cout << "Welcome to the number guessing game!" << endl;
    
    while (!guessedCorrectly) {
      cout << "Guess a number between 1 and 100. You have " << 4 - guess_times << " guess(es) remaining: ";
      string guess_str;
      cin >> guess_str;
      if (check_number(guess_str)) {
        guess = stoi(guess_str);
        if (guess == correctNumber) {
          guessedCorrectly = true;
          cout << "Correct! You win the game!" << endl;
        } else if (guess < correctNumber) {
          cout << "Too low. ";
          if (guess_times == 3) {
            cout << "You didn't guess correctly within the allowed number of attempts. Game over." << "the correct number was: " << correctNumber << endl;
            break;
          } else {
            cout << "Please try again." << endl;
          }
        } else {
          cout << "Too high. ";
          if (guess_times == 3) {
            cout << "You didn't guess correctly within the allowed number of attempts. Game over." << "the correct number was: " << correctNumber << endl;
            break;
          } else {
            cout << "Please try again." << endl;
          }
        }
        guess_times++;
      } else {
        cout << "Invalid input. Please enter a number." << endl;
      }
    }
    return 0;
}
