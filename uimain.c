#include <stdio.h>

//#include "filename.h"



int main(){
  printf("Enter quit to stop program\n");

  char input[100];
  while(input !="quit"){
    printf(">");
    scanf("%s", input);
    printf("%s\n", input);

    if(input =="quit"){
      break;//dosen't work :(
    }
  }
  printf("Have a good day");

  return 0;
}
