#include <stdlib.h>
#include <string.h>

#include "a2_question2.h"

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
