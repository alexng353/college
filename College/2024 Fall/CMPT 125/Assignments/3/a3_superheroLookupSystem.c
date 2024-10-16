#include "a3_superherolib.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void *loadFile() {
  char *buf = malloc(sizeof(char) * 256);
  buf[256] = '\0';

  if (fgets(buf, 255, stdin) == NULL) {
    return NULL;
  }

  return NULL;
}

int main() {
  printBanner("Superhero Lookup System", "Alexander Ng", "301633831",
              "ana156@sfu.ca", 60);

  while (1) {
    Option option = promptUser();
    switch (option) {
    case Load:
      break;
    case ListByHeight:
      break;
    case ListByName:
      break;
    case Lookup:
      break;
    case PromptUnknownOption:
      break;
    case Exit:
      break;
    }

    if (option == Exit) {
      break;
    }
  }

  Option prompt = promptUser();

  printf("%d\n", prompt);

  return 0;
}
