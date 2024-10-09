// The max number of digits in an int (unsigned int - 1).length
#define MAX_DIGITS 10

/*
 * This function replaces any matching target digit in the input number with
 * the replacement digit.
 *
 * input: number - the number to be modified
 *        target - the digit to be replaced
 *        replacement - the digit used for replacement
 *        place - the position of the target digit in the number
 *
 * returns: the modified number
 */
int replaceDigitHelper(int number, int target, int replacement, int place) {
  if (number == 0) {
    return 0;
  }

  // Extract the last digit (the remainder of a decimal number divided by 10
  // is it's last digit)
  int lastDigit = number % 10;

  if (lastDigit == target) {
    lastDigit = replacement;
  }

  // Recursively process the remaining digits
  //
  // By adding the replaced lastDigit * the place value, we effectively replace
  // the digit in the nth place with the replaced value.
  //
  // Multiplying the place value by 10 each time effectively shifts the
  // position of the target place value left by 1 place.
  return replaceDigitHelper(number / 10, target, replacement, place * 10) +
         lastDigit * place;
}

/*
 * This function prepares recursively replaces the target digit in the input
 * number with the replacement digit.
 *
 * input: number - the number to be modified
 *        target - the digit to be replaced
 *        replacement - the digit used for replacement
 *
 * returns: the modified number
 *
 * constraint: the target and replacement characters are digits. Calling this
 * function with a non-digit character will result in unspecified behavior.
 */
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
