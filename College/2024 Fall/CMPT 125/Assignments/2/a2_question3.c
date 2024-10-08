#include "a2_question2.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 301 // Max length + 1 for NUL terminator.

typedef struct {
  short feet;
  short inches;
} Height;

char *fmtLine(char *line, const char *beginning) {
  char *out;
  out = line + (strlen(beginning) + 6);

  int len = strlen(out);

  out[len - 1] = '\0';

  return out;
}

Height *fmtHeight(char *height) {
  short feet;
  short inches;

  if (sscanf(height, "**Height:** %hd'%hd\"", &feet, &inches) == 2) {
    Height *height = (Height *)malloc(sizeof(Height));

    height->feet = feet;
    height->inches = inches;

    return height;
  } else {
    return NULL;
  }
}

char *centerEqual(const char *str) {
  int len = strlen(str);
  if (len == 0) {
    char *buf = (char *)malloc(sizeof(char) * 61);
    for (int i = 0; i < 60; i++) {
      buf[i] = '=';
    }
    buf[60] = '\0';

    return buf;
  }

  bool isOdd = len % 2 != 0;

  if (len >= 80) {
    return NULL;
  }

  int lenOfSide = 30 - (len / 2);

  char *rightSide = (char *)malloc(sizeof(char) * lenOfSide);
  char *leftSide = (char *)malloc(sizeof(char) * lenOfSide);

  for (int i = 0; i < lenOfSide; i++) {
    leftSide[i] = '=';
    rightSide[i] = '=';
  }

  leftSide[lenOfSide - 1] = '\0';
  rightSide[lenOfSide - 1] = '\0';

  if (isOdd) {
    rightSide[lenOfSide - 2] = '\0';
  }

  char *buf = (char *)malloc(sizeof(char) * 80);
  buf[0] = '\0';

  strcat(buf, leftSide);
  strcat(buf, " ");
  strcat(buf, str);
  strcat(buf, " ");
  strcat(buf, rightSide);

  free(rightSide);
  free(leftSide);

  return buf;
}

void printBanner() {
  char *roof = centerEqual("");
  char *title = centerEqual("Superheros Lookup System");
  char *name = centerEqual("Alexander Ng");
  char *studentNumber = centerEqual("301633831");
  char *email = centerEqual("ana156@sfu.ca");

  printf("%s\n", roof);
  printf("%s\n", title);
  printf("%s\n", name);
  printf("%s\n", studentNumber);
  printf("%s\n", email);
  printf("%s\n", roof);

  free(title);
  free(name);
  free(studentNumber);
  free(email);
  free(roof);
}

void printHero(Superhero *hero, int idx) {
  printf("Superhero #%d\n", idx + 1);
  printf("%s\n", hero->name);
  printf("%hd'%hd\"\n", hero->feetInHeight, hero->inchesInHeight);
  printf("%s: %s", hero->superpower, hero->traits);
}

int main() {
  int cap = 16;
  int used = 0;
  Superhero **heroArray = (Superhero **)malloc(sizeof(Superhero *) * cap);

  // 1204 byte data buffer for linewise hero data
  char heroDataBuf[4][MAX_LINE_LENGTH];

  // buf for reading linewise
  char buf[MAX_LINE_LENGTH];

  FILE *file;
  file = fopen("superheros.txt", "r");
  if (file == NULL) {
    printf("Error while opening file\n");
    return 1;
  }

  int lineCounter = 0;

  // while (fgets(buf, sizeof(buf), file) != NULL) {
  while (!feof(file)) {
    fgets(buf, sizeof(buf), file);

    if (used == cap) {
      // Grow by 2x cap
      cap *= 2;
      heroArray = (Superhero **)realloc(heroArray, sizeof(Superhero *) * cap);
    }

    if (((lineCounter % 5) == 4 && lineCounter != 0)) {
      Height *height = fmtHeight(heroDataBuf[1]);

      if (height == NULL) {
        // DEBUG
        printf("HEIGHT IS NUL PANICKING");
        return 1;
      }

      Superhero *hero = createSuperhero(
          fmtLine(heroDataBuf[0], "Name"), height->feet, height->inches,
          fmtLine(heroDataBuf[2], "Superpower"), heroDataBuf[3]);

      heroArray[used] = hero;
      used++;

      free(height);
    } else {
      strcpy(heroDataBuf[lineCounter % 5], buf);
    }

    lineCounter++;
  }

  printBanner();

  char *separator = centerEqual("");

  for (int i = 0; i < used; i++) {
    printHero(heroArray[i], i);
    printf("%s\n", separator);
  }

  printf("cap: %d; used: %d\n", cap, used);

  for (int i = 0; i < used; i++) {
    clearSuperhero(heroArray[i]);
    free(heroArray[i]);
  }

  free(heroArray);
  fclose(file);
  free(separator);

  return 0;
}
