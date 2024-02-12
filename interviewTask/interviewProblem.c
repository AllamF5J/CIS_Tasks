#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_Bool palindrome(char *word) {
  int size = strlen(word);
  int i = 0;
  int j = size - 1;
  while (i < j) {
    if (word[i++] != word[j--]) return 0;
  }
  return 1;
}
int main() {
  char array[100];
  printf("Enter a palindrome ,please : ");
  gets(array);

  if (palindrome(array))
    printf("Your word is a palindrome");
  else
    printf("Your word isn't a palindrome");

  return 0;
}
