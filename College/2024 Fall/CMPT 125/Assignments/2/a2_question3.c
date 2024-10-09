#include "a2_question2.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 301 // Max length + 1 for NUL terminator.
#define DISPLAY_WIDTH 60    // Must be even

// Struct representing a height in feet and inches
typedef struct {
  short feet;
  short inches;
} Height;

/*
 * Remove the beginning of the line and the trailing newline character
 *
 * input: line - the line to be formatted
 *        beginning - the beginning of the line to be removed
 *
 * output: the formatted line
 */
char *fmtLine(char *line, const char *beginning) {
  char *out;

  // Trim the beginning of the line by moving the char pointer forwards by n
  out = line + strlen(beginning);

  int len = strlen(out);

  // Remove the trailing newline character if it exists
  if (out[len - 1] == '\n') {
    out[len - 1] = '\0';
  }

  return out;
}

/*
 * Parse the height string and return a Height struct
 *
 * Safety: if the height string is not in the correct format, the function
 *         returns NULL
 *
 * input: height - the height string to be parsed
 *
 * output: the Height struct
 */
Height *fmtHeight(char *height) {
  short feet;
  short inches;

  // Parse the height line from feet'inches" to the feet and inches variables
  if (sscanf(height, "**Height:** %hd'%hd\"", &feet, &inches) == 2) {
    Height *height = (Height *)malloc(sizeof(Height));

    height->feet = feet;
    height->inches = inches;

    return height;
  } else {
    return NULL;
  }
}

/*
 * Center a string between two strings of equal signs, totalling LINE_WIDTH
 * characters
 *
 * input: str - the string to be centered
 *
 * output: the centered string
 */
char *centerEqual(const char *str) {
  int len = strlen(str);

  // If the string is empty, return a string of equal signs of length
  // DISPLAY_WIDTH
  if (len == 0) {
    // Allocation of memory for the string + 1 for the NUL terminator
    char *buf = (char *)malloc(sizeof(char) * DISPLAY_WIDTH + 1);

    // Note that because index begins at 0, buf[DISPLAY_WIDTH] is the last
    // character index in the string.
    for (int i = 0; i < DISPLAY_WIDTH; i++) {
      buf[i] = '=';
    }
    buf[DISPLAY_WIDTH] = '\0';

    return buf;
  }

  if (len >= DISPLAY_WIDTH) {
    return NULL;
  }

  bool isOdd = len % 2 != 0;
  int lenOfSide = (DISPLAY_WIDTH - len) / 2;

  // Allocate enough memory for the left and right sides of the string + 1 for
  // the NUL terminator
  char *rightSide = (char *)malloc(sizeof(char) * (lenOfSide + 1));
  char *leftSide = (char *)malloc(sizeof(char) * (lenOfSide + 1));

  for (int i = 0; i < lenOfSide; i++) {
    leftSide[i] = '=';
    rightSide[i] = '=';
  }

  // Set the last and first character of the left and right sides respectively
  // to spaces to save on the number of strcat calls and still have a space
  // in the formatting
  leftSide[lenOfSide - 1] = ' ';
  rightSide[0] = ' ';

  // Set the last character to a NUL byte to ensure c-string safety
  leftSide[lenOfSide] = '\0';
  rightSide[lenOfSide] = '\0';

  if (isOdd) {
    rightSide[lenOfSide - 2] = '\0';
  }

  char *buf = (char *)malloc(sizeof(char) * (DISPLAY_WIDTH + 1));
  // Set the first character of the buffer to a NUL byte for c-string safety
  // within string.h library functions.
  buf[0] = '\0';

  strcat(buf, leftSide);
  // strcat(buf, " ");
  strcat(buf, str);
  // strcat(buf, " ");
  strcat(buf, rightSide);

  free(rightSide);
  free(leftSide);

  return buf;
}

/*
 * Print the banner at the top of the program
 */
