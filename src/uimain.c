#include <stdio.h>
#include <string.h>

int main() {
  char input[1000];

  printf("q to quit\n");
  
  while (1) {

    printf(">");
    fgets(input, sizeof(input), stdin); // Read input including spaces

    if (strcmp(input, "q") == 0) {
      break; // Should exit the loop but it dosn't :(
    }
    
    printf("%s", input);
  }
  return 0;
}

