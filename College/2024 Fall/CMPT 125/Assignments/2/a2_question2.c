#include <stdlib.h>
#include <string.h>

#include "a2_question2.h"

char *allocate_and_copy_string(const char *source) {
  // strlen(name) + 1 gives enough space to hold `name` and it's NUL terminator.
  char *dest = (char *)malloc((strlen(source) + 1) * sizeof(char));
  if (dest == NULL) {
    return NULL;
  }
  // Safe to do strcpy here because `name` is guaranteed to be a valid c-string
  // and hero->name definitely has enough space to hold name.
  strcpy(dest, source);
  return dest;
}

Superhero *createSuperhero(const char *name, short feetInHeight,
                           short inchesInHeight, const char *superpower,
                           const char *traits) {
  Superhero *hero = (Superhero *)malloc(sizeof(Superhero));

  if (hero == NULL) {
    return NULL;
  }

  hero->name = allocate_and_copy_string(name);
  if (hero->name == NULL) {
    free(hero);
    return NULL;
  }

  hero->feetInHeight = feetInHeight;
  hero->inchesInHeight = inchesInHeight;

  hero->superpower = allocate_and_copy_string(superpower);
  if (hero->superpower == NULL) {
    free(hero->name);
    free(hero);
    return NULL;
  }

  hero->traits = allocate_and_copy_string(traits);

  if (hero->traits == NULL) {
    free(hero->name);
    free(hero->superpower);
    free(hero);
    return NULL;
  }

  return hero;
}

void clearSuperhero(Superhero *superhero) {
  if (superhero == NULL) {
    return;
  }

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
