// The max number of digits in an int (unsigned int - 1).length
#define MAX_DIGITS 10

// Helper function to replace digits recursively
int replaceDigitHelper(int number, int target, int replacement, int place) {
  if (number == 0) {
    return 0;
  }

  // Extract the last digit
  int lastDigit = number % 10;

  // Replace the target digit if found
  if (lastDigit == target) {
    lastDigit = replacement;
  }

  // Recursively process the remaining digits
  return replaceDigitHelper(number / 10, target, replacement, place * 10) +
         lastDigit * place;
}

int replaceDigitsRecursive(int number, char target, char replacement) {
  // Convert the char 'target' and 'replacement' to integers
  // Subtracting b'0' is equivalent to subtracting the ASCII value of '0',
  // effectively converting our char target to an integer
  int targetDigit = target - '0';
  int replacementDigit = replacement - '0';

  // Handle negative numbers by converting to positive
  int isNegative = (number < 0);
  if (isNegative) {
    number = -number;
  }

  // Replace the digits recursively
  int newNumber = replaceDigitHelper(number, targetDigit, replacementDigit, 1);

  // Restore the sign if the number was negative
  if (isNegative) {
    newNumber = -newNumber;
  }

  return newNumber;
}
