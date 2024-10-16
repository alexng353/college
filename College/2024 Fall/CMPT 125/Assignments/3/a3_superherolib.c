#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "a3_superherolib.h" // for the Superhero struct

/*
 * This helper function allocates and deep copies a string.
 *
 * input: source - the string to be copied
 *
 * returns: a pointer to the newly allocated and copied string
 */
char *allocateAndCopyString(const char *source) {
  // strlen(name) + 1 gives enough space to hold `name` and its NUL terminator.
  char *dest = (char *)malloc((strlen(source) + 1) * sizeof(char));
  if (dest == NULL) {
    return NULL;
  }

  // Safe to do strcpy here because `name` is guaranteed to be a valid c-string
  // and hero->name definitely has enough space to hold `name`.
  strcpy(dest, source);

  return dest;
}

/*
 * Creates and returns a Superhero struct pointer.
 *
 * Superhero represents three char arrays: name, superpower and traits, and
 * two shorts representing feet in height and inches in height respectively.
 *
 * Safety:
 * The Superhero struct and the three char arrays are allocated on the heap
 * using malloc. The three char arrays are deep copied from the input
 * parameters using strcpy. A helper function `clearSuperhero` is provided to
 * free the three char arrays. The Caller is responsible for freeing the
 * Superhero struct pointer.
 *
 * Safety 2:
 * If any of the allocations fail, this function will free all previously
 * allocated memory and return NULL.
 *
 * input: name - the name of the superhero
 *        feetInHeight - the feet in height of the superhero
 *        inchesInHeight - the inches in height of the superhero
 *        superpower - the superpower of the superhero
 *        traits - the traits of the superhero
 *
 * returns: a Superhero struct pointer
 */
Superhero *createSuperhero(const char *name, short feetInHeight,
                           short inchesInHeight, const char *superpower,
                           const char *traits) {
  Superhero *hero = (Superhero *)malloc(sizeof(Superhero));

  if (hero == NULL) {
    return NULL;
  }

  hero->feetInHeight = feetInHeight;
  hero->inchesInHeight = inchesInHeight;

  // Allocate and deep copy the name, superpower and traits char arrays.
  //
  // If any of these allocations fail, then free the Superhero struct
  // and all of its existing char arrays, and return NULL.
  hero->name = allocateAndCopyString(name);
  if (hero->name == NULL) {
    free(hero);
    return NULL;
  }

  hero->superpower = allocateAndCopyString(superpower);
  if (hero->superpower == NULL) {
    free(hero->name);
    free(hero);
    return NULL;
  }

  hero->traits = allocateAndCopyString(traits);
  if (hero->traits == NULL) {
    free(hero->name);
    free(hero->superpower);
    free(hero);
    return NULL;
  }

  return hero;
}

/*
 * Frees the three char arrays in the Superhero struct.
 *
 * input: superhero - the Superhero struct pointer
 *
 * returns: void
 */
void clearSuperhero(Superhero *superhero) {
  if (superhero == NULL) {
    return;
  }

  // name, superpower and traits are all heap mallocated character arrays, so
  // we need to free them.
  //
  // According to the code in `test2.c`, the Superhero* pointer should be
  // freed by the caller instead of this function.
  //
  // If these are NULL pointers, then:
  //    1. We don't need to free them
  //    2. We still need to free the rest of the Superhero struct
  if (superhero->name != NULL) {
    free(superhero->name);
  }
  if (superhero->superpower != NULL) {
    free(superhero->superpower);
  }
  if (superhero->traits != NULL) {
    free(superhero->traits);
  }
}

Superhero **lookupSuperheroBySuperpower(Superhero **array, int size,
                                        const char *superpower);

int compareSuperheroesByHeight(const void *p1, const void *p2);

int compareSuperheroesByName(const void *p1, const void *p2);

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
 *
 * safety: returns NULL if displayWidth is not % 2
 */
char *centerEqual(const char *str, int displayWidth) {
  if (displayWidth % 2 != 0) {
    printf("displayWidth is not even");
    return NULL;
  }

  int len = strlen(str);

  // If the string is empty, return a string of equal signs of length
  // displayWidth
  if (len == 0) {
    // Allocation of memory for the string + 1 for the NUL terminator
    char *buf = (char *)malloc(sizeof(char) * displayWidth + 1);

    // Note that because index begins at 0, buf[displayWidth] is the last
    // character index in the string.
    for (int i = 0; i < displayWidth; i++) {
      buf[i] = '=';
    }
    buf[displayWidth] = '\0';

    return buf;
  }

  if (len >= displayWidth) {
    return NULL;
  }

  bool isOdd = len % 2 != 0;
  int lenOfSide = (displayWidth - len) / 2;

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

  char *buf = (char *)malloc(sizeof(char) * (displayWidth + 1));
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
void printBanner(const char *title, const char *name, const char *studentNumber,
                 const char *email, int displayWidth) {
  char *separator = centerEqual("", displayWidth);
  char *fmtTitle = centerEqual(title, displayWidth);
  char *fmtName = centerEqual(name, displayWidth);
  char *fmtStudentNumber = centerEqual(studentNumber, displayWidth);
  char *fmtEmail = centerEqual(email, displayWidth);

  printf("%s\n", separator);
  printf("%s\n", title);
  printf("%s\n", name);
  printf("%s\n", studentNumber);
  printf("%s\n", email);
  printf("%s\n", separator);

  free(fmtTitle);
  free(fmtName);
  free(fmtStudentNumber);
  free(fmtEmail);
  free(separator);
}

Option promptUser() {
  printf("Press numbers 1-5 for the following options and then enter:\n");

  printf("1) Load a Superheros file\n");
  printf("2) List Superheros by Height\n");
  printf("3) List Superheros by Name\n");
  printf("4) Lookup a Superhero\n");
  printf("5) Exit Program\n");

  printf("Option: ");

  int inputBuf = -1;
  scanf("%d", &inputBuf);

  if (inputBuf < 1 || inputBuf > 5) {
    return PromptUnknownOption;
  }

  return inputBuf;
}
