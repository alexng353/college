#include "a2_question2.h"
#include <stdio.h>
#include <string.h>

// a helper function that compares 2 shorts
void checkAndPrintShorts(short expected, short result) {
  if (expected == result) {
    printf("%d is the same as %d, PASS\n", expected, result);
  } else {
    printf("%d is not the same as %d, FAIL\n", expected, result);
  }
}

int main() {

  // only exceptions to the character limits so as to keep the content intact
  char *name = "Thunderstrike";
  char *superpower = "Weather Control";
  char *traits =
      "Harnessing storms, Thunderstrike commands thunder and lightning, using "
      "nature's fury to protect the innocent and fight against evil.";

  // creating a Superhero struct variable and print its content
  Superhero *superhero = createSuperhero(name, 6, 0, superpower, traits);
  printf("%s\n%d\'%d\"\n%s: %s\n", superhero->name, superhero->feetInHeight,
         superhero->inchesInHeight, superhero->superpower, superhero->traits);

  if (strcmp(name, superhero->name) == 0) {
    printf("Names have the same content, PASS\n");
  } else {
    printf("Names do not have the same content, FAIL\n");
  }
  if (name == superhero->name) { // should do a deep copy
    printf("Names have the same address, FAIL\n");
  } else {
    printf("Names do not have the same address, PASS\n");
  }

  checkAndPrintShorts(6, superhero->feetInHeight);
  checkAndPrintShorts(0, superhero->inchesInHeight);

  if (strcmp(superpower, superhero->superpower) == 0) {
    printf("Superpowers have the same content, PASS\n");
  } else {
    printf("Superpowers do not have the same content, FAIL\n");
  }
  if (superpower == superhero->superpower) { // should do a deep copy
    printf("Superpowers have the same address, FAIL\n");
  } else {
    printf("Superpowers do not have the same address, PASS\n");
  }

  if (strcmp(traits, superhero->traits) == 0) {
    printf("Traits have the same content, PASS\n");
  } else {
    printf("Traits do not have the same content, FAIL\n");
  }
  if (traits == superhero->traits) { // should do a "deep-copy"
    printf("Traits have the same address, FAIL\n");
  } else {
    printf("Traits do not have the same address, PASS\n");
  }

  // to check if there is any memory leaks, use this tool in the command line:
  // valgrind --leak-check=yes ./test2
  clearSuperhero(superhero);
  free(superhero);
  superhero = NULL;

  return 0;
}
