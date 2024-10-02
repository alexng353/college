/*
Modify to test fewer or more cases.
No need to submit it as we'll supply one.
*/
#include "a2_question1.h" //function header

#include <stdio.h> //for console I/O

//a helper function that compares 2 ints
void checkAndPrintInts(int expected, int result) {
    if (expected != result) {
        printf("Different values: %d vs %d, FAIL\n", expected, result);
    } else {
        printf("Values are equal, PASS\n");
    }
}

int main() {
    //function should return 2
    checkAndPrintInts(2, replaceDigitsRecursive(1, '1', '2'));

    //function should return -202
    checkAndPrintInts(-202, replaceDigitsRecursive(-232, '3', '0'));

    //function should return 123
    checkAndPrintInts(123, replaceDigitsRecursive(123, '4', '5'));

    //function should return 1223
    checkAndPrintInts(1223, replaceDigitsRecursive(1223, '!', '?'));

    //function should return 670
    checkAndPrintInts(670, replaceDigitsRecursive(5670, '5', '0'));

    //function should return 39499
    checkAndPrintInts(39499, replaceDigitsRecursive(30400, '0', '9'));

    return 0;
}