void printBanner() {
  char *separator = centerEqual("");
  char *title = centerEqual("Superheros Lookup System");
  char *name = centerEqual("Alexander Ng");
  char *studentNumber = centerEqual("301633831");
  char *email = centerEqual("ana156@sfu.ca");

  printf("%s\n", separator);
  printf("%s\n", title);
  printf("%s\n", name);
  printf("%s\n", studentNumber);
  printf("%s\n", email);
  printf("%s\n", separator);

  free(title);
  free(name);
  free(studentNumber);
  free(email);
  free(separator);
}

/*
 * Print a correctly formatted superhero
 */
void printHero(Superhero *hero, int idx) {
  // printf("Superhero #%d\n", idx + 1);
  // printf("%s\n", hero->name);
  // printf("%hd'%hd\"\n", hero->feetInHeight, hero->inchesInHeight);
  // printf("%s: %s", hero->superpower, hero->traits);

  // Equiavelnt to the above but saves on the number of printf calls

  printf("Superhero #%d\n%s\n%hd'%hd\"\n%s: %s", idx + 1, hero->name,
         hero->feetInHeight, hero->inchesInHeight, hero->superpower,
         hero->traits);
}

int main() {
  // Initiate our hero array with a sensible capacity
  int cap = 16;
  int used = 0;
  Superhero **heroArray = (Superhero **)malloc(sizeof(Superhero *) * cap);

  // 1204 byte data buffer for linewise hero data
  char heroDataBuf[4][MAX_LINE_LENGTH];

  // buf for doing the linewise read of the file
  char readBuf[MAX_LINE_LENGTH];

  FILE *file;
  file = fopen("superheros.txt", "r");
  if (file == NULL) {
    printf("Error while opening file\n");
    return 1;
  }

  // Iterate through the file line by line with fgets and feof, incrementing
  // lineCounter each time. We use !feof(file) instead of fgets(...) != NULL
  // in order to inclue the final iteration
  int lineCounter = 0;
  while (!feof(file)) {
    fgets(readBuf, sizeof(readBuf), file);

    // Grow the capacity if more is needed, doubling it each time
    //
    // We do this at the beginning of each iteration because we don't want to
    // grow the capacity unnecessarily if we're at the end of the file
    if (used == cap) {
      cap *= 2;
      heroArray = (Superhero **)realloc(heroArray, sizeof(Superhero *) * cap);
    }

    int currentDataLine = lineCounter % 5;

    // Format specifies that data stops at the fifth line, so we check if we
    // are at the fifth line and if so, create the superhero and append it to
    // our dynamic array
    if (currentDataLine == 4) {
      Height *height = fmtHeight(heroDataBuf[1]);

      if (height == NULL) {
        return 1;
      }

      Superhero *hero = createSuperhero(
          fmtLine(heroDataBuf[0], "**Name:** "), height->feet, height->inches,
          fmtLine(heroDataBuf[2], "**Superpower:** "), heroDataBuf[3]);

      heroArray[used] = hero;
      used++;

      free(height);
    } else {
      // If we are not at the fifth line, copy the line to the appropriate
      // buffer
      strcpy(heroDataBuf[currentDataLine], readBuf);
    }

    lineCounter++;
  }

  // We're done reading the file, so close it as soon as possible
  fclose(file);

  printBanner();

  char *separator = centerEqual("");

  for (int i = 0; i < used; i++) {
    printHero(heroArray[i], i);
    printf("%s\n", separator);
  }

  free(separator);
  separator = NULL;

  // For debugging purposes
  // printf("cap: %d; used: %d\n", cap, used);

  // Iterate through the array and free the memory allocated to each superhero,
  // then free the array itself
  for (int i = 0; i < used; i++) {
    clearSuperhero(heroArray[i]);
    free(heroArray[i]);
    heroArray[i] = NULL;
  }

  free(heroArray);
  heroArray = NULL;

  return 0;
}
